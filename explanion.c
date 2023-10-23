#include <signal.h>

/*
örnek: 
ABC
A = 65 = 0b01000001 
B = 66 = 0b01000010
C = 67 = 0b01000011
ilk önce A ile başlanır. A 65 olduğu için 8 kere döner.
A = 0b01000001
ilk önce 128 ile karşılaştırma yapılır en soldaki bit 1 ise sigusr1 gönderilir.
server tarafında alınan sinyal sigusr1 ise 1 ise letter değişkenine power 128 olur
*/





//image.png




/*
her bir karakterin binary karşılığı 8 bit olduğu için 8 kere döndürüyoruz.
str[i] & power ile str[i] nin binary karşılığının power ile and işlemi yapıyoruz.
eğer sonuç 0 ise 0, 1 ise 1 oluyor. 0 ise SIGUSR2, 1 ise SIGUSR1 gönderiyoruz.
power 2 nin 8. kuvvetinden başlıyor ve her döngüde 2 nin bir eksiğine bölünüyor.
yani 128, 64, 32, 16, 8, 4, 2, 1 şeklinde.
örnek:{
str = "A"
str[0] = 'A' = 65 = 0b01000001
power = 128 = 0b10000000
power = 64 = 0b01000000
power = 32 = 0b00100000
power = 16 = 0b00010000
power = 8 = 0b00001000
power = 4 = 0b00000100
power = 2 = 0b00000010
power = 1 = 0b00000001
str[0] & power = 0b01000001 & 0b10000000 = 0b00000000 = 0
kill(pid, SIGUSR2);

bu şekilde her bir bitin ne olduğu açığa çıkar ve bu açığa çıkan bitleri de 
kill fonksiyonu ile göndeririz. server üzerinde de yeniden bit to byte yapılır.
}
┌─────────────┬──────────────┬───────────────┐
│ str[i]      │ power        │ str[i] & power│
├─────────────┼──────────────┼───────────────┤
│   0b00000001│    0b10000000│    0b00000000 │
│   0b00000010│    0b10000000│    0b00000000 │
│   0b00000100│    0b10000000│    0b00000000 │
│   0b00001000│    0b10000000│    0b00000000 │
│   0b00010000│    0b10000000│    0b00000000 │
│   0b00100000│    0b10000000│    0b00000000 │
│   0b01000000│    0b10000000│    0b00000000 │
│   0b10000000│    0b10000000│    0b10000000 │
└────────────┴──────────────┴─────────────── ┘
up area is the cliebt side


down is the server side
/*
`letter` değişkeni her bit için toplanır. İşte bir örnek:

Varsayalım ki `client` tarafından gönderilen 8 bitlik binary bir karakter, "01000001" yani 'A' karakteridir.

1. İşlem: 
   - Başlangıçta `letter = 0`, `power = 128`.
   - İlk bit (en sol bit) 0 olduğu için `signum` değeri `SIGUSR2` olur.
   - Çünkü `signum` değeri `SIGUSR2`, `letter` değeri değişmez (0).
   - `power` değeri 64 olur (`power /= 2`).

2. İşlem: 
   - İkinci bit 1 olduğu için `signum` değeri `SIGUSR1` olur.
   - `letter` değeri 64 ile toplanır (`letter += power`), yani `letter = 64`.
   - `power` değeri 32 olur (`power /= 2`).

3. İşlem: 
   - Üçüncü bit 0 olduğu için `signum` değeri `SIGUSR2` olur.
   - `letter` değeri değişmez (64).
   - `power` değeri 16 olur (`power /= 2`).

Bu işlem devam eder ve tüm 8 bit işlendikten sonra `power` değeri 0 olur ve tam bir karakter (burada 'A') elde edilir. `letter` değişkeni, her bit için sırasıyla işlem yaparak karakterin değerini toplar.
*/
// client 1 karakter için 8 döngü boyunca 1 ve 0 gönderiyor. sonrasında gönderilen bu değerler serverda handler fonksiyonuna gidiyor. 
//bu fonksiyona gelen 0 ve 1 değerleri letter denilen değişkende toplanarak ortaya bitlerden toplanan bir karakter ortaya çıkıyor
//tüm bitler bittikten sonra power 0 olur. fakat letter 0 olmadığı için ilk karakteri yazdırır tekrardan döngü devam eder. 
//son seviyede sinyaller hep 0 olacağı için letter de 0 olur ve fonskiyondan çıkılarak program sonlanır.



*/