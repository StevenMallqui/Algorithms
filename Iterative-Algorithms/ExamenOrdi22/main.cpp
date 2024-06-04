// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


/*
  N = datos.size()
  Coste O(N)
  P: Vi: 0<=i<N : v[i]>=0
*/
// función que resuelve el problema
int resolver(vector<int> datos) {
  int segmentos = 0, ini = 0;
  for(long unsigned int i = 0; i < datos.size(); i++){
  /*
  I: 0<=i<=datos.size() /\ ini = min j:0<=j<=i: pares(v,j,i) /\ segmentos = #(p, q): 0<=p<q<=i: todosPares(v, p, q)
  */
    if(datos[i] % 2 != 0)
      ini = i + 1;

    segmentos += i - ini + 1;
  }

  return segmentos;
}

/*
  Q: #(q,p): 0<=q<p<=datos.size(): todosPares(v, q, p)
  todosPares(v, q, p) = Vk:q<=k<p: P(v[k])
    P(x) = x%2==0
*/

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
  // leer los datos de la entrada
  
  int N, elem; cin >> N;
  vector<int> enteros;
  for(int i = 0; i < N; i++){
    cin >> elem;
    enteros.push_back(elem);
  }

  // escribir sol
  cout << resolver(enteros) << '\n';
    
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