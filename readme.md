# ☆ PROGRAM CEK PASSWORD ☆

## ▶️Studi Kasus
    Di sebuah universitas, sistem keamanan sangat penting untuk melindungi informasi pribadi mahasiswa dari
    akses yang tidak sah. Setiap mahasiswa diwajibkan untuk membuat kata sandi yang kuat saat mendaftar
    akun di sistem informasi kampus. Namun, banyak mahasiswa masih bingung tentang cara membuat kata sandi
    yang benar-benar aman dan sesuai. Sebagai seorang mahasiswa baru jurusan Ilmu Komputer, anda diminta
    membuat sebuah program yang dapat memeriksa apakah kata sandi yang dibuat mahasiswa memenuhi standar
    keamanan yang ada atau tidak.
        
        Kata sandi yang memenuhi standar harus mencakup syarat sebagai berikut:
    • Kata sandi minimal memiliki 8 karakter
    • Mengandung huruf besar dan kecil
    • Mengandung angka
    • Mengandung simbol khusus seperti @*%#
    
    Program ini akan membaca kata sandi yang dimasukkan dan kemudian memeriksa semua kriteria yang ada.
    Jika semua persyaratan terpenuhi, program akan menampilkan pesan yang menyatakan bahwa kata sandi
    "Aman Digunakan." Namun, jika ada persyaratan yang tidak terpenuhi, program akan memberikan penjelasan
    mengenai informasi yang hilang, seperti memunculkan kalimat "Kata Sandi Tidak Memiliki Angka" atau
    “Kata Sandi Tidak Memiliki Simbol Khusus”.

Dari studi kasus diatas, terciptalah sebuah program. Program ini dibuat sebagai salah satu solusi untuk memastikan setiap mahasiswa membuat kata sandi yang kuat saat mendaftar ke sistem informasi akademik. Karena saat ini masih banyak mahasiswa yang masih kesulitan dalam membuat password yang aman, sehingga terciptalah program ini untuk membantu mengecek apakah password yang di input memenui aturan keamanan atau tidak.

Program ini dibuat untuk mengecek validitas dan tingkat kekuatan password berdasarkan jenis karakter yang digunakan, panjang password, serta beberapa pola tertentu.
Program akan menilai password dalam empat level yaitu, Lemah (weak), Medium, Kuat (strong), Sangat kuat (very strong).

Program juga memberikan penjelasan kenapa password lemah, saran agar password lebih aman serta rekomendasi password yang lebih kuat maupun fitur cek password berulang kali.


