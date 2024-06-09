// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema

void combinatorio(int a, int b, vector<vector<int>>& combs){
  if(b == 0 || a == b){
    combs[a][b] = 1;
  }else if(b == 1){
    combs[a][b] = a;
  }else{
    if (combs[a - 1][b - 1] == -1)
      combinatorio(a - 1, b - 1, combs);
    if (combs[a - 1][b] == -1)
      combinatorio(a - 1, b, combs);
    combs[a][b] = combs[a-1][b-1] + combs[a-1][b];
  }
}


void resolver(int a, int b) {
  vector<vector<int>> combs(a + 1, vector<int>(b + 1, -1));
  combinatorio(a, b, combs);
  cout << combs[a][b] <<'\n';
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int a; cin >> a;
  if (! std::cin)
      return false;
  
  int b; cin >> b;
  
  resolver(a, b);

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
     #endif
    
    return 0;
}