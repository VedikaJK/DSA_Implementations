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

struct  Node{
	int key;
	struct Node *left;
	struct Node *right;
	int height;
};

struct Node *newNode(int data){
	struct Node *N = (struct Node *)malloc(sizeof(struct Node));
	N->key = data;
	N->left = NULL;
	N->right = NULL;
	N->height = 0;
	return N;
}

int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

struct Node *rightrotate(struct Node *y){
	struct Node *x = y->left;
	struct Node *t2 = x->right;

	x->right = y;
	y->left = t2;

	x->height = height(x->left) > height(x->right) ? height(x->left) : height(x->right);
	y->height = height(y->left) > height(y->right) ? height(y->left) : height(y->right);
	return x;
}
struct Node *leftrotate(struct Node *x){
	struct Node *y = x->right;
	struct Node *t2 = y->left;

	x->right = t2;
	y->left = x;

	x->height = height(x->left) > height(x->right) ? height(x->left) : height(x->right);
	y->height = height(y->left) > height(y->right) ? height(y->left) : height(y->right);
	return y;
}



struct Node*Insert(struct Node* root, int key)
{
    if (root == NULL)
        return(newNode(key));
    if (key < root->key)
        root->left  = Insert(root->left, key);
    else if (key > root->key)
        root->right = Insert(root->right, key);
    else //equal keys
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    // left left case
    if (balance > 1 && key < root->left->key)  return rightrotate(root);

    // right right case
    if (balance < -1 && key > root->right->key)  return leftrotate(root);

    // left right case
    if (balance > 1 && key > root->left->key){
        root->left =  leftrotate(root->left);
        return rightrotate(root);
    }

    // right left case
    if (balance < -1 && key < root->right->key){
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }
      return root;
}

struct Node * Min(struct Node* node) {
    struct Node* temp = node;
    while (temp->left != NULL)
        temp = temp->left;

    return temp;
}

struct Node* Delete(struct Node* root, int key){

    if (root == NULL)
        return root;
    if ( key < root->key )
        root->left = Delete(root->left, key);
    else if( key > root->key )
        root->right = Delete(root->right, key);
    else{

        
        if( (root->left == NULL) || (root->right == NULL) ) {
            struct Node *temp = root->left ? root->left : root->right;

            // No child
            if (temp == NULL){
                temp = root;
                root = NULL;
            }
            else //one child case
             *root = *temp;
            free(temp);
        }
        else{
            //node with two children
            struct Node* temp = Min(root->right);

            root->key = temp->key;

            root->right = Delete(root->right, temp->key);
        }
    }
      if (root == NULL)
      return root;

    root->height = 1 + max(height(root->left),
                           height(root->right));
    int balance = getBalance(root);

    // left left case
    if (balance > 1 && key < root->left->key)  return rightrotate(root);

    // right right case
    if (balance < -1 && key > root->right->key)  return leftrotate(root);

    // left right case
    if (balance > 1 && key > root->left->key){
        root->left =  leftrotate(root->left);
        return rightrotate(root);
    }
    // right left case
    if (balance < -1 && key < root->right->key){
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }

    return root;
}

struct Node *Search(int k, struct Node *root){
    if(root == NULL || root->key == k) return root;
    if(root->key > k) return Search(k, root->left);
    return Search(k, root->right);
}
int Max(struct Node *root){
    while(root->right!=NULL) root = root->right;
    return root->key;
}

struct Node *join(struct Node *t1, struct Node *t2){
    if(t1 == NULL) return t2;
    if(t2 == NULL) return t1;

    int m = Max(t1);
    t1 = Delete(t1, m);
    struct Node *root = newNode(m);
    root->left = t1;
    root->right = t2;
    root->height = 1 + max(height(root->left),
                           height(root->right));
    int balance = getBalance(root);

    // left left case
    if (balance > 1 )  return rightrotate(root);
    // right right case
    if (balance < -1 )  return leftrotate(root);

    return root;

}
void inorder(struct Node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}
int main(){
	  struct Node *root = NULL;

  
    root = Insert(root, 99);
    root = Insert(root, 5);
    root = Insert(root, 1);
    root = Insert(root, 8);
    root = Insert(root, 7);
    root = Insert(root, 111);
    root = Insert(root, 18);
    root = Insert(root, -3);
    root = Insert(root, 2);
    inorder(root);
    cout<<endl;

    struct Node *root2 = NULL;

 
    root2 = Insert(root2, 2);
    root2 = Insert(root2, 52);
    root2 = Insert(root2, 12);
    root2 = Insert(root2, 20);
    root2 = Insert(root2, 72);
    root2 = Insert(root2, 112);
    root2 = Insert(root2, -1);
    root2 = Insert(root2, 82);
    root2 = Insert(root2, 44);

    inorder(root2);
    cout<<endl;
    struct Node *t = join(root, root2);
    inorder(t);
    cout<<endl;
    struct Node *a = Search(29, root2);
    if(a==nullptr) cout<<0;
    else cout<<1;
    cout<<endl;

    return 0;
}
