// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

using matriz = vector<vector<int>>;

int podaSimple(const int calidad, const int n, const int tarea, const int maximo){
  return calidad + (n-tarea-1)*maximo;
}

int poda(const int calidad, const int tarea, const vector<int>& sumaMayores){
  return calidad + sumaMayores[tarea];
}

bool es_solucion(const vector<int>& T, const vector<int>& D, const vector<int>& dedicacion, const matriz& C, const int i, const int tarea){
  return (dedicacion[i] + T[tarea]) <= D[i] && (C[tarea][i] > 0);
}

void vuelta_atras(const int N, const int M, int k, const vector<int>& T, const vector<int>& D, const matriz& C, int& calidad, int& calidadMax, vector<int>& dedicacion, const vector<int>& sumaMayores, const int maximoPoda){
  for(int i = 0; i < M; i++){
    if(es_solucion(T, D, dedicacion, C, i, k)){
      dedicacion[i] += T[k];
      calidad += C[k][i];
      if(k == N -1){
        if(calidad > calidadMax)
          calidadMax = calidad;
      }else{
        int estimacion = poda(calidad, k, sumaMayores);
        if(estimacion > calidadMax)
          vuelta_atras(N, M, k + 1, T, D, C, calidad, calidadMax, dedicacion, sumaMayores, maximoPoda);
      }
      dedicacion[i] -= T[k];
      calidad -= C[k][i];
    }
  }
}


// función que resuelve el problema
int resolver(const int& N, const int& M, const vector<int>& T, const vector<int>& D, const matriz& C) {
    
  //Marcadores
  int calidad = 0;
  vector<int> dedicacion(M, 0);
  // Solucion
  int calidadMax = 0;   
  // Podas
  int maximoPoda = 0;
  vector<int> sumaMayores(N, 0);

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      maximoPoda = max(maximoPoda, C[i][j]);
      sumaMayores[i] = max(sumaMayores[i], C[i][j]);
    }
  }

  for(int i = N - 2; i >= 0; i--)
    sumaMayores[i] += sumaMayores[i + 1];

  vuelta_atras(N, M, 0, T, D, C, calidad, calidadMax, dedicacion, sumaMayores, maximoPoda);
  return calidadMax;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int N, M; cin >> N >> M;
  if (N == 0 && M == 0)
    return false;

  vector<int> T(N);
  for(int i = 0; i < N; i++)
    cin >> T[i];

  vector<int> D(M);
  for(int i = 0; i < M; i++)
    cin >> D[i];

  matriz C(N, vector<int>(M));

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      cin >> C[i][j];
    }
  }

  cout << resolver(N, M, T, D, C) <<'\n';

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
    #endif
  
  return 0;
}
