// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm> 
using namespace std;

struct Persona{
  string nombre;
  int altura;
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int N; cin >> N;
    if (! std::cin)
        return false;
    
    int altura; cin >> altura;
    Persona aux;
    vector<string> bajos;
    vector<string> altos;
    
    for(int i = 0; i < N; i++){
      cin >> aux.nombre >> aux.altura;
      if(aux.altura <= altura)
        bajos.push_back(aux.nombre);
      else
        altos.push_back(aux.nombre);
    }

    sort(bajos.begin(), bajos.end());
    sort(altos.begin(), altos.end());

    // escribir sol
    cout << "Bajos: ";
    for(string aux : bajos){
      cout << aux << ' ';
    }
    cout <<'\n';

    cout << "Altos: ";
    for(string aux : altos){
      cout << aux << ' ';
    }
    cout <<'\n';

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