// Nombre del alumno ..... Steven Mallqui Aguilar
// Usuario del Juez ...... F40


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


struct sol{
  bool extranyo = true;
  int sumP = 0, sumImp = 0;
  int prodP = 1, prodImp = 1;
};

// función que resuelve el problema
sol extrano(const vector<int> &elementos, int i, int f) {
  if(i >= f){
    sol aux;
    if(elementos[i]%2 == 0){
      aux.sumP += elementos[i];
      aux.prodP *= elementos[i];
    }else{
      aux.sumImp += elementos[i];
      aux.prodImp *= elementos[i];
    }
    return aux;
  }else{
    int m = (i+f)/2;
    sol iz = extrano(elementos, i, m);
    sol der = extrano(elementos, m+1, f);
    
    sol aux;
    if((iz.sumP + iz.prodImp) > (der.prodP + der.sumImp))
      aux.extranyo = false;
    
    aux.sumP = iz.sumP + der.sumP;
    aux.sumImp = iz.sumImp + der.sumImp;
    aux.prodP = iz.prodP * der.prodP;
    aux.prodImp = iz.prodImp * der.prodImp;
    aux.extranyo = aux.extranyo ? iz.extranyo || der.extranyo : false;
  
    return aux;
  }  
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
  // leer los datos de la entrada
  int N; cin >> N;
  vector<int> elementos(N);
  for(int i = 0; i < N; i++)
    cin >> elementos[i];
  
  // escribir sol
  if(extrano(elementos, 0, N-1).extranyo)
    cout << "SI";
  else
    cout << "NO";
  
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