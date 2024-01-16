// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


bool cerosUnos(vector<int> const& datos, int ini, int fin){
  int ceros = 0, unos = 0;

  for(int i = ini; i < fin; i++){
    if(datos[i] == 0) ceros++;
    else if(datos[i] == 1) unos++;
  }
 
  return ceros == unos;
}


// función que resuelve el problema
int resolver(vector<int> const& datos, int l) {
  int segmentos = 1;
  int ceros = 0, unos = 0, cont = 0;

  for(long unsigned int i = l; i < datos.size(); i++){
    if(datos[i] == 0) ceros++;
    else if(datos[i] == 1) unos++;

    if(datos[i - l] == 0) ceros--;
    else if(datos[i - l] == 1) unos--;

    if(ceros == unos) segmentos++;
  }

  return segmentos;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int l, N, aux; cin >> l >> N;
    vector<int> datos;
    for(int i = 0; i < N; i++){
      cin >> aux;
      datos.push_back(aux);
    }
    
    int sol = resolver(datos, l);
    // escribir sol
    cout << sol << '\n';
    
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