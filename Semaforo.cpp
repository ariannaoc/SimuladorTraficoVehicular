#include "Semaforo.h"
namespace TraficoVehicular {

	Semaforo::Semaforo(int xx, int yy, Direccion s) {
		x = xx;
		y = yy;
		estadoActual = EstadoSemaforo::Verde;
		timer = 0;
		duracionEstado = 50;
		duracionAmarillo = 20;
		sentido = s;
	}
	int Semaforo::getDuracionEstado() {
		return duracionEstado;
	}

	Point Semaforo::getPosicion() {
		return Point(x, y);
	}

	Direccion Semaforo::getDireccion() {
		return sentido;
	}

	void Semaforo::Cambiar() {
		timer++;


			if (estadoActual == EstadoSemaforo::Verde) {
				if (timer >= duracionEstado) {
					estadoActual = EstadoSemaforo::Amarillo;
					timer = 0; 
				}
			}
			else if (estadoActual == EstadoSemaforo::Amarillo) {
				if (timer >= duracionAmarillo) {
					estadoActual = EstadoSemaforo::Rojo;
					timer = 0; 
				}
			}
			else if (estadoActual == EstadoSemaforo::Rojo) {
				if (timer >= (duracionEstado + duracionAmarillo)) {
					estadoActual = EstadoSemaforo::Verde;
					timer = 0;
				}
			}
	}
	void Semaforo::setEstado(EstadoSemaforo e) {
		estadoActual = e;
		timer = 0;
	}

	void Semaforo::Dibujar(BufferedGraphics^ graph, Bitmap^ fig) {
		int xx = 0;

		switch (estadoActual) {
		case EstadoSemaforo::Verde:    xx = 0;       break;
		case EstadoSemaforo::Amarillo: xx = 125;     break;
		case EstadoSemaforo::Rojo:     xx = 125 * 2; break;
		}

		Rectangle recorte(xx, 0, 120, fig->Height);
		Rectangle contenedor(x, y, 25, 60);


		// Guardar estado gráfico
		System::Drawing::Drawing2D::GraphicsState^ estado = graph->Graphics->Save();

		// trasladar origen al centro del sprite
		float cx = x + contenedor.Width / 2.0f;
		float cy = y + contenedor.Height / 2.0f;
		graph->Graphics->TranslateTransform(cx, cy);

		int angulo = 0;
		switch (sentido)
		{
		case Direccion::Norte:
			angulo = 0;
			break;
		case Direccion::Sur:
			angulo = 180;
			break;
		case Direccion::Este:
			angulo = 90;
			break;
		case Direccion::Oeste:
			angulo = -90;
			break;
		default:
			break;
		}

		graph->Graphics->RotateTransform((float)(angulo));
		graph->Graphics->TranslateTransform(-cx, -cy);

		// dibujar sprite rotado
		graph->Graphics->DrawImage(fig, contenedor, recorte, GraphicsUnit::Pixel);

		// restaurar estado
		graph->Graphics->Restore(estado);

	}

}