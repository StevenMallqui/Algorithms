// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;


// función que resuelve el problema
void polidivisibles(long long raiz, int nivel, int maxDigitos) {
  if(nivel > maxDigitos) return;

  cout << raiz <<'\n';

  for(int i = 0; i < 10; i++){
    long long nuevoNum = raiz * 10 + i;
    if(nuevoNum%(nivel + 1) == 0)
      polidivisibles(nuevoNum, nivel + 1, maxDigitos);
  }
}

void escribePolidivisibles(long long raiz, int maxDigitos){
  int nivel = to_string(raiz).size();
  polidivisibles(raiz, nivel, maxDigitos);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  long long int N, D; cin >> N;
  if (! std::cin)
      return false;
  cin >> D;  

  escribePolidivisibles(N, D);
  cout << "---" << '\n';

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