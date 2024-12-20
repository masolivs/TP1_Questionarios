#include <iostream>

using namespace std;

class Codigo {
     private:
          int valor; 

     public:
          void set(int valor) {
               this->valor = valor;
          }

          int get() {
               return valor;
          }
};

// Implementações de métodos.

int main() {
     Codigo codigo; 
     int valor;

     cin >> valor;
     codigo.set(valor);

     cout << codigo.get();

     return 0;
}
