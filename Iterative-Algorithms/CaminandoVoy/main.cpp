// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema
bool resolver(const vector<int> &datos, const int &D, const int &N) {
  bool apto = true;
  int curD = 0;
  for(int i = 1; i < N && apto; i++){
    if(datos[i-1] < datos[i])
      curD += datos[i] - datos[i-1];
    else
      curD = 0;

    if(curD > D)
      apto = false;
  }
    
  return apto;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int D; cin >> D;
  if (! std::cin)
      return false;
  
  int N; cin >> N;
  vector<int> heights(N);
  for(int i = 0; i < N; i++){
    cin >> heights[i];
  }

  // escribir sol
  if(resolver(heights, D, N))
    cout << "APTA\n";
  else 
    cout << "NO APTA\n";

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