// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema

bool superb(const vector<int> &v, int ini, int fin, int &min, int &max){
  int n = fin - ini;
  if(n < 3){
    if(n == 1){
      min = v[ini];
      max = v[ini];
    }else if(n == 2){
      min = std::min(v[ini], v[ini+1]);
      max = std::max(v[ini], v[ini+1]);
    } 
    return true;
  }else{
    int pos = (ini + (fin - 1)) / 2;
    int minIz, maxDer, maxIz, minDer;
    bool superbIZ = superb(v, ini, pos, minIz, maxIz);
    bool superbDER = superb(v, pos+1, fin, minDer, maxDer);
    min = std::min(v[pos], std::min(minIz, minDer));
    max = std::max(v[pos], std::max(maxIz, maxDer));

    return superbIZ && superbDER && (v[pos] == abs(maxIz - minDer));
  }
}

bool resolver(const vector<int>& datos) {
  int min;
  int max;    
  return superb(datos, 0, datos.size(), min, max);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int N; cin >> N;
  if (N == -1)
      return false;

  vector<int> v(N);
  int elem;
  for(int i = 0; i < N; i++){
    cin >> elem;
    v[i] = elem;
  }


  if(resolver(v))
    cout << "SUPERB\n";
  else
    cout << "NO SUPERB\n";

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
