#include <iostream>

using namespace std;

class Estudante {
     private:
        string nome;         
        static int contador; 

     public:    
          Estudante(string nome); 

          static int getContador(); 

          string getNome();
};

Estudante::Estudante(string nome) {
     this->nome = nome;
     contador++;
}

int Estudante::getContador() {
     return contador;
}

string Estudante::getNome() {
     return nome;
}

int Estudante::contador = 0;

int main() {
     string nomeA, nomeB;   

     cin >> nomeA;
     cin >> nomeB;

     cout << Estudante::getContador();

     Estudante estudanteA(nomeA);

     cout << Estudante::getContador();
     cout << estudanteA.getNome();

     Estudante estudanteB(nomeB);    

     cout << Estudante::getContador();
     cout << estudanteB.getNome();

     return 0;
}
