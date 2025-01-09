// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Resultado {
  int max_longitud; 
  int primero;      
  int ultimo;       
};

Resultado escalonMasLargo(const vector<int>& escalera, int c, int f) {
  if (c == f) {
    return {1, 1, 1};
  } else {
    int m = (c + f) / 2;
    Resultado iz = escalonMasLargo(escalera, c, m);
    Resultado der = escalonMasLargo(escalera, m + 1, f);

    int max_longitud = max(iz.max_longitud, der.max_longitud);
    int primero = iz.primero;
    int ultimo = der.ultimo;

    if (escalera[m] == escalera[m + 1]) {
      int escalon_central = iz.ultimo + der.primero;
      max_longitud = max(max_longitud, escalon_central);
      
      if (iz.primero == m - c + 1)
        primero = escalon_central;

      if (der.ultimo == f - m)
        ultimo = escalon_central; 
    }

    return {max_longitud, primero, ultimo};
  }
}


bool resuelveCaso() {
  // leer los datos de la entrada
  int N; cin >> N;
  if (N == 0)
    return false;

  vector<int> escalera(N);
  for(int i = 0; i < N; i++)
    cin >> escalera[i];

  Resultado resultado = escalonMasLargo(escalera, 0, N - 1);
  cout << resultado.max_longitud << '\n';

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
