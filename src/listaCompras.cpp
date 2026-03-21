#include "listaCompras.h"

void gerarListaCompras(char caminho[], vector<string>& clientes, map<string, int>& mapaClientes, vector<string>& produtos, map<int, int>& mapaProdutos, vector<vector<int>>& listaDeCompras){
    FILE *arquivo;
    arquivo = fopen(caminho, "r");

    Produto produto;

    fscanf(arquivo, "%*[^\n]\n");
    while(fscanf(arquivo, "%d,%8[^,],%d,%49[^\n]\n", &produto.dataCompra, produto.codeCliente, &produto.codeProduto, produto.nomeProduto) == 4){
        if(mapaClientes.find(produto.codeCliente) == mapaClientes.end()){
            clientes.push_back(produto.codeCliente);
            mapaClientes[produto.codeCliente] = clientes.size() - 1;

            listaDeCompras.push_back(vector<int>()); 
        }

        if(mapaProdutos.find(produto.codeProduto) == mapaProdutos.end()){
            produtos.push_back(produto.nomeProduto);
            mapaProdutos[produto.codeProduto] = produtos.size() - 1;
        }
        

        int indiceCliente = mapaClientes[produto.codeCliente];
        int indiceProduto = mapaProdutos[produto.codeProduto];
        
        listaDeCompras[indiceCliente].push_back(indiceProduto);
    
    }
    fclose(arquivo);
}