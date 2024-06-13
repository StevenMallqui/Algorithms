// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema

int countLab(const vector<vector<int>> &datos, int x, int y, int tam){
  int count = 0;
  for(int i = x; i < x + tam; i++){
    for(int j = y; j < y + tam; j++){
      count += datos[i][j];
    }
  }
  return count;
}

bool equilibrado(const vector<vector<int>> &datos, int x, int y, int tam){
  if(tam == 1)
    return true;
  
  int centro = tam / 2;
  int totalLab = countLab(datos, x, y, tam);

  int totalCeldas = tam * tam;
  if(totalLab < totalCeldas / 4 - 1 || totalLab > 3 * totalCeldas / 4)
    return false;

  int labs[4];
  labs[0] = countLab(datos, x, y, centro);
  labs[1] = countLab(datos, x, y + centro, centro);
  labs[2] = countLab(datos, x + centro, y, centro);
  labs[3] = countLab(datos, x + centro, y + centro, centro);

  for(int i = 0; i < 4; i++){
    for(int j = i + 1; j < 4; j++){
      if(abs(labs[i] - labs[j]) > 2)
        return false;
    }
  }

  return equilibrado(datos, x, y, centro) && 
        equilibrado(datos, x, y + centro, centro) && 
        equilibrado(datos, x + centro, y, centro) && 
        equilibrado(datos, x + centro, y + centro, centro);
}


bool resolver(const vector<vector<int>> &datos) {
  return equilibrado(datos, 0, 0, datos.size());
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
  // leer los datos de la entrada
  int N; cin >> N;
  vector<vector<int>> v(N, vector<int>(N));

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
        cin >> v[i][j];
    }
  }

  // escribir sol
  cout << (resolver(v) ? "SI" : "NO") << '\n';
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