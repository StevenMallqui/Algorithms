// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema

int minimo(const vector<int> &v, int inicio, int fin){
  if(inicio == fin){
    return v[inicio];
  }else{
    int centro = (inicio + fin)/2;
    if(v[centro] > v[centro + 1])
      return minimo(v, centro + 1, fin);
    else
      return minimo(v, inicio, centro);
  }
}

int resolver(const vector<int> &v) {
  return minimo(v, 0, v.size()-1);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int N; cin >> N;
  if (! std::cin)
      return false;
  
  vector<int> v(N);
  for(int i = 0; i < N; i++){
    cin >> v[i];
  }

  cout << resolver(v) <<'\n';
  
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