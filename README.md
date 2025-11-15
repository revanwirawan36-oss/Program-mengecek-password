# Program Pengecekan Password 🔐

Program ini ditulis dalam bahasa **C++** untuk melakukan validasi dan mengecek tingkat kekuatan sebuah password berdasarkan aturan tertentu.

---

## 📌 Workflow Program

### 1. Tampilan Awal
- Fungsi `awal()` menampilkan banner program dan aturan dasar:
  - Password harus memiliki **minimal 8 karakter**.

### 2. Input Password
- Program meminta pengguna untuk memasukkan password.
- Jika password tidak valid atau terlalu lemah, pengguna diminta untuk mengulang input.

### 3. Pengecekan Karakter
Program memeriksa apakah password mengandung:
- **Angka** (`numbers`)
- **Huruf kecil** (`lowercase`)
- **Huruf besar** (`uppercase`)
- **Karakter spesial** (`special`)

Hasil pengecekan disimpan dalam array `hash[4]`.

### 4. Validasi Panjang Password
- Password dianggap **valid** jika panjangnya ≥ 8 karakter.

### 5. Pengecekan Tingkat Kekuatan
Program menentukan level kekuatan password berdasarkan aturan berikut:

| Level        | Syarat                                                                 |
|--------------|------------------------------------------------------------------------|
| **Weak**     | Password terlalu sederhana, tidak mengandung angka/karakter spesial.   |
| **Medium**   | Mengandung ≥ 2 huruf besar.                                            |
| **Strong**   | Mengandung angka.                                                      |
| **Very Strong** | Mengandung ≥ 3 karakter spesial.                                    |
| **Abstrak**  | Password tanpa angka & karakter spesial, tetapi memiliki pola unik (konsonan berurutan berbeda). |

### 6. Output
- Jika password tidak valid → tampil pesan `"Password yang anda masukkan invalid!"`.
- Jika password terlalu lemah → tampil pesan `"Password yang anda buat terlalu mudah!"`.
- Jika memenuhi syarat abstrak → password tidak dianggap lemah.
- Program terus meminta input hingga password valid dan tidak lemah.

---

## 🛠️ Fungsi Pendukung
- `garis()` → Menampilkan garis pemisah untuk memperjelas output.
- `awal()` → Menampilkan banner awal program.

---

## 🚀 Cara Menjalankan
1. Kompilasi program:
   ```bash
   g++ password_checker.cpp -o password_checker
