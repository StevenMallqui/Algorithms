// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema

string intToColor(const int i){
  if(i == 0)
    return "azul";
  else if(i == 1)
    return "rojo";
  else
    return "verde";
}

void printTower(vector<int> &sol){
  for(int i : sol)
    cout << intToColor(i) << ' ';
  cout << '\n';
}

bool esValida(const vector<int> &sol, const int k){
  return !(sol[k-1] == 2 && sol[k] == 2);
}

void backtracking(const int n, const int k, vector<int> &sol){

  if(k == n){
    printTower(sol);
    return;
  }

  for(int i = 0; i < 3; i++){
    sol[k] = i;
    if(esValida(sol, k))
      backtracking(n, k+1, sol);
  }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int n; cin >> n;
  if (n == 0)
      return false;

  // escribir sol
  vector<int> sol(n);
  sol[0] = 1;

  backtracking(n, 1, sol);
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
