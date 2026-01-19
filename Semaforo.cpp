#include "Semaforo.h"
namespace TraficoVehicular {

	Semaforo::Semaforo(int xx, int yy) {
		x = xx + 200;
		y = yy;
		estadoActual = EstadoSemaforo::Verde;
		timer = 0;
		duracionEstado = 50;
		duracionAmarillo = 20;
	}

	void Semaforo::Cambiar() {
		timer++;
		if (timer >= duracionAmarillo && estadoActual == EstadoSemaforo::Amarillo) {
			estadoActual = EstadoSemaforo::Rojo;
			timer = 0;
		}
		if (timer >= duracionEstado) {
			if (estadoActual == EstadoSemaforo::Verde)
				estadoActual = EstadoSemaforo::Amarillo;

			else if (estadoActual == EstadoSemaforo::Rojo)
				estadoActual = EstadoSemaforo::Verde;

			timer = 0;
		}
	}

	void Semaforo::Dibujar(BufferedGraphics^ graph, Bitmap^ fig) {
		int xx = 0;

		switch (estadoActual) {
		case EstadoSemaforo::Verde:    xx = 0;       break;
		case EstadoSemaforo::Amarillo: xx = 120;     break;
		case EstadoSemaforo::Rojo:     xx = 120 * 2; break;
		}

		Rectangle recorte(xx, 0, 130, fig->Height);
		Rectangle contenedor(x, y, 25, 50);

		graph->Graphics->DrawImage(fig, contenedor, recorte, GraphicsUnit::Pixel);
	}

}