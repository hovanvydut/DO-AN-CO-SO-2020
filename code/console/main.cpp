#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>

void Eratosthenes(int A[], int n) {
    int i, j;
    A[0] = 1; A[1] = 1;

    for (i = 2; i <= n; i++)
        A[i] = 0;

    for (i = 2; i * i <= n; i++)
        for (j = i * i; j <= n; j += i)
            A[j] = 1;
}

int HeightNumber(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n = n / 10;
    }
    return sum;
}

int main()
{
    int n, h;
    do {
        printf("Nhap N = "); scanf("%d", &n);
        printf("%d", n);
        getch();
    } while (n < 10 || n > 1000000);

    do {
        printf("Nhap h = "); scanf("%d", &h);
        getch();
    } while (h < 1 || h > 54);

    int *A = (int *)malloc(sizeof(int) * (n + 1));
    Eratosthenes(A, n);
    int count = 0;
    for (int i = 2; i <= n; i++) {
        if (A[i] == 0 && HeightNumber(i) == h) {
            count++;
            printf("%d\t", i);
        }
    }
    printf("\nCo tat ca %d so co chieu cao la %d trong doan [2, %d]", count, h, n);
    return 0;
}
