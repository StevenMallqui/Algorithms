// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;


int multiplicativoAux(int n, int &producto){
    int m = 0;
    
    if(n < 10){
        producto = n;
        if(n == 1)
            m = 1;
    }else{
        m = multiplicativoAux(n/10, producto);
        if(n%10 == producto)
            m++;
        producto = producto * n%10;
    }
    
    return m;
}

// función que resuelve el problema
int multiplicativos(int n) {
    int producto;
    return multiplicativoAux(n, producto);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n; cin >> n;
    // escribir sol
    cout << multiplicativos(n) << '\n';
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