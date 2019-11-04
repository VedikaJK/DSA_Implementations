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
#define SIZE 100

using namespace std;

int i;

class DisjointSet{
private:
    int rank[SIZE];
    int parent[SIZE];
public:
    DisjointSet(){
        fo(i,SIZE) {parent[i]=-1;
        rank[i]=0;}
    }
    void MakeSet(int);
    int FindSet(int);
    void Union(int,int);
    void Link(int,int);
    void DisplaySet();
};

int main(){
    DisjointSet DS;
    cout<<"Following operations can be performed.\n"<<"1. Insert elt\n2. Union\n3. Find set\n4. Display set\n5. Quit\nEnter serial no and input parameters accordingly.\n";
    int x,y,z;
    cin>>x;
    while(x!=5){
        switch (x)
        {
        case 1:
            cin>>y;
            DS.MakeSet(y);
            break;
        case 2:
            cin>>y>>z;
            DS.Union(y,z);
            break;
        case 3:
            cin>>y;
            cout<<"Set of "<<y<<" is "<<DS.FindSet(y)<<"\n";
            break;
        case 4:
            DS.DisplaySet();
            break;
        }
        cin>>x;
    }
    return 0;
}

void DisjointSet::MakeSet(int elt){
    if(parent[elt]!=-1) cout<<"Already present.\n";
    else parent[elt]=elt;
}
int DisjointSet::FindSet(int j){
    /*if(parent[i]==i) return i;
    else {parent[i]=FindSet(i);
    return parent[i];}*/
    if(parent[j]==-1){
        cout<<j<<" not present.\n";
        return -1;
    }
     if (parent[j] != j) { 

            parent[j] = FindSet(parent[j]); 
  
            // so we recursively call Find on its parent 
            // and move i's node directly under the 
            // representative of this set 
        } 
  
        return parent[j];
}
void DisjointSet::Link(int a,int b){
    int arep,brep;
    arep=FindSet(a);
    brep=FindSet(b);
    if(arep==-1||brep==-1){
        cout<<"Elt not present.\n";
    }
    else if(rank[arep]>rank[brep]) parent[brep]=arep;
    else if(rank[brep]>rank[arep]) parent[arep]=brep;
    else{
        parent[brep]=arep;
        rank[arep]++;
        }
}

void DisjointSet::Union(int a, int b){
    int arep,brep;
    arep=FindSet(a);
    brep=FindSet(b);
    if(arep==-1||brep==-1){
        cout<<"Elt not present.\n";
    }
    else if(arep==brep) return;
    else Link(a,b);
}
void DisjointSet::DisplaySet(){
    fo(i,SIZE){
        if(parent[i]!=-1)
        cout<<i<<"\t"<<parent[i]<<"\n";
    }
}