/*
 * @file Proje1.c
 * @description Projede kullanılan fonksiyonların uygulamasını (implementation) içeren C dosyası
 * @assignment 1. Ödev
 * @date 06.12.2024
 * @author Ekrem Baş | ekrem.bas@stu.fsm.edu.tr
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Proje1.h"

// Dizilere ekleme işlemleri için toplam çalışan ve birim sayısı.
int toplamCalisanSayisi = 0;
int toplamBirimSayisi = 0;

/*
    1. İlgili değerleri alıp bir Birim struct döndüren bir fonksiyon.
*/
Birim *birimOlustur(char *birimAdi, unsigned short int birimKodu)
{
    // Yeni birim için bellekte yer tahsis et.
    Birim *yeniBirim = malloc(sizeof(Birim));
    // Verilen string değerinin uzunluğu kadar bellekte yer ayır ve atama işlemini gerçekleştir.
    yeniBirim->birimAdi = strdup(birimAdi);
    yeniBirim->birimKodu = birimKodu;
    // Her bir birim için maksimum 20 Çalışanlık alanı calloc ile oluştur.
    yeniBirim->birimCalisanlar = calloc(20, sizeof(Calisan));
    // Her bir birimin kendi çalışan sayısını tut.
    yeniBirim->calisanSayisi = 0;
    return yeniBirim;
}

/*
    2. İlgili değerleri alıp bir Calisan struct döndüren fonksiyon.
*/
Calisan *calisanOlustur(char *calisanAdi, char *calisanSoyadi, unsigned short int birimKodu, float maas, int girisYili)
{
    // Bellekte yeni bir çalışan için alan tahsis et.
    Calisan *yeniCalisan = malloc(sizeof(Calisan));
    // İsim ve soyisim için verilen stringlerin boyutunda bellekten yer ayır ve atama işlemini gerçekleştir.
    yeniCalisan->calisanAdi = strdup(calisanAdi);
    yeniCalisan->calisanSoyadi = strdup(calisanSoyadi);
    yeniCalisan->birimKodu = birimKodu;
    yeniCalisan->maas = maas;
    yeniCalisan->girisYili = girisYili;
    return yeniCalisan;
}

/*
    Birime çalışan ekleme fonksiyonu.
*/
void birimeCalisanEkle(Calisan *calisan, Birim *birim)
{
    // Birimin çalışanlar listesine verilen çalışanı ekle.
    birim->birimCalisanlar[birim->calisanSayisi] = calisan;
    // Birimin çalışan sayısını arttır.
    birim->calisanSayisi++;
}

/*
    3. Oluşturulan yeni struct yapılarını diziye ekleyen fonksiyon.
    birimi diziye ekle
*/
void calisaniDiziyeEkle(Calisan *calisan, Calisan ***calisanlar) {
    // Parametre olarak verilen çalışanlar dizisinde yeni bir çalışan için yer aç.
    *calisanlar = realloc(*calisanlar, (toplamCalisanSayisi + 1) * sizeof(Calisan *));
    // Yer açma işlemi başarısız olursa hata döndür.
    if (*calisanlar == NULL) {
        printf("Bellek yeniden tahsis edilemedi.\n");
        exit(1);
    }
    // Parametre olarak verilen Çalışanlar dizisine verilen çalışanı ekle.
    (*calisanlar)[toplamCalisanSayisi] = calisan;
    // Birimden bağımsız tüm çalışanların sayısını arttır.
    toplamCalisanSayisi++;
}

