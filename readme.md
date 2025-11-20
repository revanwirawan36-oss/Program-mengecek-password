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

### 1. Saran Perbaikan

```cpp
if (hash[0] == 0) {
    cout << "- Password anda terlalu mudah, tambahkan angka agar lebih kuat." << endl;
}
if (hash[1] == 0) {
    cout << "- Tambahkan huruf kecil untuk variasi karakter." << endl;
}
if (hash[2] == 0) {
    cout << "- Tambahkan huruf besar agar password lebih sulit ditebak." << endl;
}
if (hash[3] == 0) {
    cout << "- Tambahkan karakter spesial seperti !@#$% untuk meningkatkan keamanan." << endl;
}

