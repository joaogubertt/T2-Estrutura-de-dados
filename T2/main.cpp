#include <iostream>
#include <string>
#include <windows.h>
#include <cstdlib>
using namespace std;

//REMOVER DA ÁRVORE
//REMOVER TODOS OS ITENS APÓS O PROGRAMA RODAR (LIMPAR MEMÓRIA);
//COMENTAR O CÓDIGO

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
bool boolNome(No* raiz, string Nome);
bool boolCPF(No* raiz, long int CPF);

int main() {

    int op;

    do
    {
        system("cls");
        cout<<"Qual sera a operacao?\n\n";
        cout<<"\t 1- Inserir na arvore\n";
        cout<<"\t 2- Mostra lista de funcionarios\n";
        cout<<"\t 3- Buscar funcionario\n";
        cout<<"\t 4- Remover funcionario\n";
        cout<<"\t 0- Encerrar programa\n\n";

        cout << "\tOpcao: ";
        cin >> op;

        system("cls");
              
        Info *aux = new Info; 
        Info *busca = new Info;

        switch(op)
        {
            case 1:
                PedirInfo(aux);
                if(!boolCPF(arvoreCPF, aux->CPF) && !boolNome(arvoreNome, aux->Nome)) //Evitar redundancia
                {
                    inserirEmAmbas(arvoreNome, arvoreCPF, aux);
                    cout << "\nFuncionario cadastrado com sucesso!\n" << endl;
                } else cout << "\nNome ou CPF ja cadastrado!!\n";
                break;
            case 2:
                int resposta;

                cout<<"\tOrdenado por: \n\t1-CPF\n\t2-Nome\n";
                cout<<"\n\tOpcao: ";
                cin>>resposta;
                system("cls");
                cout << "\t Funcionarios: \n";
                
                if(resposta ==1) infixado(arvoreCPF);
                else if(resposta == 2)  infixado(arvoreNome);
                
                break;
            case 3:
                resposta=0;
                cout<<"Busca por: \n\t1-CPF\n\t2-Nome\n";
                cout<<"\n\tOpcao: ";cin>>resposta;
                system("cls");

                if(resposta == 1){
                    long int cpf;
                    cout<< "Insira o CPF a buscar: "; cin>>cpf;
                    busca = buscarCPF(arvoreCPF, cpf);
                }else if(resposta == 2){
                    string nome;
                    cout<< "Insira o nome para buscar: "; cin>>nome;
                    busca = buscarNome(arvoreNome, nome);
                }
                if(busca != NULL)
                    cout << "\n\tResultado:\n\t- Nome: " << busca->Nome << "\n\t- CPF: " << busca->CPF << "\n\t- Profissao: " << busca->Profissao << endl << endl;
                else cout << "\n\t Nao houve resultados...\n";
                break;
            case 0:
                cout << "Sistema finalizando...";
                system("pause");
                break;
            default:
                cout<<"Opcao invalida";
                break;
        }
        system("pause");
    }while(op !=0);


    return 0;
}

void PedirInfo(Info *&info){
    string nome;
    cout << "CADASTRO DE FUNCIONARIO" << endl;
    cout << "\n\tDigite o nome do funcionario: ";
    cin >> info->Nome;
    cout << "\tDigite o CPF: ";
    cin >> info->CPF;
    cout<< "\tInforme a profissao: ";
    cin>> info->Profissao;
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
    if (raiz->info->CPF > info->CPF) inserirCPF(raiz->esq, info);
    
    else  inserirCPF(raiz->dir, info);
}

void inserirNome(No*& raiz, Info* info) {
    if (raiz == NULL) {
        raiz = new No;
        raiz->info = info;
        raiz->esq = NULL;
        raiz->dir = NULL;
        return;
    }
    if (raiz->info->Nome > info->Nome) inserirNome(raiz->esq, info);

    else  inserirNome(raiz->dir, info);
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

bool boolNome(No* raiz, string Nome) {
    if (raiz == NULL) {
        return false;
    }
    if (raiz->info->Nome == Nome) { // Se achar retornará verdadeiro, tal qual na função de CPF
        return true;
    }
    else if (raiz->info->Nome > Nome) {
        return boolNome(raiz->esq, Nome);
    }
    else {
        return boolNome(raiz->dir, Nome);
    }
}

bool boolCPF(No* raiz, long int CPF) {
    if (raiz == NULL) {
        return false;
    }
    if (raiz->info->CPF == CPF) {
        return true;
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
