#include <iostream>
using namespace std;

int main(){
    bool valid=false,weak=true;
    string numbers= "0123456789";
    string lowercase= "abcdefghijklmnopqrstuvwxyz";
    string uppercase= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string special= "!@#$%^&*()-+=,.<>?/;{}[]|\"";
    int hash[4]={0,0,0,0};
    cout << "Program pengecekan password" << endl;
    int cekbrp=0;
    while(!valid || weak){
    for(int i = 0; i < 4; i++){
        hash[i] = 0;
    }
    bool medium=false,strong=false, verystrong=false, abstrak=false;
    valid=false;
    weak=true;
    int indnum=1,indlow=1,indup=1,indspec=1;
    if(cekbrp==0){
        cout << "Masukkan Password yang akan di cek: ";
    } else if(cekbrp!=0){
        cout << endl << " Masukkan ulang password yang akan di cek: ";
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
    
    int kurang=0;
    for(int i=0; i<4; i++){
        if(hash[i]==0){
            kurang++;
        }
    }
    //cek ke abstrakan ketika password tidak menggunakan angka dan karakter special
    if(hash[3]==0 && hash[0]==0){
        for(int i=1; i<n; i++){
        string vokal="aiueoAIUEO";
        bool prevvokal= vokal.find(pass[i-1]) != string::npos;
        bool nowvokal= vokal.find(pass[i]) != string::npos;

        if(!prevvokal && !nowvokal && pass[i]!=pass[i-1]){
        abstrak=true;
        break;
        }
    }
    }

    if(hash[3]==0 && hash[0]==0 && abstrak){
        weak=false;
    }
    if(n>=8){
        valid=true;
    }
    if(hash[2]>=2){
        medium=true;
        weak=false;
    }
    if(hash[0]>0){
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
        cout <<"Password yang anda masukkan tidak valid! ";
    }
    if(weak){
        cout << "Password yang anda buat terlalu mudah!";
    }
}
    return 0;
}