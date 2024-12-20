// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;


// función que resuelve el problema
int decrecientes(int n, int maxDer, int result, int factor) {
  if(n < 10){
    if(n >= maxDer)
      return n * factor + result;
    else
      return result;
  }else{
    int lastD = n%10;
    int maxDerecha = max(maxDer, lastD);
    if(lastD >= maxDer){
      result = lastD * factor + result;
      factor *= 10;
    }
    
    return decrecientes(n/10, maxDerecha, result, factor);
  }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
  // leer los datos de la entrada
  int n; cin >> n;
  
  // escribir sol
  cout << decrecientes(n, -1, 0, 1) << '\n';
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