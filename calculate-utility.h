void Eratosthenes(int arr[], int n) {
    // arr[i] == 0 --> i is prime number
    // arr[i] == 1 --> i is not prime number
    for (int i = 0; i <= n; i++) {
        arr[i] = 0;
    }

    arr[0] = 1; arr[1] = 1;

    // LCM of a prime number is non-prime number, so set they equal 1
    for (int i = 2; i * i <= n; i++) {
        if (arr[i] == 0) {
            for (int j = i * i; j <= n; j = j + i) {
                arr[j] = 1;
            }
        }
    }
}

int heightNumber(int n) {
    int sumOfDigit = 0;
    while (n > 0) {
        sumOfDigit += n % 10;
        n /= 10;
    }
    return sumOfDigit;
}

// @ return 1 --> read file OK, return 0 --> read file ERROR
int readDataFromFile(const char fileName[], int *n, int *h) {
    char path[100] = "E:\\DoAn\\DO_AN_CO_SO\\";

    strcat(path, fileName);
    printf("%s\n", path);

    FILE *fileInput = fopen(path, "r");
    printf("hello");
    if (fileInput == NULL) {
        return 0;
    }

    fscanf(fileInput, "%d %d", n, h);
    printf("%d %d", *n, *h);
    fclose(fileInput);
    return 1;
}

int writeDataToFile(const char path[], int arr[], int n, int h) {
    FILE *fileOutput = fopen(path, "w");

    if (fileOutput == NULL) {
        return 0;
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0 && heightNumber(i) == h) {
            count++;
            fprintf(fileOutput, "%d\t", i);
            if (count % 8 == 0) {
                fprintf(fileOutput, "\n");
            }
        }

    }
    fprintf(fileOutput, "\r\n");
    fprintf(fileOutput, "Co tat ca %d so nguyen to co chieu cao la % trong doan [10, %d]", count, h, n);

    fclose(fileOutput);
    return 1;
}

int char2Number(char ch[], int len) {
    int sum = 0, pow = 1, i = 0;
    for (i = len - 1; i >= 0; i--) {
        sum += (ch[i] - '0') * pow;
        pow *= 10;
    }
    return sum;
}

void number2Char (int num, char ch[]) {
    int tmp = num;
    int numOfDigit = 0;
    while (tmp > 0) {
        tmp /= 10;
        numOfDigit++;
    }
    for (int i = numOfDigit - 1; i >= 0; i--) {
        ch[i] = num % 10 + '0';
        num /= 10;
    }
    ch[numOfDigit] = '\0';
}
