// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;


// función que resuelve el problema

string def2binF(int n, string acc) {
  if(n == 1)return '1' + acc;
  else if(n == 0) return '0' + acc;
  else return def2binF(n/2, to_string(n%2) + acc);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
  // leer los datos de la entrada
  
  int n; cin >> n;
  cout << def2binF(n, "") <<'\n';
  // escribir sol

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     #endif
    
    return 0;
}