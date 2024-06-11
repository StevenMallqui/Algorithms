// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema

int buscarIz(vector<int> datos, int inicio, int fin, int altura){
  int pos = -1;
  if(inicio <= fin){
    int centro = (inicio + fin) / 2;
    if((centro == 0 || altura > datos[centro - 1]) && datos[centro] == altura){
      pos = centro;
    }else if(datos[centro] < altura){
      pos = buscarIz(datos, centro + 1, fin, altura);
    }else{
      pos = buscarIz(datos, inicio, centro - 1, altura);
    }
  }
  return pos;
}

int buscarDer(vector<int> datos, int inicio, int fin, int altura){
  int pos = -1;
  if(inicio <= fin){
    int centro = (inicio + fin) / 2;
    if((centro == datos.size() - 1 || altura < datos[centro + 1]) && datos[centro] == altura){
      pos = centro;
    }else if(datos[centro] > altura){
      pos = buscarDer(datos, inicio, centro - 1, altura);
    }else{
      pos = buscarDer(datos, centro + 1, fin, altura);
    }
  }
  return pos;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada

  int N; cin >> N;
  if (! std::cin)
      return false;
  
  int altura, elem; cin >> altura;
  vector<int> sospechosos(N);
  for(int i = 0; i < N; i++){
    cin >> elem;
    sospechosos[i] = elem;
  }

  int first = buscarIz(sospechosos, 0, sospechosos.size() - 1, altura);
  if(first == -1){
    cout << "NO EXISTE";
  }else{
    int last = buscarDer(sospechosos, 0, sospechosos.size() - 1, altura);
    if(first == last)
      cout << first;
    else{
      cout << first <<" " << last;
    }
  }

  cout <<'\n';
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