/*
* @file Proje1.c
 * @description Programınızın açıklaması ne yaptığına dair.
 * @assignment 1. Ödev
 * @date 06.12.2024
 * @author Ekrem Baş | ekrem.bas@stu.fsm.edu.tr
 */

#include <stdio.h>
#include "Proje1.h";

Birim birimOlustur(char *birimAdi, unsigned short int birimKodu, Calisan *birimCalisanlar)
{
    Birim yeniBirim;
    yeniBirim.birimAdi = birimAdi;
    yeniBirim.birimKodu = birimKodu;
    yeniBirim.birimCalisanlar = birimCalisanlar;
    return yeniBirim;
}

Calisan calisanOlustur(char *calisanAdi, char *calisanSoyadi, unsigned short int birimKodu, float maas, int girisYili)
{
    Calisan yeniCalisan;
    yeniCalisan.calisanAdi = calisanAdi;
    yeniCalisan.calisanSoyadi = calisanSoyadi;
    yeniCalisan.birimKodu = birimKodu;
    yeniCalisan.maas = maas;
    yeniCalisan.girisYili = girisYili;
    return yeniCalisan;
}

void calisanBilgiYazdir(Calisan calisan)
{
    printf("Calisan Adi: %s\n", calisan.calisanAdi);
    printf("Calisan Soyadi: %s\n", calisan.calisanSoyadi);
    printf("Calisan Birim Kodu: %d\n", calisan.birimKodu);
    printf("Calisan Maasi: %f\n", calisan.maas);
    printf("Calisan Giris Yili: %d\n", calisan.girisYili);
}

void birimBilgiYazdir(Birim birim)
{
    printf("Birim Adi: %s\n", birim.birimAdi);
    printf("Birim Kodu: %d\n", birim.birimKodu);
    // TODO: Birimin çalışanlarının nasıl yazdırılabileceğine bak.
    for (size_t i = 0; i < 20; i++)
    {
        printf("%d. Çalışan: %s", (i + 1), birim.birimCalisanlar[i]);
    }
}

void birimlerBilgiYazdir(Birim *birimler)
{
}

float maasOrtalamaHesapla(Birim birim)
{
    int maasToplam = 0;
    int calisanToplam = 0;
    for (size_t i = 0; i < 20; i++)
    {
        if (birim.birimCalisanlar[i].maas > 0)
        {
            maasToplam += birim.birimCalisanlar[i].maas;
            calisanToplam += 1;
        }
    }
    return maasToplam / calisanToplam;
}

void ortalamaUstuMaas(Birim birim)
{
}

void enYuksekMaaslar(Birim *birimler) {}

void maasAyarla(float maas) {}