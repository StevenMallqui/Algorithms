// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;


pair<long long int, int> complementario_invertido(long long int n){
  if(n < 10){
    return {9 - n, 10};
  }else{
    pair<long long int, int> inv = complementario_invertido(n/10);

    int num_invertido = 9 - (n%10);
    num_invertido *= inv.second;
    num_invertido += inv.first;

    return {num_invertido, inv.second*10};
  }
}

long long int complementario(long long int n){
  if(n < 10){
    return 9 - n;
  }else{
    return complementario(n/10) * 10 + (9 - (n % 10));
  }
}

// función que resuelve el problema
pair<long long int, long long int> resolver(long long int n) {
  long long comp = complementario(n);
  pair<long long int, int> inv = complementario_invertido(n);
  return {comp, inv.first};
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
  // leer los datos de la entrada
  long long int n; cin >> n;

  pair<long long int, long long int> sol = resolver(n);

  cout << sol.first <<' ' << sol.second <<'\n';
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