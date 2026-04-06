import csv


def gerarListaCompras(caminho):
    
    clientes = []           
    mapaClientes = {}      
    produtos = []           
    mapaProdutos = {}     
    listaDeCompras = []   

    with open(caminho, 'r', encoding='utf-8') as arquivo:
        linhaDoCsv = csv.reader(arquivo)
        
        next(linhaDoCsv)
        
        for linha in linhaDoCsv:
            if len(linha) != 4:
                continue 
            
            dataCompra = linha[0]
            codigoCliente = linha[1]
            codigoProduto = int(linha[2]) 
            nomeProduto = linha[3]
            
            if codigoCliente not in mapaClientes:

                clientes.append(codigoCliente)
            
                mapaClientes[codigoCliente] = len(clientes) - 1

                listaDeCompras.append([]) 
            
            if codigoProduto not in mapaProdutos:

                produtos.append(nomeProduto)
                
                mapaProdutos[codigoProduto] = len(produtos) - 1
                
            indiceCliente = mapaClientes[codigoCliente]
            
            indice_produto = mapaProdutos[codigoProduto]
            
            listaDeCompras[indiceCliente].append(indice_produto)
            
    return clientes, mapaClientes, produtos, mapaProdutos, listaDeCompras