// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema
vector<int> resolver(vector<int> const& datos1, vector<int> const& datos2) {
  vector<int> solucion;   
  int cont1 = 0, cont2 = 0;

  while(cont1 < datos1.size() && cont2 < datos2.size()){
    if(datos1[cont1] > datos2[cont2]){
      solucion.push_back(datos2[cont2]);
      cont2++;
    }else if(datos1[cont1] < datos2[cont2]){
      solucion.push_back(datos1[cont1]);
      cont1++;
    }else{
      solucion.push_back(datos1[cont1]);
      solucion.push_back(datos2[cont2]);
      cont1++;
      cont2++;
    }
  }

  for(int i = cont1; i < datos1.size(); i++){
    solucion.push_back(datos1[i]);
  }
  
  for(int i = cont2; i < datos2.size(); i++){
    solucion.push_back(datos2[i]);
  }

  return solucion;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int N1, N2, aux; cin >> N1 >> N2;
    vector<int> datos1, datos2;

    for(int i = 0; i < N1; i++){
        cin >> aux;
        datos1.push_back(aux); 
    }

    for(int i = 0; i < N2; i++){
        cin >> aux;
        datos2.push_back(aux);
    }
    
    vector<int> sol = resolver(datos1, datos2);
    // escribir sol
    for(int aux : sol)
        cout << aux << ' ';

    cout << '\n';
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