// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


bool esPosible(const vector<int> &tramos, int P, int tiempo){
  int paradas = 0;
  int tramosAct = 0;

  for(int t : tramos){
    if(tramosAct + t > tiempo){
      paradas++;
      tramosAct = t;
      if(paradas > P)
        return false;
    }else
      tramosAct += t;
  }

  return true;
}

// función que resuelve el problema
int tiempoMaximo(const vector<int> &tramos, int i, int f, const int P, int maximo, int suma) {
  int iz = maximo;
  int der = suma;

  int resultado = der;

  while(iz <= der){
    int m = (iz+der)/2;

    if(esPosible(tramos, P, m)){
      resultado = m;
      der = m - 1;
    }else
      iz = m + 1;
  }

  return resultado;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int N, P; cin >> N >> P;
  if (N == 0 && P == 0)
      return false;

  vector<int> tramos(N);
  int maximo = -1, suma = 0;
  for(int i = 0; i < N; i++){
    cin >> tramos[i];
    maximo = max(maximo, tramos[i]);
    suma += tramos[i];
  }
  
  cout << tiempoMaximo(tramos, 0, N-1, P, maximo, suma) <<'\n';

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
