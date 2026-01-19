#pragma once
#include "ListaAutos.hpp"
#include <string>

namespace TraficoVehicular {
	ref class Simulador
	{
	private: 
		int tiempo; 
		int nivelTrafico; // 1: bajo, 2: medio, 3: alto
		ListaAutos^ carros;
		Lista<Carril^>^ carriles;
		Lista<Semaforo^>^ semaforos;

		
		
	public:
	
		String^ infoAutos;
		Simulador();
		void IniciarSimulacion(bool inicio, BufferedGraphics^ graph, Bitmap^ autos, int mX, int mY, Bitmap^ semaforo);
		void setNivelTrafico(int nivel);
		void Dibujar(BufferedGraphics^ graph, Bitmap^ autos, Bitmap^ semaforo);

	};
   
};
