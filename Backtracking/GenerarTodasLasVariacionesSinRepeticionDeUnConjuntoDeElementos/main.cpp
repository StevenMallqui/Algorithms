// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

char intToChar(const int num){
  return 'a' + num;
}


void backtracking(int k, string& palabra, int m, int n, vector<bool>& usados){
  for(int i = 0; i < m; i++){
    if(!usados[i]){
      palabra += intToChar(i);
      usados[i] = true;

      if(k == n - 1)
        cout << palabra <<'\n';
      else
        backtracking(k+1, palabra, m, n, usados);
      
      usados[i] = false;
      palabra.pop_back();
    }
  }
}
   
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int m; cin >> m;
  if (! std::cin)
      return false;
  
  int n; cin >> n;

  // escribir sol
  string palabra;
  vector<bool> usados(m, false);
  backtracking(0, palabra, m, n, usados);
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