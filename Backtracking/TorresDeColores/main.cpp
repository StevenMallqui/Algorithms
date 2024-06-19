// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

/*
0 : rojo
1 : verde
2 : azul
*/

void imprimirTorre(const vector<int>& sol){
  for(int i = 0; i < sol.size(); i++){
    if(sol[i] == 0)
      cout << "azul";
    else if(sol[i] == 1)
      cout << "rojo";
    else
      cout << "verde";
    
    if(i != sol.size())
      cout << ' ';
  }

  cout << '\n';
}

bool es_solucion(const vector<int>& sol, const int k, const vector<int>& piezas, const int r, const int a, const int v){
  if(piezas[1] > r || piezas[2] > v || piezas[0] > a)
    return false;
  if(k > 0 && (sol[k] == 2 && sol[k-1] == 2))
    return false;
  if(piezas[2] > piezas[0])
    return false;
  if(sol[0] != 1)
    return false;

  return true;
}

void vuelta_atras(const int n, int k, vector<int>& sol, vector<int>& piezas, const int r, const int a, const int v, bool& haySolucion){
  for(int i = 0; i < 3; i++){
    sol[k] = i;
    piezas[i]++; 
    if(es_solucion(sol, k, piezas, r, a, v)){
      if(k == n - 1){
        if(piezas[1] > (piezas[2] + piezas[0])){
          imprimirTorre(sol);
          haySolucion = true;
        }
      }else{
        vuelta_atras(n, k+1, sol, piezas, r, a, v, haySolucion);
      }
    }
    piezas[i]--; 
  }
}

void resolver(const int n, int a, int r, int v) {
  //Solucion
  vector<int> sol(n);
  vector<int> piezas(3, 0);
  bool haySolucion = false;
  vuelta_atras(n, 0, sol, piezas, r, a, v, haySolucion);

  if(!haySolucion)
    cout <<"SIN SOLUCION\n";

  cout <<'\n';
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int n, a, r, v; cin >> n >> a >> r >> v;
  if (n == 0 && a == 0 && r == 0 && v == 0)
      return false;

  resolver(n, a, r, v);

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
