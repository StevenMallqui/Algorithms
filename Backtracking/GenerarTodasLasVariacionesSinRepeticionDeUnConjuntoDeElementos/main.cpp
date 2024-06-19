// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

char intToChar(const int num){
  return 'a' + num;
}

bool es_solucion(vector<bool>& usados, const int i){
  return !usados[i];
}

void vuelta_atras(int k, string& par, const int N, const int M, vector<bool>& usados){
  for(int i = 0; i < M; i++){
    if(es_solucion(usados, i)){
      usados[i] = true;
      par += intToChar(i);
      if(k == N - 1){
        cout << par << '\n';
      }else{
        vuelta_atras(k + 1, par, N, M, usados);
      }
      usados[i] = false;
      par.pop_back();
    }
  }
}

// función que resuelve el problema
void resolver(const int N, const int M) {
  string par;
  vector<bool> usados(M, false);
  vuelta_atras(0, par, N, M, usados);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int M; cin >> M;
  if (! std::cin)
      return false;
  
  int N; cin >> N;

  resolver(N, M);
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