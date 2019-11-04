#include<bits/stdc++.h>
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;i<n;i++)
#define lli long long int
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define ll long long

using namespace std;

#define SIZE 20
int i;

class HashTable{
     private:
     string table[SIZE];
     int occupied[SIZE];
     int capacity;
     public:
     HashTable(){
         fo(i,SIZE){
             table[i]=" ";
             occupied[i]=0;
         }
         capacity=0;
     }
     int getHash(string s);   //returns an integer between 0 and SIZE-1
     void displayHT();
     void insert(string s);
    void search(string s);
    void delete_(string s);

 };

int main(){
    HashTable ht;
    cout<<" 1 for Insert, enter String also \n 2 for Search, enter String also \n 3 to Display\n4 Delete , enter string too\n 5 to stop \n ";
    cout<<"Enter queries:\n";
    while(1){
        int a;
        cin>>a;
        if(a==5) break;
        string s;
        switch(a){
            case 1:
            cin>>s;
            ht.insert(s);
            break;
            case 2:
            cin>>s;
            ht.search(s);
            break;
            case 3:
            ht.displayHT();
            break;
            case 4:
            cin>>s;
            ht.delete_(s);
        }
        
    }
    return 0;
 }

int HashTable::getHash(string s){
    int n=0;
    fo(i,s.length()){
        n=n+(s[i]-'a')*i;
    }
    
    return n%SIZE;
}

void HashTable::displayHT(){
    fo(i,SIZE){
        if(occupied[i]!=0)
        cout<<i<<"\t"<<table[i]<<"\n";
    }
    //cout<<"done\n";
    cout<<endl;
}

void HashTable::insert(string s){
    int hashIndex=getHash(s);
    if(capacity>=SIZE) cout<<"Table is full. Cannot insert.\n";
    else{
        while(table[hashIndex]!=" "||(occupied[hashIndex]!=0))  hashIndex=(hashIndex+1)%SIZE;
        table[hashIndex]=s;
        occupied[hashIndex]=1;
        capacity++;
    }
    //cout<<s<<" inserted\n";

}


void HashTable::search(string s){
    int hashIndex=getHash(s);
    int p=hashIndex,flag=0;
    while(1){
        int index=getHash(table[hashIndex]);
        if(index!=p) {flag=1; cout<<s<<" not found.\n"; return;}
        if((table[hashIndex]==s)&&(occupied[hashIndex]==1)){
            cout<<s<<" found.\n"; return;
        }
        if((table[hashIndex]==s)&&(occupied[hashIndex]==0)){
            cout<<s<<" not Found.\n"; return;
        }
        if(table[hashIndex]==" "){
            cout<<s<<" not found.\n"; return;
        }
        hashIndex=(hashIndex+1)%SIZE;
    }
    
}

void HashTable::delete_(string s){

    int hashIndex=getHash(s);
    int p=hashIndex,flag=0;
    while(1){
        int index=getHash(table[hashIndex]);
        if(index!=p) { return;}
        if((table[hashIndex]==s)&&(occupied[hashIndex]==1)){
            occupied[hashIndex]=0; return;
        }
        if((table[hashIndex]==s)&&(occupied[hashIndex]==0)){
            return;
        }
        if(table[hashIndex]==" "){
             return;
        }
        hashIndex=(hashIndex+1)%SIZE;
    }
    
}




