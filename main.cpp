#include "listaCompras.h"

int main(){
    vector<string> codigoClientesVector;
    map<string, int> codigoClientesMapa;
    FILE *arquivo;
    Produto produto;

    for(int i = 0; i <= 10; i++){
        char caminho[35];
        sprintf(caminho, "data/dados_venda_cluster_%d.csv", i);
        gerarListaCompras(caminho, codigoClientesVector, codigoClientesMapa);
    }

    imprimirVetor(codigoClientesVector);
    imprimirMapa(codigoClientesMapa);

    return 0;
}
