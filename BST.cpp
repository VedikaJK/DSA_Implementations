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

class BST{
private:
	int data;
	BST *left, *right;
public:
  BST *newnode(int key){
    BST *a = (BST*)malloc(sizeof(BST));
    a->data=key;
    a->left=NULL;
    a->right=NULL;
    return a;
  }
  BST* Insert(int key, BST* root){
    BST *a = newnode(key);
    if(root == NULL)return a;
    else{
        if(root->data >= key){
            root->left = Insert(key, root->left);
        }else{
            root->right = Insert(key, root->right);
        }
        return root;
    }
  }

  BST* Search(int key, BST* root){
    if(root == NULL || root->data == key) return root;
    if(root->data > key) return Search(key, root->left);
    return Search(key, root->right);
  }

 BST* Min(BST* root){
    BST* temp = root;
    while(temp->left) temp = temp->left;
    return temp;
  }

  BST* Max(BST* root){
    BST* temp = root;
    while(temp->right) temp = temp->right;
    return temp;
  }

  BST* Delete(int key, BST* root){
    if(root==NULL)return root;
    if(root->data > key) root->left = Delete(key, root->left);
    else if(root->data < key) root->right = Delete(key, root->right);
    else{
      if(root->left == NULL){
            BST *temp = root->right;
            free(root);
            return temp;
      }
      else if(root->right == NULL){
            BST *temp = root->left;
            free(root);
            return temp;
      }

      BST* temp=Min(root->right);
      root->data=temp->data;
      root->right=Delete(temp->data, root->right);
    }
    return root;
  }

  void inorder(BST *root){
    if (root != NULL)
    {
        inorder(root->left);
        cout<< root->data<<" ";
        inorder(root->right);
    }
  }

  BST *join(BST *t1, BST *t2){
    if(t1 == NULL) return t2;
    if(t2 == NULL) return t1;

    BST *t = newnode(Max(t1)->data);
    t1 = Delete(t->data, t1);
    t->left = t1;
    t->right = t2;
    return t;
  }


};

int main(){
	  BST* t1=NULL;
    t1 = t1->Insert(75, t1);
    t1->Insert(0, t1);
    t1->Insert(85, t1);
    t1->Insert(10, t1);
    t1->Insert(2, t1);
    t1->Insert(22, t1);
    t1->inorder(t1);
    cout<<endl;

    BST* t2=NULL;
    t2 = t2->Insert(111, t2);
    t2->Insert(222, t2);
    t2->Insert(333, t2);
    t2->Insert(444, t2);
    t2->Insert(555, t2);
    t2->Insert(666, t2);
	  t2->inorder(t2);
    cout<<endl;
    if(t2->Search(222,t2)) cout<<1;
    else cout<<0;
    cout<<endl;
if(t2->Search(22,t2)) cout<<1;
    else cout<<0;
    cout<<endl;
    BST *t = NULL;
    t = t->join(t1, t2);
    t->inorder(t);
    cout<<endl;

}
