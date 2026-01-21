#pragma once
#include <cstdlib>
#include <cmath>
#include "Motor.hpp"
#include "Lista.hpp"
#include "Carril.hpp"



using namespace System;
using namespace System::Drawing;

namespace TraficoVehicular {

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
		Direccion direccion; 
		bool estado; // 0 estacionado, 1 andando 
		Lista<Auto^>^ autosCercanos;
		Carril^ carrilActual;

		Auto(Carril^ carril);
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
		Carril^ getCarril();
		bool estaAdelante(Auto^ otro);

		void girar(int giro);
		void tomarDecision();
		void Mover();
		void Dibujar(BufferedGraphics^ graph, Bitmap^ fig);
		bool isHover(int mouseX, int mouseY);
	};
}


