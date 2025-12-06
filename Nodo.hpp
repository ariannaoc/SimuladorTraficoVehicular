#pragma once
#include <cstdlib>
using namespace System::Drawing;
namespace TraficoVehicular {

	public class Nodo {
	public:
		int x, dx, y, dy;

		Nodo(int xx, int yy) {
			x = xx;
			y = yy;
			dx = 0;
			dy = 0; // distancia recorrida en una unidad de tiempo  
		}

		void setVelocidad(int dx, int dy) {
			this->dx = dx;
			this->dy = dy; 
		}
		void tomarDecision() {
			// decidir velocidad 
			
			setVelocidad(0, rand()%6+3);
			// decidir direccion
		}

		void Mover() {
			x += dx;
			y -= dy; 
		}
		void Dibujar(BufferedGraphics^ graph, Bitmap^ fig) {
			Rectangle recorte(200, 0, 100, 155);
			Rectangle contenedor(x, y, 100, 150);
			graph->Graphics->DrawImage(fig, contenedor, recorte, GraphicsUnit::Pixel);
		}

	};

};

