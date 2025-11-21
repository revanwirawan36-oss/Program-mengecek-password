#include <iostream> //membuka library iostream
#include <ctime> //membuka library time untuk srand
#include <cstdlib> //membuka library stdlib untuk fungsi random (rand, srand)
using namespace std; //agar tidak menggunakan std::
void garis(); //deklarasi fungsi untuk mencetak garis
void awal();//deklarasi fungsi untuk menampilkan header

int main(){ //dalam c++ minimal memiliki satu fungsi main
    bool valid=false,weak=true; //mendeklarasikan nilai boolean
    string numbers= "0123456789"; //mendeklarasikan angka yang akan digunakan untuk syarat kekuatan password
    string lowercase= "abcdefghijklmnopqrstuvwxyz"; //mendeklarasikan huruf kecil yang akan digunakan untuk syarat kekuatan password
    string uppercase= "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //mendeklarasikan huruf kapital yang akan digunakan untuk syarat kekuatan password
    string special= "!@#$%^&*()-+=,.<>?/;{}[]|\""; //mendeklarasikan karakter spesial yang akan digunakan untuk syarat kekuatan password
    int hash[4]={0,0,0,0}; //panjang array hash adalah 4, dan setiap indeks hash bernilai 0 saat awal
    cout << "Program pengecekan password" << endl; 
    awal();
    int cekbrp=0;
    int pilihan=0;

    srand(time(NULL)); //inisialisasi nilai random

    while(!valid || weak || pilihan==1){ //ketika password yang dimasukkan invalid or weak program akan terus melakukan perulangan hinggga password minimal medium n maksimal very strong
    
    //semua kategori di reset menjadi 0
    for(int i = 0; i < 4; i++){ 
        hash[i] = 0;
    }
    
    
    bool medium=false,strong=false, verystrong=false, abstrak=false, tuwaga=false; //deklarasi ulang variabel tingkat keamanan
    valid=false;
    weak=true;
    int indnum=1,indlow=1,indup=1,indspec=1; //masing-masing variabel bernilai 1 diawal
    if(cekbrp==0){
        cout << "Masukkan Password yang akan di cek: ";
    } else if(cekbrp!=0){
        garis();
        cout << endl << "Masukkan ulang password yang akan di cek: ";
    }
    cekbrp++; //untuk menentukan perulangan while udah diiterasi keberapa
    string pass;
    cin >> pass;
    int n=pass.length(); //panjang password
    
    for(int i=0; i<n; i++){ //looping untuk lowercase dan uppercase
        for(int j=0; j<26; j++){ //berhenti di <26 karena mengikuti banyak alfabet
            if(pass[i]==lowercase[j]){
                hash[1]=indlow; indlow++; //lowercase berada pada indeks ke1, dengan nilai awal 1, ketika lowercase yg diinputkan dalam password bertambah nilai lowercase juga akan bertambah mengikuti banyaknya huruf yg dimasukkan
            }
            if(pass[i]==uppercase[j]){
                hash[2]=indup; indup++; //upcase ada pada indeks ke2, nilai awal 1, dan kan terus bergambah mengikuti berapa banyak huruf besar yg  diinputkan pada password
            }
        }
    }
    
    for(int i=0; i<n; i++){ //looping untuk angka
        for(int j=0; j<10; j++){ //berhenti di <10 karena mengikuti banyaknya nilai angka
            if(pass[i]==numbers[j]){
                hash[0]=indnum; indnum++; //numbers ada pada indeks ke0, nilai awal 1, dan akan terus bertambah mengikuti banyaknya angka yg diinputkan dalam password
            }
        }
    }
    
    for(int i=0; i<n; i++){ //looping untuk huruf spesial
        for(int j=0; j<27; j++){ //berhenti di <27 karena mengikuti banyaknya karakter spesial 
            if(pass[i]==special[j]){
                hash[3]=indspec; indspec++; //karakter spesial ada pada indeks ke 3, dgn nilai awal 1, dan akan terus bertambah sesuai dengan banyaknya karakter spesial yg diinputkan pada password
            }
        }
    }
    
    //cek ke abstrakan ketika password tidak menggunakan angka dan char special
        for(int i=1; i<n; i++){
        string vokal="aiueoAIUEO";
        bool prevvokal= vokal.find(pass[i-1]) != string::npos;
        bool nowvokal= vokal.find(pass[i]) != string::npos;
        bool depannya_angka= numbers.find(pass[i]) != string ::npos;

        /*ketika dicek indeks sebelumnya vokal, dan sesudahnya vokal, lalu indeks sebelumnya, dan sesudahnya memiliki huruf yg berbeda
        maka akan abstrak bernilai true, tetapi ketika tidak memenuhi syarat tsb abstrak bernilai false*/
        abstrak=true;
        if(!prevvokal && !nowvokal && pass[i]!=pass[i-1] &&
   pass[i-1]!='f' && pass[i-1]!='F' &&
   pass[i-1]!='v' && pass[i-1]!='V' &&
   !depannya_angka){
    abstrak = true;
    break;
}
    }

    //pengecekan pola "123" di akhir password
    if(n >= 3){
    if(pass[n-3] == '1' && pass[n-2] == '2' && pass[n-1] == '3'){
        tuwaga=true;
    }
    }

    //jika memenuhi syarat tertentu, password tidak weak
    if(!(hash[0] == 0 && hash[3] == 0 && !abstrak) &&
   !(hash[0] != 0 && hash[3] == 0 && !abstrak && tuwaga)){
    weak = false;
    }

    //jika password yang diinputkan >= 8 maka password valid
    if(n>=8){
        valid=true;
    }
    if(valid &&
        (
        (hash[0] > 0 && hash[1] > 0) || 
        (hash[0] > 0 && hash[2] > 0) || 
        (hash[0] > 0 && hash[3] > 0) || 
        (hash[1] > 0 && hash[2] > 0) || 
        (hash[1] > 0 && hash[3] > 0) || 
        (hash[2] > 0 && hash[3] > 0)    
        )
    ){
        medium = true; //jika memenuhi syarat diatas password bernilai medium
        weak = false; //dan tidak bernilai weak
    }

    if(valid &&
    (
       
        (hash[0]>0 && hash[1]>0 && hash[2]>0) ||
        (hash[0]>0 && hash[1]>0 && hash[3]>0) ||
        (hash[0]>0 && hash[2]>0 && hash[3]>0) ||
        (hash[1]>0 && hash[2]>0 && hash[3]>0)
    ) &&
    (
        (hash[2] > 0 && !tuwaga) ||             
        (tuwaga && hash[2] > 0 && hash[0] > 0)
    ))
    {
        strong = true; //jika memenuhi syarat diatas password bernilai strong
        medium = false; // tidak medium
        weak = false; // tidak weak
    }

   if (n >= 12 && hash[0] > 0 && hash[1] > 0 && hash[2] > 0 && hash[3] >= 3 && abstrak){
        verystrong = true; //ketika memenuhi syarat diatas password akan verystrong
        strong = false; //tdk strong
        medium = false; //tdk medium
        weak = false; //tdk weak
    }
    
    if(!valid){ //ketika password invalid menampilkan akan menampilkan ouput dibawah
        cout <<"Password yang anda masukkan invalid! "; 
    }
    if(weak && !valid){ 
        cout << "serta ";
    }
    if(weak||medium){
        if(weak) cout << "Password yang anda buat terlalu mudah!";
        if(medium) cout << "password yang anda buat terlalu basic";
        cout << endl << "Saran untuk meningkatkan keamanan password:" << endl;

    if(hash[0] == 0){
        cout << "- Password anda terlalu mudah, tambahkan angka agar lebih kuat." << endl;
    }
    if(hash[1] == 0){
        cout << "- Tambahkan huruf kecil untuk variasi karakter." << endl;
    }
    if(hash[2] == 0){
        cout << "- Tambahkan huruf besar agar password lebih sulit ditebak." << endl;
    }
    if(hash[3] == 0){
        cout << "- Tambahkan karakter spesial seperti !@#$% untuk meningkatkan keamanan." << endl;
    }
    }

//untuk menampilkan level password 
    int kurang = 8-pass.length();
if(!weak && valid){
    cout << "Level password anda adalah: ";
    if(medium) cout << "medium";
    if(strong) cout << "kuat";
    if(verystrong) cout << "sangatkuat";
 }

 //menampilkan rekomendasi password
    cout << endl;
    if(!valid || weak || medium){  //ketika password invalid or weak or med, maka akan memberikan rekomendasi password
        cout << "Rekomendasi Password: " << pass; //menampilkan output tsb
        int randomangka = rand() % 10; //mengambil angka random 0-9
        int randomlowcase = rand() % 26; //mengambil huruf kecil random (a-z)
        int randomupcase = rand() % 26; //mengambil huruf kapital random (A-Z)
        int randomspecial = rand() % 27; //mengambil karakter random

        if(kurang<=0){ //jika panjang password sudah cukup
        if(hash[0]==0) cout << numbers[randomangka]; //tp tidak memiliki angka maka akan mengeluarkan rekomendasi angka random
        if(hash[1]==0) cout << lowercase[randomlowcase]; //tp tidak memiliki huruf krcil maka akan mengeluarkan rekomendasi huruf kecil random
        if(hash[2]==0) cout << uppercase[randomupcase]; //mengeluarkan rekomendasi huruf kapital random
        if(hash[3]==0) cout << special[randomspecial]; //mengeluarkan karakter spesial random
        }
        //jika password kurang dari 8 karakter tetapi mengandung semua kategori karakter
        if(kurang>0 && hash[0]!=0 && hash[1]!=0 && hash[2]!=0 && hash[3]!=0){ //Jika panjang password belum 8, tetapi semua kategori (angka, huruf kecil, besar, spesial) sudah ada
            string temporer=pass; // Membuat string sementara untuk menambah panjang password
            while(temporer.length()<8){ //// Menggandakan password hingga mencapai minimal 8 karakter
            temporer+=temporer; // memperpanjang password
            } cout << temporer; // Menampilkan password yang sudah diperpanjang
            
        }
        //menambahkan karakter sampai panjang minimum tercapai
        else if(kurang>0){
        while(1>0){
        if(hash[0]==0){ cout << numbers[randomangka]; kurang--;}
        if(hash[1]==0){ cout << lowercase[randomlowcase]; kurang--;}
        if(hash[2]==0){ cout << uppercase[randomupcase]; kurang--;}
        if(hash[3]==0){ cout << special[randomspecial]; kurang--;}
        if(kurang<=0) break;
        }
    }
    
    }
        if(valid && !weak){ //mengecek kondisi password
        cout << endl << "Apakah anda ingin mengecek password lain? " << endl;
        cout << "ketik 1 untuk ya: ";
        cin >> pilihan;
        cout << endl;
        if (pilihan != 1) {//mengakhiri program
            cout << "Program selesai." << endl;
        }
    }

}
    return 0;
}
void garis(){
    cout << endl<<"====================================================================================================";
}
void awal(){
    cout << "+======================================================================================+\n";
    cout << "|                                                                                      |\n";
    cout << "|                          PROGRAM PENGECEKAN PASSWORD                                 |\n";
    cout << "|      Program C++ sederhana untuk cek validitas dan tingkat kekuatan password         |\n";
    cout << "|                                                                                      |\n";
    cout << "|         RULES: password yang dimasukkan harus 8 digit atau lebih dan tanpa spasi     |\n";
    cout << "|               ****************************************************                   |\n";
    cout << "|                                                                                      |\n";
    cout << "|                         **********************************                           |\n";
    cout << "|                                                                                      |\n";
    cout << "+======================================================================================+\n";
}
