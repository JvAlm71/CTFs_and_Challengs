#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int queensAttack(int n, int k, int r_q, int c_q, int obstacles_rows, int obstacles_columns, int** obstacles) {
    // Inicializar os limites das direcoes
    int left = c_q - 1;  
    int right = n - c_q;  
    int up = n - r_q;  
    int down = r_q - 1;  
    int up_left = min(n - r_q, c_q - 1);  
    int up_right = min(n - r_q, n - c_q);  
    int down_left = min(r_q - 1, c_q - 1);  
    int down_right = min(r_q - 1, n - c_q);  

    // Ajustar os limites com base nos obstaculo
    for (int i = 0; i < k; i++) {
        int obs_r = obstacles[i][0];  
        int obs_c = obstacles[i][1];  

        // obstaculo esta na mesma linha da rainha
        if (obs_r == r_q) {
            if (obs_c < c_q) {
                
                left = min(left, c_q - obs_c - 1);
            } else if (obs_c > c_q) {
                
                right = min(right, obs_c - c_q - 1);
            }
        }
        
        else if (obs_c == c_q) {
            if (obs_r < r_q) {
                // obstaculo esta abaixo
                down = min(down, r_q - obs_r - 1);
            } else if (obs_r > r_q) {
                // obstaculo esta acima
                up = min(up, obs_r - r_q - 1);
            }
        }
        // obstaculo esta em uma diagonal
        else if (abs(obs_r - r_q) == abs(obs_c - c_q)) {
            if (obs_r > r_q && obs_c < c_q) {
                // Diagonal superior esquerda
                up_left = min(up_left, obs_r - r_q - 1);
            } else if (obs_r > r_q && obs_c > c_q) {
                // Diagonal superior direita
                up_right = min(up_right, obs_r - r_q - 1);
            } else if (obs_r < r_q && obs_c < c_q) {
                // Diagonal inferior esquerda
                down_left = min(down_left, r_q - obs_r - 1);
            } else if (obs_r < r_q && obs_c > c_q) {
                // Diagonal inferior direita
                down_right = min(down_right, r_q - obs_r - 1);
            }
        }
    }

    // Somar todas as direcoes para calcular as casas que a rainha pode atacar
    int total_attackable_squares = left + right + up + down + up_left + up_right + down_left + down_right;

    return total_attackable_squares;
}

int main() {
    int n, k;
    
    // Leitura do tamanho do tabuleiro e do numero de obstaculos
    scanf("%d %d", &n, &k);

    int r_q, c_q;
    
    // Leitura da posicao da rainha
    scanf("%d %d", &r_q, &c_q);

    // Leitura dos obstaculos
    int** obstacles = (int**)malloc(k * sizeof(int*));
    for (int i = 0; i < k; i++) {
        obstacles[i] = (int*)malloc(2 * sizeof(int));
        scanf("%d %d", &obstacles[i][0], &obstacles[i][1]);
    }

    // Chamar a funcao que calcula as casas atacaveis pela rainha
    int result = queensAttack(n, k, r_q, c_q, k, 2, obstacles);

    // Exibir o resultado
    printf("%d\n", result);

    // Liberar memoria alocada para os obstaculos
    for (int i = 0; i < k; i++) {
        free(obstacles[i]);
    }
    free(obstacles);

    return 0;
}
