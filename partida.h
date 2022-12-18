#pragma once

#include "fantasma.h"
#include "pacman.h"
#include "arquivo.h"
#include "labirinto.h"

#include <iostream>
#include <random>

#define MORTO 0
#define VIVO 1

/*!
    \file partida.h
*/

/*!
   \class Labirinto
   \brief Implementa o Labirinto do PacMan
*/
class Partida {
    private:
        /*!
            \brief 1 = Perdeu, 0 = Jogando
        */
        int perdeu;

        /*!
            \brief Quantidade de pacDots coletados
        */
        int pacDots;

    public:
        /*!
            \brief Atribui um valor ao parâmetro "perdeu"
            \param valor 1, caso o usuário tenha perdido, 0 caso contrário
        */
        void setPerdeu(int valor);

        /*!
            \brief Atribui um valor ao parâmetro "perdeu"
            \param p pacman
            \param f1 fantasma 1
            \param f2 fantasma 2
            \param f3 fantasma 3
            \param f4 fantasma 4
            \param f5 fantasma 5
            \param lab estrutura da classe labirinto
        */
        void jogo(Pacman p, Fantasma f1, Fantasma f2, Fantasma f3, Fantasma f4, Fantasma f5, Labirinto lab);

        /*!
            \brief Atribui um valor ao parâmetro "perdeu"
            \param dir Valor, de 1 a 4, sorteado aleatoriamente para decidir a direção do fantasma
            \return (char) Direção aleatória para a qual o fantasma deve se mover
        */
        char decideDirecao(int dir);

        /*!
            \brief Construtor da classe Partida
        */
        Partida();

        /*!
            \brief Destrutor da classe Partida
        */
        ~Partida();
};