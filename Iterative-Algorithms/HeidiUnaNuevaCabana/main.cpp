// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema
vector<int> resolver(const vector<int> &valores, int &maximo, const int l) {
  int n = valores.size();
  int maxDer = valores[n-1], cont = 1, i = n-2;
  vector<int> sol;

  while(i >= 0){
    maxDer = max(maxDer, valores[i]);
    if(valores[i+1] == valores[i] && valores[i] >= maxDer)
      cont++;
    else{
      if(cont >= l){
        sol.push_back(i+cont);
        maximo = max(maximo, cont);
      }
      cont = 1;
    }
    i--;
  }

  if(cont >= l){
    sol.push_back(cont-1);
    maximo = max(maximo, cont);
  }
  
  return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int n, l; cin >> n >> l;
  if (! std::cin)
      return false;
  
  vector<int> valores(n);
  for(int i = 0; i < n; i++)
    cin >> valores[i];

  int maximo = 0;
  vector<int> sol = resolver(valores, maximo, l);
  
  // escribir sol
  cout << maximo << ' ' << sol.size() << ' ';
  for(int a : sol)
    cout << a << ' ';
  
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