/*
 * @file Proje1.c
 * @description Projede kullanılan fonksiyonların uygulamasını (implementation) içeren C dosyası
 * @assignment 1. Ödev
 * @date 06.12.2024
 * @author Ekrem Baş | ekrem.bas@stu.fsm.edu.tr
 */

#include <stdio.h>
#include <stdlib.h>
#include "Proje1.h"
#include <string.h>

// Dizilere ekleme işlemleri için toplam çalışan ve birim sayısı
int toplamCalisanSayisi = 0;
int toplamBirimSayisi = 0;

/*
    1. İlgili değerleri alıp bir Birim struct döndüren bir fonksiyon.
*/
Birim *birimOlustur(char *birimAdi, unsigned short int birimKodu)
{
    Birim *yeniBirim = malloc(sizeof(Birim));
    yeniBirim->birimAdi = strdup(birimAdi);
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
    yeniCalisan->calisanAdi = strdup(calisanAdi);
    yeniCalisan->calisanSoyadi = strdup(calisanSoyadi);
    yeniCalisan->birimKodu = birimKodu;
    yeniCalisan->maas = maas;
    yeniCalisan->girisYili = girisYili;
    return yeniCalisan;
}

/*
    Birime çalışan ekleme fonksiyonu
*/
void birimeCalisanEkle(Calisan *calisan, Birim *birim)
{
    birim->birimCalisanlar[birim->calisanSayisi] = calisan;
    birim->calisanSayisi++;
}

/*
    3. Oluşturulan yeni struct yapılarını diziye ekleyen fonksiyon.
    birimi diziye ekle
*/
void calisaniDiziyeEkle(Calisan *calisan, Calisan ***calisanlar) {
    *calisanlar = realloc(*calisanlar, (toplamCalisanSayisi + 1) * sizeof(Calisan *));
    if (*calisanlar == NULL) {
        printf("Bellek yeniden tahsis edilemedi.\n");
        exit(1);
    }
    (*calisanlar)[toplamCalisanSayisi] = calisan;
    toplamCalisanSayisi++;
}

void birimiDiziyeEkle(Birim *birim, Birim ***birimler)
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
    printf("-------------------------------\n");
    printf("\t----Calisan Bilgisi----\n");
    printf("-------------------------------\n");
    printf("- ");
    printf("Calisan Adi: %s\n", calisan.calisanAdi);
    printf("Calisan Soyadi: %s\n", calisan.calisanSoyadi);
    printf("Calisan Birim Kodu: %d\n", calisan.birimKodu);
    printf("Calisan Maasi: %.2f\n", calisan.maas);
    printf("Calisan Giris Yili: %d\n", calisan.girisYili);
}

/*
    5. Parametre olarak Birim türünden değişken alıp bilgilerini yazdıran bir
fonksiyon.
*/
void birimBilgiYazdir(Birim *birim)
{
    printf("-------------------------------\n");
    printf("\t----Birim Bilgisi----\n");
    printf("-------------------------------\n");
    printf("Birim Adi: %s\n", birim->birimAdi);
    printf("Birim Kodu: %d\n", birim->birimKodu);
    printf("Birimin Calisanlarinin Bilgileri:\n");
    for (int i = 0; i < birim->calisanSayisi; i++)
    {
        calisanBilgiYazdir(*(birim->birimCalisanlar[i]));
    }
    printf("-------------------------------\n");
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
    }
}

/*
    7. Parametre olarak aldığı birimin çalışanlarının maaş ortalamasını
hesaplayan bir fonksiyon yazınız.
*/
void birimOrtalamaMaas(Birim *birim)
{
    // birimdeki maaslarin toplami
    float maasToplam = 0;
    for (size_t i = 0; i < birim->calisanSayisi; i++)
    {
        maasToplam += birim->birimCalisanlar[i]->maas;
    }
    // birimdeki maaslarin toplami / birimdeki calisan sayisi
    float ortalamaMaas = maasToplam / birim->calisanSayisi;
    printf("-------------------------------\n");
    printf("\t----Birimin Ort Maası----\n");
    printf("-------------------------------\n");
    printf("Birim Adi: %s\n", birim->birimAdi);
    printf("Birim Kodu: %d\n", birim->birimKodu);
    printf("Birimin Ortalama Maası: %.2f\n", ortalamaMaas);
    printf("-------------------------------\n");
}

/*
    8. Parametre olarak aldığı birimde ortalama maaş üzerinde maaş alan
çalışanları listeleyen bir fonksiyon.
*/
void birimOrtalamaUstuMaas(Birim *birim)
{
    printf("-------------------------------\n");
    printf("\t----Ort Ustu Maaslar----\n");
    printf("\t----Birim: %d----\n", birim->birimKodu);
    printf("-------------------------------\n");
    float toplamMaas = 0;
    float ortalamaMaas = 0;
    for (size_t i = 0; i < birim->calisanSayisi; i++)
    {
        toplamMaas += birim->birimCalisanlar[i]->maas;
    }
    ortalamaMaas = toplamMaas / birim->calisanSayisi;
    for (size_t i = 0; i < birim->calisanSayisi; i++)
    {
        if (birim->birimCalisanlar[i]->maas > ortalamaMaas)
        {
            calisanBilgiYazdir(*(birim->birimCalisanlar[i]));
            printf("-------------------------------\n");
        }
    }
}

