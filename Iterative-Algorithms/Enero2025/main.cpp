// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

/*
1. Define el predicado

  P(v, q, p) = (sum i: p <= i < q /\ v[i]%2 = 0 : v[i]) > (sum i: p <= i < q /\ v[i]%2 != 0 : v[i])

2. Especifica la funnción que resuelve el problema

  Pre: {l >= 1 /\ 1 <= n <= 100000 /\ paratodo i: 0 <= i < n : v[i] >= 0}
  Q: c = # p, q: 0 <= p < q <= n /\ q-p = l : P(v, q, p)

3. Implementa el algoritmo iterativo
4. Invariante y función de cota
5. Coste asintótico en el caso peor y justificación 

  Coste: O(N), es decir, lineal con respecto al tamaño de la entrada N. Junto los bucles miran los valores como
  mucho dos veces y de operaciones son todas constantes.
*/


// función que resuelve el problema
int resolver(const int l, const vector<int> & v) {
  int sumPares = 0, sumImpares = 0, inter = 0;  

  if(l > v.size()) return 0;

  for(int i = 0; i < l; i++){
    /*
      Función de cota: l - i
      Inv: (0 <= i <= l) /\ (sumPares = sum j: 0 <= j < i: v[j] % 2 = 0) /\ (sumImpares = sum j: 0 <= j < i: v[j] % 2 = 1)    
    */
    if(v[i]%2 == 0)
      sumPares += v[i];
    else
      sumImpares += v[i];
  }
  
  if(sumPares > sumImpares) inter++;

  for(int i = l; i < v.size(); i++){
    /*
      Función de cota: N - i
      Inv: (l <= i <= N) /\ (sumP = sum j: i-l <= j < i: v[j] % 2 = 0) /\ (sumI = sum j: i-l <= j < i: v[j] % 2 = 1)
        inter = #(p, q): 0 <= p < q <= i /\ q-p = l : paresMayorImpares(v, p, q)
    */
    if(v[i-l]%2 == 0)
      sumPares -= v[i-l];
    else
      sumImpares -= v[i-l];
    
    if(v[i]%2 == 0)
      sumPares += v[i];
    else
      sumImpares += v[i];
    
    if(sumPares > sumImpares) inter++;
  }  

  return inter;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
  // leer los datos de la entrada
  int l, n; cin >> l >> n;

  vector<int> elems(n);
  for(int i = 0; i < n; i++)
    cin >> elems[i];
  
  // escribir sol
  cout << resolver(l, elems) << '\n';  
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