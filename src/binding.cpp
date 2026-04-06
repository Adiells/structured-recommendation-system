#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "listaCompras.h"
#include "similaridade.h"
#include "recomendacao.h"

namespace py = pybind11;

PYBIND11_MODULE(recomendacao, m){
    m.doc() = "Sistema de recomendação de produtos";

    m.def(
        "gerar_matriz_compras_grande",
        &gerarMatrizComprasGrande,
        "Recebe uma lista de compras, o numero de clientes e o numero de produtos e retorna uma matriz de compras. "
    );

    m.def(
        "gerar_matriz_intersecao",
        &gerarMatrizIntersecao,
        "Recebe uma matriz de compras, numero de clientes, numero de produtos e opcionalmente otimizada.",
        py::arg("matriz"),
        py::arg("numero_de_clientes"),
        py::arg("numero_de_produtos"),
        py::arg("otimizada") = true
    );

    m.def(
        "gerar_matriz_similaridade",
        &gerarMatrizSimilaridade,
        "Recebe uma matriz de intersecao e retorna uma matriz de similaridade. "
    );

    m.def(
        "recomendacao",
        &recomendacao,
        "Recebe uma matriz de similaridade, um vetor de clientes, um vetor de produtos, um mapa de clientes, uma matriz de compras, o codigo do cliente e a quantidade de produtos para recomendação e retorna uma lista de produtos recomendados. "
    );
}