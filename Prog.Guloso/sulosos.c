#include "algoritmos.h"
#include <string.h>

/* Participantes do grupo
Nome: Joaquim Pedro do Nascimento Moreira de Jesus      Matrícula: 2025.1.08.014
Nome: Murilo Antonio da Silva                           Matrícula: 2025.1.08.0
Nome: Luiz Fernando Ferreira Cabral                     Matrícula: 2025.1.08.032
Nome: Victória Almeida Tambasco                         Matrícula: 2025.1.08.0
Nome: Luiz Gabriel da Silva Cabrera                     Matrícula: 2025.1.08.0
*/

long int programacao_dinamica(char *s1, char *s2) {
    long int pontuacao = 0;
    // Lógica da Programação Dinâmica (a ser implementada)
    return pontuacao;
}

long int guloso(char *s1, char *s2) {
    long int pontuacao = 0;
    int i = 0, j = 0;
    int n = strlen(s1);
    int m = strlen(s2);

    // O loop percorre as sequências enquanto houver bases em ambas
    while (i < n && j < m) {
        
        // Verificação direta de MATCH (A-T, T-A, C-G, G-C)
        if ((s1[i] == 'A' && s2[j] == 'T') || (s1[i] == 'T' && s2[j] == 'A') ||
            (s1[i] == 'C' && s2[j] == 'G') || (s1[i] == 'G' && s2[j] == 'C')) {
            pontuacao += 2; // Ganha 2 pontos se o par for correto
        } 
        else {
            pontuacao -= 1; // Perde 1 ponto se for mismatch (bases trocadas)
        }
        
        // No algoritmo guloso simples, avançamos ambos os índices
        i++;
        j++;
    }

    /* Caso uma sequência seja maior que a outra, as bases restantes 
       são pareadas com lacunas (Gaps), custando -2 cada. */
    while (i < n) {
        pontuacao -= 2;
        i++;
    }
    while (j < m) {
        pontuacao -= 2;
        j++;
    }

    return pontuacao;
}