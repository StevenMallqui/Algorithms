// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema
bool construirPresa(const vector<int> &alturas, const int c) {
  int n = alturas.size();
  int zona = alturas[0], longitud = 1;
  bool sol = false;

  for(int i = 1; i < n; i++){
    if(zona == alturas[i]){
      longitud++;
    }else{
      if(alturas[i] > zona && longitud >= c)
        sol = true;
      else{
        zona = alturas[i];
        longitud = 1;
      }
    }
  }

  return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int N, c; cin >> N >> c;
  if (N == 0 && c == 0)
      return false;

  vector<int> alturas(N);
  for(int i = 0; i < N; i++)
    cin >> alturas[i];


  if(construirPresa(alturas, c))
    cout << "SI";
  else
    cout << "NO";
  
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
