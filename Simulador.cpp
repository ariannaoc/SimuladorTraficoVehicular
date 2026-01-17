#include "Simulador.h"

using namespace System::Drawing;
using namespace TraficoVehicular;

Simulador::Simulador() {
	tiempo = 0;

	carriles = gcnew Lista<Carril^>();

	Carril^ carrilNorte = gcnew Carril(Direccion::Norte, 210, 0, 600);
	carriles->agregar(carrilNorte);

	carros = gcnew ListaAutos;
	// Crear 10 autos inicialmente 
	for (int i = 0; i < 10; i++) {
		if (!carros->autoAqui(carrilNorte->getXCentro(), 500)) {
			//carros->agregar(gcnew Auto (20 + i * 50 + 200, 500, rand() % 4));
			carros->agregar(gcnew Auto(carrilNorte->getXCentro(), 500, 0));
		}
	}

	carros->agregarMotores();
}
void Simulador::IniciarSimulacion(bool inicio, BufferedGraphics^ g, Bitmap^ f, int mX, int mY) {
	tiempo++;
	this->Dibujar(g, f);
	Carril^ carrilNorte = carriles->getPrimero();
	if (carrilNorte == nullptr) return;
	// Iniciar la simulación
	if (inicio) {
		carros->tomarDecision();
		carros->mover();

		infoAutos = carros->getInfoAutos(mX, mY);

		int intervalo = 25;
		if (nivelTrafico == 2) intervalo = 15;
		if (nivelTrafico == 3) intervalo = 5;

		int posicionX = carrilNorte->getXCentro();
		int posicionY = 600;
		if (!carros->autoAqui(posicionX, posicionY)) {

			if (tiempo % intervalo == 0) {
				Motor* m = new Motor(1, 2, 3, 4, 5);
				Auto^ a = gcnew Auto(posicionX, posicionY, 0);
				a->setMotor(m);
				carros->agregar(a);
			}
		}
	}
}

void Simulador::setNivelTrafico(int nivel) {
	this->nivelTrafico = nivel;
}
void Simulador::Dibujar(BufferedGraphics^ graph, Bitmap^ fig) {
	carriles->dibujar(graph, fig);
	carros->dibujar(graph, fig);
}