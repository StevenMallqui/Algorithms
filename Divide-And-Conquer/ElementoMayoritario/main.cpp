// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

bool comprobar(const vector<int> &elementos, int x, int c, int f){
  int veces = 0;
  for(int i = c; i <= f; i++)
    if(elementos[i] == x)
      veces++;

  return veces > (f-c+1)/2;
}

pair<bool, int> mayoritario(const vector<int> &elementos, int c, int f){
  if(c == f)
    return {true, elementos[c]};
  else{
    int m = (c+f)/2;
    pair<bool, int> iz = mayoritario(elementos, c, m);
    pair<bool, int> der = mayoritario(elementos, m+1, f);
    bool existe = false;
    int mayor;
    if(iz.first){
      existe = comprobar(elementos, iz.second, c, f);
      mayor = iz.second;
    }

    if(!existe && der.first){
      existe = comprobar(elementos, der.second, c, f);
      mayor = der.second;
    }

    return {existe, mayor};
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

  pair<bool, int> m = mayoritario(elementos, 0, elementos.size()-1);
  if(m.first)
    cout << m.second;
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