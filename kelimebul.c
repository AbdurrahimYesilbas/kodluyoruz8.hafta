#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define HARF_SAYISI 26

struct TrieNode {
    struct TrieNode* cocuklar[HARF_SAYISI];
    bool kelimeSonu;
};

struct TrieNode* dugumOlustur() {
    struct TrieNode* dugum = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    dugum->kelimeSonu = false;
    for (int i = 0; i < HARF_SAYISI; i++) {
        dugum->cocuklar[i] = NULL;
    }
    return dugum;
}

void kelimeEkle(struct TrieNode* kok, const char* kelime) {
    struct TrieNode* current = kok;
    int uzunluk = strlen(kelime);
    
    for (int i = 0; i < uzunluk; i++) {
        int indeks = kelime[i] - 'a';
        if (current->cocuklar[indeks] == NULL) {
            current->cocuklar[indeks] = dugumOlustur();
        }
        current = current->cocuklar[indeks];
    }
    
    current->kelimeSonu = true;
}

void kelimeAra(struct TrieNode* kok, const char* kelime) {
    struct TrieNode* current = kok;
    int uzunluk = strlen(kelime);
    
    for (int i = 0; i < uzunluk; i++) {
        int indeks = kelime[i] - 'a';
        if (current->cocuklar[indeks] == NULL) {
            return;
        }
        current = current->cocuklar[indeks];
    }
    
    yazdir(kelime, current);
}

void yazdir(char* kelime, struct TrieNode* dugum) {
    if (dugum->kelimeSonu) {
        printf("%s\n", kelime);
    }
    
    for (int i = 0; i < HARF_SAYISI; i++) {
        if (dugum->cocuklar[i] != NULL) {
            kelime[strlen(kelime)] = 'a' + i;
            yazdir(kelime, dugum->cocuklar[i]);
            kelime[strlen(kelime) - 1] = '\0';
        }
    }
}

int main() {
    const char* metinListesi[] = {"apple", "application", "banana", "art", "ball", "cat"};
    int metinListesiBoyutu = sizeof(metinListesi) / sizeof(metinListesi[0]);
    
    struct TrieNode* kok = dugumOlustur();
    
    for (int i = 0; i < metinListesiBoyutu; i++) {
        kelimeEkle(kok, metinListesi[i]);
    }
    
    const char* baslangicMetni = "app";
    kelimeAra(kok, baslangicMetni);
    
    return 0;
}
