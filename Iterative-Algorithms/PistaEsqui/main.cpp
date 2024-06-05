// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema
int resolver(const vector<int> & datos) {
  int maxTramos = 0, ini = 0, i = 0, actual = datos[0];

  while(i < datos.size()){
    if(actual >= datos[i]){
      if(i - ini + 1 > maxTramos)
        maxTramos = i - ini + 1;
      actual = datos[i];
      i++;
    }else{
      ini = i;
      actual = datos[i];
    }
  }

  return maxTramos;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
  // leer los datos de la entrada
  int N, elem; cin >> N;

  vector<int> datos;
  for(int i = 0; i < N; i++){
    cin >> elem;
    datos.push_back(elem);
  }
  
  // escribir sol
  if(N == 0)
    cout << 0 << '\n';
  else 
    cout << resolver(datos) << '\n'; 
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