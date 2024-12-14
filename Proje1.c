/*
 * @file Proje1.c
 * @description Programınızın açıklaması ne yaptığına dair.
 * @assignment 1. Ödev
 * @date 06.12.2024
 * @author Ekrem Baş | ekrem.bas@stu.fsm.edu.tr
 */

#include <stdio.h>
#include <stdlib.h>
#include "Proje1.h"

/*
    1. İlgili değerleri alıp bir Birim struct döndüren bir fonksiyon.
*/
Birim *birimOlustur(char *birimAdi, unsigned short int birimKodu)
{
    Birim *yeniBirim = malloc(sizeof(Birim));
    yeniBirim->birimAdi = birimAdi;
    yeniBirim->birimKodu = birimKodu;
    yeniBirim->birimCalisanlar = calloc(20, sizeof(Calisan));
    yeniBirim->calisanSayisi = 0;
    return yeniBirim;
}

/*
    2. İlgili değerleri alıp bir Calisan struct döndüren fonksiyon.
*/
Calisan *calisanOlustur(char *calisanAdi, char *calisanSoyadi, unsigned short int birimKodu, float maas, int girisYili)
{
    Calisan *yeniCalisan = malloc(sizeof(Calisan));
    yeniCalisan->calisanAdi = calisanAdi;
    yeniCalisan->calisanSoyadi = calisanSoyadi;
    yeniCalisan->birimKodu = birimKodu;
    yeniCalisan->maas = maas;
    yeniCalisan->girisYili = girisYili;
    return yeniCalisan;
}

/*
    BİRİME BİRER BİRER ÇALIŞAN EKLEME FONKSİYONU
*/
void birimCalisanEkle(Calisan *calisan, Birim *birim)
{
    birim->birimCalisanlar[birim->calisanSayisi] = *calisan;
    birim->calisanSayisi++;
}

/*
    3. Oluşturulan yeni struct yapılarını diziye ekleyen fonksiyon.
    birimi diziye ekle
*/

// Çalışanı diziye ekle
void calisanDiziyeEkle(Calisan *calisan, Calisan ***calisanlar, int *calisanSayisi) {
    *calisanlar = realloc(*calisanlar, (*calisanSayisi + 1) * sizeof(Calisan *));
    if (*calisanlar == NULL) {
        printf("Bellek yeniden tahsis edilemedi.\n");
        exit(1);
    }
    (*calisanlar)[*calisanSayisi] = calisan;
    (*calisanSayisi)++;
}

// Birimi diziye ekle
void birimDiziyeEkle(Birim *birim, Birim ***birimler, int *birimSayisi)
{
    *birimler = realloc(*birimler, (*birimSayisi + 1) * sizeof(Birim *));
    if (*birimler == NULL)
    {
        printf("Bellek yeniden tahsis edilemedi.\n");
        exit(1);
    }
    (*birimler)[*birimSayisi] = birim;
    (*birimSayisi)++;
}
/*
    4. Parametre olarak Calisan türünden değişken alıp bilgilerini yazdıran bir
fonksiyon.
*/
void calisanBilgiYazdir(Calisan calisan)
{
    printf("Calisan Adi: %s\n", calisan.calisanAdi);
    printf("Calisan Soyadi: %s\n", calisan.calisanSoyadi);
    printf("Calisan Birim Kodu: %d\n", calisan.birimKodu);
    printf("Calisan Maasi: %f\n", calisan.maas);
    printf("Calisan Giris Yili: %d\n", calisan.girisYili);
}

/*
    5. Parametre olarak Birim türünden değişken alıp bilgilerini yazdıran bir
fonksiyon.
*/
void birimBilgiYazdir(Birim *birim)
{
    printf("Birim Adi: %s\n", birim->birimAdi);
    printf("Birim Kodu: %d\n", birim->birimKodu);
    printf("Çalışanlar:\n");
    for (int i = 0; i < birim->calisanSayisi; i++)
    {
        printf("- ");
        calisanBilgiYazdir(birim->birimCalisanlar[i]);
    }
}

