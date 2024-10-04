#include <stdio.h>

// Funcao para verificar se "num" e divisivel por todos os elementos do array "a" (condicao 1)
int isDivisibleByAll(int num, int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (num % a[i] != 0) { // Se num nao for divisivel por a[i]
            return 0;
        }
    }
    return 1;
}

// Funcao para verificar se "num" e divisor de todos os elementos do array "b" (condicao 2)
int isFactorOfAll(int num, int b[], int m) {
    for (int i = 0; i < m; i++) {
        if (b[i] % num != 0) { // Se num nao dividir b[i]
            return 0;
        }
    }
    return 1;
}

// Funcao principal para encontrar a quantidade de numeros entre os dois arrays
int getTotalX(int a[], int n, int b[], int m) {
    int count = 0;
    int maxA = a[n-1];
    int minB = b[0];

    // Itera sobre todos os numeros entre o maior valor de "a" e o menor de "b"
    for (int num = maxA; num <= minB; num++) {
        if (isDivisibleByAll(num, a, n) && isFactorOfAll(num, b, m)) {
            count++; // Conta o numero que atende as duas condicoes
        }
    }
    return count;
}

int main() {
    int n, m;
    
    // Leitura do tamanho dos arrays
    scanf("%d %d", &n, &m);
    
    int a[n], b[m];
    
    // Leitura dos elementos do array a
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // Leitura dos elementos do array b
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }
    
    // Chamada da funcao getTotalX para obter a quantidade de numeros
    int result = getTotalX(a, n, b, m);
    
    // Exibe o resultado
    printf("%d\n", result);
    
    return 0;
}
