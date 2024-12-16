// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema
int resolver(const vector<int> &datos) {

  int parejas = 0, x, y, factor = 0;
  for(int i = 0; i < datos.size(); i++){
    if(datos[i]%2 == 0){
      y = i;
      if(x < y)
        parejas += factor; 
    }else{
      x = i;
      factor++;
    }
  }

  return parejas;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

void resuelveCaso() {
  
  // leer los datos de la entrada
  int n; cin >> n;
  vector<int> elementos(n);
  
  for(int i = 0; i < n; i++)
    cin >> elementos[i];

  cout << resolver(elementos) << '\n';
}

int main() {
  // Para la entrada por fichero.
  // Comentar para acepta el reto
  #ifndef DOMJUDGE
      std::ifstream in("datos.txt");
      auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
      #endif 


  int numCasos;
  std::cin >> numCasos;
  for (int i = 0; i < numCasos; ++i)
      resuelveCaso();


  // Para restablecer entrada. Comentar para acepta el reto
      #ifndef DOMJUDGE // para dejar todo como estaba al principio
      std::cin.rdbuf(cinbuf);
      system("PAUSE");
      #endif

  return 0;
}