#include "partida.h"

void Partida::jogo(Pacman p, Fantasma f1, Fantasma f2, Fantasma f3, Fantasma f4, Fantasma f5, Labirinto lab){
    int qtdPacDots = 0, maxPontos, auxDir;
    char direcao;
    char** labirinto;
    char labAux[31][27];

    //CRIAR UM LABIRINTO AUXILIAR, PARA EVITAR QUE O FANTASMA PEGUE PACDOTS
    labirinto = lab.getLabirinto();

    for(int i = 0; i < lab.getLinhas(); i++){
        for(int j = 0; j < lab.getColunas(); j++){
            labAux[i][j] = labirinto[i][j];
        }
    }

    qtdPacDots = lab.contaPacDots(lab);
    maxPontos = qtdPacDots;
    p.setPontos(qtdPacDots);
    setPerdeu(0);

    while(!this->perdeu){
        lab.imprimeLabirinto();
        cout << "Direção (a - esquerda, d - direita, w - cima, s - baixo): ";
        cin >> direcao;
        p = lab.movimentaPacman(direcao, p, labAux);

        //DEFININDO  MOVIMENTO DOS FANTASMAS
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<>dist(1,4);

        auxDir = dist(gen);
        direcao = decideDirecao(auxDir);
        f1 = lab.movimentaFantasma(direcao, f1, labAux);


        auxDir = dist(gen);
        direcao = decideDirecao(auxDir);
        f2 = lab.movimentaFantasma(direcao, f2, labAux);


        auxDir = dist(gen);
        direcao = decideDirecao(auxDir);
        f3 = lab.movimentaFantasma(direcao, f3, labAux);


        auxDir = dist(gen);
        direcao = decideDirecao(auxDir);
        f4 = lab.movimentaFantasma(direcao, f4, labAux);

        
        auxDir = dist(gen);
        direcao = decideDirecao(auxDir);
        f5 = lab.movimentaFantasma(direcao, f5, labAux);

        //VERIFICA SE O JOGO ACABOU
        if(p.getPontos() == 0){
            lab.imprimeLabirinto();
            cout << "Congratulations! Pontos = " << maxPontos << endl;
            break;
        }
        if((p.getX() == f1.getX() && p.getY() == f1.getY()) || (p.getX() == f2.getX() && p.getY() == f2.getY()) || (p.getX() == f3.getX() && p.getY() == f3.getY()) || (p.getX() == f4.getX() && p.getY() == f4.getY()) || (p.getX() == f5.getX() && p.getY() == f5.getY())){
            lab.atualizaLabirinto(p.getX(), p.getY(), 'X');
            lab.imprimeLabirinto();
            setPerdeu(1);
            cout << "Game over! Pontos = " << maxPontos - p.getPontos() << endl;
        }
    }
}

void Partida::setPerdeu(int valor){
    if(valor == 1)
        this->perdeu = 1;
    else
        this->perdeu = 0;
}

char Partida::decideDirecao(int dir){
    char direcao;

    if(dir == 1)
        direcao = 'W';
    else if(dir == 2)
        direcao = 'A';
    else if(dir == 3)
        direcao = 'S';
    else
        direcao = 'D';
    return direcao;
}

Partida::Partida(){

}

Partida::~Partida(){
    
}