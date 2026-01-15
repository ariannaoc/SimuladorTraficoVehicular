#pragma once

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
		Direccion sentido;

	public:
		Carril(Direccion sentido, int xx, int yy) {
			sentido = sentido;
			x = xx;
			y = yy;
			ancho = anchoAuto + 20;
		}

		int getX() { return x; }
		int getY() { return y; }
		int getAncho() { return ancho; }
		Direccion getSentido() { return sentido; }

		int getXCentro() { 
			return x + (ancho - anchoAuto) / 2; // centro del carril
		}
	};
	
}