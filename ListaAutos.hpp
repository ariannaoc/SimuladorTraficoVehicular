#pragma once
#include "Auto.hpp"
#include <iostream>

namespace TraficoVehicular {
	
	ref class ListaAutos : public Lista<Auto^>
	{
	private:
		Auto^ autoHovered;
		int hoverTimer;

	public:
		ListaAutos() {
			autoHovered = nullptr;
			hoverTimer = 2000; 
		}

		void setHoverTimer(int ht) {
			if (ht >= 0) hoverTimer = ht;
		}

		void agregarMotores() {
			Nodo<Auto^>^ aux = head;
			while (aux != nullptr) {

				//Asignar motor aleatoriamente usando probabilidad 
				if (rand() % 99 < 50)
					aux->contenido->setMotor(new Motor(1, 2, 4, 6, 10));
				else
					aux->contenido->setMotor(new Motor(1, 3, 5, 8, 12));

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
			Nodo<Auto^>^ aux = head;
			while (aux != nullptr) {
				if (x < aux->contenido->x + anchoAuto &&
					x + anchoAuto > aux->contenido->x &&
					y < aux->contenido->y + altoAuto &&
					y + altoAuto > aux->contenido->y) {
					return true;
				}
				// Está en el campo de vision de otro auto
				if (visualizado(aux->contenido->x, aux->contenido->y,
					aux->contenido->getCampoVisualx(), aux->contenido->getCampoVisualy(),
					aux->contenido->getCampoVisualAncho(), aux->contenido->getCampoVisualAlto(),
					x, y)) {
					return true; 
				}
				aux = aux->next;
			}
			return false;
		}

		// Gestion de los Autos
		void tomarDecision() {
			Nodo<Auto^>^ aux = head;
			while (aux != nullptr) {
				// Limpiar lista
				if (aux->contenido->autosCercanos != nullptr) {
					aux->contenido->autosCercanos->limpiar();
				}
				else {
					aux->contenido->autosCercanos = gcnew Lista();
				}

				Nodo<Auto^>^ aux2 = head;
				while (aux2 != nullptr) {
					if (aux != aux2) {
						Auto^ otro = aux2->contenido;
						// Verificar si el otro auto esta en el campo visual del auto1

						if (visualizado(aux->contenido->x, aux->contenido->y,
							aux->contenido->getCampoVisualx(), aux->contenido->getCampoVisualy(),
							aux->contenido->getCampoVisualAncho(), aux->contenido->getCampoVisualAlto(),
							otro->x, otro->y))
						{
							// Agregar autos a la lista de autos cercanos
							aux->contenido->autosCercanos->agregar(otro);
						}
					}
					aux2 = aux2->next;
				}
				aux->contenido->tomarDecision();
				aux = aux->next;
			}
		}

		void mover() {
			Nodo<Auto^>^ aux = head;
			while (aux != nullptr) {
				aux->contenido->Mover();
				aux = aux->next;
			}
		}

		String^ getInfoAutos(int mX, int mY) {
			Nodo<Auto^>^ aux = head;
			while (aux != nullptr) {
				// Si hay un auto bajo el mouse, mostrar su informacion
				if (aux->contenido->isHover(mX, mY)) {
					System::Console::WriteLine(aux->contenido->getInfo());
					autoHovered = aux->contenido;
					return aux->contenido->getInfo();
				}
				aux = aux->next;
			}
			// Si no hay auto bajo el mouse, mostrar la informacion del ultimo auto hover
			if (autoHovered != nullptr) {
				if (hoverTimer > 0) {
					hoverTimer -= 100; 
					return autoHovered->getInfo();
				}
				else {
					// Se acabó el tiempo, limpia el puntero y resetea el timer
					autoHovered = nullptr;
					hoverTimer = 2000;
				}
			}
		}

	};

}