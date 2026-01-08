#pragma once
#include <cstdlib>
#include <cmath>
#include "Motor.hpp"


using namespace System;
using namespace System::Drawing;

namespace TraficoVehicular {
	const int altoAuto = 30;
	const int anchoAuto = 20;

	class ListaAutos;

	public class Auto {
	public:
		int x, y;
		int velocidad;
		int tiempo;
		int marcha;
		int color;
		Motor* motor;
		int angulo;        // dirección en grados
		int anguloObjetivo;
		char direccion; // Norte, Sur, Este, Oeste .
		bool estado; // 0 estacionado, 1 andando 
		ListaAutos* autosCercanos;


		Auto(int xx, int yy) {
			x = xx;
			y = yy;
			velocidad = 0;
			tiempo = 0;
			marcha = 0;
			color = rand() % 6;
			angulo = -90;
			anguloObjetivo = 0;
			direccion = 'N';
			estado = 0;
			autosCercanos = nullptr;
			motor = nullptr;
		}

		void setMotor(Motor* m) { motor = m; }

		void setPosicion(int xx, int yy) {
			x = xx;
			y = yy;
		}

		Point getPosicion() { return Point(x, y); }

		String^ getInfoTexto() {
			String^ info = "Estado: " + estado ? "Estacionado" : "Andando" + "\r\n" +
				"Velocidad: " + velocidad + " km/h\r\n" +
				"Marcha: " + marcha + "\r\n" +
				"Direccion: " + direccion;
			return info;
		}
		// Campo visual del auto para detectar colisiones
		int getCampoVisualx();
		int getCampoVisualy();
		int getCampoVisualAncho();
		int getCampoVisualAlto();


		void girar(int giro);

		void tomarDecision();

		void Mover();

		void Dibujar(BufferedGraphics^ graph, Bitmap^ fig);

	};
}


