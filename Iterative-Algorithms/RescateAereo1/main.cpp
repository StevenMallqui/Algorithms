// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
void resolver(const vector<int> &datos, const int &t, const int &n) {
  int ini = 0, fin = 0, maxLong = 0, curLong = 0; 

  for(int i = 0; i < n; i++){
    if(datos[i] > t){
      curLong++;
    }else{
      if(curLong > maxLong){
        ini = i - curLong;
        fin = i - 1;
        maxLong = curLong;
      }
      curLong = 0;
    }
  }

  if(curLong > maxLong) {
    ini = n - curLong;
    fin = n - 1;
  }

  cout << ini <<' ' << fin << '\n';
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
  // leer los datos de la entrada
  int n, t; cin >> n >> t;
  vector<int> heights(n);

  for(int i = 0; i < n; i++){
    cin >> heights[i];
  }
  
  // escribir sol
  resolver(heights, t, n);

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