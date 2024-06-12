#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

long long dp[20][2][2];
vector<int> digits;

// Función que implementa la DP para contar números sin '1'
long long countNumbersWithout1(size_t pos, bool limit, bool leadingZero) {
    if (pos == digits.size()) {
        return 1;  // Si llegamos al final, es un número válido
    }
    if (dp[pos][limit][leadingZero] != -1) {
        return dp[pos][limit][leadingZero];
    }
    
    int maxDigit = limit ? digits[pos] : 9;
    long long result = 0;
    
    for (int d = 0; d <= maxDigit; ++d) {
        if (d == 1) continue;  // No queremos '1' en el número
        result += countNumbersWithout1(pos + 1, limit && (d == maxDigit), leadingZero && (d == 0));
    }
    
    return dp[pos][limit][leadingZero] = result;
}

// Función que convierte un número a una lista de dígitos y llama a la DP
long long solve(long long n) {
    if (n < 0) return 0;
    digits.clear();
    while (n > 0) {
        digits.push_back(n % 10);
        n /= 10;
    }
    reverse(digits.begin(), digits.end());
    
    memset(dp, -1, sizeof(dp));
    return countNumbersWithout1(0, true, true);
}

int resolver(int n) {
    return solve(n);
}

// Resuelve un caso de prueba, leyendo de la entrada la configuración, y escribiendo la respuesta
bool resuelveCaso() {
  // leer los datos de la entrada
  int n; cin >> n;
  if (!std::cin)
      return false;
  
  cout << resolver(n) << '\n';
  
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
     #endif
    
    return 0;
}
