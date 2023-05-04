#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

struct Info {
    long long int CPF;
    string Nome;
    string Profissao;
};

struct No {
    Info* info;
    No* esq;
    No* dir;
};

No* arvoreCPF = NULL;
No* arvoreNome = NULL;

void PedirInfo(Info*& info);
void gerarInfo(No*& raiz, Info* info); // Função que gera a info, ocupando o mesmo espaço na memória para ambas as árvores..
void inserirCPF(No*& raiz, Info* info);
void inserirNome(No*& raiz, Info* info);
void inserirEmAmbas(No*& raiz1, No*& raiz2, Info* Info);
void infixado(No* raiz);
Info* buscarNome(No* raiz, string Nome);
Info* buscarCPF(No* raiz, long int CPF);

int main() {
    Info* info1 = new Info;
    Info* info2 = new Info;
    Info* info3 = new Info;
    
    
    info1->CPF = 991;
    info1->Nome = "Igor";
    info1->Profissao = "Programador";
    inserirEmAmbas(arvoreCPF, arvoreNome, info1);
    
    
    info2->CPF = 744;
    info2->Nome = "Joao";
    info2->Profissao = "Programador";
    inserirEmAmbas(arvoreCPF, arvoreNome, info2);
    //delete(info1);

    info3->CPF = 999;
    info3->Nome = "Artur";
    info3->Profissao = "Programador";
    inserirEmAmbas(arvoreCPF, arvoreNome, info3);
    
    
    
    //delete(info2);
    //delete(info3);
    system("cls");
    infixado(arvoreCPF);
    cout << " ---------------------------------------------------------------------------------------------";
    infixado(arvoreNome);


    /* CONFERIR ENDEREÇOS
    cout << info1 << endl;
    cout << arvoreNome->info << endl;
    cout << arvoreCPF->info  << endl;
    cout << info2 << endl;
    cout << arvoreNome->esq->info << endl;
    cout << arvoreCPF->esq->info;*/

    return 0;
}

void PedirInfo(Info*& info)
{
    system("cls");
    cout << "\n\tEntre com as informacoes do funcionario: ";
    cout << "\n\tNome: ";
    getline(cin, info->Nome);
    system("cls");
    cout << "\tEntre com as informacoes do funcionario:";
    cout << "\tCPF: ";
    cin >> info->CPF;
    system("cls");
    cout << "\tEntre com as informacoes do funcionario:";
    cout << "\t Profissao:";
    cin >> info->Profissao;
    system("cls");
}

void gerarInfo(No*& raiz, Info* info)
{
    if (raiz == NULL) {
        raiz = new No;
        raiz->info = info;
        raiz->esq = NULL;
        raiz->dir = NULL;
        return;
    }
}

void inserirCPF(No*& raiz, Info* info) {
    if (raiz == NULL) {
        raiz = new No;
        raiz->info = info;
        raiz->esq = NULL;
        raiz->dir = NULL;
        return;
    }
    if (raiz->info->CPF > info->CPF) {
        inserirCPF(raiz->esq, info);
    }
    else {
        inserirCPF(raiz->dir, info);
    }
}

void inserirNome(No*& raiz, Info* info) {
    if (raiz == NULL) {
        raiz = new No;
        raiz->info = info;
        raiz->esq = NULL;
        raiz->dir = NULL;
        return;
    }
    if (raiz->info->Nome > info->Nome) {
        inserirNome(raiz->esq, info);
    }
    else {
        inserirNome(raiz->dir, info);
    }
}

void inserirEmAmbas(No*& raiz1, No*& raiz2, Info* Info)
{
    inserirNome(raiz1, Info);
    inserirCPF(raiz2, Info);
}

Info* buscarNome(No* raiz, string Nome) {
    if (raiz == NULL) {
        return NULL;
    }
    if (raiz->info->Nome == Nome) {
        return raiz->info;
    }
    else if (raiz->info->Nome > Nome) {
        return buscarNome(raiz->esq, Nome);
    }
    else {
        return buscarNome(raiz->dir, Nome);
    }
}

Info* buscarCPF(No* raiz, long int CPF) {
    if (raiz == NULL) {
        return NULL;
    }
    if (raiz->info->CPF == CPF) {
        return raiz->info;
    }
    else if (raiz->info->CPF > CPF) {
        return buscarCPF(raiz->esq, CPF);
    }
    else {
        return buscarCPF(raiz->dir, CPF);
    }
}

void infixado(No* raiz) {
    if (raiz == NULL) return;
    infixado(raiz->esq);
    cout << "\n\t- Nome: " << raiz->info->Nome << "\n\t- CPF: " << raiz->info->CPF << "\n\t- Profissao: " << raiz->info->Profissao << endl << endl;
    infixado(raiz->dir);
}
