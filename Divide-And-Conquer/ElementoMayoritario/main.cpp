// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


struct segmento {
  int valor;
  int cantidad;
};

segmento combinar(const segmento& iz, const segmento& der) {
  segmento result;
  
  if (iz.valor == der.valor) {
      result.valor = iz.valor;
      result.cantidad = iz.cantidad + der.cantidad;
  } else {
      if (iz.cantidad > der.cantidad) {
          result.valor = iz.valor;
          result.cantidad = iz.cantidad - der.cantidad;
      } else {
          result.valor = der.valor;
          result.cantidad = der.cantidad - iz.cantidad;
      }
  }
  return result;
}

// Función recursiva de divide y vencerás
segmento mayoritarioAux(const vector<int>& elementos, int i, int f) {
  if (i == f) {
      return {elementos[i], 1};
  } else {
      int m = (i + f) / 2;
      segmento iz = mayoritarioAux(elementos, i, m);
      segmento der = mayoritarioAux(elementos, m + 1, f);
      return combinar(iz, der);
  }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
  vector<int> elementos;
  int num;
  cin >> num;
  while (num != 0) {
      elementos.push_back(num);
      cin >> num;
  }

  if (elementos.empty()) {
      cout << "NO" << endl;
      return;
  }

  sort(elementos.begin(), elementos.end());
  segmento res = mayoritarioAux(elementos, 0, elementos.size() - 1);
  int n = elementos.size();
  
  // Verificar si el candidato es mayoritario
  int count = 0;
  for (int i = 0; i < n; ++i)
    if (elementos[i] == res.valor)
      ++count;

  if (count > n / 2)
    cout << res.valor;
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