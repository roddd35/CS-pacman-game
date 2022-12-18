#pragma once

#include <iostream>
#include <fstream>
#define MAX 256

using namespace std;

/*!
    \file arquivo.h
*/

/*!
   \class Arquivo
   \brief Implementa a leitura do arquivo de entrada
*/
class Arquivo {
    private:
        /*!
            \brief Labirinto de entrada
        */
        char** labirinto;

        /*!
            \brief Quantidade de linhas do labirinto
        */
        int qtd_lin;

        /*!
            \brief Quantidade de colunas do labirinto
        */
        int qtd_col;

    public:
        /*!
            \brief Construtor da classe Arquivo
        */
        Arquivo();

        /*!
            \brief Destrutor da classe Arquivo
        */
        ~Arquivo();

        /*!
            \brief Devolve, em uma variável, a quantidade de linhas do labirinto
            \return (int) Quantidade de linhas do labirinto
        */
        int getLinhas();

        /*!
            \brief Devolve, em uma variável, a quantidade de colunas do labirinto
            \return (int) Quantidade de colunas do labirinto
        */
        int getColunas();

        /*!
            \brief Aloca, dinamicamente, espaço para o labirinto na memória
            \param qtd_lin Quantidade de Linhas que o labirinto deve ter
            \param qtd_col Quantidade de Colunas que o labirinto deve ter
            \return (char**) Matriz do labirinto, com espaço alocado dinamicamente
        */
        char** alocaEspaco(int qtd_lin, int qtd_col);

        /*!
            \brief Abre, lê e fecha o arquivo de entrada
            \return (char**) Matriz do labirinto, preenchida
        */
        char** lerArquivo();
};