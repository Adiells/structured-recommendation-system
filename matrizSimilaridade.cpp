#include "listaCompras.h"

vector<vector<int>> gerarMatrizComprasGrande (vector<vector<int>> &ListaDeCompras, int numeroDeClientes, int numDeProdutos){

    vector<vector<int>> MatrizCompras (numeroDeClientes, vector<int>(numDeProdutos,0));

    for (int i = 0; i < numeroDeClientes; i++){
        for(int j = 0; i < ListaDeCompras[i].size(); j++){
            int produtoComprado = ListaDeCompras[i][j];
            MatrizCompras[i][produtoComprado] = 1;
        }
    }
    return MatrizCompras;
}

vector<vector<int>> GerarMatrizIntersecao (vector<vector<int>> &MatrizDeCompras1, int numeroDeClientes, int numDeProdutos) {

    vector<vector<int>> MatrizIntersecao (numeroDeClientes, vector<int>(numDeProdutos,0));

    for(int i =0; i < numeroDeClientes; i++){
        for(int j = 0; j < numeroDeClientes; j++){
            for(int k = 0 ; k < numDeProdutos; k++){
                MatrizIntersecao[i][j] += MatrizIntersecao[i][k] * MatrizIntersecao[j][k];
            }
        }
    }
    return MatrizIntersecao;   
}

vector<vector<float>> GerarMatrizSimilaridade(vector<vector<int>> &MatrizIntersecao, vector<vector<int>> &ListaDeCompras){
    
    int numeroClientes = MatrizIntersecao.size();

    vector<vector<float>> MatrizSimilaridade(numeroClientes, vector<float>(numeroClientes,0.0 ));

    for(int i =0; i < numeroClientes; i++){
        for(int j=0; j < numeroClientes; j++){
            int valorIntersecao = MatrizIntersecao[i][j];
            int totalCompradoCliente = ListaDeCompras[i].size();

            MatrizSimilaridade[i][j] = 1.0 - ((float)valorIntersecao / (float)totalCompradoCliente);


        }
    }
    return MatrizSimilaridade;
}