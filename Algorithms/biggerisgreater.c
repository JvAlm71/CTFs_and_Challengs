#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Funcao para reverter uma parte da string
void reverse(char* s, int start, int end) {
    while (start < end) {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}

// Funcao para encontrar a proxima string lexicograficamente maior
void biggerIsGreater(char* w) {
    int len = strlen(w);
    int i = len - 2;

    // Passo 1: Encontrar o ponto de troca
    while (i >= 0 && w[i] >= w[i + 1]) {
        i--;
    }

    // Se nao encontrou tal ponto, a string ja esta na maior forma possivel
    if (i == -1) {
        printf("no answer\n");
        return;
    }

    // Passo 2: Encontrar o menor caractere a direita de w[i] que seja maior que w[i]
    int j = len - 1;
    while (w[j] <= w[i]) {
        j--;
    }

    // Passo 3: Trocar w[i] com w[j]
    char temp = w[i];
    w[i] = w[j];
    w[j] = temp;

    // Passo 4: Reverter a parte da string apos i
    reverse(w, i + 1, len - 1);

    // Imprimir a nova string
    printf("%s\n", w);
}

int main() {
    int T;
    char w[101];

    // Ler o numero de casos de teste
    scanf("%d", &T);

    // Processar cada caso de teste
    while (T--) {
        scanf("%s", w);
        biggerIsGreater(w);
    }

    return 0;
}
