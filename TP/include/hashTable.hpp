#ifndef HR
#define HT
#include "BST.hpp"

class HashTable{
    public:
    HashTable(int m = 0);
    
    void criaTabela(int m);

    void insereEmail(Message email);
    Message buscaEmail(int usuario, int identificador);
    int removeEmail(int usuario, int identificador);
    BinarySearchTree caixasDeEntrada[100000];
    int tamanho;
    friend class ArvoreBinaria;
};

#endif