#include <stdio.h>
#include <stdlib.h>

/**
 * factorize - A function that factorizes an integer
 * @n: The integer to be factorize
 * Return: Nothing
*/

void factorize(int n) {
    for (int p = 2; p <= n / 2; ++p) {
        if (n % p == 0) {
            int q = n / p;
            printf("%d=%d*%d\n", n, p, q);
            return;
        }
    }
}

/**
 * main - Entry point
 * @argc: Name of the program
 * @argv: File name
 * Return: 0 if successful, 1 if unsuccessful
*/

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char buffer[20];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        int n = atoi(buffer);
        if (n <= 1) {
            printf("%d is not a valid natural number\n", n);
        } else {
            factorize(n);
        }
    }

    fclose(file);
    return 0;
}
