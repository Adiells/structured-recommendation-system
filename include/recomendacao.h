#include <vector>
#include <map>
#include <iostream>
using namespace std;


vector<string> listaVizinhos(vector<vector<float>> &similaridade, vector<string> &clientesVector, int indiceCliente);

vector<float> listaRankeamento(vector<vector<float>> &similaridade, vector<string> &vizinhos, vector<vector<int>> &compras, vector<int> &produtos, int indiceCliente);