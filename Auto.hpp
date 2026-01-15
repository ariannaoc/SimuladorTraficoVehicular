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


	public ref class Auto {
	public:
		int x, y;
		int velocidad;
		int tiempo;
		int marcha;
		int color;
		Motor* motor;
		int angulo;        // dirección en grados
		int anguloObjetivo;
		int direccion; // 0 Norte, 1 Sur, 2 Este, 3 Oeste .
		bool estado; // 0 estacionado, 1 andando 
		Lista^ autosCercanos;

		Auto(int xx, int yy, int dir);
		~Auto();

		void setMotor(Motor* m);
		void setPosicion(int xx, int yy);
		Point getPosicion();
		String^ getInfo();
		// Campo visual del auto para detectar colisiones
		int getCampoVisualx();
		int getCampoVisualy();
		int getCampoVisualAncho();
		int getCampoVisualAlto();

		void girar(int giro);
		void tomarDecision();
		void Mover();
		void Dibujar(BufferedGraphics^ graph, Bitmap^ fig);
		bool isHover(int mouseX, int mouseY);
	};
}


