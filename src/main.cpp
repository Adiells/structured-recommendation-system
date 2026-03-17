#include "listaCompras.h"

int main(){
    vector<string> codigoClientesVector;
    map<string, int> codigoClientesMapa;
    FILE *arquivo;
    Produto produto;

    vector<string> nomeProdutosVector;
    map<int, int> codigoProdutosMapa;

    vector<vector<int>> listaFinalCompras(codigoClientesMapa.size());

    for(int i = 0; i <= 10; i++){
        char caminho[35];
        sprintf(caminho, "data/dados_venda_cluster_%d.csv", i);
        gerarListaCompras(caminho, codigoClientesVector, codigoClientesMapa, nomeProdutosVector, codigoProdutosMapa, listaFinalCompras);
    }

    int numeroDeClientes = codigoClientesMapa.size();
    int numeroDeProdutos = codigoProdutosMapa.size();

    vector<vector<int>> MatrizDeCompras1 = gerarMatrizComprasGrande(listaFinalCompras, numeroDeClientes, numeroDeProdutos);

    vector<vector<int>> MatrizIntersecao = GerarMatrizIntersecao(MatrizDeCompras1, numeroDeClientes, numeroDeProdutos);

    vector<vector<float>> MatrizSimilaridade = GerarMatrizSimilaridade(MatrizIntersecao, listaFinalCompras);

    imprimirVetor(codigoClientesVector);
    imprimirMapa(codigoClientesMapa);

     cout << "Imprimindo matrizes \n" << endl;

     imprimirMatrizComprasGrande(MatrizDeCompras1);
     ImprimirMatrizIntersecao(MatrizIntersecao);
     imprimirMatrizSimilaridade(MatrizSimilaridade);

    return 0;
}
