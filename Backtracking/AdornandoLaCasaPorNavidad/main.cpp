// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

bool es_solucion(const int p, const int precioAct){
  return precioAct <= p; 
}

void vuelta_atras(const int n, const int p, const int k, const vector<pair<int, int>>& objetos, int& precioAct, int& superficieAct, int& superficieMax){
  
  if(k == n - 1){
    if(superficieAct > superficieMax)
      superficieMax = superficieAct;
  }else
    vuelta_atras(n, p, k + 1, objetos, precioAct, superficieAct, superficieMax);
  
  precioAct += objetos[k].first;
  superficieAct += objetos[k].second;
  if(es_solucion(p, precioAct)){
    if(k == n - 1){
      if(superficieAct > superficieMax)
        superficieMax = superficieAct;
    }else
      vuelta_atras(n, p, k + 1, objetos, precioAct, superficieAct, superficieMax);
  }
  precioAct -= objetos[k].first;
  superficieAct -= objetos[k].second;
}

// función que resuelve el problema
int resolver(const int n, const int p, const vector<pair<int, int>>& objetos) {
  //Marcadores
  int precioAct = 0;
  int superficieAct = 0;
  //Solucion
  int superficieMax = 0;

  vuelta_atras(n, p, 0, objetos, precioAct, superficieAct, superficieMax);
  return superficieMax;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int n; cin >> n;
  if (! std::cin)
      return false;
  
  int p; cin >> p;
  vector<pair<int, int>> objetos(n);
  for(int i = 0; i < n; i++){
    cin >> objetos[i].first >> objetos[i].second;
  }

  cout << resolver(n, p, objetos) <<'\n';
  
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