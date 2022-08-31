#include <sstream>
#include <fstream>
#include "hashTable.hpp"


using namespace std;

int main(int argc, char** argv){
    ifstream inFile;
    ofstream outFile;
    for (int i = 0; i < argc; i++) {
        if(sizeof(argv[i]) > 1 && (argv[i][1] == 'i' || argv[i][1] == 'I') && argc >= i+1){
            inFile.open(argv[i+1], ifstream::in);
            i++;
        }
        if(sizeof(argv[i]) > 1 && (argv[i][1] == 'o' || argv[i][1] == 'O') && argc >= i+1){
            outFile.open(argv[i+1], ofstream::out);
            i++;
        }
    }
    if(!inFile.is_open()){
        cout << "Nao foi possivel abrir nenhum arquivo de entrada." << endl;
        return 0;
    }
    if(!outFile.is_open()){
        cout << "Nao foi inserido nenhum arquivo de saida." << endl;
        return 0;
    }
    int tamTabela;
    string aux;
    getline(inFile, aux);
    tamTabela = stoi(aux);
    string linha;
    HashTable servidorDeEmails = HashTable(tamTabela);

    while(getline(inFile, linha)){
        stringstream s(linha);
		string comando;
        s >> comando;

        if(comando == "ENTREGA"){
            int destinatario, identificador, numPalavras;
            s >> destinatario >> identificador >> numPalavras;
            string mensagem;
            getline(s, mensagem);
            mensagem.erase(mensagem.begin());//Retira o espaco em branco apos o inteiro
            
            Message email(destinatario, identificador, numPalavras, mensagem);

            servidorDeEmails.insereEmail(email);
            outFile << "OK: MENSAGEM " << identificador << " PARA " << destinatario;
            outFile << " ARMAZENADA EM " << destinatario%tamTabela << endl;

        } else if(comando == "CONSULTA"){
            int destinatarioConsulta, identificadorConsulta;
            s >> destinatarioConsulta >> identificadorConsulta;
            Message email = servidorDeEmails.buscaEmail(destinatarioConsulta, identificadorConsulta);

            if(email.identificador == -1 || email.destinatario != destinatarioConsulta){
                outFile << "CONSULTA " << destinatarioConsulta << " " << identificadorConsulta << ": ";
                outFile << "MENSAGEM INEXISTENTE" << endl;
            } else {
                outFile << "CONSULTA " << destinatarioConsulta << " " << identificadorConsulta << ": ";
                outFile << email.mensagem << endl;
            }

        } else if(comando == "APAGA"){
            int destinatario, identificador;
            s >> destinatario >> identificador;
            int resultado = servidorDeEmails.removeEmail(destinatario, identificador);

            if(resultado){
                outFile << "OK: MENSAGEM APAGADA" << endl;
            }else outFile << "ERRO: MENSAGEM INEXISTENTE" << endl;
            
        } else {
            cout << "Erro! Um comando nao reconhecido foi inserido. Por favor, atente-se:" << endl;
            cout << "Os comandos reconhecidos sao 'ENTREGA', 'CONSULTA' e 'APAGA'." << endl;
            return 0;
        }
    }
    return 0;
}