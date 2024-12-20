// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;


// función que resuelve el problema
int recursivaFinal(int n, int maxDer, int result, int factor) {
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
    
    return recursivaFinal(n/10, maxDerecha, result, factor);
  }
}

int recursivaNoFinal(int n, int maxDer) {
  if(n < 10){
    if(n >= maxDer)
      return n;
    else
      return 0;
  }else{
    int lastD = n%10;
    int maxDerecha = max(maxDer, lastD);
    int d = recursivaNoFinal(n/10, maxDerecha);
    if(lastD >= maxDer)
      d = d * 10 + lastD;
    return d;
  }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
  // leer los datos de la entrada
  int n; cin >> n;
  
  // escribir sol
  cout << recursivaNoFinal(n, -1) << ' ' << recursivaFinal(n, -1, 0, 1) << '\n';
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