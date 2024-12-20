#include <iostream>

using namespace std;

class Codigo {
    private:
    
         int valor;
         
    public:

         bool set(int valor) {
             if (valor % 2 == 0) { // verifica se é par
                 this-> valor = valor;
                 return true; //se for, retorna verdadeiro
             }
             return false; //se não for, retorna falso
         }

         int get() {
              return valor; //retorna o valor armazenado
         }

};

// Implementações de métodos.



int main(){

     Codigo codigo; 

     int valor;

     cin >> valor;

     if(valor % 2 == 0 && codigo.set(valor) && codigo.get() == valor) {

          cout << "SUCESSO";

          return 0;

     }

     if(valor % 2 != 0 && !codigo.set(valor) && codigo.get() != valor){

          cout << "SUCESSO";

          return 0;

     }

     cout << "FALHA";

     return 0;

}
