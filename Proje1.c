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
#include <string.h>

int toplamCalisanSayisi = 0;
int toplamBirimSayisi = 0;

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
void calisanDiziyeEkle(Calisan *calisan, Calisan ***calisanlar) {
    *calisanlar = realloc(*calisanlar, (toplamCalisanSayisi + 1) * sizeof(Calisan *));
    if (*calisanlar == NULL) {
        printf("Bellek yeniden tahsis edilemedi.\n");
        exit(1);
    }
    (*calisanlar)[toplamCalisanSayisi] = calisan;
    toplamCalisanSayisi++;
}

void birimDiziyeEkle(Birim *birim, Birim ***birimler)
{
    *birimler = realloc(*birimler, (toplamBirimSayisi + 1) * sizeof(Birim *));
    if (*birimler == NULL)
    {
        printf("Bellek yeniden tahsis edilemedi.\n");
        exit(1);
    }
    (*birimler)[toplamBirimSayisi] = birim;
    toplamBirimSayisi++;
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
void birimlerBilgiYazdir(Birim **birimler)
{
    for (size_t i = 0; i < toplamBirimSayisi; i++)
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
void enYuksekMaaslar(Birim **birimler)
{
    for (size_t i = 0; i < toplamBirimSayisi; i++)
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
void dosyayaYaz(char *calisanlarDosyaAdi, char *birimlerDosyaAdi, Calisan **calisanlar, Birim **birimler) {
    printf("Dosyaya yazma işlemi başlatılıyor...\n");
    FILE *calisanlarDosya = fopen(calisanlarDosyaAdi, "w");
    FILE *birimlerDosya = fopen(birimlerDosyaAdi, "w");
    if (calisanlarDosya == NULL || birimlerDosya == NULL) {
        perror("Dosyalar Acilamadi");
        return;
    }
    for (int i = 0; i < toplamCalisanSayisi; i++) {
        if (calisanlar[i] != NULL) {
            fprintf(calisanlarDosya, "%s;%s;%d;%.2f;%d;\n",
                calisanlar[i]->calisanAdi,
                calisanlar[i]->calisanSoyadi,
                calisanlar[i]->birimKodu,
                calisanlar[i]->maas,
                calisanlar[i]->girisYili);
        }
    }

    fclose(calisanlarDosya);

    for (int i = 0; i < toplamBirimSayisi; i++) {
        if (birimler[i] != NULL) {
            fprintf(birimlerDosya, "%s;%d;\n", birimler[i]->birimAdi, birimler[i]->birimKodu);
        }
    }

    fclose(birimlerDosya);
    printf("Bilgiler basariyle dosyaya yazildi!\n");
}

/*
    12. Tüm Birim ve Calisan bilgilerini dosyadan diziye aktaran bir fonksiyon.
*/
void dosyadanOku(char *calisanlarDosyaAdi, char *birimlerDosyaAdi, Calisan ***calisanlar, Birim ***birimler) {
    FILE *calisanlarDosya = fopen(calisanlarDosyaAdi, "r");
    FILE *birimlerDosya = fopen(birimlerDosyaAdi, "r");

    if (calisanlarDosya == NULL || birimlerDosya == NULL) {
        perror("Dosyalar Acilamadi");
        return;
    }

    // Birimleri oku
    //TODO: Malloc yerine calisanAdi[30] tanımlaması yapmayı dene.
    char birimAdi[128];
    int birimKodu;
    while (fscanf(birimlerDosya, "%127[^;];%d\n", birimAdi, &birimKodu) == 2) {
        // Birim için dinamik bellek ayırma
        char *dinamikBirimAdi = malloc(strlen(birimAdi) + 1);
        if (dinamikBirimAdi == NULL) {
            perror("Bellek ayrilamadi");
            fclose(birimlerDosya);
            return;
        }
        strcpy(dinamikBirimAdi, birimAdi);

        // Yeni birim oluştur
        Birim *yeniBirim = birimOlustur(dinamikBirimAdi, birimKodu);
        birimDiziyeEkle(yeniBirim, birimler);
    }
    fclose(birimlerDosya);

    // Çalışanları oku
    char calisanlarSatir[256];
    while (fgets(calisanlarSatir, sizeof(calisanlarSatir), calisanlarDosya)) {
        calisanlarSatir[strcspn(calisanlarSatir, "\n")] = '\0'; // Yeni satır karakterini temizle

        // Çalışan bilgilerini ayrıştır
        char *calisanAdiTmp = strtok(calisanlarSatir, ";");
        char *calisanSoyadiTmp = strtok(NULL, ";");
        int birimKodu = atoi(strtok(NULL, ";"));
        float maas = atof(strtok(NULL, ";"));
        int girisYili = atoi(strtok(NULL, ";"));

        // Dinamik bellek ayırma ve kopyalama
        char *calisanAdi = malloc(strlen(calisanAdiTmp) + 1);
        char *calisanSoyadi = malloc(strlen(calisanSoyadiTmp) + 1);
        if (calisanAdi == NULL || calisanSoyadi == NULL) {
            perror("Bellek ayrilamadi");
            fclose(calisanlarDosya);
            fclose(birimlerDosya);
            return;
        }
        strcpy(calisanAdi, calisanAdiTmp);
        strcpy(calisanSoyadi, calisanSoyadiTmp);

        // Yeni çalışan oluştur
        Calisan *yeniCalisan = calisanOlustur(calisanAdi, calisanSoyadi, birimKodu, maas, girisYili);
        calisanDiziyeEkle(yeniCalisan, calisanlar);
    }

    fclose(calisanlarDosya);

     for (int i = 0; i < toplamBirimSayisi; i++) {
         for (int j = 0; j < toplamCalisanSayisi; j++) {
             if ((*birimler)[i]->birimKodu == (*calisanlar)[j]->birimKodu) {
                 birimCalisanEkle((*calisanlar)[j], (*birimler)[i]);
             }
         }
     }
}

/*
    Birimleri, Çalışanları ve Birimlerin Çalışanlarını serbest bırak
*/
void bellekTemizliği(Birim **birimler, Calisan **calisanlar) {
    for (int i = 0; i < toplamBirimSayisi; i++) {
        free(birimler[i]->birimAdi); // Birim adı belleğini serbest bırak
        free(birimler[i]);           // Birim nesnesini serbest bırak
    }
    free(birimler);

    for (int i = 0; i < toplamCalisanSayisi; i++) {
        free(calisanlar[i]->calisanAdi); // Çalışan adı belleğini serbest bırak
        free(calisanlar[i]->calisanSoyadi); // Çalışan soyadı belleğini serbest bırak
        free(calisanlar[i]);            // Çalışan nesnesini serbest bırak
    }
    free(calisanlar);
}