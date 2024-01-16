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
    int N = max(datos1.size(), datos2.size()), i = 0;


    while(i < datos1.size() && i < datos2.size()){
        if(datos1[i] < datos2[i]){
            solucion.push_back(datos1[i]);
            solucion.push_back(datos2[i]);
        }else{
            solucion.push_back(datos2[i]);
            solucion.push_back(datos1[i]);
        }
        i++;
    }

    if(i != N){
        if(datos1.size() > datos2.size()){
            for(int j = i; j < datos1.size(); j++){
                solucion.push_back(datos1[i]);
            }
        }else{
            for(int j = i; j < datos2.size(); j++){
                solucion.push_back(datos2[i]);
            }
        }
    }
    // if(datos1.size() > datos2.size()){
    //     N = datos1.size();
    //     j = datos2.size();
    // }else if(datos1.size() < datos2.size()){
    //     N = datos2.size();
    //     j = datos2.size();
    // }else{
    //     N = datos1.size();
    // }    

    // for(int i = 0; i < N; i++){
    //     if(i < datos1.size()){

    //     }
    // }

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