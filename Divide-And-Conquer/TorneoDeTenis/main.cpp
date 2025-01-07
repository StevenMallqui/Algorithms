// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema
int numPartidos(const vector<bool> &jugadores, int i, int f, int R, bool &ganador, int &ronda) {
  if(f <= i){
    ronda = 0;
    ganador = jugadores[i];
    return 0;
  }else{
    int m = (i+f)/2;
    bool jugIz, jugDer;
    int rondaIz = 0, rondaDer = 0;
    int pIz = numPartidos(jugadores, i, m, R, jugIz, rondaIz);
    int pDer = numPartidos(jugadores, m+1, f, R, jugDer, rondaDer);

    int p = pIz + pDer;
    if (rondaIz < R && rondaDer < R) {
      if(jugIz && jugDer)
        p++;
    }
    ganador = jugIz || jugDer;
    ronda = max(rondaIz, rondaDer) + 1; 

    return p;
  }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int N, R; cin >> N >> R;
  if (! std::cin)
      return false;
  
  vector<bool> jugadores(N);
  string aux;
  for(int i = 0; i < N; i++){
    cin >> aux;
    if(aux == "NP")
      jugadores[i] = false;
    else
      jugadores[i] = true;
  }

  // escribir sol
  int ronda;
  bool jugador;
  cout << numPartidos(jugadores, 0, N-1, R, jugador, ronda) << '\n';
  
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