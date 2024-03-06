#include <stdbool.h>
#include <stdio.h>

bool printable_buf(const void *buf, int len) {
    const unsigned char *ptr = (const unsigned char *) buf; // Rzutowanie wskaźnika na unsigned char
    for (int i = 0; i < len; i++) {
        if (ptr[i] < 32 || ptr[i] > 126) { // Sprawdzenie, czy bajt mieści się w zakresie [32, 126]
            return false; // Jeśli znaleziono znak spoza zakresu, zwraca false
        }
    }
    return true; // Jeśli wszystkie znaki są drukowalne, zwraca true
}

int main() {
    char buf1[] = "Hello, World!"; // Znakowe bufor o poprawnych znakach
    char buf2[] = "Hello, \nWorld!"; // Znakowe bufor o niepoprawnych znakach

    if (printable_buf(buf1, sizeof(buf1))) {
        printf("Bufor 1 zawiera tylko drukowalne znaki ASCII.\n");
    } else {
        printf("Bufor 1 zawiera co najmniej jeden znak spoza zakresu drukowalnych znakow ASCII.\n");
    }

    if (printable_buf(buf2, sizeof(buf2))) {
        printf("Bufor 2 zawiera tylko drukowalne znaki ASCII.\n");
    } else {
        printf("Bufor 2 zawiera co najmniej jeden znak spoza zakresu drukowalnych znakow ASCII.\n");
    }

    return 0;
}

