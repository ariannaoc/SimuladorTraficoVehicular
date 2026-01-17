#pragma once
using namespace System::Drawing;

namespace TraficoVehicular {

	ref class Auto;

	template <class T>
	ref struct Nodo {
		T contenido;
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

		D getPrimero() {
			if (head != nullptr) return head->contenido;
			return nullptr;
		}

		void dibujar(BufferedGraphics^ graph, Bitmap^ fig) {
			Nodo<D>^ aux = head;
			while (aux != nullptr) {
				aux->contenido->Dibujar(graph, fig);
				aux = aux->next;
			}
		}

	};

}