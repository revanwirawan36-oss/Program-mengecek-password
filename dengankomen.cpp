#include <iostream> //untuk membuka library iostream
using namespace std; //agar tidak menggunakan std::

int main(){ //dalam bahasa pemrograman c++ minimal memiliki satu fungsi main
    bool valid=false,weak=true; //mendeklarasikan nilai boolean
    string numbers= "0123456789"; //mendeklarasikan angka yang akan digunakan untuk syarat kekuatan password
    string lowercase= "abcdefghijklmnopqrstuvwxyz"; //mendeklarasikan huruf kecil untuk syarat kekuatan password
    string uppercase= "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //mendeklarasikan huruf kapital untuk syarat kekuatan password
    string special= "!@#$%^&*()-+=,.<>?/;{}[]|\""; //mendeklarasikan huruf spesial untuk syarat kekuatan password
    int hash[4]={0,0,0,0}; //panjang array hash adalah 4, dan setiap indeks hash bernilai 0 saat awal
    cout << "Program pengecekan password" << endl; 
    int cekbrp=0;

    while(!valid || weak){ //ketika password yang dimasukkan invalid or weak program akan terus melakukan perulangan hinggga password minimal medium n maksimal very strong
    for(int i = 0; i < 4; i++){
        hash[i] = 0;
    }
    bool medium=false,strong=false, verystrong=false, abstrak=false;
    valid=false;
    weak=true;
    int indnum=1,indlow=1,indup=1,indspec=1; //masing-masing variabel bernilai 1 di awal
    if(cekbrp==0){
        cout << "Masukkan Password yang akan di cek: ";
    } else if(cekbrp!=0){
        cout << endl << "Masukkan ulang password yang akan di cek: ";
    } 
    cekbrp++; //untuk menentukan perulangan while ini udah diiterasi keberap
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
    
    for(int i=0; i<n; i++){ //looping untuk numbers
        for(int j=0; j<10; j++){ //berhenti di <10 karena mengikuti nilai angka gt
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
    
    int kurang=0;
    for(int i=0; i<4; i++){
        if(hash[i]==0){
            kurang++;
        }
    }
    //cek ke abstrakan ketika password tidak menggunakan angka dan karakter special
    if(hash[3]==0 && hash[0]==0){
        for(int i=1; i<n; i++){
        string vokal ="aiueoAIUEO";
        bool prevvokal = vokal.find(pass[i-1]) != string::npos;
        bool nowvokal = vokal.find(pass[i]) != string::npos;

        if(!prevvokal && !nowvokal && pass[i]!=pass[i-1]){ //ketika dicek indeks sebelumnya vokal, dan sesudahnya vokal, lalu indeks sebelumnya, dan sesudahnya memiliki huruf yg berbeda maka akan abstrak bernilai true, tetapi ketika tidak memenuhi syarat tsb abstrak bernilai false
        abstrak=true;
        break;
        }
}
    }

    if(hash[3]==0 && hash[0]==0 && abstrak){ //ketika hash indeks ke 3=o, dan hash indkes ke 0=0, maka weak bernilai false
        weak=false;
    }
    if(n>=8){
        valid=true; //kerika banyak karakter yg diinputkan pd password lebih dari sama dengan 8 maka akan bernilai true, dan sebaliknya jika kurang dr 8 akan bernilai false
    }
    if(hash[2]>=2){ //ketika hash indeks ke2 (huruf kapital) lebih dr samadengan 2 maka:
        medium=true; //memenuhi syarat medium
        weak=false; //dan utk kategori weak bernilai false atau dia ga lemah passwordnya tp medium
    }
    if(hash[0]>0){ //ketika hash indeks 0 (angka) lebih bsr dr 0 maka:
        strong=true; //akan memenuhi syarat strong
        medium=false; //tdk termasuk medium
        weak=false; //tdk termasuk weak
    }
    if(hash[3]>=3){ //ketika hash indeks ke 3(karakter spesial) lebih dr sama dengan 3 diinputkan dalam password
        verystrong=true; //maka password akan masuk kedlaam kategori very strong
        strong=false; //tdk strong
        medium=false; //tdk med
        weak=false; //tdk weak
    }
if(!valid){ //ketika password yg dimasukkan invalid, maka akan memnunculkan output dibawah
        cout <<"Password yang anda masukkan tidak valid! ";
    }
    if(weak){ //ketika password yg diinputkan dalam kategori weak, maka akan memunculkan output dibawah dan meminta kita menginputkan password yg lebih kuat
        cout << "Password yang anda buat terlalu mudah!";
    }
}

return 0;
} //menutup program