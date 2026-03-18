#include <stdio.h>

#include <vector>
#include <map>
#include <iostream>

#include "listaCompras.h"
#include "matrizSimilaridade.h"
#include "utils.h"

using namespace std;

int main(int argc, char **argv){
    vector<string> codigoClientesVector;
    map<string, int> codigoClientesMapa;

    vector<string> nomeProdutosVector;
    map<int, int> codigoProdutosMapa;

    vector<vector<int>> listaFinalCompras(codigoClientesMapa.size());


    gerarListaCompras(argv[1], codigoClientesVector, codigoClientesMapa, nomeProdutosVector, codigoProdutosMapa, listaFinalCompras);

    int numeroDeClientes = codigoClientesMapa.size();
    int numeroDeProdutos = codigoProdutosMapa.size();

    vector<vector<int>> MatrizDeCompras1 = gerarMatrizComprasGrande(listaFinalCompras, numeroDeClientes, numeroDeProdutos);

    vector<vector<int>> MatrizIntersecao = gerarMatrizIntersecao(MatrizDeCompras1, numeroDeClientes, numeroDeProdutos);

    vector<vector<float>> MatrizSimilaridade = gerarMatrizSimilaridade(MatrizIntersecao);

    imprimirVetor(codigoClientesVector);

    // imprimirMapa(codigoClientesMapa);
    //  imprimirMatriz(MatrizDeCompras1);
    //  imprimirMatriz(MatrizIntersecao);
    //  imprimirMatriz(MatrizSimilaridade);

    return 0;
}
