// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


// función que resuelve el problema
vector<int> resolver(const vector<int> &repeticiones) {
  vector<int> solucion;
  int maximo = -1;
  for(int i = 0; i < repeticiones.size(); i++){
    if(repeticiones[i] > maximo){
      maximo = repeticiones[i];
      solucion.clear();
      solucion.push_back(i);
    }else if(repeticiones[i] == maximo){
      solucion.push_back(i);
    }
  }

  return solucion;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int tiradas; cin >> tiradas;
  if (tiradas == -1)
      return false;

  int valorMax; cin >> valorMax;
  vector<int> repeticiones(valorMax + 1, 0);
  int index;
  for(int i = 0; i < tiradas; i++){
    cin >> index;
    repeticiones[index]++;
  }

  vector<int> solucion = resolver(repeticiones);
  sort(solucion.begin(), solucion.end(), greater());

  // escribir sol
  for(int a : solucion)
    cout << a << ' ';
  
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
