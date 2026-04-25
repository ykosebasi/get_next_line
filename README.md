*This project has been created as part of the 42 curriculum by ykosebas.*

## DESCRIPTION
get_next_line projesi, bir dosya tanımlayıcısından (fd) okunan metni her çağrıldığında satır satır döndüren bir fonksiyonun uygulanmasıdır.
Bu projenin amacı, C dilinde statik değişkenlerin (static variables) çalışma mantığını anlamak, dinamik bellek yönetimini hatasız yürütmek ve verimli buffer manipülasyonu yapabilmektir.

✨ FEATURES

✔ Bu implementasyon aşağıdaki özellikleri destekler:

✔ Her çağrıda tek bir satır (\n dahil) döndürür.

✔ Farklı BUFFER_SIZE değerleri ile sorunsuz çalışır.

✔ Dosya sonuna (EOF) ulaşıldığında veya hata oluştuğunda NULL döndürür.

✔ Bellek sızıntısı (leak) içermeyen bir yapı sağlar.

## INSTRUCTIONS
Projeyi derlemek için dosya boyutu (BUFFER_SIZE) belirtilmelidir.

⚙️ COMPILATION

`cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 *.c` komutu ile derlenir.

▶️ EXECUTION

`valgrind ./a.out`

 🧩 ALGORITHM OVERVIEW

🔹 `Static Buffer System`
✔ Veri static char *saved içinde tutulur
✔ Fonksiyon çağrıları arasında state korunur
🔹 `Read Process`
✔ read() ile BUFFER_SIZE kadar veri okunur
✔ saved içine eklenir
🔹 `Line Extraction`
✔ \n bulunana kadar veri biriktirilir
✔ Satır tamamlanınca döndürülür
🔹 `Remaining Data`
✔ Satırdan kalan kısım static değişkende tutulur
✔ Bir sonraki çağrıda devam eder

## RESOURCES
https://www.geeksforgeeks.org/static-variables-in-c/?utm_source=chatgpt.com
https://www.codequoi.com/en/local-global-static-variables-in-c

## AI USAGE
🤖 AI yalnızca öğrenme ve mantık kurgusu aşamalarında destek amaçlı kullanılmıştır.
 🔹Edge case (boş dosya, hatalı fd, büyük buffer) senaryolarının mantıksal analizinde.

## ALGORITHM AND DATA STRUCTURE

Projede Static Variable yapısı kullanılmıştır.
Buffer Okuma: read() fonksiyonu ile BUFFER_SIZE kadar veri okunur ve statik bir string içinde biriktirilir.
Satır Ayrıştırma: Statik değişken içinde \n karakteri aranır. Bulunduğunda, o noktaya kadar olan kısım ayrıştırılıp kullanıcıya döndürülür.
Artık Veri Saklama: Satır döndürüldükten sonra geri kalan veri, bir sonraki fonksiyon çağrısı için statik değişkende saklanmaya devam eder.
Bellek Yönetimi: Okuma bittiğinde veya hata durumunda ayrılan tüm alanlar free edilerek sızıntı önlenir.