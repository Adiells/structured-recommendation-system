#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <map>
#include <iostream>

using namespace std;

template <typename T>
void imprimirVetor(vector<T>& vetor){
    int i = 1;
    for(auto& elemento : vetor){
        cout << "Código: " << i << " " << elemento << endl;
        i++;
    }
}

template <typename K, typename V>
void imprimirMapa(map<K, V>& mapa){
    for(auto& elemento : mapa){
        cout << "Código: " << elemento.first << " | Índice interno: " << elemento.second << endl;
    }
}

template <typename T>
void imprimirMatriz(vector<vector<T>>& matriz){
    for(int i = 0; i < matriz.size(); i++){
        cout << "Cliente [" << i << "]: ";
        for(int j = 0; j < matriz[i].size(); j++){
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

#endif