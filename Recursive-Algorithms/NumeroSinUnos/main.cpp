// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;


// función que resuelve el problema
bool sinUnos(int n){
  if(n < 10){
    if(n == 1)
      return false;
    return true;
  }else{
    if(n%10 == 1)
      return false;
    return sinUnos(n/10);
  }
}

int resolver(int n){
  if(n == 0){
    return 1;
  }else if(n < 10){
    return n;
  }else{
    if(sinUnos(n)){
      return resolver(n-1) + 1;
    }
    else{
      if(n%10 == 1 || sinUnos(n-1))
        return resolver(n-1);
      else
        return resolver(n-10);
    }
  }
}

// void resolver(int n) {
//   int cont = 0;
//   while (n >= 0)
//   {
//     if(sinUnos(n))
//       cont++;
//     n--;
//   }
//   cout << cont <<'\n';
// }

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