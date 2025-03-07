// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema
int minimoElemento(const vector<int> &elementos, const int i, const int f) {
  if(i == f){
    return elementos[i];
  }else{
    int m = (i + f)/2;
    int iz = minimoElemento(elementos, i, m);
    int der = minimoElemento(elementos, m+1, f);

    return min(iz, der);
  }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int n; cin >> n;
  if (! std::cin)
      return false;
  
  vector<int> elementos(n);
  for(int i = 0; i < n; i++)
    cin >> elementos[i];
  
  // escribir sol
  cout << minimoElemento(elementos, 0, n-1) << '\n';
  
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