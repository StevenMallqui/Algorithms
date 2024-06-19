// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

bool es_solucion(const int k, const vector<char>& asignaturas, const vector<int>& prerrequisitos){
  return asignaturas[k] == 'N' && (asignaturas[prerrequisitos[k]] == 'A' || prerrequisitos[k] == -1);
}

void vuelta_atras(const int n, const int C, int k, const vector<char>& asignaturas, const vector<int>& prerrequisitos, const vector<int>& numeroCreditos, const vector<int>& costesMatriculacion, int& creditos, int& precioAct, int& precioMin){
  if(es_solucion(k, asignaturas, prerrequisitos)){
    creditos += numeroCreditos[k];
    precioAct += costesMatriculacion[k];
    if(k == n - 1){
      if(creditos >= C)
        if(precioAct < precioMin)
          precioMin = precioAct;
    }else{
        vuelta_atras(n, C, k+1, asignaturas, prerrequisitos, numeroCreditos, costesMatriculacion, creditos, precioAct, precioMin);
    } 
    creditos -= numeroCreditos[k];
    precioAct -= costesMatriculacion[k];
  }
  
  if(k == n - 1){
    if(creditos >= C)
      if(precioAct < precioMin)
        precioMin = precioAct;
  }else{
      vuelta_atras(n, C, k+1, asignaturas, prerrequisitos, numeroCreditos, costesMatriculacion, creditos, precioAct, precioMin);
  } 
}

// función que resuelve el problema
int resolver(const int n, const int C, const vector<char>& asignaturas, const vector<int>& prerrequisitos, const vector<int>& numeroCreditos, const vector<int>& costesMatriculacion) {
  //Marcadores
  int precioAct = 0;
  int creditos = 0;
  //Solucion
  int precioMin = INT_MAX;
  vuelta_atras(n, C, 0, asignaturas, prerrequisitos, numeroCreditos, costesMatriculacion, creditos, precioAct, precioMin);
  return precioMin;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
  // leer los datos de la entrada
  int n, C; cin >> n >> C;
  
  vector<char> asignaturas(n);
  for(int i = 0; i < n; i++)
    cin >> asignaturas[i];

  vector<int> prerrequisitos(n);
  for(int i = 0; i < n; i++)
    cin >> prerrequisitos[i];

  vector<int>numeroCreditos(n);
  for(int i = 0; i < n; i++)
    cin >> numeroCreditos[i];
  
  vector<int>costesMatriculacion(n);
  for(int i = 0; i < n; i++)
    cin >> costesMatriculacion[i];

  int sol = resolver(n, C, asignaturas, prerrequisitos, numeroCreditos, costesMatriculacion);  
  if(sol < INT_MAX)
    cout << sol;
  else
    cout << "NO";

  cout <<'\n';
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
     #endif
    
    return 0;
}