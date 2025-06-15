#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void printArray(int *array){
    for(int i = 0; i < SIZE; i++){
        printf("array[%d] = %d\n",i, array[i]);
        printf("*(%p) = %d\n\n",array + i, *(array+i));
    }
}

void menu(void){
    printf("Wybierz opcje: \n");
    printf("1. Wprowadz wartosci do tablicy. \n");
    printf("2. Wyswietl tablice. \n");
    printf("3. Wyswietl najmniejsza wartosc z tablicy. \n");
    printf("4. Wyswietl najwieksza wartosc z tablicy. \n");
    printf("5. Wyswietl srednia wartosc liczb z tablicy.\n");
    printf("6. zapisz do pliku\n");
    printf("0. Wyjdz z programu.\n");
}

FILE *fptr;
int save()
{
    fptr = fopen("tekst.txt","a");
    if(fptr == 0) {
        printf("Nie mozna otworzyc pliku");
        exit(1);
    }
    fprintf(fptr,"\n Zostalo zapisane do pliku\n");
    fclose(fptr);
}

void numbers(int array[SIZE], int size){

    for (int i = 0; i < SIZE; i++) {
        scanf("%d",&array[i]);
    }
}

int minimum(int *array){
    int min = *array;
    for (int i = 1; i < SIZE; ++i) {
        if(min > *(array+i)){
            min = *(array+i);
        }
    }
    return min;
}


int maksimum(int *array){
    int max = *array;
    for (int i = 0; i < SIZE; ++i) {
        if(max < *(array+i)){
            max = *(array+i);
        }
    }
    return max;
}

float findAverage(int *array,int size){
    int sum = 0;
    for(int i=1; i<SIZE; i++){
        sum += *(array+i);
    }
    float average = (float) sum / size;
    return average;
}
FILE *fptr;
int zapis(int *array)
{
    fptr = fopen("C:\\Users\\student\\Desktop\\tekst.txt","w");
    if(fptr == 0) {
        printf("Nie mozna otworzyc pliku");
        exit(1);
    }
    for (int i = 0; i < SIZE; i++) {
        fprintf(fptr,"\n %d \n",array[i]);
    }
    fclose(fptr);
}


int main() {
    int array [SIZE] = {1,2,3,4,5,6,7,8,9,10};
    int option = 0;

    do{
        menu();
        scanf("%d",&option);

        switch (option) {
            case 0:
                break;
            case 1:
                printf("Wprowadzam dane do tablicy\n\n");
                numbers(array, SIZE);
                break;
            case 2:
                printArray(array);
                break;
            case 3:
                printf("okreslam najmniejsza wartosc %d \n\n", minimum(array));
                break;
            case 4:
                printf("okreslam najwieksza wartosc %d \n\n",maksimum(array));
                maksimum(array);
                break;
            case 5:
                printf("okreslam srednia wartosc liczb %f \n\n", findAverage(array,SIZE));
                break;
            case 6:
                printf("zapisuje do pliku tekst \n\n", zapis(array));
                break;
            default:
                printf("wybierz wlasciwa opcje\n\n");
        }

    }
    while (option != 0);

    printf("koniec programu");

    return 0;
}