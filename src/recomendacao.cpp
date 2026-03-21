#include "recomendacao.h"

vector<string> listaVizinhos(vector<vector<float>> &similaridade, vector<string> &clientesVector, int indiceCliente){
    vector<string> vizinhos;
    for(int j = 0; j < similaridade[indiceCliente].size(); j++){
        if(similaridade[indiceCliente][j] < 1.0 && similaridade[indiceCliente][j] > 0.0){
            vizinhos.push_back(clientesVector[j]);
        }
    }
    return vizinhos;
}

vector<float> listaRankeamento(vector<vector<float>> &similaridade, vector<string> &vizinhos, vector<vector<int>> &compras, vector<int> &produtos, int indiceCliente){
    vector<float> ranking(produtos.size(), 1.0);

    vector<int> comprou(produtos.size(), 0);
    for(int i = 0; i < compras[indiceCliente].size(); i++){
        comprou[compras[indiceCliente][i]] = 1;
    }

    for(int i = 0; i < vizinhos.size(); i++){
        for(int j = 0; j < compras[i].size(); j++){
            //amanha continuo
        }
    }
}