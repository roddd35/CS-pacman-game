#include "labirinto.h"

#define MAX 256

int Labirinto::contaPacDots(Labirinto lab){
    int qtd = 0;
    for(int i = 0; i < lab.getLinhas(); i++){
        for(int j = 0; j < lab.getColunas(); j++){
            if(this->lab[i][j] == '.')
                qtd++;
        }
    }
    return qtd;
}

int Labirinto::getLinhas(){
    return this->qtd_linhas;
}

int Labirinto::getColunas(){
    return this->qtd_colunas;
}

Pacman Labirinto::movimentaPacman(char mov, Pacman p, char labAux[31][27]){
    // -*** VERTICAL ***-
    if(mov == 'W' || mov == 'w'){
        //  SOMAR PONTOS E MOVIMENTAR PRA CIMA
        if(this->lab[p.getY() - 1][p.getX()] != '*' && p.getY() - 1 >= 0){
            if(this->lab[p.getY() - 1][p.getX()] == '.')
                p.setPontos(p.getPontos() - 1);
            this->lab[p.getY() - 1][p.getX()] = 'C';
            this->lab[p.getY()][p.getX()] = ' ';
            labAux[p.getY()][p.getX()] = ' ';
            
            p.setY(p.getY() - 1);
        }
        //  APARECER O PACMAN DO OUTRO LADO DO TABULEIRO
        else if(p.getY() - 1 < 0){
            if(this->lab[this->qtd_linhas - 1][p.getX()] == '.')
                p.setPontos(p.getPontos() - 1);
            this->lab[p.getY()][p.getX()] = ' ';
            labAux[p.getY()][p.getX()] = ' ';
            this->lab[this->qtd_linhas][p.getX()] = 'C';
            p.setY(this->qtd_colunas - 1);
        }
    }

    else if(mov == 'S' || mov == 's'){
        //  SOMAR PONTOS E MOVIMENTAR PRA BAIXO
        if(this->lab[p.getY() + 1][p.getX()] != '*' && p.getY() + 1 < this->qtd_linhas){
            if(this->lab[p.getY() + 1][p.getX()] == '.')
                p.setPontos(p.getPontos() - 1);
            this->lab[p.getY() + 1][p.getX()] = 'C';
            this->lab[p.getY()][p.getX()] = ' ';
            labAux[p.getY()][p.getX()] = ' ';
            p.setY(p.getY() + 1);
        }
        //  APARECER O PACMAN DO OUTRO LADO DO TABULEIRO
        else if(p.getY() + 1 >= this->qtd_linhas){
            if(this->lab[0][p.getX()] == '.')
                p.setPontos(p.getPontos() - 1);
            this->lab[p.getY()][p.getX()] = ' ';
            labAux[p.getY()][p.getX()] = ' ';
            this->lab[0][p.getX()] = 'C';
            p.setY(0);
        }
    }

    // -*** HORIZONTAL ***-

    else if(mov == 'D' || mov == 'd'){
        //  SOMAR PONTOS E MOVIMENTAR PRA DIREITA
        if(this->lab[p.getY()][p.getX() + 1] != '*' && p.getX() + 1 < this->qtd_colunas){
            if(lab[p.getY()][p.getX() + 1] == '.')
                p.setPontos(p.getPontos() - 1);
            this->lab[p.getY()][p.getX() + 1] = 'C';
            this->lab[p.getY()][p.getX()] = ' ';
            labAux[p.getY()][p.getX()] = ' ';
            p.setX(p.getX() + 1);
        }
        //  APARECER O PACMAN DO OUTRO LADO DO TABULEIRO
        else if(p.getX() + 1 >= this->qtd_colunas){
            if(this->lab[p.getY()][0] == '.')
                p.setPontos(p.getPontos() - 1);
            this->lab[p.getY()][p.getX()] = ' ';
            labAux[p.getY()][p.getX()] = ' ';
            this->lab[p.getY()][0] = 'C';
            p.setX(0);
        }
    }

    else if(mov == 'A' || mov == 'a') {
        //  SOMAR PONTOS E MOVIMENTAR PRA ESQUERDA
        if(this->lab[p.getY()][p.getX() - 1] != '*' && p.getX() - 1 >= 0){
            if(this->lab[p.getY()][p.getX() - 1] == '.')
                p.setPontos(p.getPontos() - 1);
            this->lab[p.getY()][p.getX() - 1] = 'C';
            this->lab[p.getY()][p.getX()] = ' ';
            labAux[p.getY()][p.getX()] = ' ';
            p.setX(p.getX() - 1);
        }
        //  APARECER O PACMAN DO OUTRO LADO DO TABULEIRO
        else if(p.getX() - 1 < 0){
            if(this->lab[p.getY()][this->qtd_colunas - 1] == '.')
                p.setPontos(p.getPontos() - 1);
            this->lab[p.getY()][p.getX()] = ' ';
            labAux[p.getY()][p.getX()] = ' ';
            this->lab[p.getY()][this->qtd_colunas - 1] = 'C';
            p.setX(this->qtd_colunas - 1);
        }
    }
    return p;
}

