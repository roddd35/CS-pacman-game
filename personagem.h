#pragma once

#include <iostream>

using namespace std;


/*!
    \file personagem.h
*/

/*!
   \class Personagem
   \brief Implementa atributos básicos do personagem
*/
class Personagem {
    protected:
        /*!
            \brief Coordenada do personagem no eixo X
        */
        int x;

        /*!
            \brief Coordenada do personagem no eixo Y
        */
        int y;

        /*!
            \brief Direção de movimento do personagem
        */
        char direcao;

    public:
        /*!
            \brief Define uma direção para o personagem
        */
        void setDirecao(char direcao);

        /*!
            \brief Recebe, em uma variável, a direção de um personagem
            \return (char) Direção do personagem
        */
        char getDirecao();
};