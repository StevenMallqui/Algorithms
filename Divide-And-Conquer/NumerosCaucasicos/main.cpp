// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

bool caucasico(const vector<int> &datos, int inicio, int fin, int &pares){
  if(fin - inicio == 1){
    if(datos[inicio] % 2 == 0)
      pares = 1;
    else
      pares = 0;
    return true;
  }else{
    int centro = (inicio + fin) / 2;
    int paresIz, paresDer;
    bool izq = caucasico(datos, inicio, centro, paresIz);
    bool der = caucasico(datos, centro, fin, paresDer);
    pares = paresIz + paresDer;

    return izq && der && (abs(paresIz-paresDer) <= 2);
  }
}

// función que resuelve el problema
bool resolver(const vector<int> &datos){
  int pares;
  return caucasico(datos, 0, datos.size(), pares);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int N; cin >> N;
  if (N == 0)
      return false;
  vector<int> v(N);
  for(int i = 0; i < N; i++){
    cin >> v[i];
  }

  if(resolver(v))
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
