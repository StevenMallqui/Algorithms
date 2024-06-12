// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

/*
bool disperso(const vector<int>& nums, int K, int start, int end) {
    // Caso base: una secuencia de un solo elemento siempre es suficientemente dispersa
    if (start >= end)
        return true;

    int first = nums[start];
    int last = nums[end];
    
    if (abs(last - first) < K) 
        return false;
    
    int mid = (start + end) / 2;
    
    // Verificar recursivamente ambas mitades
    return disperso(nums, K, start, mid) && disperso(nums, K, mid + 1, end);
}

*/

bool disperso(const vector<int>& v, int inicio, int fin, int D){
  int n = fin - inicio;
  if(n < 2){
    return (n == 0) ? true : abs(v[inicio] - v[fin]) >= D; 
  }else{
    int mitad = (inicio + fin) / 2;
    bool first = disperso(v, inicio, mitad, D);
    bool second = disperso(v, mitad + 1, fin, D);

    return first && second && abs(v[inicio] - v[fin]) >= D;
  }
}

// función que resuelve el problema
bool resolver(const vector<int> datos, int D) {
    return disperso(datos, 0, datos.size() - 1, D);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int N; cin >> N;
  if (! std::cin)
      return false;
  
  int D, elem; cin >> D;
  vector<int> v(N);
  for(int i = 0; i < N; i++){
    cin >> elem;
    v[i] = elem;
  }


  if(resolver(v, D))
    cout << "SI\n";
  else
    cout << "NO\n";
  
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