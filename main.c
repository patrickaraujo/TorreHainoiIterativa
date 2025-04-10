#include <stdio.h>
#include <math.h>

// Função auxiliar para mover um disco entre torres
void moverDisco(int origem, int destino) {
    printf("Mover disco de %d para %d\n", origem, destino);
}

// Função iterativa para resolver o problema da Torre de Hanói
void hanoiIterativo(int num_discos) {
    // Define as torres como números: 1 (origem), 2 (auxiliar), 3 (destino)
    int torres[3] = {1, 2, 3};

    // Calcula o número total de movimentos: 2^n - 1
    unsigned long long total_movimentos = (1ULL << num_discos) - 1;
    printf("Total de movimentos: %llu\n\n", total_movimentos);

    // Variáveis para controlar o estado das torres
    int disco_menor = 1; // O menor disco sempre começa na torre 1

    for (unsigned long long i = 1; i <= total_movimentos; i++) {
        if (i % 2 == 1) {
            // Movimento do menor disco
            int destino;

            if (num_discos % 2 == 0) {
                // Movimento para discos pares
                if (disco_menor == 1) {
                    destino = 2;
                } else if (disco_menor == 2) {
                    destino = 3;
                } else { // disco_menor == 3
                    destino = 1;
                }
            } else {
                // Movimento para discos ímpares
                if (disco_menor == 1) {
                    destino = 3;
                } else if (disco_menor == 2) {
                    destino = 1;
                } else { // disco_menor == 3
                    destino = 2;
                }
            }

            moverDisco(disco_menor, destino);
            disco_menor = destino; // Atualiza a posição do menor disco
        } else {
            // Movimento de outro disco (não o menor)
            int origem, destino;

            // Encontra a origem (torre que não contém o menor disco)
            for (int j = 1; j <= 3; j++) {
                if (j != disco_menor) {
                    origem = j;
                    break;
                }
            }

            // Encontra o destino (outra torre que não contém o menor disco ou a origem)
            for (int j = 1; j <= 3; j++) {
                if (j != disco_menor && j != origem) {
                    destino = j;
                    break;
                }
            }

            moverDisco(origem, destino);
        }
    }
}

int main() {
    int num_discos;

    // Solicita ao usuário o número de discos
    printf("Resolvendo o problema da Torre de Hanói\n");
    printf("Digite o número de discos: ");
    scanf("%d", &num_discos);

    if (num_discos < 1) {
        printf("Número de discos deve ser positivo.\n");
        return 1;
    }

    printf("\nSolução para %d discos:\n", num_discos);

    // Chama a função iterativa
    hanoiIterativo(num_discos);

    return 0;
}
