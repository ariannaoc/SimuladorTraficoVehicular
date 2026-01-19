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
					aux->contenido->setMotor(new Motor(2, 4, 6, 8, 10));
				else
					aux->contenido->setMotor(new Motor(3, 5, 8, 10, 12));

				aux = aux->next;
			}
		}
		// Verifica si un auto esta dentro del campo visual de otro auto
		bool rectsChocan(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2) {
			return !(x1 + w1 < x2 || x1 > x2 + w2 || y1 + h1 < y2 || y1 > y2 + h2);
		}

		bool visualizado(int cvx, int cvy, int anchocv, int altocv, Auto^ otro) {
			// Compara el Campo Visual recibido con el cuerpo del auto 'otro'
			return rectsChocan(cvx, cvy, anchocv, altocv, otro->x, otro->y, anchoAuto, altoAuto);
		}


		//  Verifica si hay un auto en ese espacio 

		bool autoAqui(int x, int y) {
			Nodo<Auto^>^ aux = head;
			while (aux != nullptr) {
				if (rectsChocan(x, y, anchoAuto, altoAuto, aux->contenido->x, aux->contenido->y, anchoAuto, altoAuto)) {
					return true;
				}

				if (rectsChocan(x, y, anchoAuto, altoAuto,
					aux->contenido->getCampoVisualx(), aux->contenido->getCampoVisualy(),
					aux->contenido->getCampoVisualAncho(), aux->contenido->getCampoVisualAlto())) {
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

						if (visualizado(
							aux->contenido->getCampoVisualx(),
							aux->contenido->getCampoVisualy(),
							aux->contenido->getCampoVisualAncho(),
							aux->contenido->getCampoVisualAlto(),
							otro))
							
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