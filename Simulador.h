#pragma once
#include "ListaAutos.hpp"
#include <string>

namespace TraficoVehicular {
	ref class Simulador
	{
	private: 
		int tiempo; 
		int nivelTrafico; // 1: bajo, 2: medio, 3: alto
		// Lista de autos
		ListaAutos^ carros;
		// Semaforos
		//Pista *pista;
		
	public:
	
		String^ infoAutos;
		Simulador();
		void IniciarSimulacion(bool inicio, BufferedGraphics^ graph, Bitmap^ fig, int mX, int mY);
		void setNivelTrafico(int nivel);
		void Dibujar(BufferedGraphics^ graph, Bitmap^ fig);

	};
   
};
