// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema
void resolver(int m, const vector<long long int>& nacimientos, int primero) {
  int a, b; 
  long long int suma = 0;
  for(int i = 0; i < m; i++){
    cin >> a >> b;

    b -= primero; a -= primero;
    a--;
    suma = nacimientos[b];
    if(a >= 0)
      suma -= nacimientos[a];

    cout << suma << '\n';
    suma = 0;
  }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int p, u; cin >> p >> u;
  if (p == 0 && u == 0)
      return false;

  int n = (u - p + 1);
  vector<long long int> nacimientos(n);
  cin >> nacimientos[0];
  for(int i = 1; i < n; i++){
    cin >> nacimientos[i];
    nacimientos[i] += nacimientos[i-1];
  }

  int m; cin >> m;

  // escribir sol
  resolver(m, nacimientos, p);
  cout << "---\n";

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
