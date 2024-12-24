// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema
int bongo(const vector<int> &carton, int i, int f, const int num) {
  if(i > f){
    return -1;
  }else{
    int m = (i+f)/2;
    if(num + m == carton[m])
      return carton[m];
    else if(num + m < carton[m])
      return bongo(carton, i, m-1, num);
    else
      return bongo(carton, m+1, f, num);
  }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

  // leer los datos de la entrada
  int n, num; cin >> n >> num;
  vector<int> carton(n);  
  for(int i = 0; i < n; i++)
    cin >> carton[i];

  // escribir sol  
  int sol = bongo(carton, 0, n-1, num);
  if(sol != -1)
    cout << sol;
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