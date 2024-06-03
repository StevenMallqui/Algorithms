// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema
bool resolver(vector<int> datos) {
  bool encontrado = false;
  int suma = 0;

  for(int i = datos.size() - 1; i >= 0 && !encontrado; i--){
    if(suma == datos[i]) 
      encontrado = true;
    suma += datos[i];
  }
    
  return encontrado;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
  int N; cin >> N;
  if (N == 0)
      return false;
  
  int aux;
  vector<int> datos;
  for(int i = 0; i < N; i++){
    cin >> aux;
    datos.push_back(aux);
  }

  bool sol = resolver(datos);

  // escribir sol
  if(sol) cout << "YES\n";
  else cout << "NO\n";

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
