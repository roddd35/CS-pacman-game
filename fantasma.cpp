#include "fantasma.h"

void Fantasma::setX(int x){
    this->x = x;
}

void Fantasma::setY(int y){
    this->y = y;
}

int Fantasma::getX(){
    return this->x;
}

int Fantasma::getY(){
    return this->y;
}

Fantasma::Fantasma(int x, int y){
    this->x = x;
    this->y = y;
    status = VIVO;
}

Fantasma::~Fantasma(){

}