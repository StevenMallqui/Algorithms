// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

/*
  Predicados auxiliares:
    N = calorias.size()
    M = valorNutri.size()
    sum(v, i, j) = SUMA k: i <= k <= j: v[k]

  Precondición:
    N == M /\ 1 <= N <= 10^6 /\ Vi: 0 <= i < N: calorias[i] <= u /\ Vi: 0 <= i < N: valorNutri[i] >= 0
  Postcondición:  
    maxValorNutri = max i,j: 0 <= i <= j < N && sum(calorias, i, j) <= u: sum(val, i, j) 
*/

// función que resuelve el problema
int resolver(vector<int> calorias, vector<int> valorNutri, int umbral) {
  int vNutri = 0, maxValorNutri = 0, kcals = 0, i = 0, ini = 0;

  while(i < calorias.size()){
    /*
      INV: 0<= i <= N /\ kcals = sum(calorias, ini, i - 1) /\ vNutri = sum(valorNutri, ini, i - 1)
      /\ maxValorNutri = max i,j: 0 <= i <= j < pos && sum(calorias, i, j) <= u: sum(valorNutri, i, j)

      COTA: 2N - ini - i
    */
    if(kcals + calorias[i] <= umbral){
      kcals += calorias[i];
      vNutri += valorNutri[i];
      if(vNutri > maxValorNutri)
        maxValorNutri = vNutri;
      
      i++;
    }else{
      kcals -= calorias[ini];
      vNutri -= valorNutri[ini];
      ini++;
    }
  }

  return maxValorNutri;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
  int N, elem, umbral; cin >> N;
  if (N == -1)
      return false;

  vector<int> calorias;
  for(int i = 0; i < N; i++){
    cin >> elem;
    calorias.push_back(elem);
  }

  vector<int> valorNutri;
  for(int i = 0; i < N; i++){
    cin >> elem;
    valorNutri.push_back(elem);
  }

  cin >> umbral;

  // escribir sol
  cout << resolver(calorias, valorNutri, umbral) <<'\n';

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
     system("PAUSE");
     #endif
    
    return 0;
}
