// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema
void resolver(const vector<int> &alturas, const int L) {
  int ini = 0, cont = 1, ant = alturas[0];
  vector<int> inicios;

  for(int i = 1; i < alturas.size(); i++){
    if(abs(alturas[i]-ant) <= 1)
      cont++;
    else{
      if(cont >= L)
        inicios.push_back(ini);
      cont = 1;
      ini = i;
    }
    ant = alturas[i];
  }

  if(cont >= L)
    inicios.push_back(ini);
    
  cout << inicios.size() << ' ';
  for(int i : inicios)
    cout << i << ' ';
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int N, L; cin >> N >> L;
  if (N == 0 && L == 0)
      return false;

  vector<int> alturas(N);
  for (int i = 0; i < N; i++) 
    cin >> alturas[i];

  // escribir sol
  resolver(alturas, L);
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
