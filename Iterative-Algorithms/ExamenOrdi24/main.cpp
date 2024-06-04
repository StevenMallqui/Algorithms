// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema
int resolver(const vector<int> &datos, int l) {
  int segmentos = 0, count = 0, dat = -1;

  for(int i = 0; i < datos.size(); i++){
    if(dat != datos[i]){
      dat = datos[i];
      count = 0;
    }
    count++;
    if(count >= l)
      segmentos += count - l + 1; 
  }

  return segmentos;   
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
  // leer los datos de la entrada
  int l, N, elem;
  cin >> l >> N;

  vector<int> datos;
  for(int i = 0; i < N; i++){
    cin >> elem;
    datos.push_back(elem);
  }
  
  // escribir sol
  cout << resolver(datos, l) <<'\n';
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
     #endif
    
    return 0;
}