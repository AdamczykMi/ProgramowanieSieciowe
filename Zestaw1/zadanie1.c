#include <stdio.h>

void drukuj(int tablica[], int liczba_elementow) {
    printf("Liczby większe od 10 i mniejsze od 100:\n");
    for (int i = 0; i < liczba_elementow; i++) {
        if (tablica[i] > 10 && tablica[i] < 100) {
            printf("%d\n", tablica[i]);
        }
    }
}

int main() {
    int liczby[50];
    int wczytane = 0;

    printf("Wpisuj liczby, wpisz 0 aby przerwac lub wczytaj maksymalną ilosc liczb (50):\n");

    // Wczytywanie liczb do tablicy
    while (wczytane < 50) {
        scanf("%d", &liczby[wczytane]);

        if (liczby[wczytane] == 0) {
            break;
        }

        wczytane++;
    }

    drukuj(liczby, wczytane);

    return 0;
}

