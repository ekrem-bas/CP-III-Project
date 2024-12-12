#include <stdio.h>
#include <stdlib.h>
#include "Proje1.h"

int main(int argc, char const *argv[])
{
    // Çalışanlar
    Calisan *calisan1 = calisanOlustur("Calisan 1", "Calisan", 101, 5500, 2020);
    Calisan *calisan2 = calisanOlustur("Calisan 2", "Calisan", 101, 12000, 2010);
    Calisan *calisan3 = calisanOlustur("Calisan 3", "Calisan", 101, 5500, 2020);
    Calisan *calisan4 = calisanOlustur("Calisan 4", "Calisan", 102, 12500, 2012);
    Calisan *calisan5 = calisanOlustur("Calisan 5", "Calisan", 102, 14000, 2020);

    // Birimler
    Birim *birim1 = birimOlustur("Birim1", 101);
    Birim *birim2 = birimOlustur("Birim2", 102);

    // birim ve çalışanlar dizileri
    Calisan **calisanlar = calloc(10, sizeof(Calisan *));
    calisanlar[0] = calisan1;
    calisanlar[1] = calisan2;
    calisanlar[2] = calisan3;

    Birim **birimler = calloc(10, sizeof(Birim *));
    birimler[0] = birim1;
    birimler[1] = birim2;

    // calışanları birime ekle
    birimCalisanEkle(calisan1, birim1);
    birimCalisanEkle(calisan2, birim1);
    birimCalisanEkle(calisan3, birim1);

    // birim bilgi yazdır test
    printf("--------------------------------------\n");
    printf("Birim Bilgi Yazdır Çalıştırıldı.\n");
    printf("--------------------------------------\n");
    birimBilgiYazdir(birim1);

    // birim ortalama maaş test
    float maasOrt = maasOrtalamaHesapla(birim1);
    printf("--------------------------------------\n");
    printf("Maaş Ortalama Hesapla Çalıştırıldı.\n");
    printf("--------------------------------------\n");
    printf("Maaş Ortalaması: %.2f\n", maasOrt);

    // ortalama üstü maaş
    printf("--------------------------------------\n");
    printf("Ortalama Ustu Maas Çalıştırıldı.\n");
    printf("--------------------------------------\n");
    ortalamaUstuMaas(birim1);

    // maas ayarla fonksiyonu test
    maasAyarla(calisan2, birim1, 25000);
    printf("--------------------------------------\n");
    printf("Maaş Ayarla Çalıştırıldı.\n");
    printf("--------------------------------------\n");

    // birim bilgi test
    printf("--------------------------------------\n");
    printf("Birim Bilgi Yazdır Çalıştırıldı.\n");
    printf("--------------------------------------\n");
    birimBilgiYazdir(birim1);

    // ortalama maas test
    maasOrt = maasOrtalamaHesapla(birim1);
    printf("--------------------------------------\n");
    printf("Maaş Ortalama Hesapla Çalıştırıldı.\n");
    printf("--------------------------------------\n");
    printf("Maaş Ayarladan sonraki maas ortalaması: %.2f\n", maasOrt);

    // ortalama üstü maaş
    printf("--------------------------------------\n");
    printf("Ortalama Ustu Maas Çalıştırıldı.\n");
    printf("--------------------------------------\n");
    ortalamaUstuMaas(birim1);

    // en yuksek maaşlar test
    printf("--------------------------------------\n");
    printf("En Yüksek Maaslar Çalıştırıldı.\n");
    printf("--------------------------------------\n");
    enYuksekMaaslar(birimler);

    // bellek temizliği

    // çalışanları temizle
    free(birim1->birimCalisanlar);
    free(birim2->birimCalisanlar);

    // çalışanlar dizisini temizle
    for (int i = 0; i < 10; i++)
    {
        free(calisanlar[i]);
    }
    free(calisanlar);

    // birimler dizisini temizle
    for (int i = 0; i < 10; i++)
    {
        free(birimler[i]);
    }
    free(birimler);

    return 0;
}