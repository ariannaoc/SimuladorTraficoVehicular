#pragma once
#include "Auto.hpp"

namespace TraficoVehicular {
	class Simulador
	{
		
		Auto* autos[10];
		// Lista de autos
		// Semaforos
		//Pista *pista;
	public:
		Simulador();
		void IniciarSimulacion(bool inicio, BufferedGraphics^ graph, Bitmap^ fig);
		void Dibujar(BufferedGraphics^ graph, Bitmap^ fig);

	};

};
