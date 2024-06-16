// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

using matriz = vector<vector<int>>;

int poda(const int k, const int m, const int rec_max){
  return (m-(k+1)) * rec_max;
}

bool es_solucion(const int& castigo, const int& C){
  return castigo <= C;
}

void vuelta_atras(int k, const int n, const int m, const int C, const matriz& recompensa, const int rec_max, int &maxRec, int &castigo, int &rec, vector<int>&sol){
  for(int i = 0; i < n; i++){
    sol[k] = i;
    if(k > 0){
      if(recompensa[sol[k-1]][i] >= 0)
        rec += recompensa[sol[k-1]][i];
      else  
        castigo -= recompensa[sol[k-1]][i];
    } 
    if(es_solucion(castigo, C)){
      if(k == m - 1){
        if(rec > maxRec)
          maxRec = rec;
      } else {
        int beneficio = poda(k, m, rec_max);
        if(rec + beneficio > maxRec)
          vuelta_atras(k + 1, n, m, C, recompensa, rec_max, maxRec, castigo, rec, sol);
      }
    }
    if(k > 0){
      if(recompensa[sol[k-1]][i] >= 0)
        rec -= recompensa[sol[k-1]][i];
      else  
        castigo += recompensa[sol[k-1]][i];
    }
  }
}

int resolver(const int n, const int m, const int C, const matriz& recompensa, const int rec_max) {
  int rec = 0;
  int castigo = 0;
  int maxRec = -1;
  vector<int> sol(m);

  vuelta_atras(0, n, m, C, recompensa, rec_max, maxRec, castigo, rec, sol);
  return maxRec;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
  // leer los datos de la entrada
  int n, m, C; cin >> n >> m >> C;
  matriz recompensa(n, vector<int>(n));
  int rec_max = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> recompensa[i][j];
      if(recompensa[i][j] >= rec_max)
        rec_max = recompensa[i][j];
    }
  }
  
  int sol = resolver(n, m, C, recompensa, rec_max);
  if(sol > -1)
    cout << sol;
  else
    cout << "NO";
  
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
     #endif
    
    return 0;
}