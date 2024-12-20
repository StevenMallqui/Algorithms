// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema
bool resolver(const vector<int> &datos, const int d) {
  int dCur = d-1;
  for(int i = 1; i < datos.size(); i++){
    int diferencia = datos[i] - datos[i-1];
    if(diferencia == 0 || diferencia == 1){
      if(diferencia == 0)
        dCur--;
      else
        dCur = d-1;
      
      if(dCur < 0) return false;
    }else 
      return false;
  }
  return true;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
  
  // leer los datos de la entrada
  int d, n; cin >> d >> n;
  vector<int> elementos(n);
  for(int i = 0; i < n; i++)
    cin >> elementos[i];

  // escribir sol
  if(n > 0){
    if(resolver(elementos, d))
      cout << "SI";
    else
      cout << "NO";
  }else
    cout << "SI";

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