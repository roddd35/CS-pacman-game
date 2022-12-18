#pragma once

#include "fantasma.h"
#include "pacman.h"
#include <iostream>
#include <fstream>

using namespace std;

/*!
    \file labirinto.h
*/

/*!
   \class Labirinto
   \brief Implementa o Labirinto do PacMan
*/
class Labirinto {
    private:
        /*!
            \brief Quantidade de Linhas do labirinto
        */
        int qtd_linhas;
        /*!
            \brief Quantidade de colunas do labirinto
        */
        int qtd_colunas;
        /*!
            \brief Matriz que guarda o labirinto
        */
        char** lab;

    public:
        /*!
            \brief Atribui os personagens no labirinto, ao início da partida
            \param x Posição do personagem no eixo X
            \param y Posição do personagem no eixo Y
            \param sprite Símbolo do personagem a ser colocado no labirinto
        */
        void atualizaLabirinto(int x, int y, char sprite);

        /*!
            \brief Objeto suporte, faz a chamada de "atualizaLabirinto" para todos os personagens
            \param p Pacman
            \param f1 Fantasma 1
            \param f2 Fantasma 2
            \param f3 Fantasma 3
            \param f4 Fantasma 4
            \param f5 Fantasma 5
        */
        void definePosicoes(Pacman p, Fantasma f1, Fantasma f2, Fantasma f3, Fantasma f4, Fantasma f5);

        /*!
            \brief Imprime, iterativamente, o labirinto
        */
        void imprimeLabirinto();

        /*!
            \brief Objeto destinado a obter em uma variável o labirinto
            \return retorno: (char**) matriz do labirinto
        */
        char** getLabirinto();

        /*!
            \brief Objeto destinado a contar a quantidade de PacDots no tabuleiro
            \param lab Labirinto da classe Labirinto
            \return retorno: (int) quantidade de PacDots
        */
        int contaPacDots(Labirinto lab);

        /*!
            \brief Receber a quantidade de linhas do tabuleiro
            \return retorno: (int) quantidade de linhas
        */
        int getLinhas();

        /*!
            \brief Receber a quantidade de colunas do tabuleiro
            \return retorno: (int) quantidade de colunas
        */
        int getColunas();

        /*!
            \brief Realiza a movimentação do PacMan no labirinto
            \param mov Movimento desejado pelo usuário
            \param p Pacman da classe Pacman
            \param labAux Labirinto auxiliar
            \return retorno: (Pacman) Pacman com os dados atualizados, após o movimento
        */
        Pacman movimentaPacman(char mov, Pacman p, char labAux[31][27]);
        
        /*!
            \brief Realiza a movimentação do Fantasma no labirinto
            \param mov Movimento escolhido pseudo-aleatoriamente
            \param f Fantasma da classe Fantasma
            \param labAux Labirinto auxiliar
            \return retorno: (Fantasma) Fantasma com os dados atualizados, após o movimento
        */
        Fantasma movimentaFantasma(char mov, Fantasma f, char labAux[31][27]);

        /*!
            \brief Construtor da classe Labirinto
            \param qtd_lin Quantidade de Linhas do labirinto
            \param qtd_col Quantidade de Colunas do labirinto
            \param lab Labirinto, da classe labirinto
        */
        Labirinto(int qtd_lin, int qtd_col, char** lab);

        /*!
            \brief Destrutor da classe Labirinto
        */
        ~Labirinto();
};