#include "listaCompras.h"
#include "matrizSimilaridade.h"
#include "utils.h"

int main(){
    vector<string> codigoClientesVector;
    map<string, int> codigoClientesMapa;
    FILE *arquivo;
    Produto produto;

    vector<string> nomeProdutosVector;
    map<int, int> codigoProdutosMapa;

    vector<vector<int>> listaFinalCompras(codigoClientesMapa.size());

    //Deixando em 1 por enquanto para nao demorar a gerar a matriz intersecao
    for(int i = 0; i < 1; i++){
        char caminho[35];
        sprintf(caminho, "data/dados_venda_cluster_%d.csv", i);
        gerarListaCompras(caminho, codigoClientesVector, codigoClientesMapa, nomeProdutosVector, codigoProdutosMapa, listaFinalCompras);
    }

    int numeroDeClientes = codigoClientesMapa.size();
    int numeroDeProdutos = codigoProdutosMapa.size();

    vector<vector<int>> MatrizDeCompras1 = gerarMatrizComprasGrande(listaFinalCompras, numeroDeClientes, numeroDeProdutos);

    vector<vector<int>> MatrizIntersecao = gerarMatrizIntersecao(MatrizDeCompras1, numeroDeClientes, numeroDeProdutos);

    vector<vector<float>> MatrizSimilaridade = gerarMatrizSimilaridade(MatrizIntersecao);

    // imprimirVetor(codigoClientesVector);
    // imprimirMapa(codigoClientesMapa);

    //  cout << "Imprimindo matrizes \n" << endl;

    //  imprimirMatriz(MatrizDeCompras1);
    //  imprimirMatriz(MatrizIntersecao);
    //  imprimirMatriz(MatrizSimilaridade);

    return 0;
}
