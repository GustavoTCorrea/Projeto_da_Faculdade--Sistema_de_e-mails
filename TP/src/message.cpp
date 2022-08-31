#include "message.hpp"

Message::Message(int u, int e, int n, std::string msg){
    destinatario = u;
    identificador = e;
    nPalavras = n;
    mensagem = msg;
    esq = nullptr;
    dir = nullptr;
}