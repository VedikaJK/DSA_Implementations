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

struct node{
    int data;
    node* next;
};

class LinkedList{
    private:
    node* head;
    public:
    LinkedList(){
        head=nullptr;
    }
    void Display();
    void Add_At_End(int);
    void Add_At_Start(int);
    void Add_After_Elt(int,int);
    bool search(int);
    void delete_fisrt();
    void delete_last();
    void deleteit(node*);
    void delete_given(int);

};

int main(){
    LinkedList lt;
    cout<<"Operations: \n";
    cout<<"0. Quit\n1. Display()\n2. Add_At_End(int)\n3. Add_At_Start(int)\n4. Add_After_Elt(int)\n5. search(int)\n6. delete_fisrt()\n7. delete_last()\n8. delete_given(int)\n";
    int a,b;
    cin>>a;
    while(a){
        switch(a){
            case 1:
            lt.Display();
            break;
            case 2:
            cin>>b;
            lt.Add_At_End(b);
            break;
            case 3:
            cin>>b;
            lt.Add_At_Start(b);
            break;
            case 4:
            int c;
            cin>>b>>c;
            lt.Add_After_Elt(b,c);
            break;
            case 5:
            cin>>b;
            if(lt.search(b)) cout<<"True\n";
            else cout<<"False\n";
            
            break;
            case 6:
            lt.delete_fisrt();
            break;
            case 7:
            lt.delete_last();
            break;
            case 8:
            cin>>b;
            lt.delete_given(b);
            break;
            default:
            cout<<"Invalid choice.\n";
        }
        cin>>a;
    }
    return 0;
}

void LinkedList::Display(){
    node* tmp;
tmp=head;
if(head==NULL){cout<<"Empty"<<endl;}
else{
    while(tmp!=NULL) 
    {cout<<tmp->data<<" "; 
    tmp=tmp->next;} 
    cout<<endl;
}
}

void LinkedList::Add_At_End(int elt){
    if(!head){
        Add_At_Start(elt);
        return;
    }
    node* temp;
    node* prev;
    temp=head;
    while(temp!=nullptr){
        prev=temp;
        temp=temp->next;
    }
    node* t=new node;
    prev->next=t;
    t->data=elt;
    t->next=nullptr;
}


void LinkedList::Add_At_Start(int elt){
    node *tmp = new node;
tmp->data=elt;
if(head==NULL){tmp->next=NULL;}
else{tmp->next=head;}
head=tmp;
}

void LinkedList::Add_After_Elt(int elt, int key){
    node* t=new node;
    t->data=key;
    if(!search(elt)){
        cout<<elt<<" not present.\n";
        return;
    }
    node* temp=head;
    
    node* n;
    while(temp->data!=elt){
        temp=temp->next;
    }
    if(temp==nullptr){
        Add_At_End(key);
        return;
    }
    n=temp->next;
    temp->next=t;
    t->next=n;
}
bool LinkedList::search(int elt){
  
node* prev=NULL;
node* curr=head;
if(head==NULL){return 0 ;}
else   {
             while(1)
                {
                 if(curr->data==elt){return 1; }
                 else{prev=curr;curr=curr->next;}
                 if(curr==NULL){ return 0;}
                 }
              
        }
}

void LinkedList::delete_fisrt(){
    node *tmp = new node;
if(head==NULL){cout<<"-1"<<endl;}
else{node *tmp = new node; 
tmp=head;
head=head->next;
delete tmp;}

}

void LinkedList::delete_last(){

    if (head == NULL) 
        return ; 
  
    if (head->next == NULL) { 
        node* t=head;
        head=nullptr; 
        delete t; 
        return;
    } 

    node* second_last = head; 
    while (second_last->next->next != NULL) 
        second_last = second_last->next; 
  
    delete (second_last->next); 
    second_last->next = NULL;   
}

void LinkedList::delete_given(int elt){
   
    node* prev=NULL;
node* curr=head;
if(head==NULL){return;}
else   {
          if (head->data==elt)   {delete_fisrt();}
          else
             {while(1)
                {
                 if(curr->data==elt){deleteit(curr); break;}
                 else{prev=curr;curr=curr->next;}
                 if(curr==NULL){return;}
                 }
              }
        }
}

void LinkedList::deleteit(node* ptr){
//not concerned with deleting first ele
//only mid or end
node* tmp= new node;
tmp=head;
while(tmp->next!=ptr){tmp=tmp->next;}
tmp->next=ptr->next;
delete ptr;}
