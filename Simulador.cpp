#include "Simulador.h"

using namespace System::Drawing;
using namespace TraficoVehicular;

Simulador::Simulador() {
	tiempo = 0;
	carros = new ListaAutos;
	// Crear 10 autos inicialmente 
	for (int i = 0; i < 10; i++)
		carros->agregar(new Nodo(new Auto(20 + i * 50 +200, 500)));

	carros->agregarMotores();
}
void Simulador::IniciarSimulacion(bool inicio, BufferedGraphics^ g, Bitmap^ f) {
	tiempo++;
	this->Dibujar(g, f);
	// Iniciar la simulación
	if (inicio) {
		carros->tomarDecision();
		carros->mover();

		int intervalo = 25;
		if (nivelTrafico == 2) intervalo = 15;
		if (nivelTrafico == 3) intervalo = 5;

		if (tiempo % intervalo == 0) {
			Motor* m = new Motor(1, 2, 3, 4, 5);
			Auto* a = new Auto(rand() % 500 +200, 500);
			a->setMotor(m);
			carros->agregar(new Nodo(a));
		}
	}
}

void Simulador::setNivelTrafico(int nivel) {
	this->nivelTrafico = nivel;
}
void Simulador::Dibujar(BufferedGraphics^ graph, Bitmap^ fig) {
	carros->dibujar(graph, fig);
}