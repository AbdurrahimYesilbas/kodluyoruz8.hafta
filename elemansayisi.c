#include <stdio.h>
#include <stdlib.h>

struct Node {
    int veri;
    struct Node* sonraki;
};

int elemanSayisi(struct Node* head) {
    int sayac = 0;
    struct Node* current = head;
    
    while (current != NULL) {
        sayac++;
        current = current->sonraki;
    }
    
    return sayac;
}

int main() {
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;
    
    // İlk düğümü oluştur
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    
    head->veri = 1;
    head->sonraki = second;
    
    second->veri = 2;
    second->sonraki = third;
    
    third->veri = 3;
    third->sonraki = NULL;
    
    int sayac = elemanSayisi(head);
    printf("Eleman sayisi: %d\n", sayac);
    
    return 0;
}
