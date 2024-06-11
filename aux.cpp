// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema
bool buscar(const vector<int>& datos, int inicio, int fin ,int valor){
  if(inicio > fin)
    return false;
  else{
    int pos = (inicio + fin) / 2;
    if(datos[pos] == valor)
      return true;
    
    if(datos[inicio] <= datos[pos - 1]){
      if(datos[inicio] <= valor && valor < datos[pos]){
        return buscar(datos, inicio, pos - 1, valor);
      }else{
        return buscar(datos, pos + 1, fin, valor);
      }
    }else if(datos[pos + 1] <= datos[fin]){
      if(valor > datos[pos] && valor <= datos[fin]){
        return buscar(datos, pos + 1, fin, valor);
      }else{
        return buscar(datos, inicio, pos - 1, valor);
      }
    }
  }
}

bool resolver(const vector<int>& datos, int valor) {
  return buscar(datos, 0, datos.size() - 1, valor);    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  int N; cin >> N;
  if (N == -1)
    return false;

  int valor, elem; cin >> valor;
  vector<int> v(N);
  for(int i = 0; i < N; i++){
    cin >> elem;
    v[i] = elem;
  }


  if(resolver(v, valor))
    cout << "SI";
  else 
    cout << "NO";

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
     #endif
    
    return 0;
}
