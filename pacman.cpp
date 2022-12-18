#include "pacman.h"
// #include <gtest/gtest.h>

void Pacman::setStatus(int status){
    this->status = status;
}

int Pacman::getStatus(){
    return this->status;
}

void Pacman::setPontos(int pontos){
    this->pontos = pontos;
}

int Pacman::getPontos(){
    return this->pontos;
}

void Pacman::setX(int x){
    this->x = x;
}

void Pacman::setY(int y){
    this->y = y;
}

int Pacman::getX(){
    return this->x;
}

int Pacman::getY(){
    return this->y;
}

Pacman::Pacman(int qtdCol, int qtdLin){
    this->x = qtdCol / 2;
    this->y = qtdLin / 2;
    this->status = VIVO;
}

Pacman::~Pacman(){  //colocar %d numero de pacdots comidos

}