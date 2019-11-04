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

struct Tnode{
    int priority;
    int key;
    Tnode* l;
    Tnode* r;
    Tnode(int a){
        this->key=a;
        this->priority=rand()%100;
        this->l=nullptr;
        this->r=nullptr;
    }
};


void LR(Tnode* &root){
    Tnode* z=root->r;
    Tnode* T3=root->r->l;
    z->l=root;
    root->r=T3;
    root=z;
}
void RR(Tnode* &root){
    Tnode* y=root->l;
    Tnode* T2=root->l->r;
    y->r=root;
    root->l=T2;
    root=y;
}

void insert(Tnode* &root,int k){
    if(root==nullptr){
        root=new Tnode(k);
        return;
    }
    if(root->key>k){
        insert(root->l,k);
        if(root->l!=nullptr&&root->l->priority>root->priority){
            RR(root);
        }
    }
    else{
        insert(root->r,k);
        if(root->r!=nullptr&&root->r->priority>root->priority){
            LR(root);
        }
    }
}

void printTreap(Tnode* root){
    if(root){
        printTreap(root->l);
        cout<<"Key : "<<root->key<<" | priority: "<<root->priority;
        if(root->l) cout<<" | l child: "<<root->l->key;
        if(root->r) cout<<" | r child: "<<root->r->key;
        if(!root->l&&!root->r) cout<<" | leaf";
        cout<<endl;
        printTreap(root->r);
    }
}
bool search(Tnode* root,int k){
    if(!root) return false;
    if(root->key==k) return true;
    if(root->key>k) return search(root->l,k);
    else return search(root->r,k);
}




void DelNode(Tnode* &root,int k){
    
    if(root==nullptr) return;
    if(root->key>k) DelNode(root->l,k);
    else if(root->key<k) DelNode(root->r,k);
    else
    {
        //it is a leaf node
        if(root->l==nullptr&&root->r==nullptr) {
            delete root;
            root=nullptr;
            }
        //2 children
        else if(root->l && root->r){
                if(root->l->priority<root->r->priority){
                    LR(root);
                    DelNode(root->l,k);
                }
                else{
                    RR(root);
                    DelNode(root->r,k);
                } 
            }
        //1 child
        else{
            Tnode* child;
            child=(root->r)?root->r:root->l;
            Tnode* curr=root;
            root=child;
            delete curr;
        }
    }
}

	
			
int main(){
    Tnode* root=nullptr;
    //srand(time(nullptr));
    int keys[] = { 5, 2, 1, 4, 9, 8, 10 };
    for(int data:keys){
        insert(root,data);
    }
    printTreap(root);
    cout<<search(root,4)<<"\n";
    cout<<search(root,11)<<"\n";
    DelNode(root,9);
    //DelNode(root,2);
    
    printTreap(root);
    

}