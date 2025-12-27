#pragma once
#include "Auto.hpp"
#include <iostream>
namespace TraficoVehicular {
	struct Nodo
	{
		Auto* autoPtr;
		Nodo* next;

		Nodo(Auto* carro) {
			autoPtr = carro;
			next = NULL;
		}

	};
	class ListaAutos
	{
	private:
		Nodo* head;
	public:
		ListaAutos() {
			head = NULL;
		}
		void agregar(Nodo* n) {
			if (head == NULL)
				head = n;
			else {
				n->next = head;
				head = n;
			}

		}
		void eliminar() {

		}
		void agregarMotores() {
			Nodo* aux = head;
			while (aux != NULL) {

				//Asignar motor aleatoriamente usando probabilidad 
				if (rand() % 99 < 50)
					aux->autoPtr->setMotor(new Motor(1, 2, 3, 4, 5));
				else
					aux->autoPtr->setMotor(new Motor(1, 3, 5, 8, 12));

				aux = aux->next;
			}
		}
		// Gestion de los Autos
		void tomarDecision() {
			Nodo* aux = head;
			while (aux != NULL) {

				aux->autoPtr->tomarDecision();
				aux = aux->next;
			}
		}
		void mover() {
			Nodo* aux = head;
			while (aux != NULL) {

				aux->autoPtr->Mover();
				aux = aux->next;
			}
		}
		void dibujar(BufferedGraphics^ graph, Bitmap^ fig) {
			Nodo* aux = head;
			while (aux != NULL) {

				aux->autoPtr->Dibujar(graph, fig);
				aux = aux->next;
			}
		}

	};

}