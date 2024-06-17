// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

using matriz = vector<vector<int>>;


bool es_solucion(const int juguete, const vector<bool>& marcador){
  return !marcador[juguete];
}

bool poda(const int& actSatis, const int& max_sat_restante, const int& maxSatis){
  return (actSatis + max_sat_restante) > maxSatis;
}


void vuelta_atras(const int n, const int m, int k, const matriz& satisfaccion, int &maxSatis, int &actSatis, vector<bool>& marcador, const vector<int>& maxSatisfacciones, int& max_sat_restante){
  for(int i = 0; i < m; i++){
    if(es_solucion(i, marcador)){
      actSatis += satisfaccion[k][i];
      max_sat_restante -= maxSatisfacciones[i];
      if(k == n-1){
        if(actSatis > maxSatis)
          maxSatis = actSatis;
      }else{
        marcador[i] = true;
        if(poda(actSatis, max_sat_restante, maxSatis))
          vuelta_atras(n, m, k + 1, satisfaccion, maxSatis, actSatis, marcador, maxSatisfacciones, max_sat_restante);
        marcador[i] = false;
      } 
      actSatis -= satisfaccion[k][i]; 
      max_sat_restante += maxSatisfacciones[i];
    }
  }
}

// función que resuelve el problema
int resolver(const int m, const int n, const matriz& satisfaccion, const vector<int>& maxSatisfacciones, int& max_sat_restante) {
    // Marcadores
    int actSatis = 0;
    vector<bool> marcador(m, false);
    // Solucion
    int maxSatis = 0;
    // Poda
    vuelta_atras(n, m, 0, satisfaccion, maxSatis, actSatis, marcador, maxSatisfacciones, max_sat_restante);
    return maxSatis;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int m; cin >> m;
  if (! std::cin)
      return false;
  
  int n; cin >> n;
  matriz satisfaccion(n, vector<int>(m));
  vector<int> maxSatisfacciones(m, -1);
  int max_sat_restante = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> satisfaccion[i][j];
      if(maxSatisfacciones[j] == -1 || satisfaccion[i][j] > maxSatisfacciones[j]){
        if(maxSatisfacciones[j] != -1)
          max_sat_restante -= maxSatisfacciones[j];
        maxSatisfacciones[j] = satisfaccion[i][j];
        max_sat_restante += maxSatisfacciones[j];
      }
    }
  } 

  cout << resolver(m, n, satisfaccion, maxSatisfacciones, max_sat_restante) <<'\n';
  
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