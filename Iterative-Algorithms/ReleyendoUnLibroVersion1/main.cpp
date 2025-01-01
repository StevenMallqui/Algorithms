// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema
int resolver(const vector<int> &datos, const int L) {
  int sum = 0, ini = 0, maxP, maxI;
  for(int i = 0; i < L; i++)
    sum += datos[i];

  maxI = ini;
  maxP = sum;

  for(int i = L; i < datos.size(); i++){
    sum = sum + datos[i] - datos[ini];
    if(sum >= maxP){
      maxP = sum;
      maxI = i - (L-1);
    }
    ini++;
  }
  
  return maxI;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int n, L; cin >> n >> L;
  if (n == 0 && L == 0)
      return false;

  vector<int> paginas(n);
  for(int i = 0; i < n; i++)
    cin >> paginas[i];

  // escribir sol
  cout << resolver(paginas, L) << '\n';

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
