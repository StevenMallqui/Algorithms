// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;


// función que resuelve el problema
// bool sinUnos(int n){
//   if(n < 10){
//     if(n == 1)
//       return false;
//     return true;
//   }else{
//     if(n%10 == 1)
//       return false;
//     return sinUnos(n/10);
//   }
// }

int noUnosInter(int n){
  return pow(9, n);
}

int resolver(int n){
  int digits = to_string(n).size();
  cout << digits<<'\n';
  int noUnos = noUnosInter(digits);
  int upper = pow(10, digits);
  int result = noUnos - ((upper-n)/pow(10,digits-1));
  return result;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int n; cin >> n;
  if (! std::cin)
      return false;
  
  cout << resolver(n) <<'\n';
  
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