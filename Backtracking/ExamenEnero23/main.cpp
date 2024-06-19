// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

bool es_solucion(const int k, const int i, const vector<int>& G, const vector<int>& P, const vector<int>& patrullasCiudad){
  return  patrullasCiudad[i] + P[k] <= G[i];
}

void vuelta_atras(int k, const int n, const int m, const int r, const vector<int>& L, const vector<int>& G, const vector<int>& S, const vector<int>& P, vector<int>& patrullasCiudad, vector<int>& sol, int& precioAct, int& precioMin){
  for(int i = 0; i < n; i++){
    sol[k] = i;
    if(es_solucion(k, i, G, P, patrullasCiudad)){
      patrullasCiudad[i] += P[k];
      precioAct += (P[k] * S[i]);
      if(patrullasCiudad[i] >= L[i]){
        if(precioAct < precioMin)
          precioMin = precioAct;
      }else{
          vuelta_atras(k + 1, n, m, r, L, G, S, P, patrullasCiudad, sol, precioAct, precioMin);
      }
      patrullasCiudad[i] -= P[k];
      precioAct -= (P[k] * S[i]);
    }
  }
}

// función que resuelve el problema
int resolver(const int n, const int m, const int r, const vector<int>& L, const vector<int>& G, const vector<int>& S, const vector<int>& P){
  //Marcadores
  vector<int> patrullasCiudad(n, 0); // Personas por ciudad
  //Soluciones
  vector<int> sol(m); 
  int precioAct = 0;
  int precioMin = INT_MAX;

  vuelta_atras(0, n, m, r, L, G, S, P, patrullasCiudad, sol, precioAct, precioMin);
  return precioMin;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
  // leer los datos de la entrada
  int n, m, r; cin >> n >> m >> r;
  vector<int> L(n);
  for(int i = 0; i < n; i++){
    cin >> L[i];
  }
  vector<int> G(n);
  for(int i = 0; i < n; i++){
    cin >> G[i];
  }
  vector<int> S(n);
  for(int i = 0; i < n; i++){
    cin >> S[i];
  }
  vector<int> P(m);
  for(int i = 0; i < m; i++){
    cin >> P[i];
  }

  sort(P.begin(), P.end());
  
  int sol = resolver(n, m, r, L, G, S, P);
  if(sol < INT_MAX)
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
     system("PAUSE");
     #endif
    
    return 0;
}