#include "algoritmos.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/* Preencher os campos abaixo
Participantes do grupo
Nome: Joaquim Pedro do Nascimento Moreira de Jesus      Matrícula: 2025.1.08.014
Nome: Murilo Antonio da Silva                           Matrícula: 2025.1.08.0
Nome: Luiz Fernando Ferreira Cabral                     Matrícula: 2025.1.08.032
Nome: Victória Almeida Tambasco                         Matrícula: 2025.1.08.0
Nome: Luiz Gabriel da Silva Cabrera                     Matrícula: 2025.1.08.0
*/

bool comparacao_de_base_DNA(char b1, char b2) {
    // Pares específicos (A-T e C-G)
    if ((b1 == 'A' && b2 == 'T') || (b1 == 'T' && b2 == 'A') || (b1 == 'C' && b2 == 'G') || (b1 == 'G' && b2 == 'C'))
        return true;
    
    // Mismatch (Bases totalmente diferentes)
    return false;
}

long int programacao_dinamica(char *s1, char *s2) {
    long int pontuacao = 0;
    
    // 1. Obter o comprimento das strings
    int n = strlen(s1);
    int m = strlen(s2);

    // 2. Alocação Linear
    // Alocamos (n+1) * (m+1) posições de inteiros
    int *matriz = malloc((n + 1) * (m + 1) * sizeof(int));

    if (matriz == NULL) return NULL; // Tratamento de erro

    // 3. Preenchendo primeira LINHA (Horizontal)
    // Representa o alinhamento de s2 com uma string vazia.
    // Índices: 0, 1, 2, ..., m
    matriz[0] = 0;
    for(int j = 1; j <= m; j++) {
        matriz[j] = matriz[j - 1] - 2;
    }

    // 4. Preenchendo primeira COLUNA (Vertical)
    // Representa o alinhamento de s1 com uma string vazia.
    // Índices: 0, (m+1), 2*(m+1), ..., n*(m+1)
    for(int i = 1; i <= n; i++) {
        int atual = i * (m + 1);
        int anterior = (i - 1) * (m + 1);
        matriz[atual] = matriz[anterior] - 2;
    }

    // 5. Cálculo do restante da matriz
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int diag = i * (m + 1) + j; // índice atual
            int diag_ant = (i-1) * (m+1) + (j-1);
            int cima = (i-1) * (m + 1) + j;
            int esquerda = i * (m + 1) + (j-1);
            int score_diag;

            // 1. Opção Diagonal (Pareamento ou Mismatch)
            if (comparacao_de_base_DNA(s1[i-1], s2[j-1])) {
                score_diag = matriz[diag_ant] + 2;
            } else {
                score_diag = matriz[diag_ant] - 1;
            }

            // 2. Opções de Gap (Cima e Esquerda) - 
            int score_cima = matriz[cima] - 2; 
            int score_esq  = matriz[esquerda] - 2;

            // 3. Escolher o máximo entre as três opções
            int max = score_diag;
            if (score_cima > max) max = score_cima;
            if (score_esq > max) max = score_esq;

            matriz[diag] = max;  
        }
    }

    pontuacao = matriz[n * (m + 1) + m];
    free(matriz);

    /* Esta retorno também é obrigatório e não deve ser retirado*/
    return pontuacao;
}

long int guloso(char *s1, char *s2) {
    long int pontuacao = 0;

    /***********************
    ***********************
     Implementar código aqui
    ************************
    ***********************/

    /* Esta retorno também é obrigatório e não deve ser retirado*/
    return pontuacao;
}
