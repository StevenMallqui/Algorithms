// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

pair<bool, int> interesante(int n, int sumaSu){
  if(n < 10){
    return {sumaSu%n == 0, n};
  }else if(n == 0)
    return {false, -1};
  else{
    int ultimo = n%10;
    auto[inter, sumaPre] = interesante(n/10, sumaSu + ultimo);
    return {inter && (sumaPre%ultimo == 0) && (sumaSu%ultimo == 0), sumaPre + ultimo};
  }
}

void resuelveCaso() {
  // leer los datos de la entrada
  
  int n; cin >> n;
  if(interesante(n, 0).first)
    cout << "SI\n";
  else 
    cout << "NO\n";
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