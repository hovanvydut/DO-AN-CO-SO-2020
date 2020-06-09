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

// return 0 --> error, 1 --> success
int readDataFromFile(char inputFileName[], int *n, int *h) {
    FILE *fpt = fopen(inputFileName, "r");
    if (fpt == NULL)
        return 0;
    fscanf(fpt, "%d %d", n, h);
    fclose(fpt);
    return 1;
}

int writeDataToFile(const char path[], int arr[], int n, int h) {
    FILE *fileOutput = fopen(path, "w");

    if (fileOutput == NULL) {
        return 0;
    }

    int count = 0;
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == 0 && HeightNumber(i) == h) {
            count++;
            fprintf(fileOutput, "%d ", i);
            if (count % 8 == 0) {
                fprintf(fileOutput, "\n");
            }
        }

    }
    fprintf(fileOutput, "\r\n");
    fprintf(fileOutput, "Co tat ca %d so nguyen to co chieu cao la %d trong doan [10, %d]", count, h, n);

    fclose(fileOutput);
    return 1;
}

int main(){
    int choice, count, i, n, h, result;
    char ch;
START:
    do {
        printf("\n1. Nhap du lieu tu ban phim\n");
        printf("2. Nhap du lieu tu file\n");
        printf("==> "); scanf("%d", &choice);
    } while(choice != 1 && choice != 2);

    if (choice == 1)
        goto INPUT_KEYBOARD;
    if (choice == 2)
        goto INPUT_FILE;

INPUT_KEYBOARD:
    printf("\n");
    do {
        printf("Nhap N = "); scanf("%d", &n);
    } while (n < 10 || n > 1000000);

    do {
        printf("Nhap h = "); scanf("%d", &h);
    } while (h < 1 || h > 54);

    goto CACULATE;
INPUT_FILE:
    printf("\n");
    char inputFileName[100];
    printf("Nhap ten file: "); scanf("%s", inputFileName);

    result = readDataFromFile(inputFileName, &n, &h);

    if (result == 0) {
        printf("File khong ton tai. Vui long nhap dung ten file!\n");
        goto INPUT_FILE;
    }

    if (n < 10 || n > 1000000) {
        printf("\n Vui long dieu chinh file de 10 <= N <= 1000000");
        goto INPUT_FILE;
    }

    if (h < 1 || h > 54) {
        printf("\n Vui long dieu chinh file de 1 <= H <= 54");
        goto INPUT_FILE;
    }
    goto CACULATE;

CACULATE:
    int *A = (int *)malloc(sizeof(int) * (n + 1));
    Eratosthenes(A, n);

    do {
        printf("\n1. Xuat du lieu ra man hinh\n");
        printf("2. Xuat du lieu ra file\n");
        printf("==> "); scanf("%d", &choice);
    } while (choice != 1 && choice != 2);

    if (choice == 1)
        goto OUTPUT_SCREEN;
    if (choice == 2)
        goto OUTPUT_FILE;

OUTPUT_SCREEN:
    printf("\n");
    count = 0;
    for (i = 2; i <= n; i++) {
        if (A[i] == 0 && HeightNumber(i) == h) {
            count++;
            printf("%d\t", i);
        }
    }

    printf("\nCo tat ca %d so co chieu cao la %d trong doan [2, %d]", count, h, n);
    goto END;

OUTPUT_FILE:
    result = writeDataToFile("output.txt", A, n, h);
    if (result == 0) {
        printf("\nLoi trong qua trinh ghi file. Vui long thu lai!");
        goto START;
    }
    printf("\nVui long xem ket qua o file output.txt\n");
    goto START;
END:
    printf("\n");
    do {
        printf("\n1. Tiep tuc\n");
        printf("2. Thoat chuong trinh\n");
        printf("==> "); scanf("%d", &choice);
    } while (choice != 1 && choice != 2);

    if (choice == 1)
        goto START;

    printf("\n** GOOD BYE!!! **\n");
    return 0;
}

