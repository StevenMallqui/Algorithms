// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

bool es_solucion(const int p, const int precioAct){
  return precioAct <= p; 
}

bool poda(const vector<pair<int,int>>& objetos, const int n, const int k, const int precioAct, const int p, const int superficieAct, const int superficieMax){
  int sup_restante = 0, coste = precioAct;
  int cont = k + 1;

  while(cont < n && coste < p){
    sup_restante += objetos[cont].first;
    coste += objetos[cont].first;
    cont++;
  }

  if(cont < n + 1 && coste > p){
    sup_restante -= objetos[cont - 1].second * (coste - p) / objetos[cont - 1].first;
  }

  return superficieAct + sup_restante > superficieMax;
}

void vuelta_atras(const int n, const int p, const int k, const vector<pair<int, int>>& objetos, int& precioAct, int& superficieAct, int& superficieMax){
  
  if(k == n - 1){
    if(superficieAct > superficieMax)
      superficieMax = superficieAct;
  }else
    if(poda(objetos, n, k, precioAct, p, superficieAct, superficieMax))
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
int resolver(const int n, const int p, const vector<pair<int, int>>& objetos, const int sup_inicial) {
  //Marcadores
  int precioAct = 0;
  int superficieAct = 0;
  //Solucion
  int superficieMax = sup_inicial;

  vuelta_atras(n, p, 0, objetos, precioAct, superficieAct, superficieMax);
  return superficieMax;
}

int inicializar_sol(const vector<pair<int, int>>& objetos, const int n, const int p){
  int sup_inicial = 0, coste = 0;
  int cont = 0;

  while(cont < n && coste < p){
    sup_inicial += objetos[cont].second;
    coste += objetos[cont].first;
    cont++;
  }

  if(cont < n + 1 && coste > p)
    sup_inicial -= objetos[cont - 1].second;

  return sup_inicial;
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

  sort(objetos.begin(), objetos.end(), [](const pair<int, int> o1, const pair<int, int> o2){return (float)o1.second/o1.first > (float)o2.second/o2.first; });

  int sup_inicial = inicializar_sol(objetos, n, p);

  cout << resolver(n, p, objetos, sup_inicial) <<'\n';
  
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