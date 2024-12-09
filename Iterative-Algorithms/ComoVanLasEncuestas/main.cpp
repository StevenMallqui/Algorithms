// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


// función que resuelve el problema
pair<long long int, int> resolver(const vector<int>& datos) {
  
  int rep = 1, cont = 0, min = datos[0];
  long long suma = 0;

  for(int i = 1; i < datos.size(); i++){
    if(min > datos[i]){
      suma += (min * rep);
      min = datos[i];
      cont += rep;
      rep = 1;
    }else if(min == datos[i]){
      rep++;
    }else{
      suma += datos[i];
      cont++;
    }
  }

  return {suma, cont};
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

  // leer los datos de la entrada
  int N; cin >> N;
  vector<int> valores(N);
  for(int i = 0; i < N; i++)
    cin >> valores[i];
  
  pair<long long int, int> sol = resolver(valores);
  
  // escribir sol
  cout << sol.first << ' ' << sol.second << '\n';
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