#pragma once

using namespace System;
using namespace System::Drawing;

namespace TraficoVehicular {
		public enum EstadoSemaforo { Verde = 0, Amarillo = 1, Rojo = 2 };

		public enum Direccion { Norte = 0, Sur = 1, Este = 2, Oeste = 3 };

	ref class Semaforo {
	private:
		int timer;
		int duracionEstado;
		int duracionAmarillo;
	public:
		int x, y; // Posición del semáforo
		EstadoSemaforo estadoActual;
		Direccion sentido;

		Semaforo(int xx, int yy, Direccion s);
		Point getPosicion(); 
		Direccion getDireccion();
		int getDuracionEstado();
		void Cambiar();
		void setEstado(EstadoSemaforo e);
		void Dibujar(BufferedGraphics^ graph, Bitmap^ semaforo);

	};
}