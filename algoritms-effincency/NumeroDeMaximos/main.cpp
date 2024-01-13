// Nombre del alumno ..... Steven Mallqui
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

struct Maximo {
  int numero = 0, cont = 0;
};

// función que resuelve el problema
Maximo resolver() {

  int aux;  cin >> aux;
  bool cambio = false;
  Maximo solucion;
  solucion.numero = aux;
 
  while(aux != 0){

    if(aux > solucion.numero){
      solucion.numero = aux;
      solucion.cont = 1;
    }else if (aux == solucion.numero){
      solucion.cont++;
    }
    
    cin >> aux;
  }
   return solucion; 
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

  // leer los datos de la entrada  
  Maximo sol = resolver();

  // escribir sol
  cout << sol.numero <<" " << sol.cont << '\n';
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
     system("PAUSE");
     #endif
    
    return 0;
}