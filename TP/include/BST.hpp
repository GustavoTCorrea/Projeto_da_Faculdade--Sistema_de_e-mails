#ifndef BST
#define BST

#include <message.hpp>

class BinarySearchTree
{
    public:
    BinarySearchTree();
    ~BinarySearchTree();

    void Insere(Message item);
    Message Pesquisa(int chave);
    int Remove(int chave, int usuario);
    void Limpa();

    //private:
    void InsereRecursivo(Message* &p, Message item);
    void ApagaRecursivo(Message* p);
    Message PesquisaRecursivo(Message* p, int chave);
    int RemoveRecursivo(Message* &p, int chave, int usuario);
    void Antecessor(Message* q, Message* &r);
    Message *raiz;
};

#endif