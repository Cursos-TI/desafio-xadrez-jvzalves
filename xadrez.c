/*
 * MateCheck – Desafio de Xadrez (Nível Mestre)
 * Linguagem: C (ANSI C)
 *
 * Requisitos atendidos:
 * - Entrada via constantes/variáveis internas ao código (sem leitura externa).
 * - Uso de funções recursivas para Bispo, Torre e Rainha.
 * - Bispo: utiliza recursão E loops aninhados para compor o movimento diagonal
 *   como combinações das direções básicas ("Cima" + "Direita").
 * - Cavalo: 1 movimento em L para cima e para a direita, utilizando loop com
 *   múltiplas variáveis/condições e uso de continue/break.
 * - Saída clara e organizada.
 * - Código comentado, manutenível e com nomes de variáveis expressivos.
 */

#include <stdio.h>
#include <stdbool.h>

/* ========================= Nomenclatura de saída ========================= */
static inline void imprimeCima(void) { printf("Cima\n"); }
static inline void imprimeBaixo(void) { printf("Baixo\n"); }
static inline void imprimeEsquerda(void) { printf("Esquerda\n"); }
static inline void imprimeDireita(void) { printf("Direita\n"); }

/* ======================= Constantes de movimentação ====================== */
/* Ajuste aqui os "passos" desejados para cada peça */
enum
{
    PASSOS_BISPO = 5, /* diagonal superior direita */
    PASSOS_TORRE = 5, /* para a direita */
    PASSOS_RAINHA = 8 /* para a esquerda */
};

/* ======================= Utilidades de apresentação ====================== */
static void separador(const char *titulo)
{
    printf("\n================ %s ================\n", titulo);
}

/* ================= Funções recursivas: Bispo / Torre / Rainha ============ */

static void mover_bispo_diagonal_superior_direita_rec(int passos_restantes)
{
    if (passos_restantes <= 0)
    {
        return; /* Caso base da recursão */
    }

    /* Loops aninhados para compor o movimento diagonal: */
    for (int i = 0; i < 2; ++i)
    { /* 0 -> Cima, 1 -> Direita */
        for (int repeticao = 0; repeticao < 1; ++repeticao)
        {
            if (i == 0)
            {
                imprimeCima();
            }
            else
            {
                imprimeDireita();
            }
        }
    }

    mover_bispo_diagonal_superior_direita_rec(passos_restantes - 1);
}

static void mover_torre_direita_rec(int passos_restantes)
{
    if (passos_restantes <= 0)
    {
        return; /* Caso base */
    }
    imprimeDireita();
    mover_torre_direita_rec(passos_restantes - 1);
}

static void mover_rainha_esquerda_rec(int passos_restantes)
{
    if (passos_restantes <= 0)
    {
        return; /* Caso base */
    }
    imprimeEsquerda();
    mover_rainha_esquerda_rec(passos_restantes - 1);
}

static void mover_cavalo_L_cima_direita_uma_vez(void)
{

    int subidas_alvo = 2;  /* duas casas para cima */
    int direitas_alvo = 1; /* uma casa para a direita */

    for (int subidas = 0, direitas = 0; (subidas < subidas_alvo) || (direitas < direitas_alvo);)
    {

        if (subidas < subidas_alvo)
        {
            imprimeCima();
            ++subidas;
            continue;
        }

        if (direitas < direitas_alvo)
        {
            imprimeDireita();
            ++direitas;
        }

        if ((subidas == subidas_alvo) && (direitas == direitas_alvo))
        {
            break;
        }
    }
}

/* ================================ main() ================================= */
int main(void)
{
    separador("BISPO – 5 casas na diagonal superior direita (recursivo + loops aninhados)");
    mover_bispo_diagonal_superior_direita_rec(PASSOS_BISPO);

    separador("TORRE – 5 casas para a direita (recursivo)");
    mover_torre_direita_rec(PASSOS_TORRE);

    separador("RAINHA – 8 casas para a esquerda (recursivo)");
    mover_rainha_esquerda_rec(PASSOS_RAINHA);

    separador("CAVALO – 1 movimento em L para cima e direita (loops com múltiplas variáveis/condições, continue e break)");
    mover_cavalo_L_cima_direita_uma_vez();

    separador("FIM");
    return 0;
}
