# Sistema de Recomendação

Este projeto tem como objetivo implementar um **sistema de recomendação de produtos para clientes de lojas de varejo**, desenvolvido como parte da disciplina de **Programação Estruturada**.

O sistema utiliza o **histórico de compras de clientes** para organizar os dados em estruturas apropriadas e, posteriormente, aplicar algoritmos de recomendação baseados em similaridade entre clientes.

A ideia principal é que **clientes com comportamentos de compra semelhantes tendem a se interessar pelos mesmos produtos**.

---

# Objetivo do Projeto

O objetivo geral é construir um sistema capaz de **recomendar produtos para clientes** a partir do histórico de compras registrado em arquivos CSV.

O sistema irá:

- Ler bases de dados contendo registros de compras
- Organizar os dados em estruturas internas
- Representar relações entre clientes e produtos
- Calcular similaridade entre clientes
- Recomendar produtos que um cliente ainda não comprou

A abordagem utilizada no projeto é baseada em **filtragem colaborativa baseada em usuário**, utilizando o **método da vizinhança**.

---

# Estrutura Atual do Projeto

Até o momento foi implementado o **módulo ListaCompras**, responsável por ler os arquivos de dados e organizar as informações em estruturas de dados internas.

Esse módulo realiza:

- Leitura de arquivos CSV contendo registros de compras
- Armazenamento dos códigos de clientes
- Criação de um mapeamento entre **código original do cliente** e **índice interno utilizado pelo sistema**

As principais estruturas utilizadas são:

- `vector<string>` para armazenar os códigos de clientes
- `map<string, int>` para associar o código do cliente a um índice interno

Essas estruturas serão utilizadas posteriormente para construir as estruturas necessárias para o sistema de recomendação.

---

# Estrutura dos Arquivos


```
.
├── main.cpp
├── listaCompras.cpp
├── listaCompras.h
└── data/
    └── dados_venda_cluster_X.csv
```

#
### Descrição dos arquivos

**main.cpp**

Programa de teste responsável por:

- Ler os arquivos de dados
- Chamar as funções do módulo `ListaCompras`
- Exibir as estruturas geradas

**listaCompras.h**

Arquivo de cabeçalho contendo:

- Definição da estrutura `Produto`
- Protótipos das funções do módulo

**listaCompras.cpp**

Implementação das funções responsáveis por:

- Leitura dos arquivos CSV
- Processamento dos dados
- Armazenamento das informações em estruturas auxiliares

---

# Estrutura do Dataset

Os arquivos de entrada são arquivos **CSV** contendo registros de compras.  
Cada linha representa uma compra realizada por um cliente.

Formato dos dados:


```
DATA_COMPRA,COD_CLIENTE,COD_PRODUTO,NOME_PRODUTO
20200515,05090301,025728,SMARTPHONE SAMSUNG GAL J4 CORE
20200515,05190001,025172,SMARTPHONE LG K9
```

### Campos

- **DATA_COMPRA** – data da compra no formato `AAAAMMDD`
- **COD_CLIENTE** – identificador único do cliente
- **COD_PRODUTO** – identificador único do produto
- **NOME_PRODUTO** – nome descritivo do produto

---

# Tecnologias Utilizadas

- **C (programação estruturada)**
- Uso pontual de recursos do **C++ STL** para estruturas de dados
  - `vector`
  - `map`
- Leitura de arquivos utilizando `fscanf`

---

# Próximas Etapas do Projeto

As próximas etapas do projeto incluem:

- Construção da **lista de produtos comprados por cada cliente**
- Construção da **matriz de compras**
- Cálculo da **matriz de similaridade entre clientes**
- Implementação do **algoritmo de recomendação de produtos**

---

# Participantes

- **Adiel Emilson da Silva**
- **Carlos Adauto de Sá Batista**