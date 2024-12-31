// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct cinta{
  char t;
  int longitud;

  bool operator<(const cinta& c) const{
    return longitud < c.longitud;
  }
};

void cambiar(vector<cinta> &cintas, int c1, int c2){
  cinta aux = cintas[c2];
  cintas[c2] = cintas[c1];
  cintas[c1] = aux;
}

// función que resuelve el problema
void resolver(vector<cinta> &cintas, int &inicio, int &final) {
  inicio = 0; final = 0;
  int pRojo = cintas.size();
  
  while(final != pRojo){
    switch (cintas[final].t){
      case 'a':{
        cambiar(cintas, final, inicio);
        inicio++;
        final++;
      }
        break;
      case 'r':{
        cambiar(cintas, final, pRojo-1);
        pRojo--;
      }
        break;
      case 'v':{
        final++;
      }
        break;
    }
  }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int n; cin >> n;
  if (! std::cin)
      return false;
  
  vector<cinta> cintas(n);
  for(int i = 0; i < n; i++)
    cin >> cintas[i].t >> cintas[i].longitud;

  int inicio, final;
  resolver(cintas, inicio, final);
  sort(cintas.begin(), cintas.begin() + inicio);
  sort(cintas.begin() + inicio, cintas.begin() + final);
  sort(cintas.begin() + final, cintas.end());

  cout << "Azules: ";
  for(int i = 0; i < inicio; i++)
    cout << cintas[i].longitud << ' ';

  cout << "\nVerdes: ";
  for(int i = inicio; i < final; i++)
    cout << cintas[i].longitud << ' ';

  cout << "\nRojas: ";
  for(int i = final; i < n; i++)
    cout << cintas[i].longitud << ' ';

  cout << '\n';

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