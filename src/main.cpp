#include <stdio.h>

#include <vector>
#include <map>
#include <iostream>

#include "listaCompras.h"
#include "matrizSimilaridade.h"
#include "utils.h"
#include "recomendacao.h"

#include <ctime>

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

    clock_t inicioMatrizIntersecao = clock();
    vector<vector<int>> MatrizIntersecao = gerarMatrizIntersecao(MatrizDeCompras1, numeroDeClientes, numeroDeProdutos);
    clock_t fimMatrizIntersecao = clock();
    double tempoMatrizIntercessao = double(fimMatrizIntersecao - inicioMatrizIntersecao) / CLOCKS_PER_SEC;
    printf("O tempo de execução para a Matriz Intercessão foi: %.3f segundos \n", tempoMatrizIntercessao);

    clock_t inicioMatrizIntercessaoOtimizada = clock();
    vector<vector<int>> matrizIntercessaoOtimizada = gerarMatrizIntersecaoOtimizada(MatrizDeCompras1, numeroDeClientes, numeroDeProdutos);
    clock_t fimMatrizIntersecaoOtimizada = clock();
    double tempoMatrizIntercessaoOtimizada = double(fimMatrizIntersecaoOtimizada - inicioMatrizIntercessaoOtimizada) / CLOCKS_PER_SEC;
    printf("O tempo de execução para a Matriz Intercessão Otimizada foi: %.3f segundos \n", tempoMatrizIntercessaoOtimizada);


    vector<vector<float>> MatrizSimilaridade = gerarMatrizSimilaridade(matrizIntercessaoOtimizada);

    int k = atoi(argv[3]);

    rankeamento(MatrizSimilaridade, codigoClientesVector, nomeProdutosVector, codigoClientesMapa, listaFinalCompras, argv[2], k);

    // imprimirVetor(codigoClientesVector);

    // imprimirMapa(codigoClientesMapa);
    //  imprimirMatriz(MatrizDeCompras1);
    //  imprimirMatriz(MatrizIntersecao);
    //  imprimirMatriz(MatrizSimilaridade);

    return 0;
}
