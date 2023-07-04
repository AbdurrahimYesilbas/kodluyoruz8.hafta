#include <stdio.h>

int main() {
    int dizi[] = {10, 5, 8, 20, 3};
    int boyut = sizeof(dizi) / sizeof(dizi[0]);
    
    int enBuyukSayi = dizi[0]; // Başlangıçta en büyük sayıyı ilk eleman olarak varsayıyoruz
    
    for (int i = 1; i < boyut; i++) {
        if (dizi[i] > enBuyukSayi) {
            enBuyukSayi = dizi[i];
        }
    }
    
    printf("En büyük sayı: %d\n", enBuyukSayi);
    
    return 0;
}
