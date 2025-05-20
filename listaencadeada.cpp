/*
Faça um programa na linguagem C/C++ que implemente uma Lista Simplesmente Encadeada, 
de modo que contemple as operações de busca, inserção (inicio da lista) e remoção de
 elementos na Lista. O programa deverá conter um menu para o que o usuário escolha as 
 operações a serem realizadas. Após cada operação a Lista deverá ser apresentada na tela. 
 No encerramento da execução do programa toda a lista deve ser desalocada.
*/

#include <iostream>
using namespace std;

struct no {
    int valor;
    no* proximo;

    no(int v) : valor(v), proximo(nullptr) {}
};

class lista_encadeada {
private:
    no* cabeca;

public:
    lista_encadeada() : cabeca(nullptr) {}

    ~lista_encadeada() {
        destruir();
    }

    void inserir_inicio(int valor) {
        no* novo = new no(valor);
        novo->proximo = cabeca;
        cabeca = novo;
        cout << "inserido com sucesso.\n";
    }

    bool remover(int valor) {
        no* atual = cabeca;
        no* anterior = nullptr;

        while (atual != nullptr && atual->valor != valor) {
            anterior = atual;
            atual = atual->proximo;
        }

        if (atual == nullptr) return false;

        if (anterior == nullptr) {
            cabeca = atual->proximo;
        } else {
            anterior->proximo = atual->proximo;
        }

        delete atual;
        return true;
    }

    bool buscar(int valor) const {
        no* atual = cabeca;
        while (atual != nullptr) {
            if (atual->valor == valor) return true;
            atual = atual->proximo;
        }
        return false;
    }

    void exibir() const {
        no* atual = cabeca;
        cout << "lista: ";
        while (atual != nullptr) {
            cout << atual->valor << " -> ";
            atual = atual->proximo;
        }
        cout << "null\n";
    }

    void destruir() {
        no* atual = cabeca;
        while (atual != nullptr) {
            no* temp = atual;
            atual = atual->proximo;
            delete temp;
        }
        cabeca = nullptr;
    }
};

int main() {
    lista_encadeada lista;
    int opcao, valor;

    do {
        cout << "\n=== menu ===\n";
        cout << "1. inserir no início\n";
        cout << "2. remover elemento\n";
        cout << "3. buscar elemento\n";
        cout << "4. exibir lista\n";
        cout << "0. sair\n";
        cout << "escolha: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "digite o valor a inserir: ";
                cin >> valor;
                lista.inserir_inicio(valor);
                lista.exibir();
                break;

            case 2:
                cout << "digite o valor a remover: ";
                cin >> valor;
                if (lista.remover(valor))
                    cout << "removido com sucesso.\n";
                else
                    cout << "valor não encontrado.\n";
                lista.exibir();
                break;

            case 3:
                cout << "digite o valor a buscar: ";
                cin >> valor;
                if (lista.buscar(valor))
                    cout << "valor encontrado na lista.\n";
                else
                    cout << "valor não encontrado.\n";
                break;

            case 4:
                lista.exibir();
                break;

            case 0:
                cout << "encerrando programa...\n";
                break;

            default:
                cout << "opção inválida.\n";
        }

    } while (opcao != 0);

    return 0;
}
