// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

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

bool esValida(int k, const vector<int> &usadas, const vector<int> &sol){
  return !(sol[k-1] == 2 && sol[k] == 2) && (usadas[0] >= usadas[2]);
}

// función que resuelve el problema
void backtracking(int n, int k, vector<int> &restantes, vector<int> &usadas, vector<int> &sol, bool &haySolucion) {
  if(k == n){
    if(usadas[1] > (usadas[0] + usadas[2])){
      printTower(sol);
      haySolucion = true;
    }
    return;
  }
  
  for(int i = 0; i < 3; i++){
    if(restantes[i] > 0){
      sol[k] = i;
      restantes[i]--;
      usadas[i]++;
      if(esValida(k, usadas, sol))
        backtracking(n, k+1, restantes, usadas, sol, haySolucion);
      restantes[i]++;
      usadas[i]--;
    }
  }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int n, a, r, v; cin >> n >> a >> r >> v;
  if (n == 0 && a == 0 && r == 0 && v == 0)
    return false;

  vector<int> restantes = {a, r-1, v};
  vector<int> usadas = {0, 1, 0};
  vector<int> sol(n);
  sol[0] = 1;
  bool haySolucion = false;

  // escribir sol
  backtracking(n, 1, restantes, usadas, sol, haySolucion);
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
