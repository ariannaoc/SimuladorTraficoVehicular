#pragma once
#include <cstdlib>
#include <cmath>
#include "Motor.hpp"
using namespace System::Drawing;

namespace TraficoVehicular {

	public class Auto {
	public:
		int x, y;
		int velocidad;
		int tiempo;
		int marcha; 
		int color;
		Motor* motor;
		int angulo;        // dirección en grados
		char direccion; // Norte, Sur, Este, Oeste
		int altoAuto = 30;
		int anchoAuto = 20;


		Auto(int xx, int yy) {
			x = xx;
			y = yy;
			velocidad = 5;
			tiempo = 0;
			marcha = 0;
			color = rand() % 6;
			angulo = -90;
			direccion = 'N';
		}

		void setMotor(Motor* m) {
			motor = m;
		}

		void setPosicion(int xx, int yy) {
			x = xx;
			y = yy;
		}

		Point getPosicion() {
			return Point(x, y);
		}

		void girar(int direccion) {
			if (direccion == 'i') // izquierda
				angulo -= 15;
			else if (direccion == 'd') // derecha
				angulo += 15;
		}


		void tomarDecision() {
			tiempo++;

			// Lógica de cambio de marchas
			if (tiempo % 5 == 0) {
				if (tiempo < 28 && marcha < 5) {
					marcha++; 
				}
				else if (tiempo > 28 && marcha > 0) {
					marcha--;
				}
			}

			// condición de acelerar o frenar
			if (tiempo < 28) {
				motor->acelerar(marcha);
			}
			else {
				motor->frenar(marcha);
			}

			// Actualizar la velocidad del Auto con la del Motor
			velocidad = motor->getVelocidad();
		}

		void Mover() {
			// convertir ángulo a radianes
			float rad = angulo * 3.14159265f / 180.0f;

			// avanzar en la dirección del ángulo
			x += (int)(velocidad * cos(rad));
			y += (int)(velocidad * sin(rad));
		}

		void Dibujar(BufferedGraphics^ graph, Bitmap^ fig) {
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
		}
	};
}