void birimiDiziyeEkle(Birim *birim, Birim ***birimler)
{
    // Parametre olarak verilen birimler dizisinde yeni bir birim için yer aç.
    *birimler = realloc(*birimler, (toplamBirimSayisi + 1) * sizeof(Birim *));
    // Yer açma işlemi başarısız olursa hata döndür.
    if (*birimler == NULL)
    {
        printf("Bellek yeniden tahsis edilemedi.\n");
        exit(1);
    }
    // Parametre olarak verilen Birimler dizisine verilen birimi ekle.
    (*birimler)[toplamBirimSayisi] = birim;
    // Toplam birim sayısını arttır.
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
void birimBilgiYazdir(Birim birim)
{
    printf("-------------------------------\n");
    printf("\t----Birim Bilgisi----\n");
    printf("-------------------------------\n");
    printf("Birim Adi: %s\n", birim.birimAdi);
    printf("Birim Kodu: %d\n", birim.birimKodu);
    printf("Birimin Calisanlarinin Bilgileri:\n");
    for (int i = 0; i < birim.calisanSayisi; i++)
    {
        calisanBilgiYazdir(*(birim.birimCalisanlar[i]));
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
        birimBilgiYazdir(*birimler[i]);
    }
}

/*
    7. Parametre olarak aldığı birimin çalışanlarının maaş ortalamasını
hesaplayan bir fonksiyon yazınız.
*/
float birimOrtalamaMaas(Birim birim)
{
    // Birimdeki maaşların toplamının tutulacağı değişken.
    float maasToplam = 0;
    for (size_t i = 0; i < birim.calisanSayisi; i++)
    {
        // Birim içerisindeki her bir çalışanın maaşını toplam maaşa ekle.
        maasToplam += birim.birimCalisanlar[i]->maas;
    }
    // Birimdeki maaşların toplamı / birimdeki çalışan sayısı
    float ortalamaMaas = maasToplam / birim.calisanSayisi;
    return ortalamaMaas;
}

/*
    8. Parametre olarak aldığı birimde ortalama maaş üzerinde maaş alan
çalışanları listeleyen bir fonksiyon.
*/
void birimOrtalamaUstuMaas(Birim birim)
{
    printf("-------------------------------\n");
    printf("\t----Ort Ustu Maaslar----\n");
    printf("\t----Birim: %d----\n", birim.birimKodu);
    printf("  Birimin Ort Maasi: %.2f\n", birimOrtalamaMaas(birim));
    printf("-------------------------------\n");
    // Ortalama maaşı yazdığımız fonksiyondan bul.
    float ortalamaMaas = birimOrtalamaMaas(birim);
    for (size_t i = 0; i < birim.calisanSayisi; i++)
    {
        // Eğer i. çalışanın maaşı ortalama maaştan yüksekse o çalışanın bilgisini yazdır.
        if (birim.birimCalisanlar[i]->maas > ortalamaMaas)
        {
            calisanBilgiYazdir(*(birim.birimCalisanlar[i]));
            printf("-------------------------------\n");
        }
    }
}

/*
    9. Her birimin ayrı ayrı en yüksek maaş alan çalışanını yazdıran fonksiyon.
*/
void birimlerEnYuksekMaas(Birim **birimler)
{
    printf("-------------------------------\n");
    printf("\t----En Yuksek Maaslar----\n");
    printf("-------------------------------\n");

    for (size_t i = 0; i < toplamBirimSayisi; i++) {
        printf("Birim Adi: %s\n", birimler[i]->birimAdi);
        printf("Birim Kodu: %d\n", birimler[i]->birimKodu);
        printf("En Yuksek Maas Alan Calisan(lar):\n");
        printf("-------------------------------\n");

        // En yüksek maaşı bul
        float enYuksekMaas = 0;
        for (size_t j = 0; j < birimler[i]->calisanSayisi; j++) {
            if (birimler[i]->birimCalisanlar[j]->maas > enYuksekMaas) {
                enYuksekMaas = birimler[i]->birimCalisanlar[j]->maas;
            }
        }

        // En yüksek maaşa sahip çalışan(lar)ı yazdır
        for (size_t j = 0; j < birimler[i]->calisanSayisi; j++) {
            if (birimler[i]->birimCalisanlar[j]->maas == enYuksekMaas) {
                calisanBilgiYazdir(*(birimler[i]->birimCalisanlar[j]));
            }
        }
        printf("-------------------------------\n");
    }
}

/*
    10. Parametre olarak bir maaş değeri alıp, 10 yıldan fazla çalışanlar bu
maaştan az alıyor ise maaşlarını parametre olarak verilen maaşa eşitleyen
fonksiyon.
*/
void yeniMaasAyarla(float yeniMaas, Calisan **calisanlar)
{
    // Yıl bilgisi.
    int yil = 2024;
    // Tüm çalışanları gez.
    for (size_t i = 0; i < toplamCalisanSayisi; i++) {
        // Eğer i. çalışan 10 yıldan fazla çalışıyor ve maaşı da yeni maaştan az ise maaşını güncelle.
        if (yil - calisanlar[i]->girisYili > 10 && calisanlar[i]->maas < yeniMaas) {
            calisanlar[i]->maas = yeniMaas;
        }
    }
}

/*
    11. Tüm Birim ve Calisan bilgilerini bir dosyaya yazan bir fonksiyon.
*/
void dosyayaYaz(const char *calisanlarDosyaAdi, const char *birimlerDosyaAdi, Calisan **calisanlar, Birim **birimler) {
    // Dosya yazma fonksiyonunun başladığını bildir.
    printf("-------------------------------\n");
    printf("Dosyaya yazma islemi baslatiliyor...\n");

    // Dosyaların işaretçileri (pointer).
    FILE *calisanlarDosya = fopen(calisanlarDosyaAdi, "w");
    FILE *birimlerDosya = fopen(birimlerDosyaAdi, "w");

    // Eğer dosyalar açılamazsa hata döndür.
    if (calisanlarDosya == NULL || birimlerDosya == NULL) {
        perror("Dosyalar Acilamadi");
        return;
    }

    // Bütün çalışanları dosyaya yazmak için gerekli olan döngü.
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

    // Yazma işlemi bittikten sonra dosyayı kapat.
    fclose(calisanlarDosya);

    // Bütün birimleri dosyaya yazmak için gerekli olan döngü.
    for (int i = 0; i < toplamBirimSayisi; i++) {
        if (birimler[i] != NULL) {
            fprintf(birimlerDosya, "%s;%d;\n", birimler[i]->birimAdi, birimler[i]->birimKodu);
        }
    }

    // Yazma işlemi bittikten sonra dosyayı kapat.
    fclose(birimlerDosya);

    // Bilgilerin başarıyla yazıldığı bilgisini bildir.
    printf("Bilgiler basariyle dosyaya yazildi!\n");
    printf("-------------------------------\n");
}

/*
    12. Tüm Birim ve Calisan bilgilerini dosyadan diziye aktaran bir fonksiyon.
*/
void dosyadanOku(const char *calisanlarDosyaAdi, const char *birimlerDosyaAdi, Calisan ***calisanlar, Birim ***birimler) {
    // Dosyadan okuma işleminin başladığı bilgisini göster.
    printf("-------------------------------\n");
    printf("Dosyadan okuma islemi başlatiliyor...\n");

    // Dosyaların işaretçileri (pointer).
    FILE *calisanlarDosya = fopen(calisanlarDosyaAdi, "r");
    FILE *birimlerDosya = fopen(birimlerDosyaAdi, "r");

    // Eğer dosyalar açılmazsa hata döndür.
    if (calisanlarDosya == NULL || birimlerDosya == NULL) {
        perror("Dosyalar Acilamadi");
        return;
    }

    // Satırı saklamak için değişken.
    char satir[256];

    // Birimleri dosyadan oku.
    while (fgets(satir, sizeof(satir), birimlerDosya)) {
        char birimAdi[256];
        int birimKodu;
        // sscanf ile ayrıştır.
        if (sscanf(satir, "%[^;];%d;", birimAdi, &birimKodu) == 2) {
            // Ayrıştırma işlemi başarılı olduğunda yeni bir birim oluştur ve birimler dizisine ekle.
            Birim *yeniBirim = birimOlustur(birimAdi, birimKodu);
            birimiDiziyeEkle(yeniBirim, birimler);
        }
    }

    // Okuma işlemi bittikten sonra dosyayı kapat
    fclose(birimlerDosya);

    // Çalışanları dosyadan oku.
    while (fgets(satir, sizeof(satir), calisanlarDosya)) {
        char calisanAdi[256];
        char calisanSoyadi[256];
        int birimKodu;
        float maas;
        int girisYili;

        // sscanf ile ayrıştır
        if (sscanf(satir, "%[^;];%[^;];%d;%f;%d;", calisanAdi, calisanSoyadi, &birimKodu, &maas, &girisYili) == 5) {
            // Ayrıştırma işlemi başarılı olduğunda yeni bir çalışan oluştur ve çalışanlar dizisine ekle.
            Calisan *yeniCalisan = calisanOlustur(calisanAdi, calisanSoyadi, birimKodu, maas, girisYili);
            calisaniDiziyeEkle(yeniCalisan, calisanlar);
        }
    }

    // Okuma işlemi tamamlandıktan sonra dosyayı kapat.
    fclose(calisanlarDosya);

    // Çalışanları birimlerine ekle.
    for (int i = 0; i < toplamBirimSayisi; i++) {
        for (int j = 0; j < toplamCalisanSayisi; j++) {
            // Eğer i. birim ile j. çalışanın birim kodu eşleşiyorsa çalışanı birimine ekle.
            if ((*birimler)[i]->birimKodu == (*calisanlar)[j]->birimKodu) {
                birimeCalisanEkle((*calisanlar)[j], (*birimler)[i]);
            }
        }
    }

    // Dosyadan okuma işleminin başarılı olduğunu bildir.
    printf("Dosyadan okuma islemi basarili!\n");
    printf("-------------------------------\n");
}

/*
    Birimleri, Çalışanları ve Birimlerin Çalışanlarını serbest bırak
*/
void bellekTemizliği(Birim **birimler, Calisan **calisanlar) {
    for (int i = 0; i < toplamBirimSayisi; i++) {
        free(birimler[i]->birimAdi); // Birim adı belleğini serbest bırak
        free(birimler[i]->birimCalisanlar); // Birim çalışanlarını serbest bırak
        free(birimler[i]);           // Birimler dizisindeki birim nesnesini serbest bırak
    }
    free(birimler); // Birimler dizisini serbest bırak.

    for (int i = 0; i < toplamCalisanSayisi; i++) {
        free(calisanlar[i]->calisanAdi); // Çalışan adı belleğini serbest bırak
        free(calisanlar[i]->calisanSoyadi); // Çalışan soyadı belleğini serbest bırak
        free(calisanlar[i]);            // Çalışanlar dizisindeki çalışan nesnesini serbest bırak
    }
    free(calisanlar); // Çalışanlar dizisini serbest bırak.
}