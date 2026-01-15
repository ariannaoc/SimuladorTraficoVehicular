#pragma once
namespace TraficoVehicular {

	ref class Auto;

	template <class T>
	ref struct Nodo {
		T contenido;
		//Auto^ autoPtr;
		Nodo<T>^ next;

		Nodo(T n) {
			contenido = n;
			next = nullptr;
		}

		~Nodo() {
			next = nullptr;
		}
	};

	template <class D>
	ref class Lista
	{
	protected:
		Nodo<D>^ head;
	public:
		Lista() {
			head = nullptr;
		}


		void agregar(D n) {
			Nodo<D>^ nuevo = gcnew Nodo<D>(n);
			nuevo->next = head;
			head = nuevo;
		}
		
		void limpiar() {
			while (head != nullptr) {
				Nodo<D>^ aux = head;
				head = head->next;
				delete aux;
			}
		}

		bool tieneElementos() {
			return head != nullptr;
		}

	};

}