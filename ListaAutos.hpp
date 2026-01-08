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

		~Nodo() {
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

		//DESTRUCTOR
		~ListaAutos() {
			while (head != NULL) {
				Nodo* aux = head;    
				head = head->next;  
				delete aux;          
			}
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
		bool visualizado(int x, int y, int cvx, int cvy, int anchocv, int altocv, int ax, int ay) {
			// Dentro de limites horizontales
			if (ax >= cvx && ax <= cvx + anchocv) {
				// Dentro de limites verticales
				if (ay >= cvy && ay <= cvy + altocv) {
					return true;
				}
			}
			
			return false;
		}

		// Gestion de los Autos
		void tomarDecision() {
			Nodo* aux = head;
			while (aux != NULL) {
				Nodo* aux2 = head;
				while (aux2 != NULL)
				{
					// Limpiar lista de autos cercanos
					if (aux->autoPtr->autosCercanos != nullptr) {
						delete aux->autoPtr->autosCercanos;
					}
					// Crear lista de autos cercanos
					aux->autoPtr->autosCercanos = new ListaAutos();
					
					// Pasar lista de autos cercanos
					if (visualizado(aux->autoPtr->x, aux->autoPtr->y, aux->autoPtr->getCampoVisualx(), aux->autoPtr->getCampoVisualy(), aux->autoPtr->getCampoVisualAncho(), aux->autoPtr->getCampoVisualAlto(), aux2->autoPtr->x, aux2->autoPtr->y))
						aux->autoPtr->autosCercanos->agregar(new Nodo(aux2->autoPtr));
					aux2 = aux2->next;
				}
				aux->autoPtr->tomarDecision();
				aux = aux->next;
			}
		}

		bool tieneAutos() {
			return head != nullptr;
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