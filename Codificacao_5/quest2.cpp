#include <iostream>

using namespace std;

class Nome {
     private:
          string nome;

     public:
          void set(string nome) {
               this->nome = nome;
          }

          string get() {
               return nome;
          }
};

class Matricula {
     private:
          int matricula; 

     public:
          void set(int matricula) {
               this->matricula = matricula;
          }

          int get() {
               return matricula;
          }
};

class Estudante {
     private:
          Nome nome;           
          Matricula matricula;

     public:
          Estudante(Nome &nome, Matricula &matricula) {
               this->nome = nome;
               this->matricula = matricula;
          }

          Nome getNome() {
               return nome;
          }

          Matricula getMatricula() {
               return matricula;
          }
};

int main() {
     string dadoA;
     int dadoB;  

     cin >> dadoA;
     cin >> dadoB;

     Nome nome;
     Matricula matricula;

     nome.set(dadoA);
     matricula.set(dadoB);

     Estudante estudante(nome, matricula);

     cout << estudante.getNome().get();
     cout << estudante.getMatricula().get();

     return 0;
}
