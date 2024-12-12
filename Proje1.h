/*
 * @file Proje1.h
 * @description Programınızın açıklaması ne yaptığına dair.
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
    Calisan *birimCalisanlar;
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
void birimCalisanEkle(Calisan *calisan, Birim *birim);

/*
    3. Oluşturulan yeni struct yapılarını diziye ekleyen fonksiyon.
*/

/*
    4. Parametre olarak Calisan türünden değişken alıp bilgilerini yazdıran bir
fonksiyon.
*/
void calisanBilgiYazdir(Calisan calisan);

/*
    5. Parametre olarak Birim türünden değişken alıp bilgilerini yazdıran bir
fonksiyon.
*/
void birimBilgiYazdir(Birim *birim);

/*
    6. Parametre olarak Birim türünden dinamik bir dizi alıp bilgilerini yazdıran
bir fonksiyon.
*/
void birimlerBilgiYazdir(Birim *birimler);

/*
    7. Parametre olarak aldığı birimin çalışanlarının maaş ortalamasını
hesaplayan bir fonksiyon yazınız.
*/
float maasOrtalamaHesapla(Birim *birim);

/*
    8. Parametre olarak aldığı birimde ortalama maaş üzerinde maaş alan
çalışanları listeleyen bir fonksiyon.
*/
void ortalamaUstuMaas(Birim *birim);

/*
    9. Her birimin ayrı ayrı en yüksek maaş alan çalışanını yazdıran fonksiyon.
*/
void enYuksekMaaslar(Birim **birimler);

/*
    10. Parametre olarak bir maaş değeri alıp, 10 yıldan fazla çalışanlar bu
maaştan az alıyor ise maaşlarını parametre olarak verilen maaşa eşitleyen
fonksiyon.
*/
void maasAyarla(Calisan *calisan, Birim *birim, float yeniMaas);

/*
    11. Tüm Birim ve Calisan bilgilerini bir dosyaya yazan bir fonksiyon.
*/

/*
    12. Tüm Birim ve Calisan bilgilerini dosyadan diziye aktaran bir fonksiyon.
*/