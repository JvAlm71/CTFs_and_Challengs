#include <stdio.h>
#include <stdlib.h>

int isValid(int x, int y, int n) {
    return (x >= 1 && x <= n && y >= 1 && y <= n);
}

int queensAttack(int n, int k, int r_q, int c_q, int obstacles[k][2]) {
    int left = c_q - 1;                 // Limite para a esquerda
    int right = n - c_q;                // Limite para a direita
    int up = n - r_q;                   // Limite para cima
    int down = r_q - 1;                 // Limite para baixo
    int up_left = (r_q < c_q) ? r_q - 1 : c_q - 1;           // Limite diagonal superior esquerda
    int up_right = (n - r_q < n - c_q) ? n - r_q : n - c_q;  // Limite diagonal superior direita
    int down_left = (r_q - 1 < c_q - 1) ? r_q - 1 : c_q - 1; // Limite diagonal inferior esquerda
    int down_right = (r_q - 1 < n - c_q) ? r_q - 1 : n - c_q;// Limite diagonal inferior direita

    // Verificar 
    for (int i = 0; i < k; i++) {
        int obs_r = obstacles[i][0]; 
        int obs_c = obstacles[i][1]; 

       
        if (obs_r == r_q) {
            if (obs_c < c_q) {
                left = (c_q - obs_c - 1) < left ? (c_q - obs_c - 1) : left;  // Ajustar limite esquerdo
            } else {
                right = (obs_c - c_q - 1) < right ? (obs_c - c_q - 1) : right; // Ajustar limite direito
            }
        }
        else if (obs_c == c_q) {
            if (obs_r < r_q) {
                down = (r_q - obs_r - 1) < down ? (r_q - obs_r - 1) : down; // Ajustar limite inferior
            } else {
                up = (obs_r - r_q - 1) < up ? (obs_r - r_q - 1) : up; // Ajustar limite superior
            }
        }
        else if (obs_r > r_q && obs_c < c_q && (obs_r - r_q) == (c_q - obs_c)) {
            up_left = (obs_r - r_q - 1) < up_left ? (obs_r - r_q - 1) : up_left;
        }
        else if (obs_r > r_q && obs_c > c_q && (obs_r - r_q) == (obs_c - c_q)) {
            up_right = (obs_r - r_q - 1) < up_right ? (obs_r - r_q - 1) : up_right;
        }
        else if (obs_r < r_q && obs_c < c_q && (r_q - obs_r) == (c_q - obs_c)) {
            down_left = (r_q - obs_r - 1) < down_left ? (r_q - obs_r - 1) : down_left;
        }
        else if (obs_r < r_q && obs_c > c_q && (r_q - obs_r) == (obs_c - c_q)) {
            down_right = (r_q - obs_r - 1) < down_right ? (r_q - obs_r - 1) : down_right;
        }
    }

    // Total de casas que a rainha pode atacar
    int total_attackable_squares = left + right + up + down + up_left + up_right + down_left + down_right;

    return total_attackable_squares;
}

int main() {
    int n, k;
    int r_q, c_q;

    scanf("%d %d", &n, &k);
    
    scanf("%d %d", &r_q, &c_q);

    int obstacles[k][2];
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &obstacles[i][0], &obstacles[i][1]);
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);
    printf("%d\n", result);

    return 0;
}
