// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;


// función que resuelve el problema
int complementario(int n) {
  if(n < 10){
    return 9 - n;
  }else{  
    int lastD = n%10;
    lastD = 9 - lastD;
    return (complementario(n/10) * 10) + lastD;
  }
}

int inverso(int n, int &factor){
  if(n < 10){
    factor = 10;
    return 9 - n;
  }else{ 
    int inv = inverso(n/10, factor);
    int lastD = n%10;
    lastD = 9 - lastD;
    int num = lastD * factor + inv; 
    factor *= 10;
    return num; 
  }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

  // leer los datos de la entrada
  int n; cin >> n;  
  
  // escribir sol
  int factor = 0;
  cout << complementario(n) << ' ' << inverso(n, factor) << '\n';
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