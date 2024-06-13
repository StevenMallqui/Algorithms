// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

int bongo(const vector<int> &v, int inicio, int fin, int C){
  if(inicio > fin){
    return -1;
  }else{
    int centro = (inicio + fin) / 2;
    if(v[centro] == centro + C){
      return v[centro];
    }else if(v[centro] > centro + C){
      return bongo(v, inicio, centro - 1, C);
    }else{
      return bongo(v, centro + 1, fin, C);
    }
  }
}

// función que resuelve el problema
int resolver(const vector<int> &datos, int C) {
  return bongo(datos, 0, datos.size() - 1 , C);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
  // leer los datos de la entrada
  int N, C; cin >> N >> C;
  vector<int> v(N);
  for(int i = 0; i < N; i++){
    cin >> v[i];
  }  
  
  int sol = resolver(v, C);

  if(sol == -1)
    cout << "NO";
  else 
    cout << sol;

  cout <<'\n';
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