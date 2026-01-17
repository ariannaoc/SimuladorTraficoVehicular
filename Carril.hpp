#pragma once
#include "Semaforo.h"
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;
namespace TraficoVehicular {
	const int altoAuto = 30;
	const int anchoAuto = 20;

	enum Direccion {
		Norte = 0,
		Sur = 1,
		Este = 2,
		Oeste = 3
	};


	ref class Carril {
	private:
		int x, y; // Posición del carril
		int ancho; // Ancho del carril
		int alto; // Largo del carril
		Direccion sentido;
		Semaforo^ semaforo; // Semáforo asociado al carril 

	public:
		Carril(Direccion sentido, int xx, int yy, int alt, Semaforo^ sem) {
			sentido = sentido;
			x = xx +200;
			y = yy;
			ancho = anchoAuto + 20;
			alto = alt;
			semaforo = sem;

		}

		int getX() { return x; }
		int getY() { return y; }
		int getAncho() { return ancho; }
		int getLargo() { return alto; }
		Direccion getSentido() { return sentido; }

		int getXCentro() {
			return x + (ancho - anchoAuto) / 2; // centro del carril
		}

		// Dibuja el carril como un rectángulo
		void Dibujar(BufferedGraphics^ graph, Bitmap^ fig) {
			Graphics^ g = graph->Graphics;

			// fondo del carril
			Brush^ fondo = gcnew SolidBrush(Color::FromArgb(200, Color::LightGray));
			Rectangle rect = Rectangle(x, y, ancho, alto);
			g->FillRectangle(fondo, rect);

			// borde
			Pen^ borde = gcnew Pen(Color::White, 2);
			g->DrawRectangle(borde, rect);

		}
	};

}