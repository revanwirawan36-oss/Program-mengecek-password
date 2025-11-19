# <span style="color: black"> PROGRAM CEK PASSWORD

## <span style="color: lightblue"> Studi Kasus 
        Di sebuah universitas, sistem keamanan sangat penting untuk melindungi informasi pribadi mahasiswa dari akses yang tidak sah. Setiap mahasiswa diwajibkan untuk membuat kata sandi yang kuat saat mendaftar akun di sistem informasi kampus. Namun, banyak mahasiswa masih bingung tentang cara membuat kata sandi yang benar-benar aman dan sesuai. Sebagai seorang mahasiswa baru jurusan Ilmu Komputer, anda diminta membuat sebuah program yang dapat memeriksa apakah kata sandi yang dibuat mahasiswa memenuhi standar keamanan yang ada atau tidak.
        
        Kata sandi yang memenuhi standar harus mencakup syarat sebagai berikut:
    • Kata sandi minimal memiliki 8 karakter
    • Mengandung huruf besar dan kecil
    • Mengandung angka
    • Mengandung simbol khusus seperti @*%#
    
         Program ini akan membaca kata sandi yang dimasukkan dan kemudian memeriksa semua kriteria yang ada. Jika semua persyaratan terpenuhi, program akan menampilkan pesan yang menyatakan bahwa kata sandi "Aman Digunakan." Namun, jika ada persyaratan yang tidak terpenuhi, program akan memberikan penjelasan mengenai informasi yang hilang, seperti memunculkan kalimat "Kata Sandi Tidak Memiliki Angka" atau “Kata Sandi Tidak Memiliki Simbol Khusus”.

Dari studi kasus diatas, terciptalah sebuah program. Program ini dibuat sebagai salah satu solusi untuk memastikan setiap mahasiswa membuat kata sandi yang kuat saat mendaftar ke sistem informasi akademik. Karena saat ini masih banyak mahasiswa yang masih kesulitan dalam membuat password yang aman, sehingga terciptalah program ini untuk membantu mengecek apakah password yang di input memenui aturan keamanan atau tidak.

## <span style="color: lightblue">Fitur Utama
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

## <span style="color: lightblue">Cara Kerja

## <span style="color: lightblue">Alur Logika IF–ELSE 
    Cek apakah panjang password >= 8?
        Jika tidak → invalid + lemah
    Cek apakah ada huruf kecil?
    Cek apakah ada huruf besar?
    Cek apakah ada angka?
    Cek apakah ada simbol?
    Cek password apakah lemah?
        - tidak ada angka + tidak ada simbol
        - atau kombinasi tertentu + tidak valid
    Cek password medium:
        - huruf besar ≥ 2
    Cek password kuat:
        - ada angka
    - tidak berakhiran “123”
        - atau jika berakhiran “123” tetap kuat bila ada huruf besar
    Cek password sangat kuat:
        - karakter spesial ≥ 3

## <span style="color: lightblue">Syarat Setiap Level Password 
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


![Tengkiu](URL) {Link: Medium https://share.google/UYzMtQ8nID66mrIrC}