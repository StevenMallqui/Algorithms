// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


char preso_fugado(const vector<char> &datos, char primero, char ultimo, int ini, int fin){
  if(ini == fin - 1){
    if(datos[ini] == primero)
      return ultimo;
    else return primero;
  }else{
    int m = (ini + fin) / 2;
    char medio = (primero + ultimo) / 2;  
    if(datos[m] > medio){
      return preso_fugado(datos, primero, medio, ini, m);
    }else{
      return preso_fugado(datos, medio, ultimo, m, fin);
    }

  }
}

// función que resuelve el problema
char resolver(const vector<char> & datos, int primero, int ultimo){
  return preso_fugado(datos, primero, ultimo, 0, datos.size());
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
  // leer los datos de la entrada
  char primero, ultimo; cin >> primero >> ultimo;
  int N = ultimo - primero;
  vector<char> v(N);
  for(int i = 0; i < N; i++){
    cin >> v[i];
  }

  cout << resolver(v, primero, ultimo) <<'\n';     
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