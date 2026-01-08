#pragma once
namespace TraficoVehicular {

	class Auto;

	struct Nodo {
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

	class Lista
	{
	protected:
		Nodo* head;
	public:
		Lista() {
			head = NULL;
		}

		~Lista() {
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
		void limpiar() {
			while (head != nullptr) {
				Nodo* aux = head;
				head = head->next;
				delete aux;
			}
		}

		bool tieneElementos() {
			return head != nullptr;
		}

	};

}