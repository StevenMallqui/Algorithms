// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema
int contarSegmentos(const vector<int>& v, int l) {
    int n = v.size();
    int ceros = 0, unos = 0, count = 0;

    // Contamos ceros y unos en el primer segmento de longitud l
    for (int i = 0; i < l; ++i) {
        if (v[i] == 0) ceros++;
        if (v[i] == 1) unos++;
    }

    // Si el primer segmento tiene el mismo número de ceros que de unos, lo contamos
    if (ceros == unos) count++;

    // Deslizamiento de la ventana
    for (int i = 1; i <= n - l; ++i) {
        // Quitamos el elemento que sale de la ventana
        if (v[i - 1] == 0) ceros--;
        if (v[i - 1] == 1) unos--;

        // Añadimos el elemento que entra en la ventana
        if (v[i + l - 1] == 0) ceros++;
        if (v[i + l - 1] == 1) unos++;

        // Si el nuevo segmento tiene el mismo número de ceros que de unos, lo contamos
        if (ceros == unos) count++;
    }

    return count;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
  // leer los datos de la entrada
  int l, n; cin >> l >> n;
  vector<int> elementos(n);

  for(int i = 0; i < n; i++)
    cin >> elementos[i];

  cout << contarSegmentos(elementos, l) << '\n';  
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