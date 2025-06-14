#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAKS_SAMOCHODOW 20

// Tablice na dane
char car_brand[MAKS_SAMOCHODOW][50];
int years[MAKS_SAMOCHODOW];
char car_registration[MAKS_SAMOCHODOW][20];
int car_mileage[MAKS_SAMOCHODOW];

// Dodawanie samochodu
void AddCar(int *count_car) {
    if (*count_car >= MAKS_SAMOCHODOW) {
        printf("Osiagnieto limit samochodow.\n");
        return;
    }

    printf("Podaj marke: ");
    scanf(" %[^\n]", car_brand[*count_car]);

    printf("Podaj rok produkcji: ");
    scanf("%d", &years[*count_car]);

    printf("Podaj numer rejestracyjny: ");
    scanf(" %s", car_registration[*count_car]);

    printf("Podaj przebieg (w km): ");
    scanf("%d", &car_mileage[*count_car]);

    (*count_car)++;
}

// Wyświetlanie samochodów
void view_cars(int car_numbers) {
    if (car_numbers == 0) {
        printf("Brak zapisanych samochodow.\n");
        return;
    }

    for (int i = 0; i < car_numbers; i++) {
        printf("%d. Marka: %s | Rok: %d | Rejestracja: %s | Przebieg: %d km\n", i + 1,car_brand[i], years[i], car_registration[i], car_mileage[i]);
    }
}

// Zapis do pliku
void save_to_file(int car_numbers) {
    FILE *plik = fopen("samochody.txt", "w");
    if (plik == NULL) {
        printf("Blad: nie mozna otworzyc pliku.\n");
        return;
    }

    for (int i = 0; i < car_numbers; i++) {
        fprintf(plik, "%s;%d;%s;%d\n", car_brand[i], years[i], car_registration[i], car_mileage[i]);
    }

    fclose(plik);
    printf("Dane zapisano do pliku.\n");
}

// Wczytywanie z pliku (bez dziwnych znaków)
void load_from_file(int *car_numbers) {
    FILE *plik = fopen("samochody.txt", "r");
    if (plik == NULL) {
        printf("Blad: nie mozna otworzyc pliku.\n");
        return;
    }

    char linia[200];
    *car_numbers = 0;

    while (fgets(linia, sizeof(linia), plik) != NULL && *car_numbers < MAKS_SAMOCHODOW) {
        if (sscanf(linia, "%49[^;];%d;%19[^;];%d", car_brand[*car_numbers], &years[*car_numbers], car_registration[*car_numbers], &car_mileage[*car_numbers]) == 4) {
            (*car_numbers)++;
        }
    }

    fclose(plik);
    printf("Dane wczytano z pliku.\n");
}

// Główne menu
int main() {
    int car_numbers = 0;
    int choice;

    do {
        printf("1. Dodaj samochod\n");
        printf("2. Wyswietl samochody\n");
        printf("3. Zapisz do pliku\n");
        printf("4. Wczytaj z pliku\n");
        printf("0. Wyjscie\n");
        printf("Wybierz opcje: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                AddCar(&car_numbers);
                break;
            case 2:
                view_cars(car_numbers);
                break;
            case 3:
                save_to_file(car_numbers);
                break;
            case 4:
                load_from_file(&car_numbers);
                break;
            case 0:
                printf("Zamykanie programu...\n");
                break;
            default:
                printf("Nieprawidlowa opcja.\n");
        }

    } while (choice != 0);

    return 0;
}