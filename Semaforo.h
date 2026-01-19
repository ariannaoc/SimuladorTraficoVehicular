#pragma once

using namespace System;
using namespace System::Drawing;

namespace TraficoVehicular {
		public enum EstadoSemaforo { Verde = 0, Amarillo = 1, Rojo = 2 };

	ref class Semaforo {
	private:
		int timer;
		int duracionEstado;
		int duracionAmarillo;
	public:
		int x, y; // Posición del semáforo
		EstadoSemaforo estadoActual;

		Semaforo(int xx, int yy);
		void Dibujar(BufferedGraphics^ graph, Bitmap^ semaforo);
		void Cambiar();
		Point getPosicion(); 
	};
}