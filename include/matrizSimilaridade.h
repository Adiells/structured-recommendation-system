#include <vector>
using namespace std;

vector<vector<int>> gerarMatrizComprasGrande (vector<vector<int>> &ListaDeCompras, int numeroDeClientes, int numDeProdutos);

vector<vector<int>> gerarMatrizIntersecao (vector<vector<int>> &MatrizDeCompras1, int numeroDeClientes, int numDeProdutos);

vector<vector<float>> gerarMatrizSimilaridade(vector<vector<int>> &MatrizIntersecao, vector<vector<int>> &ListaDeCompras);

void imprimirMatrizComprasGrande ( vector<vector<int>>& MatrizComprasGrande);

void imprimirMatrizIntersecao(vector<vector<int>>& MatrizIntersecao);

void imprimirMatrizSimilaridade(vector<vector<float>>& matrizSimilaridade);