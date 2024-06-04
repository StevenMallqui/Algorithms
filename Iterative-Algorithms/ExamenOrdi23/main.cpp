// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema
bool resolver(const vector<int>& datos, int c) {
  bool c_tramo = false;
  int i = 0, c_suma = 0, ini = 0;
  
  while(i < datos.size() && !c_tramo){
    if(c_suma + datos[i] <= c){
      c_suma += datos[i];
      if(c_suma == c)
        c_tramo = true;
      i++;
    }else{
      c_suma -= datos[ini];
      ini++;
    }
  }

  return c_tramo;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int N, elem, c; cin >> N;
  if (N == -1)
      return false;

  vector<int> datos;

  for(int i = 0; i < N; i++){
    cin >> elem;
    datos.push_back(elem);
  }

  cin >> c;

  // escribir sol
  if(resolver(datos, c))
    cout << "SI\n";
  else 
    cout << "NO\n";


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
