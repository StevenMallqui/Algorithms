// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema
void resolver(const vector<string> &datos, const string nationality) {
  int last = -1;
  
  for(int i = 0; i < datos.size(); i++)
    if(datos[i] == nationality)
      last = i;
    
  if(last == -1)
    cout << "NUNCA\n";
  else
    cout << datos.size() - last << '\n';
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int N; cin >> N;
  if (N == 0)
      return false;

  string nationality; cin >> nationality;
  vector<string> winners(N);

  for(int i = 0; i < N; i++){
    cin >> winners[i];
  }

  resolver(winners, nationality);

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
