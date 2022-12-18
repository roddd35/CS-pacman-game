#include "arquivo.h"

int Arquivo::getLinhas(){
    return this->qtd_lin;
}

int Arquivo::getColunas(){
    return this->qtd_col;
}

char** Arquivo::alocaEspaco(int qtd_lin, int qtd_col){
    char** m;

    m = (char**)malloc(sizeof(char *) * qtd_lin);

    for(int i = 0; i < qtd_lin; i++)
        m[i] = (char*)malloc(sizeof(char) * qtd_col);
    for(int i = 0; i < qtd_lin; i++)
        for(int j = 0; j < qtd_col; j++)
            m[i][j] = '\0';

    return m;
}


char** Arquivo::lerArquivo(){
    char** labirinto;
    char linha[MAX];
    char nomeArquivo[256];

    fstream arquivoLabirinto;

    cout << "Digite o nome do arquivo: ";
    cin >> nomeArquivo;

    arquivoLabirinto.open(nomeArquivo, ios::in);

    //  começar lendo as linhas e colunas e alocando espaço para o labirinto
    this->qtd_col = 27;
    this->qtd_lin = 31;

    labirinto = alocaEspaco(qtd_lin, qtd_col);

    for (int i = 0; i < qtd_lin; i++){
        arquivoLabirinto.getline(linha, MAX);
        for (int j = 0; j < qtd_col; j++){
                labirinto[i][j] = linha[j];
        }
    }   
    this->labirinto = labirinto;
    arquivoLabirinto.close();
    return labirinto;
}

Arquivo::Arquivo(){

}

Arquivo::~Arquivo(){
    free(this->labirinto);
}