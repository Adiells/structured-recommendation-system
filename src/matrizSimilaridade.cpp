#include "listaCompras.h"
#include "matrizSimilaridade.h"

vector<vector<int>> gerarMatrizComprasGrande (vector<vector<int>> &ListaDeCompras, int numeroDeClientes, int numDeProdutos){

    vector<vector<int>> MatrizCompras (numeroDeClientes, vector<int>(numDeProdutos,0));

    for (int i = 0; i < numeroDeClientes; i++){
        for(int j = 0; j < ListaDeCompras[i].size(); j++){
            int produtoComprado = ListaDeCompras[i][j];
            MatrizCompras[i][produtoComprado] = 1;
        }
    }
    return MatrizCompras;
}

vector<vector<int>> gerarMatrizIntersecao (vector<vector<int>> &MatrizDeCompras1, int numeroDeClientes, int numDeProdutos) {
    vector<vector<int>> MatrizIntersecao (numeroDeClientes, vector<int>(numeroDeClientes,0));

    for(int i =0; i < numeroDeClientes; i++){
        for(int j = 0; j < numeroDeClientes; j++){
            for(int k = 0 ; k < numDeProdutos; k++){
                MatrizIntersecao[i][j] += MatrizDeCompras1[i][k] * MatrizDeCompras1[j][k];
            }
        }
    }
    return MatrizIntersecao;   
}

vector<vector<int>> gerarMatrizIntersecaoOtimizada (vector<vector<int>> &MatrizDeCompras1, int numeroDeClientes, int numDeProdutos) {
    vector<vector<int >> matrizIntersecaoOtimizada (numeroDeClientes, vector<int>(numeroDeClientes,0));

    for(int i = 0; i < numeroDeClientes; i++){
        for (int j = i; j < numeroDeClientes; j++){
            int soma = 0;
            for (int k = 0; k < numDeProdutos; k++){
                soma += MatrizDeCompras1[i][k] * MatrizDeCompras1[j][k];
            }
            matrizIntersecaoOtimizada[i][j] = soma;
            matrizIntersecaoOtimizada[j][i] = soma;
        }
    }
    return matrizIntersecaoOtimizada;
}


vector<vector<float>> gerarMatrizSimilaridade(vector<vector<int>> &MatrizIntersecao){
    
    int numeroClientes = MatrizIntersecao.size();

    vector<vector<float>> MatrizSimilaridade(numeroClientes, vector<float>(numeroClientes, 0.0));

    for(int i = 0; i < numeroClientes; i++){
        for(int j = 0; j < numeroClientes; j++){
            int valorIntersecao = MatrizIntersecao[i][j];
            int totalCompradoCliente = MatrizIntersecao[i][i];

            if(totalCompradoCliente > 0)
                MatrizSimilaridade[i][j] = 1.0 - ((float)valorIntersecao / (float)totalCompradoCliente);


        }
    }
    return MatrizSimilaridade;
}