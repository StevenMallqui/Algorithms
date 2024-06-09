// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;


// función que resuelve el problema
int resolver(int n, int minDer, int &suma, bool turno) {
  if(n < 10){
    suma += n * 3 + minDer;
    return n;
  }else{
    int ultimo = n%10;
    int minD = min(ultimo, minDer);
    int mayorIz;
    if(turno){
      mayorIz = resolver(n/10, minD, suma, false);
      suma += ultimo * 2 + mayorIz;
    }
    else{
      suma += ultimo * 3 + minDer;
      mayorIz = resolver(n/10, minD, suma, true);
    }
    return max(ultimo, mayorIz);
  }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
  // leer los datos de la entrada
  long long n; cin >> n;

  int suma = 0; 
  int a = resolver(n, n%10, suma, true);

  // escribir sol
  cout << suma <<'\n';  
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
     #endif
    
    return 0;
}