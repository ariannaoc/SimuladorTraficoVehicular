#pragma once
#include <cstdlib>
#include <cmath>
#include "Motor.hpp"
#include "Lista.hpp"


using namespace System;
using namespace System::Drawing;

namespace TraficoVehicular {
	const int altoAuto = 30;
	const int anchoAuto = 20;


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
		Lista* autosCercanos;

		Auto(int xx, int yy);
		~Auto();

		void setMotor(Motor* m);
		void setPosicion(int xx, int yy);
		Point getPosicion();
		String^ getInfoTexto();
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


