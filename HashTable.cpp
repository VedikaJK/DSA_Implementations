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
     int capacity;
     public:
     HashTable(){
         fo(i,SIZE){
             table[i]=" ";
         }
         capacity=0;
     }
     int getHash(string s);   //returns an integer between 0 and SIZE-1
     void displayHT();
     void insert(string s);
    void search(string s);

 };

int main(){
    HashTable ht;
    cout<<" 1 for Insert, enter String also \n 2 for Search, enter String also \n 3 to Display\n 4 to stop \n ";
    cout<<"Enter queries:\n";
    while(1){
        int a;
        cin>>a;
        if(a==4) break;
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
        cout<<i<<"\t"<<table[i]<<"\n";
    }
}

void HashTable::insert(string s){
    int hashIndex=getHash(s);
    if(capacity>=SIZE) cout<<"Table is full. Cannot insert.";
    else{
        while(table[hashIndex]!=" ")  hashIndex=(hashIndex+1)%SIZE;
        table[hashIndex]=s;
        capacity++;
    }
    //cout<<s<<" inserted\n";

}


void HashTable::search(string s){
    int hashIndex=getHash(s);
    while((table[hashIndex]!=s)&&(table[hashIndex]!=" ")){
        hashIndex=(hashIndex+1)%SIZE;
    }
    if(table[hashIndex]==" ") cout<<s<<" not found.\n";
    else cout<<s<<" is found.\n";
}