// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


pair<bool, int> degradado(const vector<int>& fila, int ini, int fin){
  if(ini == fin - 1){
    return {true, fila[ini]};
  }else{
    int m = (ini + fin)/2;
    pair<bool, int> izq = degradado(fila, ini, m);
    pair<bool, int> der = degradado(fila, m, fin);

    return {izq.first && der.first && izq.second < der.second, izq.second + der.second};
  }
}

// función que resuelve el problema
bool resolver(const vector<vector<int>>& imagen, const int n, const int m) {
    bool deg = true;
    int cont = 0;

    while(deg && cont < n){
      deg = degradado(imagen[cont], 0, m).first;
      cont++;
    }

    return deg;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n; cin >> n;
    if (! std::cin)
        return false;
    int m; cin >> m;

    vector<vector<int>> imagen(n, vector<int>(m));
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        cin >> imagen[i][j];
      }
    }


    if(resolver(imagen, n, m))
      cout << "SI";
    else
      cout << "NO";
    
    cout << "\n";
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