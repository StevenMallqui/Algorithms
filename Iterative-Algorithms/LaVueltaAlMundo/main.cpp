// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int n; cin >> n;
  if (n == -1)
      return false;
  
  long long int kms = 0;
  vector<int> etapas(n);
  for(int i = 0; i < n; i++){
    cin >> etapas[i];
    kms += etapas[i];
  }

  int P; cin >> P;
  vector<int> p(P);
  for(int j = 0; j < P; j++){
    cin >> p[j];
    p[j]--;
  }

  vector<long long int> sol(n);
  sol[0] = kms;
  for(int i = 1; i < sol.size(); i++)
    sol[i] = sol[i-1] - etapas[i-1]; 

  for(int i = 0; i < P; i++){
    int dia = p[i];
    if(dia == n)
      cout << 0;
    else
      cout << sol[dia];
    cout << '\n';
  }

  cout << "---\n";

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
