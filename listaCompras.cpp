#include "listaCompras.h"

void gerarListaCompras(char caminho[], vector<string>& clientes, map<string, int>& mapaClientes){
    FILE *arquivo;
    arquivo = fopen(caminho, "r");

    Produto produto;
    char ultimoCliente[9];

    fscanf(arquivo, "%*[^\n]\n");
    while(fscanf(arquivo, "%d, %8[^,], %d, %49[^\n]\n", &produto.dataCompra, produto.codeCliente, &produto.codeProduto, produto.nomeProduto) == 4){
        clientes.push_back(produto.codeCliente);
        if(mapaClientes.find(produto.codeCliente) == mapaClientes.end()){
            if(mapaClientes.empty()){
                mapaClientes[produto.codeCliente] = 0;
            }else{
                mapaClientes[produto.codeCliente] = mapaClientes[ultimoCliente] + 1;
            }
        }
        strcpy(ultimoCliente, produto.codeCliente);
    }
}

//Funções de auxílio para acompanhar o desenvolvimento do nosso código
void imprimirVetor(vector<string>& vetor){
    int i = 1;
    for(string& elemento : vetor){
        cout << "Código: " << i << " " << elemento << endl;
        i++;
    }
}

void imprimirMapa(map<string, int>& mapa){
    for(pair<const string, int>& elemento : mapa){
        cout << "Código: " << elemento.first << " | Índice interno: " << elemento.second << endl;
    }
}