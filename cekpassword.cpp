#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
void garis();
void awal();

int main(){
    bool valid=false,weak=true;
    string numbers= "0123456789";
    string lowercase= "abcdefghijklmnopqrstuvwxyz";
    string uppercase= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string special= "!@#$%^&*()-+=,.<>?/;{}[]|\"";
    int hash[4]={0,0,0,0};
    awal();
    int cekbrp=0;

    srand(time(NULL));

    while(!valid || weak){
        
    for(int i = 0; i < 4; i++){
        hash[i] = 0;
    }
    
    bool medium=false,strong=false, verystrong=false, abstrak=false, tuwaga=false;
    valid=false;
    weak=true;
    int indnum=1,indlow=1,indup=1,indspec=1;
    if(cekbrp==0){
        cout << "Masukkan Password yang akan di cek: ";
    } else if(cekbrp!=0){
        garis();
        cout << endl << "Masukkan ulang password yang akan di cek: ";
    }
    cekbrp++;
    string pass;
    cin >> pass;
    int n=pass.length();
    
    for(int i=0; i<n; i++){
        for(int j=0; j<26; j++){
            if(pass[i]==lowercase[j]){
                hash[1]=indlow; indlow++; 
            }
            if(pass[i]==uppercase[j]){
                hash[2]=indup; indup++;
            }
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<10; j++){
            if(pass[i]==numbers[j]){
                hash[0]=indnum; indnum++;
            }
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<27; j++){
            if(pass[i]==special[j]){
                hash[3]=indspec; indspec++;
            }
        }
    }
    
    //cek ke abstrakan ketika password tidak menggunakan angka dan char special
        for(int i=1; i<n; i++){
        string vokal="aiueoAIUEO";
        bool prevvokal= vokal.find(pass[i-1]) != string::npos;
        bool nowvokal= vokal.find(pass[i]) != string::npos;
        bool depannya_angka= numbers.find(pass[i]) != string ::npos;

        if(!prevvokal && !nowvokal && pass[i]!=pass[i-1] &&
   pass[i-1]!='f' && pass[i-1]!='F' &&
   pass[i-1]!='v' && pass[i-1]!='V' &&
   !depannya_angka){
    abstrak = true;
    break;
}
    }

    if(n >= 3){
    if(pass[n-3] == '1' && pass[n-2] == '2' && pass[n-1] == '3'){
        tuwaga=true;
    }
    }

   
    if(!(hash[0] == 0 && hash[3] == 0 && !abstrak) &&
   !(hash[0] != 0 && hash[3] == 0 && !abstrak && tuwaga)){
    weak = false;
    }

    if(n>=8){
        valid=true;
    }
    if(hash[2]>=2){
        medium=true;
        weak=false;
    }
    if(hash[0]>0 && !tuwaga ||(hash[2]!=0 && tuwaga && hash[0] > 0) ){
        strong=true;
        medium=false;
        weak=false;
    }
    if(hash[3]>=3){
        verystrong=true;
        strong=false;
        medium=false;
        weak=false;
    }
    if(!valid){
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

    int kurang=8-pass.length();
if(!weak && valid){
    cout << "Level password anda adalah: ";
    if(medium) cout << "medium";
    if(strong) cout << "kuat";
    if(verystrong) cout << "sangatkuat";
 }
    cout << endl;
    if(!valid || weak || medium){
        cout << "Rekomendasi Password: " << pass;
        int randomangka = rand() % 10;
        int randomlowcase = rand() % 26;
        int randomupcase = rand() % 26;
        int randomspecial = rand() % 27;

        if(kurang<=0){
        if(hash[0]==0) cout << numbers[randomangka];
        if(hash[1]==0) cout << lowercase[randomlowcase];
        if(hash[2]==0) cout << uppercase[randomupcase];
        if(hash[3]==0) cout << special[randomspecial];
        }

        if(kurang>0){
        while(1>0){
        if(hash[0]==0){ cout << numbers[randomangka]; kurang--;}
        if(hash[1]==0){ cout << lowercase[randomlowcase]; kurang--;}
        if(hash[2]==0){ cout << uppercase[randomupcase]; kurang--;}
        if(hash[3]==0){ cout << special[randomspecial]; kurang--;}
        if(kurang<=0) break;
        }
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
    cout << "|              RULES: password yang dimasukkan harus 8 digit atau lebih                |\n";
    cout << "|               ****************************************************                   |\n";
    cout << "|                                                                                      |\n";
    cout << "|                         **********************************                           |\n";
    cout << "|                                                                                      |\n";
    cout << "+======================================================================================+\n";
}
