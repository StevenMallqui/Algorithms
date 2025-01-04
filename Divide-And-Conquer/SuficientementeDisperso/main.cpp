// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema
bool suficientementeDispersos(const vector<int> &datos, int i, int f, const int K) {
  if(f <= i){
    return true;
  }else{
    int m = (i+f)/2;
    bool iz = suficientementeDispersos(datos, i, m, K);
    bool der = suficientementeDispersos(datos, m+1, f, K);

    return iz && der && abs(datos[f] - datos[i]) >= K;
  }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int N, K; cin >> N >> K;
  if (! std::cin)
      return false;
  
  vector<int> valores(N);
  for(int i = 0; i < N; i++)
    cin >> valores[i];

  // escribir sol
  if(suficientementeDispersos(valores, 0, N-1, K))
    cout << "SI";
  else
    cout << "NO";
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