// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;


// función que resuelve el problema

void suma(int elem, int &acc){
  if(elem < 10)
    acc += elem;
  else{
    acc += elem%10;
    suma(elem/10, acc); 
  }
}

void sumanLoMismo(int n, int elem) {
  int acc = 0; 
  suma(elem, acc);
  if(n == acc)
    cout << elem << ' ';
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

  int N, num, elem, aux=0; cin >> N >> num;
  suma(num, aux);
  for(int i = 0; i < N; i++){
    cin >> elem;
    sumanLoMismo(aux, elem);
  }

  cout <<'\n';
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