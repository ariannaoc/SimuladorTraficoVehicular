#pragma once
#include "ListaAutos.hpp"

namespace TraficoVehicular {
	class Simulador
	{
		int tiempo; 
		int nivelTrafico; // 1: bajo, 2: medio, 3: alto
		// Lista de autos
		ListaAutos* carros;
		// Semaforos
		//Pista *pista;
		
	public:
		Simulador();
		void IniciarSimulacion(bool inicio, BufferedGraphics^ graph, Bitmap^ fig);
		void setNivelTrafico(int nivel);
		void Dibujar(BufferedGraphics^ graph, Bitmap^ fig);

	};
   
};
