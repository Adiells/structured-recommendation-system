#ifndef MATRIZSIMILARIDADE_H
#define MATRIZSIMILARIDADE_H

#include <vector>

using namespace std;

vector<vector<int>> gerarMatrizComprasGrande (vector<vector<int>> &ListaDeCompras, int numeroDeClientes, int numDeProdutos);

vector<vector<int>> gerarMatrizIntersecaoComum (vector<vector<int>> &MatrizDeCompras1, int numeroDeClientes, int numDeProdutos);

vector<vector<int>> gerarMatrizIntersecaoOtimizada (vector<vector<int>> &MatrizDeCompras1, int numeroDeClientes, int numDeProdutos);

vector<vector<int>> gerarMatrizIntersecao(vector<vector<int>> &MatrizDeCompras1, int numeroDeClientes, int numDeProdutos, int otimizada=true);

vector<vector<float>> gerarMatrizSimilaridade(vector<vector<int>> &MatrizIntersecao);

#endif