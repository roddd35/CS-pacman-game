#include <gtest/gtest.h>

#include "fantasma.h"
#include "pacman.h"
#include "arquivo.h"
#include "labirinto.h"
#include "partida.h"

int main(int argc, char** argv){
    #ifdef TESTES_ON
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
    #else

    int qtdLin, qtdCol;
    char** m;
    Arquivo file;

    m = file.lerArquivo();
    qtdLin = file.getLinhas();
    qtdCol = file.getColunas();

    //  cria o labirinto e passa a matriz lida
    Labirinto lab(qtdLin, qtdCol, m);
    
    //  cria os personagens e define suas coordenadas iniciais
    //  obs: receber coordenadas dos fantasmas no arquivo
    Pacman pacman(qtdCol / 2, qtdLin / 2);

    Fantasma fantasma1(1, 1);
    Fantasma fantasma2(23, 1);
    Fantasma fantasma3(24, 16);
    Fantasma fantasma4(22, 29);
    Fantasma fantasma5(8, 25);
    
    //  posiciona os personagens no labirinto
    lab.definePosicoes(pacman, fantasma1, fantasma2, fantasma3, fantasma4, fantasma5);
    
    Partida match;
    match.jogo(pacman, fantasma1, fantasma2, fantasma3, fantasma4, fantasma5, lab);
    
    return 0;
    #endif
}

#ifdef TESTES_ON
    TEST(FantasmaSuite, movimentoFantasma){
        int qtdLin, qtdCol;
        char** m;
        Arquivo file;
        char** labirinto;
        char labAux[31][27];

        m = file.lerArquivo();
        qtdLin = file.getLinhas();
        qtdCol = file.getColunas();

        Labirinto lab(qtdLin, qtdCol, m);

        labirinto = lab.getLabirinto();

        for(int i = 0; i < lab.getLinhas(); i++){
            for(int j = 0; j < lab.getColunas(); j++){
                labAux[i][j] = labirinto[i][j];
            }
        }
        
        Fantasma fantasma1(1, 2);

        fantasma1 = lab.movimentaFantasma('w', fantasma1, labAux);
        fantasma1 = lab.movimentaFantasma('d', fantasma1, labAux);

        ASSERT_EQ(fantasma1.getX(),2);
        ASSERT_EQ(fantasma1.getY(),1);

        fantasma1 = lab.movimentaFantasma('a', fantasma1, labAux);
        fantasma1 = lab.movimentaFantasma('s', fantasma1, labAux);

        ASSERT_EQ(fantasma1.getX(),1);
        ASSERT_EQ(fantasma1.getY(),2);

    }
#endif

#ifdef TESTES_ON
    TEST(PacmanSuite, movimentoPacman){
        int qtdLin, qtdCol;
        char** m;
        Arquivo file;
        char** labirinto;
        char labAux[31][27];

        m = file.lerArquivo();
        qtdLin = file.getLinhas();
        qtdCol = file.getColunas();

        Labirinto lab(qtdLin, qtdCol, m);

        labirinto = lab.getLabirinto();

        for(int i = 0; i < lab.getLinhas(); i++){
            for(int j = 0; j < lab.getColunas(); j++){
                labAux[i][j] = labirinto[i][j];
            }
        }
        
        Pacman pacman(1, 2);

        pacman.setX(1);
        pacman.setY(2);

        pacman = lab.movimentaPacman('w', pacman, labAux);
        pacman = lab.movimentaPacman('d', pacman, labAux);

        ASSERT_EQ(pacman.getX(),2);
        ASSERT_EQ(pacman.getY(),1);

        pacman = lab.movimentaPacman('a', pacman, labAux);
        pacman = lab.movimentaPacman('s', pacman, labAux);

        ASSERT_EQ(pacman.getX(),1);
        ASSERT_EQ(pacman.getY(),2);

    }
#endif

#ifdef TESTES_ON
    TEST(PartidaSuite, verificaDirecao){
        char dir;

        Partida match;

        dir = match.decideDirecao(1);
        ASSERT_EQ(dir, 'W');

        dir = match.decideDirecao(2);
        ASSERT_EQ(dir, 'A');

        dir = match.decideDirecao(3);
        ASSERT_EQ(dir, 'S');
        
        dir = match.decideDirecao(4);
        ASSERT_EQ(dir, 'D');
    }
#endif