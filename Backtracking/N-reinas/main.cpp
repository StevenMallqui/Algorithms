// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

int diag_asc(const int x, const int y){
  return x + y;
}

int diag_desc(const int x, const int y, const int n){
  return(x - y + (n - 1));
}

bool es_solucion(const vector<bool>& filas, const vector<bool>& diagAsc, const vector<bool>& diagDesc, const int k, vector<int>& sol, const int N){
  return !filas[sol[k]] && !diagAsc[diag_asc(k, sol[k])] && !diagDesc[diag_desc(k, sol[k], N)];
}

void vuelta_atras(vector<int>& sol, int k, const int N, vector<bool>& filas, vector<bool>& diagAsc, vector<bool>& diagDesc, int& combinaciones){
  for(int i = 0; i < N; i++){
    sol[k] = i;
    if(es_solucion(filas, diagAsc, diagDesc, k, sol, N)){
      if(k == N - 1){
        combinaciones++;
      }else{
        filas[i] = true;
        diagAsc[diag_asc(k, i)] = true;
        diagDesc[diag_desc(k, i, N)] = true;
        vuelta_atras(sol, k + 1, N, filas, diagAsc, diagDesc, combinaciones);
        filas[i] = false;
        diagAsc[diag_asc(k, i)] = false;
        diagDesc[diag_desc(k, i, N)] = false;
      }
    }
  }
}

// función que resuelve el problema
int resolver(int N) {
  //Marcadores
  vector<bool> filas(N);
  vector<bool> diagAsc(2 * N - 1);
  vector<bool> diagDesc(2 * N - 1);
  //Solucion 
  int combinaciones = 0;
  vector<int> sol(N);
  
  vuelta_atras(sol, 0, N, filas, diagAsc, diagDesc, combinaciones);
  return combinaciones;  
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
  // leer los datos de la entrada
  int N; cin >> N;
  
  cout << resolver(N) <<'\n';
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