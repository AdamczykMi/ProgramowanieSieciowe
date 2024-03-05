#include <stdio.h>

void drukuj_alt(int *tablica, int liczba_elementow) {
    printf("Liczby większe od 10 i mniejsze od 100:\n");

    // Ustawienie wskaźnika na początek tablicy
    int *ptr = tablica;

    // Przechodzenie przez tablicę za pomocą wskaźnika
    while (ptr < tablica + liczba_elementow) {
        if (*ptr > 10 && *ptr < 100) {
            printf("%d\n", *ptr);
        }
        ptr++; // Przesunięcie wskaźnika na kolejny element
    }
}

int main() {
    int liczby[50];
    int wczytane = 0;

    printf("Wpisuj liczby, wpisz 0 aby przerwac lub wczytaj maksymalną ilosc liczb (50):\n");

    // Wczytywanie liczb do tablicy
    while (wczytane < 50) {
        int liczba;
        scanf("%d", &liczba);

        if (liczba == 0) {
            break;
        }

        liczby[wczytane] = liczba;
        wczytane++;
    }

    // Wywołanie funkcji drukuj_alt
    drukuj_alt(liczby, wczytane);

    return 0;
}

