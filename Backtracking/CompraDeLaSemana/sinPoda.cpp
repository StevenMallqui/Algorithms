// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
using matriz = vector<vector<int>>;


const int MAX_PROD_POR_SUPER = 3;

bool es_mejor(const int coste, const int mejor_coste){
  return mejor_coste == -1 || coste < mejor_coste;
}

bool es_solucion(const int k, const int p, const vector<int> &marcador, const vector<int> &sol){
  return k == p - 1 && marcador[sol[k]] < MAX_PROD_POR_SUPER;
}

bool es_completable(const int k, const int p, const vector<int> &marcador, const vector<int> &sol){  
  return k < p - 1 && marcador[sol[k]] < MAX_PROD_POR_SUPER;
}
   
void backtracking(const int s, const int p, int k, const matriz &precios, int &coste, int &mejor_coste, vector<int> &sol, vector<int> &mejor_sol, vector<int> &marcador){
  for(int i = 0; i < s; i++){
    sol[k] = i;
    coste += precios[i][k];
    if(es_solucion(k, p, marcador, sol) && es_mejor(coste, mejor_coste)){
      mejor_sol = sol;
      mejor_coste = coste;
    }else if(es_completable(k, p, marcador, sol)){
      marcador[i]++;
      backtracking(s, p, k+1, precios, coste, mejor_coste, sol, mejor_sol, marcador);
      marcador[i]--;
    }
    coste -= precios[i][k];
  }
}

int resolver(const matriz &precios, const int s, const int p){
  int coste = 0, mejor_coste = -1;
  int k = 0;
  vector<int> sol(p), mejor_sol(p);
  vector<int> marcador(s, 0);
  backtracking(s, p, k, precios, coste, mejor_coste, sol, mejor_sol, marcador);
  return mejor_coste;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
  // leer los datos de la entrada
  int s, p; cin >> s >> p;
  matriz precios(s, vector<int>(p));

  for(int i = 0; i < s; i++)
    for(int j = 0; j < p; j++)
      cin >> precios[i][j];

  int sol = resolver(precios, s, p);
  if(sol == -1)
    cout << "Sin solucion factible";
  else
    cout << sol;
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