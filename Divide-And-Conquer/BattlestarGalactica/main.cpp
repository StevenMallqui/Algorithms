// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int resolver(vector<int>& v, int ini, int fin) {
	if (ini >= fin) return 0;
	else {
		int m = (ini + fin) / 2;

		int izq = resolver(v, ini, m); // O (log n)
		int der = resolver(v, m + 1, fin); // O (log n)

		int i = ini, j = m + 1, cont = 0;

		while (i <= m && j <= fin) {

			if (v[i] > v[j]) {
				cont += (m - i + 1);
				++j;
			}
			else ++i;
		}

		sort(v.begin() + ini, v.begin() + fin + 1); // O(n log(n))
		return izq + der + cont;
	}
}

bool resuelveCaso() {
	// leer los datos de la entrada
	int num;
	cin >> num;
	if (!cin)	
		return false;

	vector<int> v(num);

	for (int i = 0; i < v.size(); i++) {
		cin >> v[i];
	}

	auto sol = resolver(v, 0, num - 1);

	// escribir sol
	cout << sol << endl;
	return true;
}


int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	//save old buf and redirect std::cin to datos.txt:
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

	while (resuelveCaso());

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
#endif

	return 0;
}