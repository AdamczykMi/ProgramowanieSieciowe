#include <stdbool.h>

bool printable_str(const char *buf) {
    const unsigned char *ptr = (const unsigned char *) buf; // Rzutowanie wskaźnika na unsigned char
    while (*ptr != '\0') {
        if (*ptr < 32 || *ptr > 126) { // Sprawdzenie, czy znak mieści się w zakresie [32, 126]
            return false; // Jeśli znaleziono znak spoza zakresu, zwraca false
        }
        ptr++; // Przechodzenie do następnego znaku w łańcuchu
    }
    return true; // Jeśli wszystkie znaki są drukowalne, zwraca true
}

#include <stdio.h>

int main() {
    const char *str1 = "Hello, World!"; // Poprawny łańcuch ASCII
    const char *str2 = "Hello, \nWorld!"; // Łańcuch z niepoprawnymi znakami

    if (printable_str(str1)) {
        printf("Lancuch 1 zawiera tylko drukowalne znaki ASCII.\n");
    } else {
        printf("Lancuch 1 zawiera co najmniej jeden znak spoza zakresu drukowalnych znakow ASCII.\n");
    }

    if (printable_str(str2)) {
        printf("Lancuch 2 zawiera tylko drukowalne znaki ASCII.\n");
    } else {
        printf("Lancuch 2 zawiera co najmniej jeden znak spoza zakresu drukowalnych znakow ASCII.\n");
    }

    return 0;
}

