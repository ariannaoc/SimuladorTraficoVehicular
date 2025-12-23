#include "Simulador.h"

using namespace System::Drawing;
using namespace TraficoVehicular;

Simulador::Simulador() {
	carros = new ListaAutos;
	// Crear 10 autos inicialmente 
	for (int i = 0; i < 10; i++)
		carros->agregar(new Nodo(new Auto(20 + i * 50, 500)));

	carros->agregarMotores();
}
void Simulador::IniciarSimulacion(bool inicio, BufferedGraphics^ g, Bitmap^ f) {
	this->Dibujar(g, f);
	// Iniciar la simulación
	if (inicio) {
		carros->tomarDecision();
		carros->mover();
	}
}

void Simulador::Dibujar(BufferedGraphics^ graph, Bitmap^ fig) {
	carros->dibujar(graph, fig);
}