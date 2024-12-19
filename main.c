/*
* @file main.h
 * @description Programınızın açıklaması ne yaptığına dair.
 * @assignment 1. Ödev
 * @date 06.12.2024
 * @author Ekrem Baş | ekrem.bas@stu.fsm.edu.tr
 */

#include <stdio.h>
#include <stdlib.h>
#include "Proje1.h"

int main(int argc, char const *argv[])
{
    // // Çalışanlar
    // Calisan *calisan1 = calisanOlustur("Calisan 1", "Calisan", 101, 5500, 2020);
    // Calisan *calisan2 = calisanOlustur("Calisan 2", "Calisan", 101, 12000, 2010);
    // Calisan *calisan3 = calisanOlustur("Calisan 3", "Calisan", 101, 5500, 2020);
    // Calisan *calisan4 = calisanOlustur("Calisan 4", "Calisan", 102, 12500, 2012);
    // Calisan *calisan5 = calisanOlustur("Calisan 5", "Calisan", 102, 14000, 2020);

    // Birimler
    Birim **birimler = NULL;
    // Birim *birim1 = birimOlustur("Birim1", 101);
    // Birim *birim2 = birimOlustur("Birim2", 102);
    // birimDiziyeEkle(birim1, &birimler);
    // birimDiziyeEkle(birim2, &birimler);
    //
    // // birim ve çalışanlar dizileri
    Calisan **calisanlar = NULL;


    // calisanDiziyeEkle(calisan1, &calisanlar);
    // calisanDiziyeEkle(calisan2, &calisanlar);
    // calisanDiziyeEkle(calisan3, &calisanlar);

    // // calışanları birime ekle
    // birimCalisanEkle(calisan1, birim1);
    // birimCalisanEkle(calisan2, birim1);
    // birimCalisanEkle(calisan3, birim1);
    // birimCalisanEkle(calisan4, birim2);
    // birimCalisanEkle(calisan5, birim2);

    // birim bilgi yazdır test
    // printf("--------------------------------------\n");
    // printf("Birim Bilgi Yazdır Çalıştırıldı.\n");
    // printf("--------------------------------------\n");
    // birimBilgiYazdir(birim1);
    //
    // // birim ortalama maaş test
    // float maasOrt = maasOrtalamaHesapla(birim1);
    // printf("--------------------------------------\n");
    // printf("Maaş Ortalama Hesapla Çalıştırıldı.\n");
    // printf("--------------------------------------\n");
    // printf("Maaş Ortalaması: %.2f\n", maasOrt);
    //
    // // ortalama üstü maaş
    // printf("--------------------------------------\n");
    // printf("Ortalama Ustu Maas Çalıştırıldı.\n");
    // printf("--------------------------------------\n");
    // ortalamaUstuMaas(birim1);
    //
    // // maas ayarla fonksiyonu test
    // maasAyarla(calisan2, birim1, 25000);
    // printf("--------------------------------------\n");
    // printf("Maaş Ayarla Çalıştırıldı.\n");
    // printf("--------------------------------------\n");
    //
    // // birim bilgi test
    // printf("--------------------------------------\n");
    // printf("Birim Bilgi Yazdır Çalıştırıldı.\n");
    // printf("--------------------------------------\n");
    // birimBilgiYazdir(birim1);
    //
    // // ortalama maas test
    // maasOrt = maasOrtalamaHesapla(birim1);
    // printf("--------------------------------------\n");
    // printf("Maaş Ortalama Hesapla Çalıştırıldı.\n");
    // printf("--------------------------------------\n");
    // printf("Maaş Ayarladan sonraki maas ortalaması: %.2f\n", maasOrt);
    //
    // // ortalama üstü maaş
    // printf("--------------------------------------\n");
    // printf("Ortalama Ustu Maas Çalıştırıldı.\n");
    // printf("--------------------------------------\n");
    // ortalamaUstuMaas(birim1);
    //
    // // en yuksek maaşlar test
    // printf("--------------------------------------\n");
    // printf("En Yüksek Maaslar Çalıştırıldı.\n");
    // printf("--------------------------------------\n");
    // enYuksekMaaslar(birimler);
    //
    // printf("--------------------------------------\n");
    // printf("Birim Bilgi Yazdır Çalıştırıldı.\n");
    // printf("--------------------------------------\n");
    // birimBilgiYazdir(birim1);
    //
    // printf("--------------------------------------\n");
    // printf("Birimler Bilgi Yazdır Çalıştırıldı.\n");
    // birimlerBilgiYazdir(birimler);
    // printf("--------------------------------------\n");

    // printf("--------------------------------------\n");
    // printf("Dosyaya yaz fonksiyonu Çalıştırıldı.\n");
    // printf("--------------------------------------\n");
    // dosyayaYaz("calisanlar.txt", "birimler.txt", calisanlar, birimler);
    //
    // printf("--------------------------------------\n");
    // printf("Dosyadan oku fonksiyonu Çalıştırıldı.\n");
    // printf("--------------------------------------\n");
    dosyadanOku("calisanlar.txt", "birimler.txt", &calisanlar, &birimler);
    //
    //
    // printf("--------------------------------------\n");
    // printf("Birimler Bilgi Yazdır Çalıştırıldı.\n");
    // printf("--------------------------------------\n");
    // birimlerBilgiYazdir(birimler);
    // printf("--------------------------------------\n");

    birimlerBilgiYazdir(birimler);
    for (int i = 0; i < 5; i++) {
        calisanBilgiYazdir(*calisanlar[i]);
        printf("------------------------------------\n");
    }


    // bellek temizliği
    bellekTemizliği(birimler, calisanlar);

    return 0;
}