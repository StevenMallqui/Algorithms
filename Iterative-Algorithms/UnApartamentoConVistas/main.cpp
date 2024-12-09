// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema
struct edificio{
  string id;
  int altura;
  int alturaPiso;
};

vector<string> resolver(const vector<edificio>& edificios, int n) {
  vector<string> sol;
  int alturaMax = edificios[n-1].altura;
  if(edificios[n-1].alturaPiso != -1)
    sol.push_back(edificios[n-1].id);

  for(int i = edificios.size()-2; i >= 0; i--){
    if(edificios[i].alturaPiso != -1)
      if(edificios[i].alturaPiso > alturaMax)
        sol.push_back(edificios[i].id);
    alturaMax = max(alturaMax, edificios[i].altura);
  }

  return sol;  
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int n; cin >> n;
  if (n == 0)
    return false;
  
  vector<edificio> edificios(n);
  for(int i = 0; i < n; i++)
    cin >> edificios[i].id >> edificios[i].altura >> edificios[i].alturaPiso;

  vector<string> sol = resolver(edificios, n);
  
  // escribir sol
  if(sol.size() == 0)
    cout << "Ninguno";
  else{
    cout << sol.size() << '\n';
    for(string a : sol)
      cout << a << ' ';
  }
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
