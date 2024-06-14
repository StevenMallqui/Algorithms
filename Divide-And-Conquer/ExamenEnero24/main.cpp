// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema
int picudo(const vector<int> &v, int inicio, int fin){
  if(inicio == fin - 1)
    return v[inicio + 1] - v[inicio];
  else{
    int centro = (inicio + fin) / 2;
    int izq = picudo(v, inicio, centro);
    int der = picudo(v, centro, fin);

    return max((v[centro + 1] - v[centro]), max(izq, der));
  }
}


int resolver(const vector<int> &v) {
  return picudo(v, 0 , v.size()-1);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
  // leer los datos de la entrada
  int N; cin >> N;
  vector<int> v(N);
  for(int i = 0; i < N; i++){
    cin >> v[i];
  }

  cout << resolver(v) <<'\n';
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