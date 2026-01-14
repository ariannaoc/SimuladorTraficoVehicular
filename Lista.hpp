#pragma once
namespace TraficoVehicular {

	ref class Auto;

	ref struct Nodo {
		Auto^ autoPtr;
		Nodo^ next;
		Nodo(Auto^ carro) {
			autoPtr = carro;
			next = nullptr;
		}

		~Nodo() {
			next = nullptr;
		}
	};

	ref class Lista
	{
	protected:
		Nodo^ head;
	public:
		Lista() {
			head = nullptr;
		}

		~Lista() {
			limpiar();
		}

		void agregar(Nodo^ n) {
			if (head == nullptr)
				head = n;
			else {
				n->next = head;
				head = n;
			}

		}
		void limpiar() {
			while (head != nullptr) {
				Nodo^ aux = head;
				head = head->next;
				delete aux;
			}
		}

		bool tieneElementos() {
			return head != nullptr;
		}

	};

}