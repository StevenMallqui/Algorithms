// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

bool esPosible(const vector<int>& obras, int maxViajes, int cap) {
    int viajes = 1; 
    int cargaActual = 0;
    
    for (int peso : obras) {
        if (cargaActual + peso > cap) {
            viajes++;  
            cargaActual = peso;  
            if (viajes > maxViajes)
                return false;  
        } else
            cargaActual += peso;  
    }
    
    return true;
}

// Función principal que usa búsqueda binaria para encontrar la mínima carga máxima
int minCarga(int n, int maxViajes, const vector<int>& obras, int maxPeso, int sumaPesos) {
    int izquierda = maxPeso;  
    int derecha = sumaPesos;  

    int resultado = derecha;

    while (izquierda <= derecha) {
        int medio = (izquierda + derecha) / 2;
        
        if (esPosible(obras, maxViajes, medio)) {
            resultado = medio;  
            derecha = medio - 1;
        }else
            izquierda = medio + 1;  
    }

    return resultado;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int N, V; cin >> N >> V;
  if (N == 0 && V == 0)
      return false;

  vector<int> obras(N);
  int sumaPesos = 0, maxPeso = 0;
  for(int i = 0; i < N; i++){
    cin >> obras[i];
    maxPeso = max(maxPeso, obras[i]);
    sumaPesos += obras[i];
  }

  // escribir sol
  cout << minCarga(N, V, obras, maxPeso, sumaPesos) << '\n';

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
