#pragma once
#include <cstdlib>
using namespace System::Drawing;
namespace TraficoVehicular {

	public class Auto {
	public:
		int x, dx, y, dy, tiempo_marcha, color, angulo;

		Auto(int xx, int yy) {
			x = xx;
			y = yy;
			dx = 0;
			dy = 0; // distancia recorrida en una unidad de tiempo  
			tiempo_marcha = 0;
			color = rand() % 6;
			angulo = rand() % 180;
		}

		void setVelocidad(int dx, int dy) {
			this->dx = dx;
			this->dy = dy;
		}
		void tomarDecision() {
			// decidir velocidad 
			if (tiempo_marcha % 5 == 0)
				setVelocidad(0, rand() % 10 + 5);

			tiempo_marcha++;
			// decidir direccion
			
		}

		void Mover() {
			x += dx;
			y -= dy;
		}
		void Dibujar(BufferedGraphics^ graph, Bitmap^ fig) {
			int xx = 0;
			int yy = 0;
			switch (color)
			{
			case 0: // rojo
				xx = 0;
				yy = 0;
				break;
			case 1: // gris
				xx = 100;
				yy = 0;
				break;
			case 2: // rosa
				xx = 200;
				yy = 0;
				break;
			case 3: // azul
				xx = 400;
				yy = 0;
				break;
			case 4: // amarillo
				xx = 400;
				yy = 190;
				break;
			case 5: // verde
				xx = 500;
				yy = 190;
				break;
			default:
				break;
			}
			Rectangle recorte(xx, yy, 100, 155);
			Rectangle contenedor(x, y, 50, 70);

			//GIRO DEL AUTO  
			
			// Guardar estado -- direccion 
			System::Drawing::Drawing2D::GraphicsState^ estado = graph->Graphics->Save();

			// Mover el origen l centro del sprite
			float cx = contenedor.Width / 2.0f;
			float cy = contenedor.Height / 2.0f;

			graph->Graphics->TranslateTransform(cx, cy);
			graph->Graphics->RotateTransform(angulo); // angulo de rotacion
			graph->Graphics->TranslateTransform(-cx, -cy);
			
			graph->Graphics->DrawImage(fig, contenedor, recorte, GraphicsUnit::Pixel);
			
			//Restaurar estado
			graph->Graphics->Restore(estado);
		}

	};

};

