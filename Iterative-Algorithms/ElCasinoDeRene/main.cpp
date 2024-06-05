// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct Ganancia{
  long long int ganancia, inicio, fin;
};

// función que resuelve el problema
Ganancia resolver(vector<int> const& datos, int bm) {
  int inicio = -1, fin = -1;
  int maxGanancia = 0, gananciaActual = 0;
  int inicioActual = 0;
  
  for(int i = 0; i < datos.size(); i++){
    gananciaActual += datos[i];

    if(gananciaActual < 0){
      gananciaActual = 0;
      inicioActual = i + 1;
    }

    if(gananciaActual > maxGanancia && gananciaActual >= bm){
      maxGanancia = gananciaActual;
      inicio = inicioActual;
      fin = i;
    }
  }

  if(inicio == -1 || fin == -1){
    return {-1,0,0};
  }

  return{maxGanancia, inicio, fin};
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
  // leer los datos de la entrada
  int N, S, aux; cin >> N >> S;
  vector<int> datos;

  for(int i = 0; i < N; i++){
    cin >> aux;
    datos.push_back(aux);
  }
  
  Ganancia sol = resolver(datos, S);
  // escribir sol
  
  if(sol.ganancia == -1) cout << "NO COMPENSA\n";
  else cout << sol.ganancia << ' ' << sol.inicio <<' ' << sol.fin <<'\n';
  
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