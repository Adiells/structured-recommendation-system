from setuptools import setup
from pybind11.setup_helpers import Pybind11Extension, build_ext

ext_modules = [
    Pybind11Extension(
        "recomendacao",
        [
            "src/binding.cpp", 
            "src/similaridade.cpp", 
            "src/recomendacao.cpp"
        ],
        include_dirs=['include'],
        cxx_std=17,
    ),
]

setup(
    name="recomendacao",
    version="0.1.0",
    description="Exemplo de integração Python + C++ com pybind11",
    ext_modules=ext_modules,
    cmdclass={"build_ext": build_ext},
    zip_safe=False,
)