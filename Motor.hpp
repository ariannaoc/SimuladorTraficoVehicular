#pragma once
#include <cstdlib>
#include <cmath>
using namespace System::Drawing;

namespace TraficoVehicular {

	public class Motor {
	private:
		int marcha[6]; // Limites de marcha
		int velocidad; // Velocidad actual del motor
		int marchaActual; // Marcha actual del motor


	public:
		Motor(int v1, int v2, int v3, int v4, int v5) {
			marcha[0] = 0;
			marcha[1] = v1;
			marcha[2] = v2;
			marcha[3] = v3;
			marcha[4] = v4;
			marcha[5] = v5;
			velocidad = 0;
		}

		void acelerar(int ma) {
			marchaActual = ma;

			//cambiar la marcha 
			if (marchaActual == 0 && velocidad > 0)
			{
				velocidad--;
			}
			else if (marchaActual == 1 && velocidad < marcha[1]) {
				velocidad++;
			}
			else if (marchaActual == 2 && velocidad < marcha[2]) {
				velocidad++;
			}
			else if (marchaActual == 3 && velocidad < marcha[3]) {
				velocidad++;
			}
			else if (marchaActual == 4 && velocidad < marcha[4]) {
				velocidad++;
			}
			else if (marchaActual == 5 && velocidad < marcha[5]) {
				velocidad++;
			}
		}

		void frenar(int ma) {
			marchaActual = ma;
			if (marchaActual == 0 && velocidad > 0)
			{
				velocidad--;
			}
			else if (marchaActual == 1 && velocidad < marcha[1]) {
				velocidad--;
			}
			else if (marchaActual == 2 && velocidad < marcha[2]) {
				velocidad--;
			}
			else if (marchaActual == 3 && velocidad < marcha[3]) {
				velocidad--;
			}
			else if (marchaActual == 4 && velocidad < marcha[4]) {
				velocidad--;
			}
			else if (marchaActual == 5 && velocidad < marcha[5]) {
				velocidad--;
			}
		}

		int getVelocidad() {
			return velocidad;
		}


	};
}



