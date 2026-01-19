#include "Auto.hpp"      
#include <iostream>

namespace TraficoVehicular {

	Auto::Auto(int xx, int yy, int dir) {
		x = xx;
		y = yy;
		velocidad = 0;
		tiempo = 0;
		marcha = 0;
		color = rand() % 6;
		angulo = dir == 1 ? 90 : dir == 2 ? 0 : dir == 3 ? 180 : 270;
		anguloObjetivo = 0;
		direccion = dir;
		estado = 0;
		autosCercanos = nullptr;
		motor = nullptr;
		carrilActual = nullptr;
	}

	Auto::~Auto() {
		if (autosCercanos != nullptr) delete autosCercanos;
	}

	void Auto::setMotor(Motor* m) { motor = m; }

	void Auto::setPosicion(int xx, int yy) {
		x = xx;
		y = yy;
	}
	Point Auto::getPosicion() { return Point(x, y); }

	String^ Auto::getInfo() {

		String^ estadoTxt = (estado == 0) ? "Estacionado" : "Andando";
		String^ direccionTxt;
		switch (direccion) {
		case 1: direccionTxt = "Sur";   break;
		case 2: direccionTxt = "Este";  break;
		case 3: direccionTxt = "Oeste"; break;
		default: direccionTxt = "Norte"; break;
		}
		String^ colorTxt;
		switch (color) {
		case 0: colorTxt = "Rojo";   break; // rojo
		case 1: colorTxt = "Gris";   break; // gris
		case 2: colorTxt = "Rosa";   break; // rosa
		case 3: colorTxt = "Azul";   break; // azul
		case 4: colorTxt = "Amarillo"; break; // amarillo
		case 5: colorTxt = "Verde"; break; // verde
		}

		String^ info = "Color: " + colorTxt + "\r\n" +
			"Estado: " + estadoTxt + "\r\n" +
			"Velocidad: " + velocidad + " km/h\r\n" +
			"Direccion: " + direccionTxt + "\r\n";

		return info;
	}

	void Auto::girar(int giro) {
		if (giro == 'i')
			angulo -= 90; // Giro de 90 grados
		else if (giro == 'd')
			angulo += 90;

		// Actualizar dirección cardinal
		if (angulo == 0 || angulo == 360) direccion = 2;      // Este
		else if (angulo == 90)           direccion = 1;      // Sur
		else if (angulo == 180)          direccion = 3;      // Oeste
		else if (angulo == 270 || angulo == -90) direccion = 0; // Norte
	}

	// Las dimensiones del campo visual cambian segun en angulo del auto 
	int Auto::getCampoVisualAncho() {
		int a = ((angulo % 360) + 360) % 360;
		if (a == 90 || a == 270) // N / S 
			return anchoAuto * 2;
		else                    // E / O 
			return altoAuto * 4;
	}

	int Auto::getCampoVisualAlto() {
		int a = ((angulo % 360) + 360) % 360;
		if (a == 90 || a == 270) // N / S
			return altoAuto * 4;
		else                     // E / O 
			return anchoAuto * 2;
	}

	int Auto::getCampoVisualx() {
		return x + (anchoAuto - getCampoVisualAncho()) / 2;
	}

	int Auto::getCampoVisualy() {
		return y + (altoAuto - getCampoVisualAlto()) / 2;
	}

	void Auto::tomarDecision() {
		tiempo++;

		bool alertaColision = false;

		if (autosCercanos != nullptr && autosCercanos->tieneElementos()) {
			alertaColision = true;
		}

		// Evaluar el semáforo del carril actual
		 EstadoSemaforo semaforo = carrilActual->getSemaforo()->estadoActual;

		if (alertaColision || semaforo == EstadoSemaforo::Rojo) {
			// Frenar el auto gradualmente
			if (this->marcha > 0) this->marcha--;
			this->motor->frenar(this->marcha);
		} else if(semaforo == EstadoSemaforo::Amarillo) {
			// Reducir la velocidad del auto a marcha 1
			if (this->marcha > 1) this->marcha--;
			this->motor->frenar(this->marcha);
		} else {
			// Acelerar el auto gradualmente
			if (this->tiempo % 5 == 0 && this->marcha < 5) {
				this->marcha++;
			}
			this->motor->acelerar(this->marcha);
		}

		// Actualizar la velocidad del Auto con la del Motor
		this->velocidad = this->motor->getVelocidad();

		// Cambiar estado 
		if (this->velocidad > 0) {
			this->estado = 1;
		}
		else {
			this->estado = 0;
		}

	}

	void Auto::Mover() {
		// Mover el auto según su velocidad y ángulo
		float radianes = angulo * 3.14159f / 180.0f;
		x += (int)(velocidad * cos(radianes));
		y += (int)(velocidad * sin(radianes));
	}

	void Auto::Dibujar(BufferedGraphics^ graph, Bitmap^ fig) {
		int xx = 0, yy = 0;
		switch (color) {
		case 0: xx = 0;   yy = 0;   break; // rojo
		case 1: xx = 100; yy = 0;   break; // gris
		case 2: xx = 200; yy = 0;   break; // rosa
		case 3: xx = 400; yy = 0;   break; // azul
		case 4: xx = 400; yy = 190; break; // amarillo
		case 5: xx = 500; yy = 190; break; // verde
		}

		Rectangle recorte(xx, yy, 100, 155);
		Rectangle contenedor(x, y, anchoAuto, altoAuto);

		// Guardar estado gráfico
		System::Drawing::Drawing2D::GraphicsState^ estado = graph->Graphics->Save();

		// trasladar origen al centro del sprite
		float cx = x + contenedor.Width / 2.0f;
		float cy = y + contenedor.Height / 2.0f;
		graph->Graphics->TranslateTransform(cx, cy);
		graph->Graphics->RotateTransform((float)(angulo + 90)); // 90°
		graph->Graphics->TranslateTransform(-cx, -cy);

		// dibujar sprite rotado
		graph->Graphics->DrawImage(fig, contenedor, recorte, GraphicsUnit::Pixel);

		// restaurar estado
		graph->Graphics->Restore(estado);

		// Solo para depuración: dibuja el campo visual en rojo transparente
		Pen^ p = gcnew Pen(Color::FromArgb(100, Color::Red));
		graph->Graphics->DrawRectangle(p, getCampoVisualx(), getCampoVisualy(), getCampoVisualAncho(), getCampoVisualAlto());

	}

	bool Auto::isHover(int mouseX, int mouseY) {
		// Posicion del mouse y del auto
		//std::cout << "Mouse: (" << mouseX << "," << mouseY << ") Auto: (" << x << "," << y << ")" << std::endl;

		if (mouseX >= x && mouseX <= (x + anchoAuto) &&
			mouseY >= y && mouseY <= (y + altoAuto)) {
			return true;
		}
		return false;
	}

	void Auto::setCarril(Carril^ c) {
		carrilActual = c;
	}


}