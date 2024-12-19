/*
* @file main.h
 * @description Projede kullanılan fonksiyonların test edildiği C dosyası
 * @assignment 1. Ödev
 * @date 06.12.2024
 * @author Ekrem Baş | ekrem.bas@stu.fsm.edu.tr
 */

#include <stdio.h>
#include <stdlib.h>
#include "Proje1.h"

int main(int argc, char const *argv[])
{
    if (argc < 3) {
        printf("%s <calisanlar_dosyasi> <birimler_dosyasi>\n", argv[0]);
        return 1; // Hata kodu
    }

    const char *calisanlarDosyaAdi = argv[1];
    const char *birimlerDosyaAdi = argv[2];


    Birim **birimler = NULL;
    Calisan **calisanlar = NULL;

    dosyadanOku(calisanlarDosyaAdi, birimlerDosyaAdi, &calisanlar, &birimler);

    birimlerBilgiYazdir(birimler);

    birimOrtalamaMaas(birimler[0]);
    birimEnYuksekMaas(birimler);

    yeniMaasAyarla(29000, calisanlar);

    birimlerBilgiYazdir(birimler);

    dosyayaYaz(calisanlarDosyaAdi, birimlerDosyaAdi, calisanlar, birimler);

    // bellek temizliği
    bellekTemizliği(birimler, calisanlar);

    return 0;
}