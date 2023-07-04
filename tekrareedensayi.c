#include <stdio.h>

#define BOYUT 100

void tekrarEdenleriBul(int dizi[], int boyut) {
    int hashTablosu[BOYUT] = {0};
    
    printf("Tekrar eden elemanlar: ");
    for (int i = 0; i < boyut; i++) {
        if (hashTablosu[dizi[i]] == 1) {
            printf("%d ", dizi[i]);
        } else {
            hashTablosu[dizi[i]]++;
        }
    }
    printf("\n");
}

int main() {
    int dizi[] = {1, 2, 3, 2, 4, 1, 5, 6, 3};
    int boyut = sizeof(dizi) / sizeof(dizi[0]);
    
    tekrarEdenleriBul(dizi, boyut);
    
    return 0;
}
