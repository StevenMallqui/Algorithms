// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct sol{
  int longitud;
  int min;
};

// función que resuelve el problema
sol maxTramoIguales(const vector<int> &elementos, int i, int f) {
  if(f <= i){
    return {1, elementos[i]};
  }else{
    int m = (i+f)/2;
    sol iz = maxTramoIguales(elementos, i, m);
    sol der = maxTramoIguales(elementos, m+1, f);

    sol solucion;
    if(iz.min == der.min){
      solucion.longitud = iz.longitud + der.longitud;
      solucion.min = iz.min;
    }else if(iz.min < der.min)
      solucion = iz;
    else
      solucion = der;

    return solucion;
  }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int N; cin >> N;
  if (N == -1)
      return false;

  vector<int> elementos(N);
  for(int i = 0; i < N; i++)
    cin >> elementos[i];

  // escribir sol

  if(N == 0)
    cout << 0;
  else
    cout << maxTramoIguales(elementos, 0, N-1).longitud;

  cout << '\n';

  return true;  
}

int main() {
  // Para la entrada por fichero.
  // Comentar para acepta el reto
  #ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
    #endif 
  
  
  while (resuelveCaso())
      ;

  
  // Para restablecer entrada. Comentar para acepta el reto
    #ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
    #endif
  
  return 0;
}
