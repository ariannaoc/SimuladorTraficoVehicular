#include "Simulador.h"

using namespace System::Drawing;
using namespace TraficoVehicular;

Simulador::Simulador() {
	auto1 = new Auto(50, 500);
	auto2 = new Auto(150, 500);
}
void Simulador::IniciarSimulacion(bool inicio, BufferedGraphics^ g, Bitmap^ f) {
	this->Dibujar(g, f);
	// Iniciar la simulación
	if (inicio)
	{
		auto1->tomarDecision();
		auto1->Mover();
		auto2->tomarDecision();
		auto2->Mover();

	}
}

void Simulador::Dibujar(BufferedGraphics^ graph, Bitmap^ fig) {
	auto1->Dibujar(graph, fig);
	auto2->Dibujar(graph, fig);
}