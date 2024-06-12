// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct segmento{
  int inicio_long;
  int fin_long;
  int max_long;
  int inicio_valor;
  int fin_valor;
};

segmento combinar(const segmento& izq, const segmento& der){
  segmento result;
  result.inicio_valor = izq.inicio_valor;
  result.fin_valor = der.fin_valor;
  result.inicio_long = izq.inicio_long;
  result.fin_long = der.fin_long;
  result.max_long = max(izq.max_long, der.max_long);

  if(izq.fin_valor == der.inicio_valor){
    int combine_length = izq.fin_long + der.inicio_long;
    result.max_long = max(result.max_long, combine_length);

    if(izq.inicio_valor == izq.fin_valor)
      result.inicio_long = combine_length;

    if(der.inicio_valor == der.fin_valor)
      result.fin_long = combine_length;
  }

  return result;
}

segmento escalonMasLargo(const vector<int>& datos, int inicio, int fin){
  if(inicio == fin){
    return {1, 1, 1, datos[inicio], datos[fin]};
  }else{
    int centro = (inicio + fin) / 2;
    segmento izq = escalonMasLargo(datos, inicio, centro);
    segmento der = escalonMasLargo(datos, centro + 1, fin);

    return combinar(izq, der);
  }
}  

// función que resuelve el problema
segmento resolver(const vector<int>& datos) {
  return escalonMasLargo(datos, 0, datos.size()-1);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int N; cin >> N;
  if (N == 0)
      return false;

  int elem;
  vector<int> v(N);
  for(int i = 0; i < N; i++){
    cin >> elem;
    v[i] = elem;
  }

  cout << resolver(v).max_long <<'\n';

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
     #endif
    
    return 0;
}
