// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;


// función que resuelve el problema
int mcd(int a, int b) {
  if(b == 0)
    return a;
  else if(b > 0)
    return mcd(b, a%b);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int a, b; cin >> a >> b;
  if (a == 0 && b == 0)
    return false;

  int sol;
  if(a > b)
    sol = mcd(a, b);
  else
    sol = mcd(b, a);

  // escribir sol
  cout << sol << '\n';

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
