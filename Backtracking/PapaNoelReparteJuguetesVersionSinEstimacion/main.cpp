// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
using matriz = vector<vector<int>>;

struct sol{
  vector<int> ninyos;
  int maximaSatisfaccion = 0;

  sol(int n) : ninyos(n){}
};

bool es_solucion(const int k, const int n){
  return k == n - 1;
}

bool es_completable(const int k, const int n){
  return k < n - 1;
}

void backtracking(const int m, const int n, int k, const matriz &satisfaccion, sol &sol, int &resultado, vector<bool> &usados){
  for(int i = 0; i < m; i++){
    sol.ninyos[k] = i;
    sol.maximaSatisfaccion += satisfaccion[k][i];
    if(!usados[i]){
      usados[i] = true;
      if(es_solucion(k, n)){
        resultado = max(resultado, sol.maximaSatisfaccion);
      }else if(es_completable(k, n)){
        backtracking(m, n, k+1, satisfaccion, sol, resultado, usados);
      }
      usados[i] = false;
    }
    sol.maximaSatisfaccion -= satisfaccion[k][i];
  }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int m, n; cin >> m >> n;
  if (! std::cin)
      return false;
  
  matriz satisfaccion(m, vector<int>(n));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> satisfaccion[i][j];
    }
  }

  int resultado = -1;
  sol sol(n);
  vector<bool> usados(m, false);
  backtracking(m, n, 0, satisfaccion, sol, resultado, usados);

  cout << resultado << '\n';
  
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
    system("PAUSE");
    #endif
  
  return 0;
}