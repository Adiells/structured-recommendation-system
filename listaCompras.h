#include <vector>
#include <map>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef struct{
    int dataCompra;
    char codeCliente[9];
    int codeProduto;
    char nomeProduto[50];
} Produto;

void gerarListaCompras(char caminho[], vector<string>& clientes, map<string, int>& mapaClientes, vector<string>& produtos, map<int, int>& mapaProdutos, vector<vector<int>>& listaDeCompras);

void imprimirVetor(vector<string>& vetor);

void imprimirMapa(map<string, int>& mapa);

vector<vector<int>> gerarMatrizComprasGrande (vector<vector<int>> &ListaDeCompras, int numeroDeClientes, int numDeProdutos);

vector<vector<int>> GerarMatrizIntersecao (vector<vector<int>> &MatrizDeCompras1, int numeroDeClientes, int numDeProdutos);

vector<vector<float>> GerarMatrizSimilaridade(vector<vector<int>> &MatrizIntersecao, vector<vector<int>> &ListaDeCompras);