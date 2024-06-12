// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

int minimo(const vector<int>& datos, int inicio, int fin){
  if(inicio == fin)
    return datos[inicio];
  else{
    int centro = (inicio + fin) / 2;
    int minIz = minimo(datos, inicio, centro);
    int minDer = minimo(datos, centro + 1, fin);
    return min(minIz, minDer);
  }
}
// función que resuelve el problema
int resolver(const vector<int> & datos) {
  return minimo(datos, 0, datos.size() - 1);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

  int N; cin >> N;  
  if (! std::cin)
      return false;
  
  vector<int> v(N);
  for(int i = 0; i < N; i++){
    cin >> v[i];
  }

  cout << resolver(v) << '\n';

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