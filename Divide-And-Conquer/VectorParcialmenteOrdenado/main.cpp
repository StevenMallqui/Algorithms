// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct solucion{
  bool ordenado;
  int max, min;
};

// función que resuelve el problema
solucion parcialmenteOrdenado(const vector<int> &elementos, int i, int f){
  if(i == f){
    return {true, elementos[i], elementos[f]};
  }else{
    int m = (i+f)/2;
    solucion iz = parcialmenteOrdenado(elementos, i, m);
    solucion der = parcialmenteOrdenado(elementos, m+1, f);
    bool b = iz.min <= der.min && der.max >= iz.max;
    return {b && iz.ordenado && der.ordenado, der.max, iz.min};
  }  
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int num; cin >> num;
  if (num == 0)
      return false;

  vector<int> elementos;
  while(num != 0){
    elementos.push_back(num);
    cin >> num;
  }

  // escribir sol
  solucion sol = parcialmenteOrdenado(elementos, 0, elementos.size()-1);
  if(sol.ordenado)
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
