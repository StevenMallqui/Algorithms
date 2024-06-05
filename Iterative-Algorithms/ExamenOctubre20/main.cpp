// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


struct Pastoso{
  bool pastoso = false; 
  int pos = -1;
};

// función que resuelve el problema
Pastoso resolver(const vector<int>& datos) {
  Pastoso p;
  int i = datos.size() - 1, sum = 0;

  while(i >= 0 && !p.pastoso){
    if(sum == datos[i]){
      p.pastoso = true;
      p.pos = i;
    }
    else
      sum += datos[i];
    i--;
  }

  return p;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
  // leer los datos de la entrada
  int N, elem; cin >> N;

  vector<int> datos;
  for(int i = 0; i < N; i++){
    cin >> elem;
    datos.push_back(elem);
  }
  
  // escribir sol
  Pastoso p = resolver(datos);

  if(p.pastoso)
    cout << "Si " << p.pos << '\n';
  else  
    cout << "No \n";
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
     #endif
    
    return 0;
}