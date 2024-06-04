// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema
int resolver(const vector<int>& datos, int k) {
  int parejas = 0, resto = 0, i = 0, ini = 0;

  while(i <  datos.size()){
    resto = datos[i] - datos[ini];
    if(resto == k){
      parejas++;
      ini++;
      i++;
    }else if(resto < k){
      i++;
    }else{
      ini++;
    }
  }
    
  return parejas;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int n, k, elem; cin >> n >> k;
  if (n == -1)
      return false;

  vector<int> datos;
  for(int i = 0; i < n; i++){
    cin >> elem;
    datos.push_back(elem);
  }

  // escribir sol
  cout << resolver(datos, k) << '\n';

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
