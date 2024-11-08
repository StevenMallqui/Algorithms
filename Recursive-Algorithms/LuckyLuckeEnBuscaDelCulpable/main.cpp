// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


int buscarIz(int i, vector<int> &alturas, int A){
  if (i >= alturas.size() || alturas[i] > A) return -1;  
  if(alturas[i] == A)
    return i;
  return buscarIz(i+1, alturas, A); 
}

int buscarDer(int i, vector<int> &alturas, int A){
  if (i < 0 || alturas[i] < A) return -1; 
  if(alturas[i] == A) return i; 
  return buscarDer(i-1, alturas, A); 
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int N, A; cin >> N >> A;
  if (! std::cin)
      return false;
  
  vector<int> alturas(N); 
  for(int i = 0; i < N; i++){
    cin >> alturas[i];
  }

  int ini = buscarIz(0, alturas, A);
  if(ini != -1){
    cout << ini;
    int fin = buscarDer(N-1, alturas, A);
    if(ini < fin)
      cout << ' ' << fin;
    cout << '\n';
  }else{
    cout << "NO EXISTE\n";
  }
  
  // escribir sol
  
  
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