#include <stdio.h>

#define TAMANHO 10  // Define o tamanho do tabuleiro 10x10
#define NAVIO 3      // Define o tamanho fixo dos navios

// Função para inicializar o tabuleiro preenchendo com '0' (água)
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0; // Preenchendo com água
        }
    }
}

// Função para exibir o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]); // Exibe cada posição do tabuleiro
        }
        printf("\n"); // Nova linha ao final de cada linha do tabuleiro
    }
}

// Função para validar se um navio pode ser posicionado em determinada coordenada
int validarPosicao(int linha, int coluna, int orientacao, int tabuleiro[TAMANHO][TAMANHO]) {
    if (orientacao == 0) { // Se for horizontal
        if (coluna + NAVIO > TAMANHO) return 0; // Verifica se ultrapassa o limite direito
        for (int i = 0; i < NAVIO; i++) {
            if (tabuleiro[linha][coluna + i] != 0) return 0; // Verifica sobreposição
        }
    } else { // Se for vertical
        if (linha + NAVIO > TAMANHO) return 0; // Verifica se ultrapassa o limite inferior
        for (int i = 0; i < NAVIO; i++) {
            if (tabuleiro[linha + i][coluna] != 0) return 0; // Verifica sobreposição
        }
    }
    return 1; // Retorna verdadeiro se a posição for válida
}

// Função para posicionar um navio no tabuleiro
void posicionarNavio(int linha, int coluna, int orientacao, int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < NAVIO; i++) {
        if (orientacao == 0) {
            tabuleiro[linha][coluna + i] = 3; // Posiciona navio horizontalmente
        } else {
            tabuleiro[linha + i][coluna] = 3; // Posiciona navio verticalmente
        }
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO]; // Declara o tabuleiro
    inicializarTabuleiro(tabuleiro); // Inicializa o tabuleiro com água

    // Define as coordenadas e orientações dos navios
    int linha1 = 2, coluna1 = 3, orientacao1 = 0; // Navio horizontal
    int linha2 = 5, coluna2 = 6, orientacao2 = 1; // Navio vertical

    // Valida e posiciona o primeiro navio
    if (validarPosicao(linha1, coluna1, orientacao1, tabuleiro)) {
        posicionarNavio(linha1, coluna1, orientacao1, tabuleiro);
    }

    // Valida e posiciona o segundo navio
    if (validarPosicao(linha2, coluna2, orientacao2, tabuleiro)) {
        posicionarNavio(linha2, coluna2, orientacao2, tabuleiro);
    }

    // Exibe o tabuleiro final com os navios posicionados
    exibirTabuleiro(tabuleiro);
    return 0;
}