/*
    9. Her birimin ayrı ayrı en yüksek maaş alan çalışanını yazdıran fonksiyon.
*/
void birimEnYuksekMaas(Birim **birimler)
{
    printf("-------------------------------\n");
    printf("\t----En Yuksek Maaslar----\n");
    printf("-------------------------------\n");
    for (size_t i = 0; i < toplamBirimSayisi; i++) {
        // birimde çalışan yoksa o birimden bilgi dönmeyecek
        if (birimler[i]->calisanSayisi == 0) {
            continue;
        } else {
            // Calisan enYuksekMaasliCalisan = *(birimler[i]->birimCalisanlar[0]);
            printf("Birim Adi: %s\n", birimler[i]->birimAdi);
            printf("Birim Kodu: %d\n", birimler[i]->birimKodu);
            printf("En Yuksek Maas Alan Calisan:\n");
            float enYuksekMaas = 0;
            for (size_t j = 0; j < birimler[i]->calisanSayisi; j++)
            {
                if (birimler[i]->birimCalisanlar[j]->maas >= enYuksekMaas)
                {
                    enYuksekMaas = birimler[i]->birimCalisanlar[j]->maas;
                    calisanBilgiYazdir(*(birimler[i]->birimCalisanlar[j]));
                    printf("-------------------------------\n");
                }
            }
        }
    }
}

/*
    10. Parametre olarak bir maaş değeri alıp, 10 yıldan fazla çalışanlar bu
maaştan az alıyor ise maaşlarını parametre olarak verilen maaşa eşitleyen
fonksiyon.
*/
void yeniMaasAyarla(float yeniMaas, Calisan **calisanlar)
{
    int yil = 2024;
    for (size_t i = 0; i < toplamCalisanSayisi; i++) {
        if (yil - calisanlar[i]->girisYili > 10 && calisanlar[i]->maas < yeniMaas) {
            calisanlar[i]->maas = yeniMaas;
        }
    }
}

/*
    11. Tüm Birim ve Calisan bilgilerini bir dosyaya yazan bir fonksiyon.
*/
void dosyayaYaz(const char *calisanlarDosyaAdi, const char *birimlerDosyaAdi, Calisan **calisanlar, Birim **birimler) {
    printf("-------------------------------\n");
    printf("Dosyaya yazma islemi baslatiliyor...\n");
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
    printf("-------------------------------\n");
}

/*
    12. Tüm Birim ve Calisan bilgilerini dosyadan diziye aktaran bir fonksiyon.
*/
void dosyadanOku(const char *calisanlarDosyaAdi, const char *birimlerDosyaAdi, Calisan ***calisanlar, Birim ***birimler) {
    printf("-------------------------------\n");
    printf("Dosyadan okuma islemi başlatiliyor...\n");
    // Dosyalar
    FILE *calisanlarDosya = fopen(calisanlarDosyaAdi, "r");
    FILE *birimlerDosya = fopen(birimlerDosyaAdi, "r");

    // Dosya açılmasında bir hata olursa
    if (calisanlarDosya == NULL || birimlerDosya == NULL) {
        perror("Dosyalar Acilamadi");
        return;
    }

    // satır
    char satir[256];

    // Birimleri oku
    while (fgets(satir, sizeof(satir), birimlerDosya)) {
        char birimAdi[256];
        int birimKodu;
        // sscanf ile ayrıştır
        if (sscanf(satir, "%[^;];%d;", birimAdi, &birimKodu) == 2) {
            // Yeni birim oluştur
            Birim *yeniBirim = birimOlustur(birimAdi, birimKodu);
            birimiDiziyeEkle(yeniBirim, birimler);
        }
    }
    fclose(birimlerDosya);

    // Çalışanları oku
    while (fgets(satir, sizeof(satir), calisanlarDosya)) {
        char calisanAdi[256];
        char calisanSoyadi[256];
        int birimKodu;
        float maas;
        int girisYili;

        // sscanf ile ayrıştır
        if (sscanf(satir, "%[^;];%[^;];%d;%f;%d;", calisanAdi, calisanSoyadi, &birimKodu, &maas, &girisYili) == 5) {
            // Yeni çalışan oluştur
            Calisan *yeniCalisan = calisanOlustur(calisanAdi, calisanSoyadi, birimKodu, maas, girisYili);
            calisaniDiziyeEkle(yeniCalisan, calisanlar);
        }
    }
    fclose(calisanlarDosya);

    // Çalışanları birimlere bağla
    for (int i = 0; i < toplamBirimSayisi; i++) {
        for (int j = 0; j < toplamCalisanSayisi; j++) {
            if ((*birimler)[i]->birimKodu == (*calisanlar)[j]->birimKodu) {
                birimeCalisanEkle((*calisanlar)[j], (*birimler)[i]);
            }
        }
    }
    printf("Dosyadan okuma islemi basarili!\n");
    printf("-------------------------------\n");
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