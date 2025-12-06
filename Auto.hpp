#pragma once
#include <cstdlib>
using namespace System::Drawing;
namespace TraficoVehicular {

	public class Auto {
	public:
		int x, dx, y, dy, tiempo_marcha, color;

		Auto(int xx, int yy) {
			x = xx;
			y = yy;
			dx = 0;
			dy = 0; // distancia recorrida en una unidad de tiempo  
			tiempo_marcha = 0;
			color = rand() % 3; // 0: auto, 1: camioneta, 2: camión
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
				xx = 200;
				yy = 0;
				break;
			case 2: // rosa
				xx = 400;
				yy = 0;
				break;
			default:
				break;
			}
			Rectangle recorte(xx, yy, 100, 155);
			Rectangle contenedor(x, y, 50, 70);
			graph->Graphics->DrawImage(fig, contenedor, recorte, GraphicsUnit::Pixel);
		}

	};

};

