// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct Minimal{
  int elemento = 0, cont = 0;
};


// función que resuelve el problema
bool resolver(vector<int> const&datos) {
  bool minimalista = true;
  Minimal solucion;
  solucion.elemento = datos[0]; solucion.cont++;
  int i = 1;

  while(i < datos.size() && minimalista){
    if(datos[i] == solucion.elemento){
      solucion.cont++;
    }else if(datos[i] < solucion.elemento){
        solucion.elemento = datos[i];
        solucion.cont = 1;
    }
    
    if(solucion.cont > 1) minimalista = false;

    i++;
  }

  return minimalista;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int N; cin >> N;
  if (N == -1)
    return false;
  
  vector<int> datos;
  int aux;
  
  for(int i = 0; i < N; i++){
    cin >> aux;
    datos.push_back(aux);
  }

  // escribir sol
  if(resolver(datos)) cout << "SI";
  else cout << "NO";

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
