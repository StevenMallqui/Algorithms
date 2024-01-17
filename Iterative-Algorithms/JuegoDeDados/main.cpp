// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema
vector<int> resolver(vector<int> const& datos, int valorMax) {
  vector<int> solucion;
  vector<int> valores(valorMax + 1);
  int maximo = 0;

  for(int i = 0; i < datos.size(); i++){
    valores[datos[i]]++;
  }

  for(int i = 0; i < valores.size(); i++){
    maximo = max(valores[i], maximo);
  }

  for(int i = valores.size() - 1; i >= 0; i--){
    if(valores[i] == maximo)
      solucion.push_back(i);
  }

  return solucion;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
  int N, valorMax, aux; cin >> N;
  if (N == -1)
      return false;
  
  cin >> valorMax;
  vector<int> datos;

  for(int i = 0; i < N; i++){
    cin >> aux;
    datos.push_back(aux);
  }

  vector<int> sol = resolver(datos, valorMax);

  // escribir sol
  for(int aux : sol)
    cout << aux << ' ';
  
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
