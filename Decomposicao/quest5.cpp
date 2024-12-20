#include <iostream>

using namespace std;

class Endereco {

     private:

          string cidade;
          string estado;

     public:    

          // apenas a cidade
          Endereco(string cidade) {
              this-> cidade = cidade;
              this-> estado = "";
          }
          
          // estado e cidade 
          Endereco(string cidade, string estado){
              this-> cidade = cidade;
              this-> estado = estado;
          }
          
          // metodo para obter a cidade
          
          string getCidade() {
              return cidade;
          }
          
          string getEstado() {
              return estado;
          }

};

// Implementações de métodos.

int main(){

    string cidade, estado;

    cin >> cidade;

    cin >> estado;    

    Endereco enderecoA(cidade);

    Endereco enderecoB(cidade, estado);   

    cout << enderecoA.getCidade();

    cout << enderecoB.getCidade();

    cout << enderecoB.getEstado();

    return 0;

}
