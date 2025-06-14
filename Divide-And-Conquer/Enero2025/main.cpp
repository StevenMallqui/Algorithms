// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


/*
1. Implementacion de la funcion recursiva
2. Analisis justificado del coste de la funcion recursiva
  El espacio de soluciones está comprenndido entre los valores:
  - El doble del valor máximo del intervalo: si tenemos todos los drones posibles la capacidad mínima será el de llevar el paquete más pesado
  - El doble de la suma de todos los valores: si sólo hay unn dron habrá que cargarlo entero.

  Sobre ese espacio realizamos la búsqueda binaria y calculamos si es posible hacer con esa batería máxima y los drones que tennemos el reparto completo

  Coste: el tamaño del intervalo es donde M = f-i+1 (proporcional a la suma de valores) y n es el tamaño del vector

  T(N) =  {c              si M = 1}
          {T(M/2) + c'n   si M > 1}

  Coste O(n log M)
*/

bool es_posible(const int N, const vector<int>& pesos, const int d, int maxhA){
  int drones = 1, consumida = 0;
  for(int p : pesos){
    if(2*p + consumida <= maxhA){
      consumida += 2*p;
    }else{
      drones++;
      consumida = 2*p; 
    }
  }

  return drones <= d;
}


int dronesMinimos(const int N, const vector<int>& pesos, const int d, int maxhA, int sumhA){
  if(maxhA == sumhA){
    return maxhA;
  }else{
    int m = (maxhA + sumhA) / 2;
    if(es_posible(N, pesos, d, m)){
      return dronesMinimos(N, pesos, d, maxhA, m);
    }else{
      return dronesMinimos(N, pesos, d, m + 1, sumhA);
    }
  }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int N, d; cin >> N >> d;
  if (N == 0 && d == 0)
      return false;

  vector<int> pesos(N);
  int maxKG = 0, sumKG = 0;
  for(int i = 0; i < N; i++){
    cin >> pesos[i];
    maxKG = max(maxKG, pesos[i]);
    sumKG += pesos[i];
  }

  // escribir sol
  cout << dronesMinimos(N, pesos, d, 2*maxKG, 2*sumKG) << '\n';

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
