
#include <stdio.h>
#include <stdlib.h>
#include "Proje1.h"

int main(int argc, char const *argv[])
{
    // Command Line Parameters.
    if (argc < 3) {
        printf("%s <calisanlar_dosyasi> <birimler_dosyasi>\n", argv[0]);
        return 1;
    }

    // Çalışanlar ve Birimler dosyasını Command Line Parameter olarak al.
    const char *calisanlarDosyaAdi = argv[1];
    const char *birimlerDosyaAdi = argv[2];

    // Dinamik Birimler ve Çalışanlar dizileri.
    Birim **birimler = NULL;
    Calisan **calisanlar = NULL;

    // Dosyadan birimleri ve çalışanları okuma işlemi.
    dosyadanOku(calisanlarDosyaAdi, birimlerDosyaAdi, &calisanlar, &birimler);

    // Tüm birimlerin bilgilerini (Birim Adı, Birim Kodu ve Birimin Çalışanlarını) yazdır.
    birimlerBilgiYazdir(birimler);

    // Birimlerdeki en yüksek maaşları yazdır.
    birimlerEnYuksekMaas(birimler);

    // 1001 Birim kodlu birimin ortalama maaşını yazdır.
    printf("-------------------------------\n");
    printf("%d Biriminin ortalama maaşı: %.2f\n", birimler[0]->birimKodu, birimOrtalamaMaas(*birimler[0]));
    printf("-------------------------------\n");

    // 10 yıldan fazla süredir çalışan ve yeni maaş miktarından az maaş alan çalışanların maaşlarını güncelle.
    // Ahmet Yılmaz isimli çalışan 10 seneden fazla çalışmakta ve aldığı maaş yeni maaştan daha düşük.
    float yeniMaas = 30000;
    printf("-------------------------------\n");
    printf("%2.f değerinden daha az maaş alan ve 10 yıldan fazla çalışanların maaşını güncelleme fonksiyonu çalıştırıldı.\n", yeniMaas);
    printf("-------------------------------\n");
    yeniMaasAyarla(yeniMaas, calisanlar);

    // Ahmet Yılmaz isimli çalışanın maaşı güncellendikten sonraki birimin ortalama maaşı.
    printf("-------------------------------\n");
    printf("%d Biriminin ortalama maaşı: %.2f\n", birimler[0]->birimKodu, birimOrtalamaMaas(*birimler[0]));
    printf("-------------------------------\n");

    // Maaş güncellemesinden sonra birimlerin bilgilerini yazdır.
    birimlerBilgiYazdir(birimler);

    // Maaş güncellemesinden sonra birimlerin en yüksek maaşlı çalışanlarını yazdır.
    birimlerEnYuksekMaas(birimler);

    // Her birim için ortalama üstü maaş alan çalışanları yazdır.
    printf("-------------------------------\n");
    printf("%d Biriminin ortalama maaşı üzerinde maaş alan çalışanları yazdırılıyor...\n", birimler[1]->birimKodu);
    printf("-------------------------------\n");
    birimOrtalamaUstuMaas(*birimler[1]);
    // En son haliyle çalışanları ve birimleri dosyaya yaz.
    dosyayaYaz(calisanlarDosyaAdi, birimlerDosyaAdi, calisanlar, birimler);

    // İşlemler için ayrılan bellekleri temizle.
    bellekTemizliği(birimler, calisanlar);
    return 0;
}