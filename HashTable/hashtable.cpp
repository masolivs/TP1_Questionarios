#include <iostream>

using namespace std;

// Declaração e implementação da classe Elemento.
class Elemento {
    private:
        int chave;
        Elemento* proximo;
    public:
        //construtor
        Elemento(int chave) : chave(chave), proximo(nullptr) {}
        //getChave
        int getChave() const {return chave;}
        //getProximoElemento
        Elemento* getProximo() const {return proximo;}
        //setProximoElemento
        void setProximo(Elemento* proximo)  {this->proximo = proximo;}
};


// Declaração e implementação da classe TabelaDispersao.

class TabelaDispersao {

private:

    int dimensao;

    Elemento **entrada;

    int funcaoDispersao(int valor) {return valor & dimensao;}

public:
    //construtor
    TabelaDispersao(int dimensao) : dimensao(dimensao) {
        entrada = new Elemento*[dimensao];
        for (int n = 0; n < dimensao; n++) {
            entrada[n] = nullptr;
        }
    }
    //destrutor
    ~TabelaDispersao(){
        for (int i = 0; i < dimensao; i++ ) {
            Elemento* atual = entrada[i];
            while (atual != nullptr) {
                Elemento* temp = atual;
                atual = atual-> getProximo();
                delete temp;
            }
        }
        delete[] entrada;
    }

    //metodos
    Elemento* ler(int chave) {
        Elemento* ponteiro = entrada[funcaoDispersao(chave)];
        while (ponteiro != nullptr) {
            if (ponteiro->getChave() == chave) {
                return ponteiro;
            }
            ponteiro = ponteiro->getProximo();
        }
        return nullptr;
    }

    void inserir(Elemento* elemento) {
        int pos = funcaoDispersao(elemento->getChave());
        Elemento* ponteiro = entrada[pos];
        Elemento* anterior = nullptr;
        
        while (ponteiro != nullptr) {
            if (ponteiro-> getChave() == elemento->getChave()) {
                return; //chave já existe
            }
            anterior = ponteiro;
            ponteiro = anterior->getProximo();
        }
        if (anterior == nullptr) {
            entrada[pos] = elemento;
        } else {
            anterior->setProximo(elemento);
        }
    }

    void remover(int chave) {
        int pos = funcaoDispersao(chave);
        Elemento* ponteiro = entrada[pos];
        Elemento* anterior = nullptr;
        
        while (ponteiro != nullptr) {
            if (ponteiro->getChave() == chave) {
                if (anterior == nullptr) {
                    entrada[pos] = ponteiro->getProximo(); 
                } else {
                    anterior->setProximo(ponteiro->getProximo());
                }
                delete ponteiro;
                return;
            }
            anterior = ponteiro;
            ponteiro = ponteiro->getProximo();
        }
    }

};

// Declaração e implementação da função main.

int main()

{

    TabelaDispersao tabela(2);

    Elemento *ponteiro;

    int entrada;

    tabela.inserir(new Elemento(100));

    tabela.inserir(new Elemento(200));

    tabela.inserir(new Elemento(300));

    tabela.inserir(new Elemento(401));

    tabela.inserir(new Elemento(501));

    tabela.remover(200);

    for(int n = 1; n < 6;n++){

        cin >> entrada;

        ponteiro = tabela.ler(entrada);

        if(ponteiro == nullptr)

            cout << 0 ;

        else

            cout << ponteiro->getChave() ;

    }

    return 0;

}