// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema
char buscarFugado(const vector<char> &presos, int i, int f, char primero, char ultimo) {
  if(i == f - 1){
    if(presos[i] == primero)
      return ultimo;
    else return primero;
  }else{
    int m = (i+f)/2;
    char media = (primero+ultimo)/2;
    if(media == presos[m]){
      return buscarFugado(presos, m, f, media, ultimo);
    }else{
      return buscarFugado(presos, i, m, primero, media);
    }
  }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
  
  // leer los datos de la entrada
  char i, f; cin >> i >> f;
  int n = f - i;
  vector<char> presos(n);
  
  for(int i = 0; i < n; i++)
    cin >> presos[i];
  
  // escribir sol
  cout << buscarFugado(presos, 0, n, i, f) << '\n';  
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