//VERIFICAR SE ANTES DO MOVIMENTO DELE TINHA UM PACDOT NA POSICAO, GUARDAR SE TEM NA NOVA
Fantasma Labirinto::movimentaFantasma(char mov, Fantasma f, char labAux[31][27]){

// -*** VERTICAL ***-
    if(mov == 'W' || mov == 'w'){
        //  MOVIMENTAR PRA CIMA
        if(this->lab[f.getY() - 1][f.getX()] != '*' && f.getY() - 1 >= 0){
            this->lab[f.getY() - 1][f.getX()] = 'F';
            if(labAux[f.getY()][f.getX()] == '.')
                this->lab[f.getY()][f.getX()] = '.';
            else
                this->lab[f.getY()][f.getX()] = ' ';
            f.setY(f.getY() - 1);
        }
        //  APARECER O FANTASMA DO OUTRO LADO DO TABULEIRO
        else if(f.getY() - 1 < 0){
            this->lab[f.getY()][f.getX()] = ' ';
            this->lab[this->qtd_linhas - 1][f.getX()] = 'F';
            if(labAux[f.getY()][f.getX()] == '.')
                this->lab[f.getY()][f.getX()] = '.';
            else
                this->lab[f.getY()][f.getX()] = ' ';
            f.setY(this->qtd_linhas - 1);
        }
    }

    else if(mov == 'S' || mov == 's'){
       //   MOVIMENTAR PARA BAIXO 
        if(this->lab[f.getY() + 1][f.getX()] != '*' && f.getY() + 1 < this->qtd_linhas){
            this->lab[f.getY() + 1][f.getX()] = 'F';
            if(labAux[f.getY()][f.getX()] == '.')
                this->lab[f.getY()][f.getX()] = '.';
            else
                this->lab[f.getY()][f.getX()] = ' ';
            f.setY(f.getY() + 1);
        }
        //  APARECER O FANTASMA DO OUTRO LADO DO TABULEIRO
        else if(f.getY() + 1 >= this->qtd_linhas){
            this->lab[f.getY()][f.getX()] = ' ';
            this->lab[0][f.getX()] = 'F';
            if(labAux[f.getY()][f.getX()] == '.')
                this->lab[f.getY()][f.getX()] = '.';
            else
                this->lab[f.getY()][f.getX()] = ' ';
            f.setY(0);
        }
    }

    // -*** HORIZONTAL ***-

    else if(mov == 'D' || mov == 'd'){
        //  MOVIMENTAR PRA DIREITA
        if(this->lab[f.getY()][f.getX() + 1] != '*' && f.getX() + 1 < this->qtd_colunas){
            this->lab[f.getY()][f.getX() + 1] = 'F';
            if(labAux[f.getY()][f.getX()] == '.')
                this->lab[f.getY()][f.getX()] = '.';
            else
                this->lab[f.getY()][f.getX()] = ' ';
            f.setX(f.getX() + 1);
        }
        //  APARECER O FANTASMA DO OUTRO LADO DO TABULEIRO
        else if(f.getX() + 1 >= this->qtd_colunas){
            this->lab[f.getY()][f.getX()] = ' ';
            this->lab[f.getY()][0] = 'F';
            if(labAux[f.getY()][f.getX()] == '.')
                this->lab[f.getY()][f.getX()] = '.';
            else
                this->lab[f.getY()][f.getX()] = ' ';
            f.setX(0);
        }
    }

    else if(mov == 'A' || mov == 'a') {
        //  MOVIMENTAR PRA ESQUERDA
        if(this->lab[f.getY()][f.getX() - 1] != '*' && f.getX() - 1 >= 0){
            this->lab[f.getY()][f.getX() - 1] = 'F';
            if(labAux[f.getY()][f.getX()] == '.')
                this->lab[f.getY()][f.getX()] = '.';
            else
                this->lab[f.getY()][f.getX()] = ' ';
            f.setX(f.getX() - 1);
        }
        //  APARECER O FANTASMA DO OUTRO LADO DO TABULEIRO
        else if(f.getX() - 1 < 0){
            this->lab[f.getY()][f.getX()] = ' ';
            this->lab[f.getY()][this->qtd_colunas - 1] = 'F';
            if(labAux[f.getY()][f.getX()] == '.')
                this->lab[f.getY()][f.getX()] = '.';
            else
                this->lab[f.getY()][f.getX()] = ' ';
            f.setX(this->qtd_colunas - 1);
        }
    }

    return f;
}

void Labirinto::atualizaLabirinto(int x, int y, char sprite){
    this->lab[y][x] = sprite;
}

void Labirinto::definePosicoes(Pacman p, Fantasma f1, Fantasma f2, Fantasma f3, Fantasma f4, Fantasma f5){
    atualizaLabirinto(p.getX(), p.getY(), 'C');
    atualizaLabirinto(f1.getX(), f1.getY(), 'F');
    atualizaLabirinto(f2.getX(), f2.getY(), 'F');
    atualizaLabirinto(f3.getX(), f3.getY(), 'F');
    atualizaLabirinto(f4.getX(), f4.getY(), 'F');
    atualizaLabirinto(f5.getX(), f5.getY(), 'F');
}

void Labirinto::imprimeLabirinto(){
    for(int i = 0; i < this->qtd_linhas; i++){
        for(int j = 0; j < this->qtd_colunas; j++){
            cout << this->lab[i][j];
        }
        cout << endl;
    }
}

char** Labirinto::getLabirinto(){
    return this->lab;
}

Labirinto::Labirinto(int qtd_lin, int qtd_col, char** labirinto){
    this->qtd_linhas = qtd_lin;
    this->qtd_colunas = qtd_col;
    this->lab = labirinto;
}

Labirinto::~Labirinto(){
    // tava dando erro: double free
    // for (int i = 0; i < this->qtd_linhas; i++) free(this->lab[i]);
    // free(this->lab);
}