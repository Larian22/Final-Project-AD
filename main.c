
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Homar
{
    int id;
    int lungime;
    int valoare;
};
float valoareaPerUnitate(struct Homar Lobsters)
{
    return Lobsters.valoare / (Lobsters.lungime * 1.0);
}
void sortareLobsters(struct Homar *Lobsters, int noLobsters)
{
    int iterator1;
    int iterator2;
    int indexMin;
    int auxSize;
    int auxId;
    int auxValue;

    for(iterator1 = 0; iterator1 < noLobsters - 1; iterator1++){
        indexMin = iterator1;
        for(iterator2 = iterator1 + 1; iterator2 < noLobsters; iterator2++){
            if (valoareaPerUnitate(Lobsters[indexMin]) < valoareaPerUnitate(Lobsters[iterator2]) ){
                indexMin = iterator2;
            }
        }
        if (indexMin != iterator1){
            auxSize = Lobsters[indexMin].lungime;
            auxId = Lobsters[indexMin].id;
            auxValue = Lobsters[indexMin].valoare;
            Lobsters[indexMin].lungime = Lobsters[iterator1].lungime;
            Lobsters[indexMin].id = Lobsters[iterator1].id;
            Lobsters[indexMin].valoare = Lobsters[iterator1].valoare;
            Lobsters[iterator1].lungime = auxSize;
            Lobsters[iterator1].id = auxId;
            Lobsters[iterator1].valoare = auxValue;
        }
    }
}
void repartizareLobsters(struct Homar *Lobsters, int noLobsters, int dimensiunePlasa)
{
    int iterator = 0;
    int dimensiunePlasaMomentan = dimensiunePlasa;
    float valoarePlasa = 0.0;

    for(iterator = 0; iterator < noLobsters && dimensiunePlasaMomentan > 0; iterator++){
        if(Lobsters[iterator].lungime <= dimensiunePlasaMomentan){
            printf("\n Lobster id .%d, value:%d and lenght:%d",Lobsters[iterator].id,Lobsters[iterator].valoare,Lobsters[iterator].lungime);
            valoarePlasa += Lobsters[iterator].valoare;
            dimensiunePlasaMomentan -= Lobsters[iterator].lungime;
        }
    }
    printf("\nMax value obtained: %f", valoarePlasa);
}

void generareLobstersi(struct Homar *Lobsters, int noLobsters)
{
    int iterator;
    for(iterator = 0; iterator < noLobsters; iterator++)
    {
        Lobsters[iterator].id = iterator;
        Lobsters[iterator].lungime = rand()%500+1;
        Lobsters[iterator].valoare = rand()%500+1;
    }
}
int generateNumbers()
{
    int generatedNumber=rand()%+1;
    return generatedNumber;
}

int main()
{
    srand(time(NULL));
    clock_t tic = clock();
    struct Homar *Lobsters;
    int noLobsters= 1120 ;
    int DimensiunePlasa=11200;
    Lobsters = malloc(noLobsters * sizeof(struct Homar));
    generareLobstersi(Lobsters, noLobsters);


    printf("  Number of lobsters:%d\n  Net capacity:%d", noLobsters, DimensiunePlasa);
    printf("\n==== Lobsters selected ====  ");
    sortareLobsters(Lobsters, noLobsters);
    repartizareLobsters(Lobsters, noLobsters, DimensiunePlasa);
    clock_t toc = clock();
    printf("\nElapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
    return 0;
}
