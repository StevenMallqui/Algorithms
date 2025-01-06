// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
bool caucasico(const vector<int> &valores, int i, int f, int &pares) {
  if(f <= i){
    if(valores[i]%2 == 0)
      pares = 1;
    else
      pares = 0;
    return true;
  }else{
    int m = (i+f)/2;
    int paresIz, paresDer;
    bool iz = caucasico(valores, i, m, paresIz);
    bool der = caucasico(valores, m+1, f, paresDer);
    
    pares = paresIz + paresDer;
    return iz && der && (abs(paresIz - paresDer) <= 2);
  }  
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int N; cin >> N;
  if (N == 0)
      return false;

  vector<int> valores(N);
  for(int i = 0; i < N; i++)
    cin >> valores[i];
  
  int pares;
  if(caucasico(valores, 0, N-1, pares))
    cout << "SI";
  else
    cout << "NO";

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
