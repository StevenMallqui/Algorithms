#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

// Función recursiva para generar números polidivisibles
void generaPolidivisibles(long long raiz, int nivel, int maxDigitos) {
    if (nivel > maxDigitos) return;

    // Verificar si el número generado hasta ahora es polidivisible
    cout << raiz << endl;

    // Extender el número actual agregando dígitos del 0 al 9
    for (int i = 0; i < 10; ++i) {
        long long nuevoNumero = raiz * 10 + i;
        if (nuevoNumero % (nivel + 1) == 0) {
            generaPolidivisibles(nuevoNumero, nivel + 1, maxDigitos);
        }
    }
}

// Función no recursiva que inicia el proceso
void escribePolidivisibles(long long raiz, int maxDigitos) {
    int nivel = to_string(raiz).length(); // Nivel inicial basado en los dígitos de la raíz
    generaPolidivisibles(raiz, nivel, maxDigitos);
    cout << "---" << endl;
}

int main() {
    vector<pair<long long, int>> casosDePrueba = {
        {2016, 4},
        {2016, 5},
        {2016, 6},
        {1, 1}
    };

    for (const auto& caso : casosDePrueba) {
        escribePolidivisibles(caso.first, caso.second);
    }

    return 0;
}