/*
    6. Parametre olarak Birim türünden dinamik bir dizi alıp bilgilerini yazdıran
bir fonksiyon.
*/
void birimlerBilgiYazdir(Birim **birimler, int *birimSayisi)
{
    for (size_t i = 0; i < *birimSayisi; i++)
    {
        birimBilgiYazdir(birimler[i]);
        printf("-------------------------------\n");
    }
}

/*
    7. Parametre olarak aldığı birimin çalışanlarının maaş ortalamasını
hesaplayan bir fonksiyon yazınız.
*/
float maasOrtalamaHesapla(Birim *birim)
{
    float maasToplam = 0;
    int calisanToplam = 0;
    for (size_t i = 0; i < birim->calisanSayisi; i++)
    {
        maasToplam += birim->birimCalisanlar[i].maas;
        calisanToplam += 1;
    }
    return maasToplam / calisanToplam;
}

/*
    8. Parametre olarak aldığı birimde ortalama maaş üzerinde maaş alan
çalışanları listeleyen bir fonksiyon.
*/
void ortalamaUstuMaas(Birim *birim)
{
    float toplamMaas = 0;
    float ortalamaMaas = 0;
    for (size_t i = 0; i < birim->calisanSayisi; i++)
    {
        toplamMaas += birim->birimCalisanlar[i].maas;
    }
    ortalamaMaas = toplamMaas / birim->calisanSayisi;
    for (size_t i = 0; i < birim->calisanSayisi; i++)
    {
        if (birim->birimCalisanlar[i].maas > ortalamaMaas)
        {
            calisanBilgiYazdir(birim->birimCalisanlar[i]);
        }
    }
}

/*
    9. Her birimin ayrı ayrı en yüksek maaş alan çalışanını yazdıran fonksiyon.
*/
void enYuksekMaaslar(Birim **birimler, int *birimSayisi)
{
    for (size_t i = 0; i < *birimSayisi; i++)
    {
        Calisan enYuksekMaasliCalisan = birimler[i]->birimCalisanlar[0];

        for (size_t j = 1; j < birimler[i]->calisanSayisi; j++)
        {
            if (birimler[i]->birimCalisanlar[j].maas > enYuksekMaasliCalisan.maas)
            {
                enYuksekMaasliCalisan = birimler[i]->birimCalisanlar[j];
            }
        }

        printf("Birim Adi: %s\n", birimler[i]->birimAdi);
        printf("En Yüksek Maaş Alan Çalışan:\n");
        calisanBilgiYazdir(enYuksekMaasliCalisan);
    }
}

/*
    10. Parametre olarak bir maaş değeri alıp, 10 yıldan fazla çalışanlar bu
maaştan az alıyor ise maaşlarını parametre olarak verilen maaşa eşitleyen
fonksiyon.
*/
void maasAyarla(Calisan *calisan, Birim *birim, float yeniMaas)
{
    int yil = 2024;
    for (size_t i = 0; i < birim->calisanSayisi; i++)
    {
        if (yil - calisan->girisYili > 10 && calisan->maas < yeniMaas && birim->birimCalisanlar[i].calisanAdi == calisan->calisanAdi)
        {
            calisan->maas = yeniMaas;
            birim->birimCalisanlar[i].maas = yeniMaas;
            break;
        }
    }
}

/*
    11. Tüm Birim ve Calisan bilgilerini bir dosyaya yazan bir fonksiyon.
*/

/*
    12. Tüm Birim ve Calisan bilgilerini dosyadan diziye aktaran bir fonksiyon.
*/

/*
    Birimleri, Çalışanları ve Birimlerin Çalışanlarını serbest bırak
*/
void bellekTemizliği(Birim **birimler, Calisan **calisanlar, int *birimSayisi, int *calisanSayisi) {
    // birimler listesinin içindeki birimleri ve o birimlerdeki çalışanları serbest bırak
    for (size_t i = 0; i < *birimSayisi; i++) {
        free(birimler[i]->birimCalisanlar);
        free(birimler[i]);
    }
    // birimler listesini serbest bırak
    free(birimler);

    for (size_t i = 0; i < *calisanSayisi; i++) {
        free(calisanlar[i]);
    }
    free(calisanlar);
}