#include "recomendacao.h"

vector<string> listaVizinhos(vector<vector<float>> &similaridade, vector<string> &clientesVector, int indiceCliente){
    vector<string> vizinhos;
    for(int j = 0; j < similaridade[indiceCliente].size(); j++){
        if (j == indiceCliente) continue;
        
        if(similaridade[indiceCliente][j] < 1.0 && similaridade[indiceCliente][j] > 0.0){
            vizinhos.push_back(clientesVector[j]);
        }
    }
    return vizinhos;
}

vector<float> vetorRanking(vector<vector<float>> &similaridade, vector<string> &vizinhos, vector<vector<int>> &compras, map<string, int> &mapaClientes, int indiceCliente, int qtdProdutos){
    vector<float> ranking(qtdProdutos, 1.0);

    vector<int> comprou(qtdProdutos, 0);

    for(int i = 0; i < compras[indiceCliente].size(); i++){
        comprou[compras[indiceCliente][i]] = 1;
    }

    for(int i = 0; i < vizinhos.size(); i++){
        string codigoVizinho = vizinhos[i];
        int indiceVizinho = mapaClientes[codigoVizinho];
        for(int j = 0; j < compras[indiceVizinho].size(); j++){
            int produto = compras[indiceVizinho][j];
            if(!comprou[produto]){
                ranking[produto] = ranking[produto]*similaridade[indiceCliente][indiceVizinho];
            }
        }
    }
    return ranking;
}

bool ordenarPorScore(const ItemRanking &itemA, const ItemRanking &itemB){
    return itemA.score < itemB.score;
}

vector<ItemRanking> ordenarVetorPorScore(vector<float> &rankeamento){
    vector<ItemRanking> vetorOrdenado;
    
    for(int i = 0; i < rankeamento.size(); i++){
        ItemRanking item;
        item.indice = i;
        item.score = rankeamento[i];
        vetorOrdenado.push_back(item);
    }

    sort(vetorOrdenado.begin(), vetorOrdenado.end(), ordenarPorScore);
    return vetorOrdenado;
}


void imprimirNomeProduto(vector<ItemRanking> &produtosOrdenados, int qtdProdutos, vector<string> &nomeProdutos){
    for(int i = 0; i < qtdProdutos; i++){
        string nomeProduto = nomeProdutos[produtosOrdenados[i].indice];
        printf("Produto: %d | %s \n", i+1, nomeProduto.c_str());
        // cout << "Produto: " << i+1 << " | " << nomeProduto << endl;
    }
}

void recomendacao(vector<vector<float>> &similaridade, vector<string> &clientesVector, vector<string> &produtosVector, map<string, int> &mapaClientes, vector<vector<int>> &matrizCompras, string codigoCliente, int kProdutos){
    int indiceInternoCliente = mapaClientes[codigoCliente];

    vector<string> vizinhos = listaVizinhos(similaridade, clientesVector, indiceInternoCliente);
    vector<float> ranking = vetorRanking(similaridade, vizinhos, matrizCompras, mapaClientes, indiceInternoCliente, produtosVector.size());
    vector<ItemRanking> rankingOrdenado = ordenarVetorPorScore(ranking);
    if (kProdutos < rankingOrdenado.size()) {
        kProdutos = rankingOrdenado.size();
        printf ("Número de produtos para rankeamento excede o número de produtos disponíveis.\n");
    }
    imprimirNomeProduto(rankingOrdenado, kProdutos, produtosVector);
}