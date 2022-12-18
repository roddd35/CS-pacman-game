#pragma once

#include "personagem.h"

#include <iostream>
#include <fstream>
#include <random>

#define MORTO 0
#define VIVO 1

using namespace std;


/*!
    \file pacman.h
*/

/*!
   \class Pacman
   \brief Subclasse de Personagem, representa o Pacman
*/
class Pacman: public Personagem {
    private:
        /*!
            \brief Define se o Pacman está vivo ou morto
        */
        int status;
        /*!
            \brief Pontuação, decrescente, do PacMan
        */
        int pontos;
    
    public:
        /*!
            \brief Define a coordenada do PacMan no eixo X
            \param x Valor inteiro da coordenada
        */
        void setX(int x);

        /*!
            \brief Define a coordenada do PacMan no eixo Y
            \param y Valor inteiro da coordenada
        */
        void setY(int y);

        /*!
            \brief Define status de vivo ou morto ao PacMan
            \param status Valor inteiro, 1 = VIVO, 0 = MORTO
        */
        void setStatus(int status);

        /*!
            \brief Define a quantidade de pontos do PacMan
            \param pontos Valor inteiro, que atualiza a quantidade de pontos na classe
        */
        void setPontos(int pontos);

        /*!
            \brief Recebe, em uma variável, a quantidade de pontos
            \return (int) Quantidade de Pontos do PacMan
        */
        int getPontos();

        /*!
            \brief Recebe, em uma variável, o status 
            \return (int) Status do PacMan
        */
        int getStatus();

        /*!
            \brief Recebe, em uma variável, a coordenada X
            \return (int) Coordenada X
        */
        int getX();

        /*!
            \brief Recebe, em uma variável, a coordenada Y
            \return (int) Coordenada Y
        */
        int getY();

        /*!
            \brief Construtor da classe Pacman, define posição inicial do personagem
            \param x Coordenada inicial do eixo X
            \param y Coordenada inicial do eixo Y
        */
        Pacman(int x, int y);

        /*!
            \brief Destrutor da classe Pacman
        */
        ~Pacman();
};