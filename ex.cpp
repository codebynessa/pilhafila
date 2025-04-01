/*Faça as seguintes implementações em C++:
- Implemente uma Pilha;
- Implemente uma Fila.
A Pilha e a Fila deverão ser representadas por meio de vetores de tamanho n, onde 
n será fornecido pelo usuário. Cada programa deverá conter um menu que proporcione 
ao usuário a realização das operações de inserção e remoção na devida estrutura de 
dados, como também, a opção para que seja mostrado na tela os elementos da estrutura.*/


#include <iostream>
using namespace std;

// classe que representa uma pilha usando vetor
class pilha {
private:
    int *arr, topo, capacidade;
public:
    pilha(int n) {
        capacidade = n;
        arr = new int[n];
        topo = -1;
    }
    ~pilha() { delete[] arr; }
    
    // metodo para adicionar um elemento na pilha
    void push(int x) {
        if (topo == capacidade - 1) {
            cout << "pilha cheia!" << endl;
            return;
        }
        arr[++topo] = x;
    }
    
    // metodo para remover um elemento da pilha
    void pop() {
        if (topo == -1) {
            cout << "pilha vazia!" << endl;
            return;
        }
        topo--;
    }
    
    // metodo para mostrar os elementos da pilha
    void mostrar() {
        if (topo == -1) {
            cout << "pilha vazia!" << endl;
            return;
        }
        for (int i = topo; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// classe que representa uma fila usando vetor
class fila {
private:
    int *arr, frente, fim, capacidade;
public:
    fila(int n) {
        capacidade = n;
        arr = new int[n];
        frente = fim = 0;
    }
    ~fila() { delete[] arr; }
    
    // metodo para adicionar um elemento na fila
    void enqueue(int x) {
        if (fim == capacidade) {
            cout << "fila cheia!" << endl;
            return;
        }
        arr[fim++] = x;
    }
    
    // metodo para remover um elemento da fila
    void dequeue() {
        if (frente == fim) {
            cout << "fila vazia!" << endl;
            return;
        }
        for (int i = 0; i < fim - 1; i++) {
            arr[i] = arr[i + 1];
        }
        fim--;
    }
    
    // metodo para mostrar os elementos da fila
    void mostrar() {
        if (frente == fim) {
            cout << "fila vazia!" << endl;
            return;
        }
        for (int i = frente; i < fim; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int n, escolha, valor;
    cout << "digite o tamanho da estrutura: ";
    cin >> n;

    pilha p(n);
    fila f(n);

    while (true) {
        cout << "\nmenu:\n1. push (pilha)\n2. pop (pilha)\n3. mostrar pilha\n";
        cout << "4. enqueue (fila)\n5. dequeue (fila)\n6. mostrar fila\n7. sair\nescolha: ";
        cin >> escolha;

        switch (escolha) {
            case 1:
                cout << "valor para empilhar: ";
                cin >> valor;
                p.push(valor);
                break;
            case 2:
                p.pop();
                break;
            case 3:
                p.mostrar();
                break;
            case 4:
                cout << "valor para enfileirar: ";
                cin >> valor;
                f.enqueue(valor);
                break;
            case 5:
                f.dequeue();
                break;
            case 6:
                f.mostrar();
                break;
            case 7:
                return 0;
            default:
                cout << "opcao invalida!" << endl;
        }
    }
}
