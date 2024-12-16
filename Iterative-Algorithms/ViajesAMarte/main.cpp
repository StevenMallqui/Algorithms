// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int n; cin >> n;
  if (! std::cin)
      return false;
  
  int altura; cin >> altura;
  vector<string> bajos; 
  vector<string> altos; 
  string nombre;
  int alt;
  for(int i = 0; i < n; i++){
    cin >> nombre >> alt;
    if(alt <= altura)
      bajos.push_back(nombre);
    else
      altos.push_back(nombre);
  }

  // escribir sol
  sort(bajos.begin(), bajos.end());
  sort(altos.begin(), altos.end());

  cout << "Bajos: ";
  for(int i = 0; i < bajos.size(); i++)
    cout << bajos[i] << ' ';

  cout << "\nAltos: ";
  for(int i = 0; i < altos.size(); i++)
    cout << altos[i] << ' ';

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