#pragma once
#include "Auto.hpp"
#include <iostream>

namespace TraficoVehicular {
	
	ref class ListaAutos : public Lista
	{
	
	public:
		ListaAutos() : Lista() {}
		
		void agregarMotores() {
			Nodo^ aux = head;
			while (aux != nullptr) {

				//Asignar motor aleatoriamente usando probabilidad 
				if (rand() % 99 < 50)
					aux->autoPtr->setMotor(new Motor(1, 2, 3, 4, 5));
				else
					aux->autoPtr->setMotor(new Motor(1, 3, 5, 8, 12));

				aux = aux->next;
			}
		}
		// Verifica si un auto esta dentro del campo visual de otro auto
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
		//  Verifica si hay un auto en ese espacio 
		bool autoAqui(int x, int y) {
			Nodo^ aux = head;
			while (aux != nullptr) {
				if (x < aux->autoPtr->x + anchoAuto &&
					x + anchoAuto > aux->autoPtr->x &&
					y < aux->autoPtr->y + altoAuto &&
					y + altoAuto > aux->autoPtr->y) {
					return true;
				}
				// Está en el campo de vision de otro auto
				if (visualizado(aux->autoPtr->x, aux->autoPtr->y,
					aux->autoPtr->getCampoVisualx(), aux->autoPtr->getCampoVisualy(),
					aux->autoPtr->getCampoVisualAncho(), aux->autoPtr->getCampoVisualAlto(),
					x, y)) {
					return true; 
				}
				aux = aux->next;
			}
			return false;
		}

		// Gestion de los Autos
		void tomarDecision() {
			Nodo^ aux = head;
			while (aux != nullptr) {
				// Limpiar lista
				if (aux->autoPtr->autosCercanos != nullptr) {
					aux->autoPtr->autosCercanos->limpiar();
				}
				else {
					aux->autoPtr->autosCercanos = gcnew Lista();
				}

				Nodo^ aux2 = head;
				while (aux2 != nullptr) {
					if (aux != aux2) {
						if (visualizado(aux->autoPtr->x, aux->autoPtr->y,
							aux->autoPtr->getCampoVisualx(), aux->autoPtr->getCampoVisualy(),
							aux->autoPtr->getCampoVisualAncho(), aux->autoPtr->getCampoVisualAlto(),
							aux2->autoPtr->x, aux2->autoPtr->y))
						{
							// Agregar autos a la lista de autos cercanos
							aux->autoPtr->autosCercanos->agregar(gcnew Nodo(aux2->autoPtr));
						}
					}
					aux2 = aux2->next;
				}
				aux->autoPtr->tomarDecision();
				aux = aux->next;
			}
		}

		void mover() {
			Nodo^ aux = head;
			while (aux != nullptr) {
				aux->autoPtr->Mover();
				aux = aux->next;
			}
		}
		void dibujar(BufferedGraphics^ graph, Bitmap^ fig) {
			Nodo^ aux = head;
			while (aux != nullptr) {

				aux->autoPtr->Dibujar(graph, fig);
				aux = aux->next;
			}
		}

		String^ getInfoAutos(int mX, int mY) {
			Nodo^ aux = head;
			while (aux != nullptr) {
				if (aux->autoPtr->isHover(mX, mY)) {
					System::Console::WriteLine(aux->autoPtr->getInfo());
					return aux->autoPtr->getInfo();
				}
				aux = aux->next;
			}
		}

	};

}