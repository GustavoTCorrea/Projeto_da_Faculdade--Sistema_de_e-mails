#include "BST.hpp"

BinarySearchTree::BinarySearchTree(){
    raiz = nullptr;
}

BinarySearchTree::~BinarySearchTree(){
    Limpa();
}

void BinarySearchTree::Limpa(){
    ApagaRecursivo(raiz);
    raiz = nullptr;
}

void BinarySearchTree::ApagaRecursivo(Message *p){
    if(p!=nullptr){
    ApagaRecursivo(p->esq);
    ApagaRecursivo(p->dir);
    delete p;
    }
}

Message BinarySearchTree::Pesquisa(int chave) {
    return PesquisaRecursivo(raiz, chave);
}

Message BinarySearchTree::PesquisaRecursivo(Message *no, int chave) {
    Message aux = Message();
    if (no == nullptr) {
        aux.identificador = -1; // Flag para item não presente
        return aux;
    }
    if (chave < no->identificador)
        return PesquisaRecursivo(no->esq, chave);
    else if (chave>no->identificador)
        return PesquisaRecursivo(no->dir, chave);
    else
        return *no;
}

void BinarySearchTree::Insere(Message item){
    //std::cout << item.destinatario << std::endl;
    InsereRecursivo(raiz,item);
}
void BinarySearchTree::InsereRecursivo(Message* &p, Message item){
    if(p==nullptr){
        p = new Message();
        *p = item;
    }
    else{
        if(item.identificador < p->identificador)
            InsereRecursivo(p->esq, item);
        else
            InsereRecursivo(p->dir, item);
    }
}

int BinarySearchTree::Remove(int chave, int usuario) {
    return RemoveRecursivo(raiz, chave, usuario);
}

int BinarySearchTree::RemoveRecursivo(Message* &no, int chave, int usuario){
    Message *aux;
    if (no == nullptr) {
        return 0;
    }
    if (chave < no->identificador)
        return RemoveRecursivo(no->esq, chave, usuario);
    else if (chave>no->identificador)
        return RemoveRecursivo(no->dir, chave, usuario);
    else {
        if(no->destinatario != usuario){
            return 0;
        }
        if (no->dir == nullptr) {
            aux = no;
            no = no->esq;
            free(aux);
            return 1;
        }
        else if(no->esq == nullptr) {
            aux = no;
            no = no->dir;
            free(aux);
            return 1;
        }
        else{
            Antecessor(no, no->esq);
            return 1;
        }
    }
}

void BinarySearchTree::Antecessor(Message *q, Message* &r){
    if(r->dir != nullptr) {
        Antecessor(q, r->dir);
        return;
    }
    //q->item = r->item;
    q = r;
    r = r->esq;
    free(q);
}