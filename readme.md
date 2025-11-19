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

## ✨Fitur Utama
    Fitur Utama dari program ini antara lain
    - Mengecek apakah password valid (minimal 8 karakter).
    - Mengecek apakah password mengandung:
        > Huruf kecil
        > huruf besar
        > angka
        > karakter spesial (@, #, %, *, dll)
    - Menentukan level kekuatan password:
        > Lemah
        > Medium
        > Kuat
        > Sangat Kuat
    - Memberikan saran otomatis untuk memperbaiki password.
    - Memberikan rekomendasi password dengan tambahan karakter acak.

## ⚒️Cara Kerja

1. Cara Kerja Program Secara Umum

    Program ini adalah Password Strength Checker, tugasnya:
     a. Meminta user memasukkan password.
     b. Memeriksa isi password:
        -ada angka?
        -ada huruf kecil?
        -ada huruf besar?
        -ada simbol?
     c. Memeriksa apakah password bersifat abstrak (gabungan huruf yang tidak umum).
     d. Memeriksa apakah password mengandung pola 123 di akhir (tuwaga).
     e. Menentukan kekuatan password:
        -Weak
        -Medium
        -Strong
        -Very Strong
     f. Jika password lemah → tampilkan saran
     g. Beri rekomendasi password baru.

    Program terus meminta input ulang selama password belum valid atau masih weak.

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

## ♻️Alur Logika IF–ELSE 

A. Weak

    Weak berarti password terlalu sederhana.
    Program akan menandai password sebagai bukan Weak (weak = false) jika:
        a. ada karakter valid (huruf/angka/simbol)
        b. TIDAK hanya huruf kecil
        c. TIDAK hanya huruf + tanpa simbol saat abstrak + tuwaga

    Atau simpelnya, jika password punya isi yang lumayan → tidak weak

B. Valid

    Password valid hanya jika panjang ≥ 8

        if(n >= 8){
            valid = true;
        }

C. Medium

    Medium = password memiliki min 2 jenis karakter berbeda dan panjang ≥ 8.
    Syaratnya:
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

D. Strong

    Strong = password:
        1. Panjang ≥ 8
        2. Memiliki minimal 3 jenis karakter
        3. Harus mengandung huruf besar
        4. Jika password berakhir “123” → wajib ada angka + huruf besar

    Contoh Strong:
        “Abcde#12”
        “TesT1234”
        “aB1!!!!”

E. Very Strong

    Very Strong :
        a. Panjang minimal 12
        b. Mengandung semua jenis karakter
        c. Simbol >= 3
        d. Tidak abstrak

    Contoh Very Strong:
        “Abc!!12@#Xyz”
        “Strong#Pass123!?”


📌Simpelnya :

    1. Hitung jumlah huruf kecil, besar, angka, simbol
    2. Deteksi abstrak?
    3. Deteksi ada "123" di akhir?
    4. Cek validitas (>= 8)
    5. Jika password tidak terlalu sederhana → bukan weak
    6. Jika valid dan punya ≥2 jenis → Medium
    7. Jika valid dan punya ≥3 jenis + huruf besar → Strong
    8. Jika panjang ≥12 + lengkap semua jenis → Very Strong
    9. Jika weak/medium → tampilkan saran
    10. Jika strong/verystrong → tampilkan level

## ⚠️Syarat Setiap Level Password 
    🔴 Password Lemah
    Kurang dari 8 karakter
    Tidak mengandung angka
    Tidak mengandung karakter spesial
    Terlalu banyak huruf yang mudah ditebak

    🟡 Password Medium
    Sudah valid (≥ 8 karakter)
    Mengandung huruf besar minimal 2
    Tapi belum memenuhi syarat "kuat" atau "sangat kuat"

    🟢 Password Kuat
    Mengandung angka
    Tidak diakhiri dengan “123”
    (kecuali sudah ada huruf besar dan angka)

    🔵 Password Sangat Kuat
    Mengandung minimal 3 karakter spesial
    Kombinasi ini langsung dianggap paling aman
