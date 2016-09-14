#include <iostream>   // includes cin to read from stdin and cout to write to stdout
#include <fstream>   // Para leer o escribir en archivo (acá no se usa)
#include <string>
#include <vector>
#include <algorithm> // Para usar "sort" en un vector y ser felices (C++ 11)
#include <math.h> // Para elevar un número (pow)
#include <iterator> // La función que muestra un vector por pantalla usa un iterador

using namespace std;  // since cin and cout are both in namespace std, this saves some text

// Defino las funciones acá para que el compilador no se queje (no da hacer un .h):
int descomponerYComponer(int);
int problema(int);
void display_vector(const vector<int> &v);
 

int problema(int n) {
/* Idea: Agarro el número, lo descompongo en sus cifras (operando módulo 10) y las meto en un vector, 
         ordeno el vector, compongo el nuevo número
         resto el número original con el nuevo número
         Si la resta no da cero, aumento en 1 el contador y repito el proceso.
*/	
	int nuevoNumero = 0;
	int cantRestas = 0;
        int resultadoResta = n;

	while (resultadoResta != 0) {
		nuevoNumero = descomponerYComponer(n);
	        resultadoResta = n - nuevoNumero;
		n = resultadoResta;
		cantRestas++;
	} 
	
	return cantRestas;
}


// Funciones auxiliares:

int descomponerYComponer(int n) {
	vector<int> digitos;
	
	while (n > 0) {
                int digito = n % 10;
		digitos.push_back(digito);
		n = (int) n / 10;		
	}
	
	sort(digitos.begin(), digitos.end());

        display_vector(digitos); // Testin'

	//cout << "termine primer while";
	int nuevoN = 0;
	int i = digitos.size() - 1;
	int exponente = 0;

	while (i >= 0) {
		nuevoN += digitos[i] * pow(10, exponente);
		i--;
		exponente++;
	}
	//cout << "termine segudno while";
	return nuevoN;

}


void display_vector(const vector<int> &v) {
        cout << "< ";
        std::copy(v.begin(), v.end(),
            std::ostream_iterator<int>(std::cout, " "));
        cout << ">" << endl;
}



// Para correrlo: g++ -g -O2 -std=gnu++11 problema-h.cpp -o problema ./problema

int main() {
        int n;
        cin >> n;  // Pasarle el int por la terminal
        cout << problema(n) << endl;
//      cout << descomponerYComponer(n) << endl; // Testin' 
        return 0;
}
