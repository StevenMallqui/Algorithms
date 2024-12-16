// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema
int resolver(const vector<int> &v, const int k) {
  int ini = 0, kemparejados = 0, i = 0, resto;

  while(i < v.size()){
    resto = v[i]-v[ini];
    if(resto == k){
      kemparejados++;
      ini++;
      i++;
    }else if(resto < k)
      i++;
    else
      ini++;
  }
  
  return kemparejados;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int n; cin >> n;
  if (n == -1)
      return false;

  int k; cin >> k;
  vector<int> v(n);
  for(int i = 0; i < n; i++)
    cin >> v[i];

  // escribir sol
  cout << resolver(v, k) << '\n';

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
