#include "Simulador.h"

using namespace System::Drawing;
using namespace TraficoVehicular;

Simulador::Simulador() {
	nivelTrafico = 1;
	tiempo = 0;

	semaforos = gcnew Lista<Semaforo^>();

	Semaforo^ semNorte = gcnew Semaforo(335, 135, Direccion::Norte);
	semaforos->agregar(semNorte);
	semNorte->Cambiar();
	Semaforo^ semEste = gcnew Semaforo(550, 150, Direccion::Este);
	semaforos->agregar(semEste);
	semEste->Cambiar();
	Semaforo^ semSur = gcnew Semaforo(540, 360, Direccion::Sur);
	semaforos->agregar(semSur);
	semSur->Cambiar();
	Semaforo^ semOeste = gcnew Semaforo(325, 345, Direccion::Oeste);
	semaforos->agregar(semOeste);
	semOeste->Cambiar();


	carriles = gcnew Lista<Carril^>();
	Carril^ carrilNorte = gcnew Carril(Direccion::Norte, 375, 0, 600, anchoAuto + 20, semNorte);
	carriles->agregar(carrilNorte);
	Carril^ carrilSur = gcnew Carril(Direccion::Sur, 475, 0, 600, anchoAuto + 20, semSur);
	carriles->agregar(carrilSur);
	Carril^ carrilEste = gcnew Carril(Direccion::Este, 150, 200, anchoAuto + 20, 600, semEste);
	carriles->agregar(carrilEste);
	Carril^ carrilOeste = gcnew Carril(Direccion::Oeste, 150, 300, anchoAuto + 20, 600, semOeste);
	carriles->agregar(carrilOeste);

	carros = gcnew ListaAutos;

}

void Simulador::IniciarSimulacion(bool inicio, BufferedGraphics^ g, Bitmap^ autos, int mX, int mY, Bitmap^ semaforo) {
	tiempo++;
	this->Dibujar(g, autos, semaforo);

	if (inicio) {
		//Sincronozacion de semaforos

		Nodo<Semaforo^>^ nodoSem = semaforos->getHead();
		// Recorre la lista de semáforos
		while (nodoSem != nullptr) {
			Semaforo^ s = nodoSem->contenido;
			Direccion dir = s->getDireccion();

			if ((tiempo / s->getDuracionEstado()) % 2 == 0) {
				// Norte y Sur en Verde, los demás en Rojo
				if (dir == Direccion::Norte || dir == Direccion::Sur) s->setEstado(EstadoSemaforo::Verde);
				else s->setEstado(EstadoSemaforo::Rojo);
			}
			else {
				// Este y Oeste en Verde, los demás en Rojo
				if (dir == Direccion::Este || dir == Direccion::Oeste) s->setEstado(EstadoSemaforo::Verde);
				else s->setEstado(EstadoSemaforo::Rojo);
			}
			nodoSem = nodoSem->next;
		}

		//logica de movimiento de autos
		carros->tomarDecision();
		carros->mover();
		infoAutos = carros->getInfoAutos(mX, mY);


		int intervalo = 25; // nivelTrafico 1 por defecto
		if (nivelTrafico == 2) intervalo = 15;
		if (nivelTrafico == 3) intervalo = 5;


		Nodo<Carril^>^ nodoCarril = carriles->getHead();
		// Recorre la lista de carriles
		while (nodoCarril != nullptr) {

			if (tiempo % intervalo == 0) {
				int posicionX = nodoCarril->contenido->getXOrigen();
				int posicionY = nodoCarril->contenido->getYOrigen();

				//Generacion de autos nuevos
				if (!carros->autoAqui(posicionX, posicionY)) {
					Auto^ a = gcnew Auto(nodoCarril->contenido);

					// Asignar motor
					if (rand() % 100 < 50)
						a->setMotor(new Motor(2, 4, 6, 8, 10));
					else
						a->setMotor(new Motor(3, 5, 8, 10, 15));
					// Agregar auto nuevo a la lista
					carros->agregar(a);
				}
			}
			nodoCarril = nodoCarril->next;
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