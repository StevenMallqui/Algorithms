// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F53


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

using matriz = vector<vector<bool>>;
using marcador = vector<bool>;

int d_asc(const int f, const int c, const int n){
  return c + f + 2 * n - 1;
}

int d_desc(const int f, const int c, const int n){
  return c - f + n - 1;
}

bool es_solucion(const matriz& invalidas, const int fila, const int col, const int n, vector<bool>& filas, vector<bool>& diagReinas){
  return !invalidas[fila][col] && !filas[fila] && !diagReinas[d_asc(fila, col, n)] && !diagReinas[d_desc(fila, col, n)]; 
}

bool hay_torres_diag(const int k, const int n, const vector<int>& sol, const vector<bool>& diagTorres){
  return diagTorres[d_asc(sol[k], k, n)] || diagTorres[d_desc(sol[k], k, n)];
}

void marcar_desmarcar(bool m_fila, bool m_diag_asc, bool m_diag_desc, vector<bool>& filas, vector<bool>& diag, const int i, const int k, const int N){
  filas[i] = m_fila;
  diag[d_asc(i, k, N)] = m_diag_asc;
  diag[d_desc(i, k, N)] = m_diag_desc;
}

void vuelta_atras(int& torres, int& reinas, const int N, const matriz& invalidas, int k, vector<int>& sol, int& combinaciones, vector<bool>& filas, vector<bool>& diagTorres, vector<bool>& diagReinas){
  for(int i = 0; i < N; i++){
    if(es_solucion(invalidas, i, k, N, filas, diagReinas)){
      sol[k] = i;
      if(torres > 0){
        torres--;
        if(k == N -1){
          combinaciones++;
        }else{
          bool anterior_asc = diagTorres[d_asc(i, k, N)];
          bool anterior_desc = diagTorres[d_desc(i, k, N)];
          marcar_desmarcar(true, true, true, filas, diagTorres, i, k, N);
          vuelta_atras(torres, reinas, N, invalidas, k + 1, sol, combinaciones, filas, diagTorres, diagReinas);
          marcar_desmarcar(false, anterior_asc, anterior_desc, filas, diagTorres, i, k, N);
        }
        torres++;
      }
      if(reinas > 0){
        reinas--;
        if(!hay_torres_diag(k, N, sol, diagTorres)){
          if(k == N - 1){
            combinaciones++;
          }else{
            marcar_desmarcar(true, true, true, filas, diagReinas, i, k, N);
            vuelta_atras(torres, reinas, N, invalidas, k + 1, sol, combinaciones, filas, diagTorres, diagReinas);
            marcar_desmarcar(false, false, false, filas, diagReinas, i, k, N);
          }
        }
        reinas++;
      }
    }
  }
}

// función que resuelve el problema
int resolver(const int T, const int R, const int N, const matriz& invalidas) {
  //Marcadores
  int torres = T;
  int reinas = R;
  //Solucion
  vector<int> sol(N);
  int combinaciones = 0;
  if(N > 0){
    vector<bool> filas(N, false);
    vector<bool> diagTorres(4* N - 2, false);
    vector<bool> diagReinas(4* N - 2, false);

    vuelta_atras(torres, reinas, N, invalidas, 0, sol, combinaciones, filas, diagTorres, diagReinas);
  }

  return combinaciones;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int T; cin >> T;
  if (! std::cin)
      return false;
  int R; cin >> R;
  int N = T+R;
  int I; cin >> I;
  matriz invalidas(N, vector<bool>(N ,false));
  int fila, col;
  for(int i = 0; i < I; i++){
    cin >> fila >> col;
    invalidas[fila - 1][col - 1] = true;
  }

  cout << resolver(T, R, N, invalidas) <<'\n';
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