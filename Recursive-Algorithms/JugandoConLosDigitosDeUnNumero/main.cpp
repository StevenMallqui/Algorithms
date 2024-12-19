// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

bool esPar(int n){
  return n%2 == 0;
}

// función que resuelve el problema
int transformar(int n) {
  if(n < 10){
    if(esPar(n))
      return n+1;
    else
      return n-1;
  }else{
    int lastD = n%10;
    if(esPar(lastD))
      lastD++;
    else
      lastD--;
    return (transformar(n/10)*10) + lastD;
  }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

  // leer los datos de la entrada
  int n; cin >> n;

  // escribir sol
  cout << transformar(n) << '\n';
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