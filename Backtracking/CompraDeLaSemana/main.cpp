// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

using matriz = vector<vector<int>>;

bool es_solucion(const int i, const vector<int>& comprasPorSuper){
  return comprasPorSuper[i] < 3;
}

bool poda(const int precioAct, const int precioMin, const vector<int>& masBaratos, const int k){
  return precioAct + masBaratos[k + 1] < precioMin;
}

void vuelta_atras(const int m, const int n, int k, const matriz& precios, vector<int>& sol, vector<int>& comprasPorSuper, int& precioAct, int& precioMin, const vector<int>& masBaratos){
  for(int i = 0; i < m; i++){
    sol[k] = i;
    if(es_solucion(i, comprasPorSuper)){
      comprasPorSuper[i]++;
      precioAct += precios[i][k];
      if(k == n - 1){
        if(precioAct < precioMin){
          precioMin = precioAct;
        }
      }else{
        if(poda(precioAct, precioMin, masBaratos, k))
          vuelta_atras(m, n, k + 1, precios, sol, comprasPorSuper, precioAct, precioMin, masBaratos);
      }
      precioAct -= precios[i][k];
      comprasPorSuper[i]--;
    }
  }
}

// función que resuelve el problema
int resolver(const int m, const int n, const matriz& precios, const vector<int>& masBaratos) {
  //Marcadores
  vector<int> comprasPorSuper(m);
  
  //Solucion
  int precioActual = 0;
  int precioMinimo = INT_MAX;
  vector<int> sol(n);

  vuelta_atras(m, n, 0, precios, sol, comprasPorSuper, precioActual, precioMinimo, masBaratos);
  return precioMinimo;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
  // leer los datos de la entrada
  int m, n; cin >> m >> n;
  matriz precios(m, vector<int>(n));
  vector<int> masBaratos(n, INT_MAX);
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      cin >> precios[i][j];
      if(precios[i][j] < masBaratos[j])
        masBaratos[j] = precios[i][j];
    }
  }

  for(int i = n - 2; i >= 0; i--){
    masBaratos[i] += masBaratos[i + 1]; 
  }

  int sol = resolver(m, n, precios, masBaratos);

  // escribir sol
  cout << sol <<'\n';
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