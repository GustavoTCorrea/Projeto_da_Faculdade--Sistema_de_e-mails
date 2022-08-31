#include "hashTable.hpp"

HashTable::HashTable(int m){
    criaTabela(m);
    tamanho = m;
}

void HashTable::criaTabela(int m){
    for(int i = 0; i<m; i++){
        caixasDeEntrada[i] = BinarySearchTree();
    }
}

void HashTable::insereEmail(Message email){
    int caixa = (email.destinatario)%tamanho;
    caixasDeEntrada[caixa].Insere(email);
}

Message HashTable::buscaEmail(int usuario, int identificador){
    return caixasDeEntrada[usuario%tamanho].Pesquisa(identificador);
}

int HashTable::removeEmail(int usuario, int identificador){
    return caixasDeEntrada[usuario%tamanho].Remove(identificador, usuario);
}