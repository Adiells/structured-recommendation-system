#ifndef LISTACOMPRAS_H
#define LISTACOMPRAS_H

#include <vector>
#include <map>
#include <iostream>

using namespace std;

typedef struct{
    int dataCompra;
    char codeCliente[9];
    int codeProduto;
    char nomeProduto[50];
} Produto;

void gerarListaCompras(char caminho[], 
    vector<string>& clientes, 
    map<string, int>& mapaClientes, 
    vector<string>& produtos, 
    map<int, int>& mapaProdutos, 
    vector<vector<int>>& listaDeCompras
);

#endif