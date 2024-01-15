// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct Intervalo{
  int inicio = 0, fin = 0, tam = 0;
};

// función que resuelve el problema
Intervalo resolver(vector<int> const& datos, int tam) {

 long unsigned int cont = 0;
  Intervalo solucion;
  int auxInicio, auxFin;

  while(cont < datos.size()){
    if(datos[cont] > tam){
      auxInicio = cont; auxFin = cont;
      cont++;
      while(cont < datos.size() && datos[cont] > tam){
        auxFin++;;
        cont++;
      }
      if(auxFin - auxInicio > solucion.fin - solucion.inicio){
        solucion.inicio = auxInicio; solucion.fin = auxFin; 
      }
    }else
      cont++;
  }

  return solucion;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
  // leer los datos de la entrada
  int N, tam, aux; cin >> N >> tam;
  vector<int> datos;

  for(int i = 0; i < N; i++){
    cin >> aux;
    datos.push_back(aux);
  } 
  
  Intervalo  sol = resolver(datos, tam);
  // escribir sol
  cout << sol.inicio <<' ' << sol.fin <<'\n';
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