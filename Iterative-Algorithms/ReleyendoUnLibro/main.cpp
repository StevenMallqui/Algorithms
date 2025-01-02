// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema
int maximo(const vector<int> &datos){
  int max = datos[0]; 
  for(int i = 1; i < datos.size(); i++){
    if(datos[i] > max)
      max = datos[i];
  }
  return max;
}

int resolver(const vector<int> &datos, const int L) {
  int max = maximo(datos);
  int sum = 0, contMax = 0;
  int sumMax = -1;
  int ini = 0, fin = 0, sol = 0;

  while(fin < L){
    sum += datos[fin];
    if(datos[fin] == max)
      contMax++;
    fin++;
  }

  if(contMax > 0)
    sumMax = sum;

  while(fin < datos.size()){
    sum -= datos[ini];
    if(datos[ini] == max)
      contMax--;
    ini++;

    sum += datos[fin];
    if(datos[fin] == max)
      contMax++;
    fin++;

    if(contMax > 0 && sum >= sumMax){
      sumMax = sum;
      sol = ini;
    }
  }

  return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int n, L; cin >> n >> L;
  if (n == 0 && L == 0)
      return false;

  vector<int> paginas(n);
  for(int i = 0; i < n; i++)
    cin >> paginas[i];

  // escribir sol
  cout << resolver(paginas, L) << '\n';

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
