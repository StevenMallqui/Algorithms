// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
bool resolver(vector<int> datos, int p) {
  
  if(p + 1 < datos.size()){
    int maxi = datos[0], mini = datos[p+1];
    for(int i = 0; i < p + 1; i++){
      maxi = max(maxi, datos[i]); 
    }
    for(int j = p + 1; j < datos.size(); j++){
      mini = min(mini, datos[j]); 
    }

    if(maxi < mini) return true;
    else return false;
  }
  
  return true;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
  // leer los datos de la entrada
  
  int N, p, aux; cin >> N >> p;
  vector<int> datos;
  for(int i = 0; i < N; i++){
    cin >> aux;
    datos.push_back(aux);
  }
  
  if(resolver(datos, p)) cout << "SI";
  else cout << "NO";
  
  cout << '\n';
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