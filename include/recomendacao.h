#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct{
    int indice;
    float score;
}ItemRanking;

vector<string> listaVizinhos(vector<vector<float>> &similaridade, vector<string> &clientesVector, int indiceCliente);

vector<float> vetorRanking(vector<vector<float>> &similaridade, vector<string> &vizinhos, vector<vector<int>> &compras, map<string, int> &mapaClientes, int indiceCliente, int qtdProdutos);

bool ordenarPorScore(const ItemRanking &itemA, const ItemRanking &itemB);

vector<ItemRanking> ordenarVetorPorScore(vector<float> &rankeamento);

void imprimirNomeProduto(vector<ItemRanking> &produtosOrdenados, int qtdProdutos, vector<string> &nomeProdutos);

void recomendacao(vector<vector<float>> &similaridade, vector<string> &clientesVector, vector<string> &produtosVector, map<string, int> &mapaClientes, vector<vector<int>> &matrizCompras, string codigoCliente, int kProdutos);