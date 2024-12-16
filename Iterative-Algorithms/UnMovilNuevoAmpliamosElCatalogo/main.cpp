// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema
vector<int> resolver(const vector<int> &l1, const vector<int> &l2) {
  vector<int> solucion;
  int i = 0, j = 0; 

  while(i < l1.size() && j < l2.size()){
    if(l1[i] < l2[j]){
      solucion.push_back(l1[i]);
      i++;
    }else if(l1[i] > l2[j]){
      solucion.push_back(l2[j]);
      j++;
    }else{
      solucion.push_back(l1[i]);
      solucion.push_back(l2[j]);
      i++;
      j++;
    }
  }

  while(i < l1.size()){
    solucion.push_back(l1[i]);
    i++;
  }

  while(j < l2.size()){
    solucion.push_back(l2[j]);
    j++;
  }
  
  return solucion;      
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
  // leer los datos de la entrada
  int n, m; cin >> n >> m;
  vector<int> l1(n);
  vector<int> l2(m);

  for(int i = 0; i < n; i++)
    cin >> l1[i];

  for(int i = 0; i < m; i++)
    cin >> l2[i];
  
  // escribir sol
  vector<int> sol = resolver(l1, l2);
  for(int i : sol)
    cout << i << ' ';

  cout << '\n';
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