// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;


// función que resuelve el problema
int multiplicativo(int n, int &prod) {
  if(n < 10){
    prod = n;
    if(n == 1)
      return 1;
    else
      return 0;
  }else{
    int lastD = n%10;
    int m = multiplicativo(n/10, prod);
    if(prod%10 == lastD)
      m++;
    prod *= lastD;
    return m;
  }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
  // leer los datos de la entrada
  int n; cin >> n;
  
  // escribir sol
  int prod = 0;
  cout << multiplicativo(n, prod) << '\n';
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