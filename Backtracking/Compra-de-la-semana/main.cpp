#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


const int MAX_PROD_POR_SUPER = 3;


int actualiza(const int coste, vector<vector<int>> const& precios, const int i, const int k){
  return coste + precios[i][k];
}

int desactualiza(const int coste, vector<vector<int>> const& precios, const int i, const int k){
  return coste - precios[i][k];
}

bool es_solucion(const int n_prod, const int k, vector<int> const& sol, vector<int> const& marcador){
  return k == n_prod -1 && marcador[sol[k]] < MAX_PROD_POR_SUPER;
}

bool mejor(const int coste, const int mejor_coste){
  return mejor_coste == -1 || coste < mejor_coste;
}

bool es_completable(const int n_prod, const int k, vector<int> const& sol, vector<int> const& marcador){
  return k < n_prod -1 && marcador[sol[k]] < MAX_PROD_POR_SUPER;
} 

void coste_minimo(vector<vector<int>> const& precios, const int n_super, const int n_prod, const int k,)