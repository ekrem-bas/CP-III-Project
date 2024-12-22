/*
 * @file Proje1.h
 * @description Projede kullanılan fonksiyonların başlıklarını (header) tutan başlık dosyası.
 * @assignment 1. Ödev
 * @date 06.12.2024
 * @author Ekrem Baş | ekrem.bas@stu.fsm.edu.tr
 */

// Çalışan Struct Yapısı
typedef struct
{
    char *calisanAdi;
    char *calisanSoyadi;
    unsigned short int birimKodu;
    float maas;
    int girisYili;
} Calisan;

// Birim Struct Yapısı
typedef struct
{
    char *birimAdi;
    unsigned short int birimKodu;
    Calisan **birimCalisanlar;
    // Her bir birimin kendi çalışan sayısını tutmak için değişken.
    int calisanSayisi;
} Birim;

/*
    1. İlgili değerleri alıp bir Birim struct döndüren bir fonksiyon.
*/
Birim *birimOlustur(char *birimAdi, unsigned short int birimKodu);

/*
    2. İlgili değerleri alıp bir Calisan struct döndüren fonksiyon.
*/
Calisan *calisanOlustur(char *calisanAdi, char *calisanSoyadi, unsigned short int birimKodu, float maas, int girisYili);

/*
    BİRİME BİRER BİRER ÇALIŞAN EKLEME FONKSİYONU
*/
void birimeCalisanEkle(Calisan *calisan, Birim *birim);

/*
    3. Oluşturulan yeni struct yapılarını diziye ekleyen fonksiyon.
*/

void calisaniDiziyeEkle(Calisan *calisan, Calisan ***calisanlar);

void birimiDiziyeEkle(Birim *birim, Birim ***birimler);

/*
    4. Parametre olarak Calisan türünden değişken alıp bilgilerini yazdıran bir
fonksiyon.
*/
void calisanBilgiYazdir(Calisan calisan);

/*
    5. Parametre olarak Birim türünden değişken alıp bilgilerini yazdıran bir
fonksiyon.
*/
void birimBilgiYazdir(Birim birim);

/*
    6. Parametre olarak Birim türünden dinamik bir dizi alıp bilgilerini yazdıran
bir fonksiyon.
*/
void birimlerBilgiYazdir(Birim **birimler);

/*
    7. Parametre olarak aldığı birimin çalışanlarının maaş ortalamasını
hesaplayan bir fonksiyon yazınız.
*/
float birimOrtalamaMaas(Birim birim);

/*
    8. Parametre olarak aldığı birimde ortalama maaş üzerinde maaş alan
çalışanları listeleyen bir fonksiyon.
*/
void birimOrtalamaUstuMaas(Birim birim);

/*
    9. Her birimin ayrı ayrı en yüksek maaş alan çalışanını yazdıran fonksiyon.
*/
void birimlerEnYuksekMaas(Birim **birimler);

/*
    10. Parametre olarak bir maaş değeri alıp, 10 yıldan fazla çalışanlar bu
maaştan az alıyor ise maaşlarını parametre olarak verilen maaşa eşitleyen
fonksiyon.
*/
void yeniMaasAyarla(float yeniMaas, Calisan **calisanlar);

/*
    11. Tüm Birim ve Calisan bilgilerini bir dosyaya yazan bir fonksiyon.
*/
void dosyayaYaz(const char *calisanlarDosyaAdi, const char *birimlerDosyaAdi, Calisan **calisanlar, Birim **birimler);

/*
    12. Tüm Birim ve Calisan bilgilerini dosyadan diziye aktaran bir fonksiyon.
*/
void dosyadanOku(const char *calisanlarDosyaAdi, const char *birimlerDosyaAdi, Calisan ***calisanlar, Birim ***birimler);

/*
    Birimleri, Çalışanları ve Birimlerin Çalışanlarını serbest bırak
*/
void bellekTemizliği(Birim **birimler, Calisan **calisanlar);