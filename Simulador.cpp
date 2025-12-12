#include "Simulador.h"

using namespace System::Drawing;
using namespace TraficoVehicular;

Simulador::Simulador() {
	for(int i = 0; i < 10; i++) {
		autos[i] = new Auto(20 + i * 50, 500);
	}
}
void Simulador::IniciarSimulacion(bool inicio, BufferedGraphics^ g, Bitmap^ f) {
	this->Dibujar(g, f);
	// Iniciar la simulación
	if (inicio)
	{
		for(int i = 0; i < 10; i++) {
			autos[i]->tomarDecision();
			autos[i]->Mover();
		}
	}
}

void Simulador::Dibujar(BufferedGraphics^ graph, Bitmap^ fig) {
	for (int i = 0; i < 10; i++)
	{
		autos[i]->Dibujar(graph, fig);
	}
}