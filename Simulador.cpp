#include "Simulador.h"

using namespace System::Drawing;
using namespace TraficoVehicular;

Simulador::Simulador() {
	tiempo = 0;

	semaforos = gcnew Lista<Semaforo^>();
	Semaforo^ semNorte = gcnew Semaforo(260, 50);
	semaforos->agregar(semNorte);
	semNorte->Cambiar();

	carriles = gcnew Lista<Carril^>();
	Carril^ carrilNorte = gcnew Carril(Direccion::Norte, 210, 0, 600, semNorte);
	carriles->agregar(carrilNorte);
	

	carros = gcnew ListaAutos;
	// Crear 10 autos inicialmente 
	for (int i = 0; i < 10; i++) {
		if (!carros->autoAqui(carrilNorte->getXCentro(), 500)) {

			Auto^ nuevoAuto = gcnew Auto(carrilNorte->getXCentro(), 500, 0);
			nuevoAuto->setCarril(carrilNorte);
			carros->agregar(nuevoAuto);

			//carros->agregar(gcnew Auto (carrilNorte->getXCentro() + 200, 500, 0));
		}
	}

	carros->agregarMotores();
}
void Simulador::IniciarSimulacion(bool inicio, BufferedGraphics^ g, Bitmap^ autos, int mX, int mY, Bitmap^ semaforo) {
	tiempo++;
	this->Dibujar(g, autos, semaforo);
	Semaforo^ auxSem = semaforos->getPrimero();
	Carril^ carril = carriles->getPrimero();
	if (carril == nullptr) return;
	// Iniciar la simulación
	if (inicio) {
		auxSem->Cambiar();
		carros->tomarDecision();
		carros->mover();

		infoAutos = carros->getInfoAutos(mX, mY);

		int intervalo = 25;
		if (nivelTrafico == 2) intervalo = 15;
		if (nivelTrafico == 3) intervalo = 5;

		int posicionX = carril->getXCentro();
		int posicionY = 600;
		if (!carros->autoAqui(posicionX, posicionY)) {

			if (tiempo % intervalo == 0) {
				Motor* m = new Motor(1, 2, 3, 4, 5);
				Auto^ a = gcnew Auto(posicionX, posicionY, 0);
				a->setMotor(m);
				a->setCarril(carril); 
				carros->agregar(a);
			}
		}
	}
}

void Simulador::setNivelTrafico(int nivel) {
	this->nivelTrafico = nivel;
}
void Simulador::Dibujar(BufferedGraphics^ graph, Bitmap^ autos, Bitmap^ semaforo) {
	semaforos->dibujar(graph, semaforo);
	carriles->dibujar(graph, autos);
	carros->dibujar(graph, autos);
}