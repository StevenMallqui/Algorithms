// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;


// función que resuelve el problema
int invertir(int n, int d) {
  if(n < 10){
    return d * 10 + n;
  }else{
    int num = d * 10 + (n%10);
    return invertir(n/10, num);
  }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int n; cin >> n;
  if (n == 0)
      return false;

  // escribir sol
  int d = 1;
  cout << invertir(n, 0) << '\n';

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
