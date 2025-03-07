// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;


// función que resuelve el problema
int cifrado(int n, bool &pos, int &maxIz, int minDer) {
   if(n < 10){
    maxIz = max(maxIz, n);
    return n * 3 + minDer;
  }else{
    int lastD = n%10;
    int minDerecha = min(minDer, lastD);
    pos = !pos;
    int c = cifrado(n/10, pos, maxIz, minDerecha);
    pos = !pos;
    if(pos)
      c += lastD * 2 + maxIz;
    else
      c += lastD * 3 + minDer;

    maxIz = max(maxIz, lastD);
    return c;
  }  
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
  // leer los datos de la entrada
  int n; cin >> n;

  // escribir sol
  int maxIz = -1;
  bool pos = true;
  cout << cifrado(n, pos, maxIz, n%10) << '\n';
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