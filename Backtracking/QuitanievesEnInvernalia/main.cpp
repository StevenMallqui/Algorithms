// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

using matriz = vector<vector<int>>;

bool es_solucion(const int k, const int i, const vector<int>& anchurasCarros, const vector<int>& anchurasCaminos, const vector<bool>& carrosUsados){
  return anchurasCarros[i] <= anchurasCaminos[k] && !carrosUsados[i];
}

bool poda(const vector<int>& maximos, const int k, const int calidadesAct, const int maxCalidades){
  return calidadesAct + maximos[k + 1] > maxCalidades;
}

void vuelta_atras(const int n, const int m, int k, const vector<int>& anchurasCarros, const vector<int>& anchurasCaminos, const matriz& calidades, vector<int>& sol, int& calidadesAct, int& maxCalidades, vector<bool>& carrosUsados, const vector<int>& maximos){
  for(int i = 0; i < n; i++){
    sol[k] = i;
    if(es_solucion(k, i, anchurasCarros, anchurasCaminos, carrosUsados)){
      calidadesAct += calidades[i][k];
      carrosUsados[i] = true;
      if(k == m - 1){
        if(calidadesAct > maxCalidades)
          maxCalidades = calidadesAct;
      }else{
        if(poda(maximos, k, calidadesAct, maxCalidades))
          vuelta_atras(n, m, k + 1, anchurasCarros, anchurasCaminos, calidades, sol, calidadesAct, maxCalidades, carrosUsados, maximos);
      }
      carrosUsados[i] = false;
      calidadesAct -= calidades[i][k];
    }
  }

  if(k == m - 1){
    if(calidadesAct > maxCalidades)
      maxCalidades = calidadesAct;
  }else{
    if(poda(maximos, k, calidadesAct, maxCalidades))
      vuelta_atras(n, m, k + 1, anchurasCarros, anchurasCaminos, calidades, sol, calidadesAct, maxCalidades, carrosUsados, maximos);
  }
}

int resolver(const int n, const int m, const vector<int>& anchurasCarros, const vector<int>& anchurasCaminos, const matriz& calidades, const vector<int>& maximos) {
  //Marcadores    
  int calidadesAct = 0;
  vector<bool> carrosUsados(n);
  //Solucion
  int maxCalidades = 0;
  vector<int> sol(m);
  vuelta_atras(n, m, 0, anchurasCarros, anchurasCaminos, calidades, sol, calidadesAct, maxCalidades, carrosUsados, maximos);
  return maxCalidades;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
  int n, m; cin >> n >> m;
  vector<int> anchurasCarros(n);
  for(int i = 0; i < n; i++){
    cin >> anchurasCarros[i];
  }

  vector<int> anchurasCaminos(m);
  for(int i = 0; i < m; i++){
    cin >> anchurasCaminos[i];
  }

  matriz calidades(n, vector<int>(m));
  vector<int> maximos(m, 0);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> calidades[i][j];
      if(calidades[i][j] > maximos[j])
        maximos[j] = calidades[i][j];
    }
  }  

  for(int i = m - 1; i >= 0; i--){
    maximos[i] += maximos[i+1];
  }

  cout << resolver(n, m, anchurasCarros, anchurasCaminos, calidades, maximos) << '\n';
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