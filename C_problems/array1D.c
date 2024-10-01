#include <stdio.h>
#include <stdlib.h>

int array1D(int n) {

    int a[n];
    for (int i = 0; i < n; i++) 
      scanf("%d", &a[i]);
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    return sum;

};


int main() {
    int n;
    scanf("%d", &n);
    int sum = array1D(n);
    printf("%d\n", sum);
    return 0;
};