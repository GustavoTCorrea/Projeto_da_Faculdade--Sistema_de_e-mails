#ifndef MESSAGE
#define MESSAGE
#include <string>
#include <iostream>

class Message
{
    public:
    Message(int u = -1, int e = -1, int n = -1, std::string msg = "");
    std::string mensagem;
    int destinatario;
    int identificador;
    int nPalavras;
    Message *esq;
    Message *dir;
    friend class ArvoreBinaria;
};
#endif