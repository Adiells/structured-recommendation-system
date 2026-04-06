import recomendacao
import sys
from lerCsv import gerarListaCompras

def main():
    if len(sys.argv) != 4:
        print("Uso correto: python main.py <caminho_csv> <codigo_cliente> <k>")
        print("Exemplo: python main.py data/dados_venda_cluster_0.csv 99CL9Y01 5")
        return

    caminhoCsv = sys.argv[1]
    codigoCliente = sys.argv[2]
    quantidadeProdutosRecomendados = int(sys.argv[3]) 
   
    clientes, mapaClientes, produtos, mapaProdutos, listaDeCompras = gerarListaCompras(caminhoCsv)
    
    matrizCompras = recomendacao.gerar_matriz_compras_grande(listaDeCompras, len(clientes), len(produtos))
    print("Matriz de Compras gerada com sucesso!\n")
    
    matrizDeIntersecao = recomendacao.gerar_matriz_intersecao_otimizada(matrizCompras, len(clientes), len(produtos))
    print("Matriz de Interseção gerada com sucesso!\n")

    matrizDeSimilaridade = recomendacao.gerar_matriz_similaridade(matrizDeIntersecao)
    print("Matriz de Similaridade gerada com sucesso!\n")

    produtosRecomendados = recomendacao.recomendacao(matrizDeSimilaridade,clientes,produtos,mapaClientes,matrizCompras,codigoCliente,quantidadeProdutosRecomendados)
    print("Lista de produtos recomendados gerada!\n")
    
    print(f"TOP {quantidadeProdutosRecomendados} RECOMENDAÇÕES PARA O CLIENTE {codigoCliente}\n")
    
    if not produtosRecomendados:
        print("Nenhuma recomendação encontrada para este cliente.")
    else:
        for i, prod in enumerate(produtosRecomendados):
            print(f"{i+1}º Lugar: {prod}")

if __name__ == "__main__":
    main()