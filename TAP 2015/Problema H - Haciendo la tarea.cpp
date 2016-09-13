#include <iostream>   // includes cin to read from stdin and cout to write to stdout
#include <fstream>
#include <string>
#include <vector>
#include <algorithm> // Para usar "sort" (C++ 11)
#include <math.h> // Para usar pow
#include <iterator>

using namespace std;  // since cin and cout are both in namespace std, this saves some text


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

	while (n - nuevoNumero > 0) {
		nuevoNumero = descomponerYComponer(n);
		int resultadoResta = n - nuevoNumero;
		n = resultadoResta;
		cantRestas++;
	} 
	
	return cantRestas;

}

// Funciones auxiliares:

int descomponerYComponer(int n) {
	vector<int> digitos;
	
	while (n / 10 >= 1) {
		digitos.push_back(n%10);
		n = n / 10;		
	}
	
	sort(digitos.begin(), digitos.end());

	display_vector(digitos);

	//cout << "termine primer while";
	int nuevoN;
	int i = digitos.size() - 1;
	int exponente = 0;

	while (i >= 0) {
		nuevoN = digitos[i] * pow(10, exponente);
		i--;
		exponente++;
	}
	//cout << "termine segudno while";
	return nuevoN;

}


void display_vector(const vector<int> &v) {
    std::copy(v.begin(), v.end(),
        std::ostream_iterator<int>(std::cout, " "));
}



// Para correrlo: g++ -g -O2 -std=gnu++11 Problema\ H\ -\ Haciendo\ la\ tarea.cpp -o proble& ./problema

int main() {
        int n;
        cin >> n;  // Pasarle el int por la terminal
        cout << problema(n) << endl;
  
        return 0;
}
