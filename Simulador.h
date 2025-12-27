#pragma once
#include "ListaAutos.hpp"

namespace TraficoVehicular {
	class Simulador
	{
		int tiempo; 
		// Lista de autos
		ListaAutos* carros;
		// Semaforos
		//Pista *pista;
		
	public:
		Simulador();
		void IniciarSimulacion(bool inicio, BufferedGraphics^ graph, Bitmap^ fig);
		void Dibujar(BufferedGraphics^ graph, Bitmap^ fig);

	};
   
};
