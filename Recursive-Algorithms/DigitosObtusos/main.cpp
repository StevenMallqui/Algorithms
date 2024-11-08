/*
 * Escribir el nombre y usuario del juez de cada mmiembro de la pareja:
 *   Nombre y usuario: OSCAR ALVAREZ ESCOBAR FAL-E03
 *   Nombre y usuario: STEVEN MALLQUI AGUILAR FAL-E40
 *
 * Explicad brevemente el algoritmo:
 *
 *
 */

#include <fstream>
#include <iostream>

using namespace std;

// No olvides la recurrencia que corresponde al coste de la función recursiva utilizando el número de dígitos de n como tamaño del problema.
// Indica también a qué orden de complejidad asintótica pertenece dicho coste.


//Escribe la función recursiva que resuelve el problema. Puedes definir los structs y funciones auxiliares que necesites
/*
T(n) = {  c1    si n < 10} 
       {  1T(n-1) + c2*n^0 si n > 10}
       a = 1 -> T(n) = O(n^0+1) = O(n)
       El coste esta en orden de O(n) siendo n el numero de digitos del numero de entrada.
*/


int obtusos(int n, int &producto) {
  if(n < 10){
    if(n%2 == 1){
      producto *= n;
      if(n == 1) return 1;
      return 0;
    }else 
      return 0;
  }else{
    int cont = obtusos(n/10, producto);
    int unidad = n%10;
    if (producto % 10 == unidad)
          cont++;
    if (unidad % 2 == 1)
        producto *= unidad;

    return cont;
  }
}

void resuelveCaso() {
    int n;
    cin >> n;

    //Llama a la función
    //Escribe el resultado
    int producto = 1;
    cout << obtusos(n, producto) << '\n';
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("1.in");  //o cambia el nombre por el fichero que te descargues
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}

 