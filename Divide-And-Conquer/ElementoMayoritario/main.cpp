// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct segmento{
  long long int inicio_long;
  long long int fin_long;
  long long int max_long;
  long long int inicio_valor;
  long long int fin_valor;
};

segmento combinar(const segmento& izq, const segmento& der){
  segmento result;
  result.inicio_valor = izq.inicio_valor;
  result.fin_valor = der.fin_valor;
  result.inicio_long = izq.inicio_long;
  result.fin_long = der.fin_long;
  result.max_long = max(izq.max_long, der.max_long);

  if(izq.fin_valor == der.inicio_valor){
    long long int combine_length = izq.fin_long + der.inicio_long;
    result.max_long = max(result.max_long, combine_length);

    if(izq.inicio_valor == izq.fin_valor)
      result.inicio_long = combine_length;
    
    if(der.inicio_valor == der.fin_valor)
      result.fin_long = combine_length;
  }
  return result;
}

segmento d_c(const vector<int>& v, int ini, int fin){
  if(ini > fin){
    return {0, 0, 0, -1, -1};
  }else if(ini == fin){
    return {1, 1, 1, v[ini], v[fin]};
  }else{
    int centro = (ini + fin) / 2;
    segmento izq = d_c(v, ini, centro);
    segmento der = d_c(v, centro + 1, fin);

    return combinar(izq, der);
  }
}

// función que resuelve el problema
pair<bool, int> resolver(const vector<int>& v) {
  long long int n = v.size();
  segmento a = d_c(v, 0, n-1);
  if(a.max_long > (n/2))
    return {true, a.inicio_valor};
  else
    return {false, -1};
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
  // leer los datos de la entrada
  vector<int> v;
  int elem;
  cin >> elem;
  while(elem != 0){
    v.push_back(elem);
    cin >> elem;
  }  

  sort(v.begin(), v.end());
  pair<bool, int> sol = resolver(v);
  if(sol.first)
    cout << sol.second;
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