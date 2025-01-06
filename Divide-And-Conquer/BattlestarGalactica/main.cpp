// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


// función que resuelve el problema
int reestructurar(vector<int> &naves, int ini, int fin) {
  if(fin <= ini){
    return 0;
  }else{
    int m = (ini+fin)/2;
    int iz = reestructurar(naves, ini, m);
    int der = reestructurar(naves, m+1, fin);

    int i = ini, j = m+1, cont = 0;
    while(i <= m && j <= fin){
      if(naves[i] > naves[j]){
        cont += (m - i + 1);
        j++;
      }else
        i++;
    }
    sort(naves.begin() + ini, naves.begin() + fin + 1);
    return iz + der + cont;
  }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int N; cin >> N;
  if (! std::cin)
      return false;
  
  vector<int> naves(N);
  for(int i = 0; i < N; i++)
    cin >> naves[i];

  // escribir sol
  cout << reestructurar(naves, 0, N-1) << '\n';
  
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