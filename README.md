
# Perhitungan Complexity untuk Algoritma CombSort
Comb sort adalah algoritma pengurutan yang relatif sederhana yang awalnya dirancang oleh Włodzimierz Dobosiewicz dan Artur Borowy pada tahun 1980, kemudian ditemukan kembali oleh Stephen Lacey dan Richard Box pada tahun 1991. (Wikipedia). Disini saya akan menghitung time complexity untuk algoritma combsort yaitu best case scenario dan worst case scenario
## Best Case
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
$$U{n}=a\ast \left( \frac{10}{13} \right)^{n}$$ 
dimana ```a``` adalah nilai awal gap yaitu banyak item dari array dan n adalah suku dari barisan bilangan tersebut. untuk mendapatkan total dari berapa kali fungsi while tersebut berulang adalah dengan mengubah ```gap > 1``` menjadi persamaan rumus geometri tadi seperti ini $a\ast \left( \frac{10}{13} \right)^{n} \gt 1$ . \
disini kita akan merubah terlebih dahulu beberapa variable
```
we'll change variable a (The Equation Form) => n (Array Size)
```
```
we'll change variable n (The Equation Form) => p (how much the while will repeat)
```
menjadi: 
$$n\ast \left( \frac{10}{13} \right)^{p} \gt 1$$
lalu kita memindahkan n ke ruas kanan <br />
$$\left( \frac{10}{13} \right)^{p} \gt \frac{1}{n}$$ 
setelah itu kita akan mendapatkan nilai p dengan menggunakan fungsi logaritma
$$p\gt \log_{\frac{10}{13}}{\left( \frac{1}{n} \right) }$$ 
kita dapat memecah fungsi logaritma tersebut menjadi
$$p\gt \log_{\frac{10}{13}}{\left( 1 \right)} - \log_{\frac{10}{13}}{\left( n \right) }$$ 
dimana ```log(1)``` pasti memiliki hasil 0. Maka, <br />
$$p\gt 0 - \log_{\frac{10}{13}}{\left( n\right) }$$ 
atau dapat dikatakan $p\simeq \log_{\frac{10}{13}}{\left( n\right) }$ secara complexity tidak ada negatif.
Dari sini kita dapat bahwa dalam best case fungsi while tersebut akan berulang sebanyak $\log_{\frac{10}{13}}{\left( n\right) } + 1$ kali. dan semua operasi didalamnya akan berulang sebanyak $\log_{\frac{10}{13}}{\left( n\right) }$ kali.
<br />
lalu kita akan menghitung kompleksitas dari for pada best case ```for (int i = 0; i < (n - gap); i++)```. \
```i``` akan berulang sampai ```i < ( n - gap )``` yang dimana $i\lt n-n\left( \frac{10}{13} \right)^{p}$ yang mana sekali lagi ```p``` adalah iterasi keberapa while tersebut. maka time complexity dari for tersebut adalah
$$n-n\left( \frac{10}{13} \right)^{p} + 1$$
sedangkan for tersebut berada didalam while maka for tersebut akan di operasikan sebanyak while itu berulang. maka kita akan mengalikan time complexity dari for dengan while
$$\left( n-n\left( \frac{10}{13} \right)^{p}\right) * \log_{\frac{10}{13}}{\left( n\right) }$$
$$n  \log_{\frac{10}{13}}{\left( n\right) }-n \log_{\frac{10}{13}}{\left( n\right) \left( \frac{10}{13} \right)^{p}}$$
$$n  \log_{\frac{10}{13}}{\left( n\right) }-\left( 1-\left( \frac{10}{13} \right)^{p}\right)$$
jadi total time complexity secara sederhana akan didapat
$\omega(n  \log_{\frac{10}{13}}{\left( n\right) }-\left( 1-\left( \frac{10}{13} \right)^{p}\right) + \log_{\frac{10}{13}}{\left( n\right)} )$ atau dapat disederhanakan lagi menjadi 
$$\omega(n  \log{\left( n\right) } )$$
## Worst Case
Pada worst case memiliki asumsi yang cukup sederhana dan simple yaitu dengan asumsi sebuah array yang initial value kita tidak perlu tahu
```cpp
arr = [,,,,,,,,,]; //Apa aja bole
```
Lalu akan di operasikan fungsi ```while(gap > 1 || swapped == true)``` sampai kondisi ```(gap > 1)``` menjadi false atau sama seperti base case tadi. disaat ```gap``` sudah memiliki value satu tersebut di asumsikan array akan menjadi case yang paling buruknya
```cpp
arr = [9,8,7,6,5,4,3,2,1,0];
```
untuk disclaimer, hal ini sangat tidak mungkin untuk terjadi, karena pada fungsi sort tersebut akan menukar posisi antara angka yang lebih besar dengan angka yang lebih kecil. Tetapi asumsi ini paling mudah untuk di pahami. \
dari sini, karena ```gap = 1``` dan ```swapped``` akan selalu bernilai true, algoritma sort ini akan sama persis dengan BubbleSort. Yang dimana algoritma bubble sort memiliki best case $\omega(n)$ worst case $O(n^{2})$. Karena pada kenyataannya worst case tambahan untuk fungsi while CombSort tidak mungkin berada di titik yang sama atau pastinya lebih rendah dibandingankan dengan worst case BubbleSort tetapi karena kita mencari worst case maka itu harus lebih tinggi dari pada best case $O(n)$ nya BubbleSort. maka,
$$\omega_{BubbleSort}(n) \lt O_{TambahanUntukWhile}(??) \lt O_{BubbleSort}(n^{2})$$
dan time complexity tambahan untuk mencapat worst case scenario dari CombSort dapat diasumsiin sebagai $an+k$, dimana a dan k hanya variable/konstanta tak tentu. maka secara keseluruhan time complexity dari fungsi ```while``` akan menjadi 
$$\log_{\frac{10}{13}}{\left( n\right) } + an+k$$
lalu beralih pada fungsi ```for``` yang berada dalam ```while```. 
```
for (int i = 0; i < (n - gap); i++)
```
best scenario akan tetap berjalan sehingga for tersebut pasti memiliki $n-n\left( \frac{10}{13} \right)^{p} + 1$. tetapi selanjutnya pada sesi worst case dimana while akan tetap berlanjut karena ```swapped``` akan selalu bernilai true dan ```gap``` akan bernilai 1. maka fungsi ```for``` tersebut akan berulang sebanyak kondisinya, jika disini ```gap = 1``` maka kondisinya adalah ```i < (n-1)``` dan memiliki time complexity tambahan sebesar ```n```. 
lalu untuk mendapatkan worst case kita akan kembali mengalikan time complexity dari while dan for
$$\left(  an+k\right) * n$$
$$an^{2} +nk$$
maka total dari worst case pada CombSort adalah jumlah dari best case dan time complexity tambahan
$$O(\omega(n  \log{\left( n\right) } )+(an^{2} +nk))$$
$$O(an^{2}+nk+\log{\left( n\right)})$$
dan jika kita mengambil orde terbesarnya maka time complexity dari worst case scenario CombSort adalah
$$O(n^{2})$$

