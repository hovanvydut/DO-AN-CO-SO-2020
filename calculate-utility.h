void Eratosthenes(int arr[], int n) {
    // arr[i] == 0 --> i is prime number
    // arr[i] == 1 --> i is not prime number
    for (int i = 0; i <= n; i++) {
        arr[i] = 0;
    }

    arr[0] = 1; arr[1] = 1;

    // LCM of a prime number is non-prime number, so set they equal 1
    for (int i = 2; i < n; i++) {
        if (arr[i] == 0) {
            for (int j = i * i; j <= n; j = j + i) {
                arr[j] = 1;
            }
        }
    }
}

int heightNumber(int n) {
    int sumOfDigit = 0;
    while (n != 0) {
        sumOfDigit += n % 10;
        n /= 10;
    }
}

// @ return 1 --> read file OK, return 0 --> read file ERROR
int readDataFromFile(const char path[], int n, int h) {
    FILE *fileInput = fopen(path, "r");

    if (fileInput == NULL) {
        return 0;
    }

    fscanf(fileInput, "%d %d", &n, &h);

    fclose(fileInput);
    return 1;
}

int writeDataToFile(const char path[], int arr[], int n) {
    FILE *fileOutput = fopen(path, "w");

    if (fileOutput == NULL) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        fprintf(fileOutput, "%d ", arr[i]);
    }

    fclose(fileOutput);
    return 1;
}

int char2Number(char ch[], int len) {
    int sum = 0, pow = 1, i = 0;
    for (i = len - 1; i >= 0; i--) {
        sum += (ch[i] - 48) * pow;
        pow *= 10;
    }
    return sum;
}
