#pragma once

#include "personagem.h"

#include <iostream>
#include <random>

#define MORTO 0
#define VIVO 1

using namespace std;

/*!
    \file fantasma.h
*/

/*!
   \class Fantasma
   \brief Implementa a subclasse Fantasma
*/
class Fantasma: public Personagem {
    private:
        /*!
            \brief Status do fantasma, 1 = VIVO, 0 = MORTO
        */
        int status;
    
    public:
        /*!
            \brief Define um valor para a coordenada X, do fantasma
            \param x Valor da coordenada
        */
        void setX(int x);

        /*!
            \brief Define um valor para a coordenada Y, do fantasma
            \param y Valor da coordenada
        */
        void setY(int y);

        /*!
            \brief Recebe, em uma variável, o valor da coordenada X do fantasma
            \return (int) Valor de X
        */
        int getX();

        /*!
            \brief Recebe, em uma variável, o valor da coordenada X do fantasma
            \return (int) Valor de Y
        */
        int getY();

        /*!
            \brief Define o símbolo F ao fantasma
            \param sprite Símbolo definido ao fantasma
        */
        void setSprite(char sprite);

        /*!
            \brief Construtor da classe Fantasma
            \param x Coordenada X inicial do fantasma
            \param y Coordenada Y inicial do fantasma
        */
        Fantasma(int x, int y);

        /*!
            \brief Destrutor da classe Fantasma
        */
        ~Fantasma();
};