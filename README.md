# Perhitungan Complexity untuk Algoritma CombSort
Comb sort adalah algoritma pengurutan yang relatif sederhana yang awalnya dirancang oleh Włodzimierz Dobosiewicz dan Artur Borowy pada tahun 1980, kemudian ditemukan kembali oleh Stephen Lacey dan Richard Box pada tahun 1991. (Wikipedia). Disini saya akan menghitung time complexity untuk algoritma combsort yaitu best case scenario dan worst case scenario
### Best Case
Pada kasus best case asumsi yang digunakan sangat mudah yaitu jika semua item dari sebuah array sudah terurut 100%.
```cpp
arr = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9];
```
https://github.com/zemetia/combsort-complexity/blob/0be022d73c53ba1c4c52a7f9ee2ceacd48d2355d/combsort.cpp#L17-L45
pada fungsi ini terdapat while yang merupakan inti dari algoritma sort ini ```while (gap > 1 || swapped == true)``` \
karena semua nya sudah terurut maka dapat dikatakan bahwa ```swapped``` akan selalu bernilai False karena tidak ada nilai yang di tukar \
Sehingga banyaknya perulangan hanya bergantung pada kondisi ```gap > 1``` saja, dan nilai gap berubah bergantung pada fungsi ```gap = updateGap(gap);```
<br />
https://github.com/zemetia/combsort-complexity/blob/0be022d73c53ba1c4c52a7f9ee2ceacd48d2355d/combsort.cpp#L6-L15
```gap``` memiliki inital value yaitu ```n``` dimana ```n``` adalah panjang dari array atau banyak item pada array. Pada fungsi ```updateGap(gap)``` terdapat ```gap = (gap * 10) / 13``` atau dapat dipersimple menjadi ```gap *= 1/1.3``` dan pada akhirnya akan dibatasi ```if (gap < 1) return 1;``` dimana jika gap lebih kecil dari 1 maka fungsi akan return angka 1. simplenya gap yang paling kecil adalah 1. <br /> <br />
nilai gap akan berubah secara geometri decreasing seiring fungsi tersebut dipanggil. Jika fungsi tersebut diubah secara linear maka akan menjadi
$U{n}=a\ast \left( \frac{10}{13} \right)^{n}$ dimana ```a``` adalah nilai awal gap yaitu banyak item dari array dan n adalah suku dari barisan bilangan tersebut. \
untuk mendapatkan total dari berapa kali fungsi while tersebut berulang adalah dengan mengubah ```gap > 1``` menjadi persamaan rumus geometri tadi seperti ini $a\ast \left( \frac{10}{13} \right)^{n} \gt 1$ . \
disini kita akan merubah terlebih dahulu beberapa variable\
```
we'll change variable a (The Equation Form) => n (Array Size)
```
```
we'll change variable n (The Equation Form) => p (how much the while will repeat)
```
menjadi $n\ast \left( \frac{10}{13} \right)^{p} \gt 1$ lalu kita memindahkan n ke ruas kanan <br />
$\left( \frac{10}{13} \right)^{p} \gt \frac{1}{n}$ setelah itu kita akan mendapatkan nilai p dengan menggunakan fungsi logaritma <br />
$p\gt \log_{\frac{10}{13}}{\left( \frac{1}{n} \right) }$ kita dapat memecah fungsi logaritma tersebut menjadi <br />
$p\gt \log_{\frac{10}{13}}{\left( \frac{1}{n} \right) - \log_{\frac{10}{13}}{\left( \frac{1}{n} \right) }$ dimana ```log(1)``` pasti memiliki hasil 0. Maka, <br />
$p\gt 0 - \log_{\frac{10}{13}}{\left( n\right) }$ atau dapat dikatakan $p\simeq \log_{\frac{10}{13}}{\left( n\right) }$ secara complexity tidak ada negatif 
