#include "listaCompras.h"

void gerarListaCompras(char caminho[], vector<string>& clientes, map<string, int>& mapaClientes, vector<string>& produtos, map<int, int>& mapaProdutos, vector<vector<int>>& listaDeCompras){
    FILE *arquivo;
    arquivo = fopen(caminho, "r");

    Produto produto;
    char ultimoCliente[9];
    int ultimoProduto = 0;

    fscanf(arquivo, "%*[^\n]\n");
    while(fscanf(arquivo, "%d, %8[^,], %d, %49[^\n]\n", &produto.dataCompra, produto.codeCliente, &produto.codeProduto, produto.nomeProduto) == 4){
        clientes.push_back(produto.codeCliente);
        if(mapaClientes.find(produto.codeCliente) == mapaClientes.end()){
            if(mapaClientes.empty()){
                mapaClientes[produto.codeCliente] = 0;
            }else{
                mapaClientes[produto.codeCliente] = mapaClientes[ultimoCliente] + 1;
            }

            listaDeCompras.push_back(vector<int>()); 
        }
        strcpy(ultimoCliente, produto.codeCliente);

        produtos.push_back(produto.nomeProduto);
        if(mapaProdutos.find(produto.codeProduto) == mapaProdutos.end()){
            if(mapaProdutos.empty()){
                mapaProdutos[produto.codeProduto] = 0;
            }else{
                mapaProdutos[produto.codeProduto] = mapaProdutos[ultimoProduto] + 1;
            }
        }
        ultimoProduto = produto.codeProduto;

        int indiceCliente = mapaClientes[produto.codeCliente];
        int indiceProduto = mapaProdutos[produto.codeProduto];
        
        listaDeCompras[indiceCliente].push_back(indiceProduto);
    
    }
    fclose(arquivo);
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