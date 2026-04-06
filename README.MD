# Sistema de Recomendacao de Produtos

Projeto da disciplina de Programacao Estruturada para recomendacao de produtos com base no historico de compras de clientes.

O fluxo principal combina:

- leitura de CSV em Python
- processamento pesado em C++
- integracao Python-C++ via pybind11

## Objetivo

Recomendar produtos que um cliente ainda nao comprou, usando similaridade entre clientes (filtragem colaborativa baseada em usuario).

## Como o sistema funciona

1. Le os dados de compras no arquivo CSV.
2. Monta a lista de compras por cliente.
3. Gera a matriz de compras (cliente x produto).
4. Gera a matriz de intersecao entre clientes.
5. Gera a matriz de similaridade.
6. Gera um ranking de produtos recomendados para um cliente alvo.

## Estrutura atual do projeto

```text
.
├── README.MD
├── setup.py
├── main.py
├── lerCsv.py
├── data/
│   ├── dados_venda_cluster_0.csv
│   ├── ...
│   └── dados_venda_cluster_10.csv
├── include/
│   ├── listaCompras.h
│   ├── similaridade.h
│   ├── recomendacao.h
│   └── utils.h
├── src/
│   ├── binding.cpp
│   ├── listaCompras.cpp
│   ├── similaridade.cpp
│   ├── recomendacao.cpp
│   └── main.cpp
└── outputs/
```

## Papel dos principais arquivos

- main.py
  - ponto de entrada principal em Python
  - recebe argumentos de linha de comando
  - chama as funcoes expostas pelo modulo C++

- lerCsv.py
  - leitura do CSV
  - gera estruturas base em Python:
    - clientes
    - mapaClientes
    - produtos
    - listaDeCompras

- setup.py
  - configuracao do build da extensao C++ com pybind11

- src/binding.cpp
  - expoe as funcoes C++ para Python no modulo recomendacao

- src/listaCompras.cpp
  - leitura de dados no caminho C++ (usado no executavel C++)

- src/similaridade.cpp
  - geracao de matriz de compras
  - geracao de matriz de intersecao
  - geracao de matriz de similaridade

- src/recomendacao.cpp
  - selecao de vizinhos
  - calculo de ranking
  - retorno da lista final de recomendacoes

- src/main.cpp
  - executavel C++ de apoio para testes/benchmark

## Requisitos

- Python 3.12 (recomendado)
- g++ com suporte a C++17
- pybind11
- setuptools

## Build da extensao C++

Com ambiente virtual ativo:

```bash
python setup.py build_ext --inplace
```

Esse comando gera/atualiza o arquivo do modulo nativo:

- recomendacao.cpython-312-x86_64-linux-gnu.so

## Execucao

```bash
python main.py <caminho_csv> <codigo_cliente> <k>
```

Exemplo:

```bash
python main.py data/dados_venda_cluster_0.csv 99CL9Y01 5
```

Onde:

- caminho_csv: arquivo de compras
- codigo_cliente: cliente alvo para recomendacao
- k: quantidade de produtos recomendados

## Formato do dataset

Cabecalho esperado:

```csv
DATA_COMPRA,COD_CLIENTE,COD_PRODUTO,NOME_PRODUTO
```

Exemplo de linha:

```csv
20200515,05090301,025728,SMARTPHONE SAMSUNG GAL J4 CORE
```

Campos utilizados no processamento atual:

- COD_CLIENTE
- COD_PRODUTO
- NOME_PRODUTO

## Observacoes

- O modulo C++ precisa ser recompilado sempre que houver alteracoes nos arquivos em src/ ou include/.
- Se houver mensagem grande com matriz no terminal, normalmente e resultado de erro de chamada em funcao pybind (mensagem de argumentos recebidos), nao um print explicito da matriz no codigo Python.

## Participantes

- Adiel Emilson da Silva
- Carlos Adauto de Sa Batista