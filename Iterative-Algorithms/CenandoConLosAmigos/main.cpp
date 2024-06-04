// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct Gocho{
  int suma = 0, inicio = 0, longitud = 0;
};

// función que resuelve el problema
Gocho resolver(const vector<int> & datos) {
    Gocho amigo;
    int i = 0, sum = 0, ini = 0, longitud = 0;
    
    while(i < datos.size()){
        if(sum + datos[i] <= 0){
            ini = i + 1;
            sum = 0;
        }else{
            sum += datos[i];
            longitud = i - ini + 1;
            if((sum > amigo.suma) || (sum == amigo.suma && longitud < amigo.longitud)){
                amigo.suma = sum;
                amigo.inicio = ini;
                amigo.longitud = longitud;
            }
        }
        i++;
    }

    return amigo;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int N, elem; cin >> N;
    if (! std::cin)
        return false;
    
    vector<int> datos;
    for(int i = 0; i < N; i++){
        cin >> elem;
        datos.push_back(elem);
    }

    Gocho sol = resolver(datos);
    
    // escribir sol
    cout << sol.suma <<' ' << sol.inicio <<' ' << sol.longitud <<'\n';
    
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