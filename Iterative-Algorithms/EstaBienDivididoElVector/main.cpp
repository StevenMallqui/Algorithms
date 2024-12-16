// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema
bool resolver(const vector<int> &datos, const int p) {
  bool divido = true;
  int maximo = datos[0];
  for(int i = 1; i <= p; i++)
    maximo = max(maximo, datos[i]);
  
  for(int i = p + 1; i < datos.size() && divido; i++)
    if(datos[i] <= maximo)
      divido = false;

  return divido;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
  // leer los datos de la entrada
  int n, p; cin >> n >> p;
  vector<int> datos(n);
  for(int i = 0; i < n; i++)
    cin >> datos[i];
  
  // escribir sol
  if(resolver(datos, p))
    cout << "SI";
  else
    cout << "NO";
  
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