## ✨Fitur Utama
    Fitur Utama dari program ini antara lain
    - Mengecek apakah password valid (minimal 8 karakter).
    - Mengecek apakah password mengandung:
        > Huruf kecil
        > Huruf besar
        > Angka
        > Karakter spesial (@, #, %, *, dll)
    - Menmberikan level kekuatan password:
        > Lemah
        > Medium
        > Kuat
        > Sangat Kuat
    - Deteksi pola:
        > Password abstrak (kombinasi tertentu dari huruf non-vokal)
        > Password berakhiran "123" (disebut tuwaga)
    - Memberikan saran peningkatan keamanan
    - Memberikan saran otomatis untuk memperbaiki password.
    - Memberikan rekomendasi password dengan tambahan karakter acak.

## ⚒️Cara Kerja

1. Cara Kerja Program Secara Umum

        Program akan melakukan beberapa langkah:

        1. User memasukkan password.
        2. Program membaca isi password dan menghitung:
            a. Panjang password
            b. jumlah angka
            c. jumlah huruf kecil
            d. jumlah huruf besar
            e. jumlah karakter spesial
        3. Program melakukan pengecekan khusus:
            a. apakah password mengandung pola dua huruf non-vokal berbeda yang tidak bernilai umum (abstrak)
            b. apakah password berakhir dengan "123" (tuwaga)
        4. Program menentukan kategori password serta memberitahukan user mengapa password yang di input berkategori tersebut.
        (Level password anda adalah: ... )
            a. Valid 
            b. Invalid : Password yang anda masukkan invalid!
            c. Weak (Lemah) : Password yang anda buat terlalu mudah!
            d. Medium (Sedang) : password yang anda buat terlalu basic
            e. Strong (Kuat)
            f. Very Strong (Sangat Kuat)
        5. Jika password masih terlalu lemah atau invalid,
        program meminta user memasukkan ulang password.
        6. Program memberikan:
            a. Hasil dan saran
            b. saran perbaikan password
            c. rekomendasi password yang lebih kuat
            d. Dapat memilih untuk cek password lagi.

2. Cara Program Mengecek Jenis Karakter

       a. Program membuat array:
            hash[0] = jumlah angka
            hash[1] = jumlah huruf kecil
            hash[2] = jumlah huruf besar
            hash[3] = jumlah simbol


       b. Jika password berisi:
            huruf kecil → hash[1] bertambah
            huruf besar → hash[2] bertambah
            angka → hash[0] bertambah
            simbol → hash[3] bertambah

3. Cara Kerja Deteksi "abstrak"

        Password dianggap abstrak jika:
        a. 2 huruf berturut-turut bukan vokal
        b. bukan angka
        c. bukan f/F atau v/V
        d. tidak sama
        e. pola seperti: xz, rq, kl, nj, dll

        Contoh abstrak:
        "xqzz", "rklpt", "bxng"

 4. Cara Kerja Deteksi "tuwaga"

        Jika password berakhir dengan “123” maka dianggap tuwaga = true.

        Contoh:
        "abcd123" → true
        "pass4123" → true

        Ini mempengaruhi aturan ke-Strong.
    
 5. Cara Kerja Tampilan Memberitahukan User Kriteria Passwordnya
 
      (Level password anda adalah: ... )
             a. Valid 
             b. Invalid : Password yang anda masukkan invalid!
             c. Weak (Lemah) : Password yang anda buat terlalu mudah!
             d. Medium (Sedang) : password yang anda buat terlalu basic
             e. Strong (Kuat)
             f. Very Strong (Sangat Kuat)
    
     Jika password lemah, medium, atau kuat akan menampilkan syarat karakter apa saja yang perlu ditambahkan ulang. Seperti :
         - Password anda terlalu mudah, tambahkan angka agar lebih kuat
         - Tambahkan huruf kecil untuk variasi karakter.
         - Tambahkan huruf besar agar password lebih sulit ditebak.
         - Tambahkan karakter spesial seperti !@#$% untuk meningkatkan keamanan.

 6. Akhir Program
      Ketika password sudah valid dan tidak lemah, user akan diberikan pilihan untuk kembali mencoba cek password lain atau tidak.
         "Apakah anda ingin mengecek password lain? 1. Ya 2. Tidak : "
      Jika user memilih 1, maka program akan dijalankan kembali.
      Jika user memilih 2, maka program selesai

## ♻️Alur Logika IF–ELSE 

A. Mengecek apakah password valid

    if (n >= 8) valid = true;
    Password harus minimal 8 karakter agar valid.

B. Mengecek apakah password lemah

    Weak berarti password terlalu sederhana.
    Password dianggap tidak Weak jika:
        - memiliki karakter variatif
        - tidak hanya huruf kecil
        - tidak kombinasi lemah tertentu saat abstrak/tuwaga aktif

    Jika syarat lain tidak terpenuhi, password dianggap Weak.

C. Menentukan Medium

    Password masuk kategori Medium ketika:
    - Panjang ≥ 8 (valid)
    - Mengandung minimal 2 jenis karakter yang berbeda:

    Contoh kombinasi:
        1. angka + huruf kecil
        2. angka + huruf besar
        3. angka + simbol
        4. huruf kecil + huruf besar
        5. huruf kecil + simbol
        6. huruf besar + simbol

    Contoh Medium:
        "pass1234"
        "HELLO12"
        "abc#xyz0"

D. Menentukan Strong

    Password masuk kategori Strong jika:
        1. Valid (≥ 8 karakter)
        2. Memiliki minimal 3 jenis karakter
        3. Mengandung huruf besar
        4. Jika password berakhir dengan "123" (tuwaga), maka harus ada huruf besar + angka

    Contoh Strong:
        “Abcde#12”
        “TesT1234”
        “aB1!!!!”

E. Menentukan Very Strong

    Password dianggap Very Strong bila:
        a. Panjang minimal 12
        b. Mengandung semua jenis karakter (angka, huruf kecil, huruf besar, simbol)
        c. Simbol >= 3
        d. Password terdeteksi sebagai abstrak

    Contoh Very Strong:
        “Abc!!12@#Xyz”
        “Strong#Pass123!?”


📌Simpelnya :

    1. Program menampilkan banner/ intro program.
    2. User memasukkan password.
    3. Program melakukan pengecekan karakter.
    4. Program mengevaluasi level password:
        - invalid?
        - weak?
        - medium?
        - strong?
        - very strong?
    5. Program memberikan hasil dan saran.
    6. User diminta memilih:
        - cek password lagi → kembali ke langkah 2
        - selesai → program berhenti

## ⚠️Syarat Setiap Level Password 

    ❌ Password Invalid
    Password dikategorikan invalid jika panjang password kurang dari 8 karakter

    🔴 Password Lemah
    Kurang dari 8 karakter
    Hanya menggunakan huruf biasa
    Tidak mengandung angka
    Tidak mengandung karakter spesial
    Tidak Abstrak
    Tiga karakter terakhir adalah 123
    Terlalu banyak huruf yang mudah ditebak

    🟡 Password Medium
    Sudah valid (≥ 8 karakter)
    Mengandung minimal dua jenis karakter
    Tapi belum memenuhi syarat "kuat" atau "sangat kuat"

    🟢 Password Kuat
    Panjang ≥ 8 karakter (valid)
    Mengandung minimal tiga jenis karakter
    Mengandung angka
    Tidak diakhiri dengan “123”
    (kecuali sudah ada huruf besar dan angka)

    🔵 Password Sangat Kuat
    Panjang minimal 12 karakter
    Mengandung angka, huruf kecil, huruf besar
    Mengandung minimal 3 karakter spesial
    Bersifat Abstrak
    Kombinasi ini langsung dianggap paling aman

    ## Bagian Program: Saran & Rekomendasi Password

Kode berikut menangani:
- Saran perbaikan password
- Penentuan level kekuatan password
- Pembuatan rekomendasi password otomatis
- Opsi untuk mengecek password lain

# Penjelasan Alur Kerja Kode Rekomendasi Password

Bagian kode ini bertugas memberikan *rekomendasi password* ketika password yang dimasukkan pengguna masih **tidak valid**, **lemah (weak)**, atau **menengah (medium)**. Berikut penjelasan alur kerjanya:

---

## 🔍 1. Mengecek kondisi password
Program masuk ke blok rekomendasi jika:
- `valid` bernilai false, atau
- password termasuk kategori `weak`, atau
- password termasuk kategori `medium`.

Jika salah satu terpenuhi, program mulai membangun rekomendasi berdasarkan password awal pengguna (`pass`).

---

## 🎲 2. Menghasilkan karakter acak
Program menyiapkan karakter acak dari empat kategori:
- Angka (`0–9`)
- Huruf kecil (`a–z`)
- Huruf besar (`A–Z`)
- Karakter spesial

Nilai acak ini dipakai ketika terdapat kategori karakter yang hilang.

---

## 🧩 3. Jika tidak ada kekurangan karakter (`kurang <= 0`)
Program hanya menambahkan karakter dari kategori yang *belum ada* pada password:
- Jika angka hilang → tambah angka acak  
- Jika huruf kecil hilang → tambah huruf kecil acak  
- Jika huruf besar hilang → tambah huruf besar acak  
- Jika karakter spesial hilang → tambah karakter spesial acak  

Tujuan: membuat password memenuhi semua kategori karakter.

---

## 🔁 4. Jika jumlah karakter kurang tetapi semua kategori sudah lengkap
Apabila `kurang > 0` namun seluruh kategori karakter sudah muncul (`hash[] != 0` semua), program:
- Membuat salinan password (`temporer`)
- Melipatgandakannya hingga maksimal 8 karakter

Ini adalah cara cepat untuk memenuhi panjang minimum tanpa karakter baru.

---

## 🔧 5. Jika jumlah karakter kurang dan ada kategori yang hilang
Jika:
- `kurang > 0`, dan
- Ada kategori karakter yang hilang

Program akan mengulang proses penambahan karakter:
- Selama `kurang > 0`, tambahkan kategori yang hilang satu per satu
- Setiap penambahan mengurangi nilai `kurang`

Loop berakhir ketika password mencapai panjang minimum.

---


# Penjelasan Workflow Fungsi `rand()` dalam Logika Rekomendasi Password

Bagian kode ini menggunakan fungsi `rand()` untuk menghasilkan karakter acak yang akan ditambahkan ke password ketika terdapat kekurangan kategori karakter (angka, huruf kecil, huruf besar, atau karakter spesial). Berikut penjelasan lengkap alur kerjanya:

---

## 🔢 1. Menghasilkan Angka Random dari Masing-Masing Kategori

Program membuat empat nilai acak:

- `rand() % 10` → menghasilkan angka acak 0–9  
- `rand() % 26` → menghasilkan indeks huruf kecil acak (0–25)  
- `rand() % 26` → menghasilkan indeks huruf besar acak (0–25)  
- `rand() % 27` → menghasilkan indeks karakter spesial acak

`rand()` menghasilkan integer besar, lalu `%` membatasi hasilnya agar sesuai dengan jumlah karakter yang tersedia di masing-masing kategori.

Contoh:
- Jika `rand() % 10` menghasilkan `7`, maka karakter angka yang dipilih adalah `numbers[7]`.
- Jika `rand() % 26` menghasilkan `2`, maka huruf kecil yang dipilih adalah `lowercase[2]` (misalnya `'c'`).

---

## 🎯 2. Mengapa Nilai Random Diambil Sekali Saja?

Variabel random berikut:

- `randomangka`
- `randomlowcase`
- `randomupcase`
- `randomspecial`

dibuat **sekali di awal**, bukan setiap kali kategori ditambahkan.  
Artinya:
- Jika kategori angka hilang, angka yang ditambahkan **selalu** `numbers[randomangka]`.
- Jika kategori huruf kecil hilang, huruf yang ditambahkan **selalu** `lowercase[randomlowcase]`.

Program **tidak menghasilkan angka random baru setiap kali loop**, sehingga karakter acak yang ditambahkan konsisten.

---

## 🔁 3. Bagaimana Random Dipakai Saat Password "Kurang Panjang"

Ketika variabel `kurang > 0` dan masih ada kategori karakter yang hilang:

Program masuk loop `while(true)`:

Setiap iterasi:
- Jika angka hilang → tambahkan `numbers[randomangka]`
- Jika huruf kecil hilang → tambahkan `lowercase[randomlowcase]`
- Jika huruf besar hilang → tambahkan `uppercase[randomupcase]`
- Jika karakter spesial hilang → tambahkan `special[randomspecial]`

Pada setiap penambahan, `kurang--`.

Loop berhenti ketika `kurang <= 0`.

Ini artinya:
- **Karakter acak dari kategori tersebut mungkin ditambahkan lebih dari sekali**, karena nilai random untuk kategori itu sama sepanjang eksekusi.

Contoh:
Jika `randomangka = 4`, semua penambahan angka akan menghasilkan angka `'4'`.

---

## 🎛️ 4. Kenapa Special Character Pakai `% 27`?

Karena array `special[]` kemungkinan berisi **27 karakter spesial**.  
`rand() % 27` memastikan indeks tidak keluar dari batas array.

---

## 📌 Ringkasan Workflow `rand()`

1. Program memanggil `rand()` **empat kali** untuk membuat empat indeks acak.
2. Setiap indeks digunakan untuk memilih satu karakter acak dari masing-masing kategori.
3. Nilai acak **tetap sama** sepanjang proses rekomendasi.
4. Karakter acak ditambahkan:
   - Jika kategori karakter hilang
   - Jika password kurang panjang dan kategori tersebut hilang
5. Tidak ada pemanggilan `rand()` di dalam loop — ini menyebabkan karakter acak konsisten.

---

Dengan demikian, seluruh logika random pada kode ini bergantung pada empat panggilan awal `rand()` dan bukan pada pengacakan yang berulang di dalam loop.

# Penjelasan Bagian Akhir Program
Jika password sudah valid dan bukan weak:
- Program bertanya apakah pengguna ingin mengecek password lain
- Jika tidak, program menutup eksekusi

