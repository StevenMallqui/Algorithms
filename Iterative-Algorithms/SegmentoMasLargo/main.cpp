// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema
int resolver(vector<int> const& datos) {
    int longitud = 1, cont = 1, auxLongitud = 1;

    if (datos.size() <= 2)
        longitud = datos.size();
    else {
        for (long unsigned int i = 1; i < datos.size(); i++) {
            if (datos[i - 1] < datos[i])
                cont++;
            else
                cont = 1;

            auxLongitud++;

            if (cont == 3) {
                longitud = max(auxLongitud - 1, longitud);
                auxLongitud = 2;
                cont = 2;
            } else {
                longitud = max(auxLongitud, longitud);
            }
        }
    }
  
    return longitud;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int N, aux; cin >> N;
    vector<int> datos;

    for(int i = 0; i < N; i++){
        cin >> aux;
        datos.push_back(aux);
    }
    
    int sol = resolver(datos);
    // escribir sol
    
    cout << sol <<'\n';
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