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

class node{
private:
    int data;
    struct node* left;
    struct node* right;
public:
    node *newnode(int key){
        struct node *a = ( node*)malloc(sizeof( node));
        a->data=key;
        a->left=NULL;
        a->right=NULL;
        return a;
    }

    node *Insertright( node *root, int key){
    	if(root == NULL) return newnode(key);
    	root->right =  Insertright(root->right, key);
    	return root;
    }

    node *Insertleft( node *root, int key){
    	if(root == NULL) return newnode(key);
    	root->left =  Insertleft(root->left, key);
    	return root;
    }

    void inorder( node* root)
    {
        if (!root) return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }

    void preorder( node* root) {
        if(root == NULL) return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder( node* root) {
        if(root == NULL) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

    bool Search( node* root, int key)
    {
        if (root == NULL)
            return false;

        if (root->data == key)
            return true;

        bool l = Search(root->left, key);

        bool r = Search(root->right, key);

        return l || r;
    }
};

int main(){
  node *root = NULL;
	root = root->Insertleft(root, 99);
	root = root->Insertright(root, 1);
	root = root->Insertright(root, 10);
	root = root->Insertright(root,77);
	root = root->Insertright(root,88);
	root->inorder(root);
	cout<<endl;
	root->preorder(root);
	cout<<endl;
	root->postorder(root);
	cout<<endl;
	cout<<root->Search(root, 84)<<endl;
}