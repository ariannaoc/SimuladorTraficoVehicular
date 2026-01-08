#pragma once
#include "Auto.hpp"
#include <iostream>

namespace TraficoVehicular {
	
	class ListaAutos : public Lista
	{
	
	public:
		ListaAutos() : Lista() {}
		
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
				// Limpiar lista
				if (aux->autoPtr->autosCercanos != nullptr) {
					aux->autoPtr->autosCercanos->limpiar();
				}
				else {
					aux->autoPtr->autosCercanos = new Lista();
				}

				Nodo* aux2 = head;
				while (aux2 != NULL) {
					if (aux != aux2) {
						if (visualizado(aux->autoPtr->x, aux->autoPtr->y,
							aux->autoPtr->getCampoVisualx(), aux->autoPtr->getCampoVisualy(),
							aux->autoPtr->getCampoVisualAncho(), aux->autoPtr->getCampoVisualAlto(),
							aux2->autoPtr->x, aux2->autoPtr->y))
						{
							// Agregar autos a la lista de autos cercanos
							aux->autoPtr->autosCercanos->agregar(new Nodo(aux2->autoPtr));
						}
					}
					aux2 = aux2->next;
				}
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