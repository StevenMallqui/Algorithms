// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema
bool es_valida(const int k, const vector<int> &sol, const vector<string> &tipos){
  return k%2 == 0 || (sol[k-1] < sol[k] && (tipos[sol[k]] != tipos[sol[k - 1]]));
}

bool es_solucion(const int k, const int tam){
  return k == tam - 1;
}

void procesar_solucion(const vector<int> &sol, const int tam){
  for(int i = 0; i < tam; i++)
    cout << sol[i] << ' ';
  cout << '\n';
}

void backtracking(const int m, int k, int n, vector<string> &tipos, vector<int> &sol, bool &haySolucion){
  for(int i = 0; i < m; i++){
    sol[k] = i;
    if(es_valida(k, sol, tipos)){
      if(es_solucion(k, n)){
        haySolucion = true;
        procesar_solucion(sol, n);
      }else{
        backtracking(m, k+1, n, tipos, sol, haySolucion);
      }
    }
  } 
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int m, n; cin >> m >> n;  
  if (! std::cin)
      return false;
  
  vector<string> tipos(m);
  for(int i = 0; i < m; i++)
    cin >> tipos[i];

  vector<int> sol(n*2);
  bool haySolucion = false;
  backtracking(m, 0, 2*n, tipos, sol, haySolucion);
  if(!haySolucion)
    cout << "SIN SOLUCION\n";
  cout << '\n';
  
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