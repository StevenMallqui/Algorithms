// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema
int resolver(const vector<int> &datos, int k, int l) {
  int segmentos = 0, i = k - 1, impares = 0, ini = 0;

  while(i < datos.size()){
    if(datos[i] % 2 != 0)
      impares++;
    
    if(impares <= l)
      segmentos++;

    if(datos[ini] % 2 != 0)
      impares--;

    i++;
    ini++;
  }

  return segmentos;  
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
  // leer los datos de la entrada
  int N, k, l, elem;
  cin >> N >> k >> l;

  vector<int> datos;
  for(int i = 0;i < N; i++){
    cin >> elem;
    datos.push_back(elem);
  }
  
  // escribir sol
  int segmentos;
  if(k == 0)
    segmentos = N + 1;
  else
    segmentos = resolver(datos, k, l);
  
  cout << segmentos << '\n';
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
     system("PAUSE");
     #endif
    
    return 0;
}