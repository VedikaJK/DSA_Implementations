/*
This is an implementation of BFS and DFS using Queue and Stack rep.
First line of input: #vertices #edges
Next #edge lines: v1 v2 weight
Next line: Starting vertex for BFS
Next line: Starting vertex for DFS

*/
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

#define SIZE 100
int i,j,k;

class Queue{
  public:
  Queue(){
      fo(i,SIZE){
          q[i]=0;
      }
      r=f=-1;
    }
  bool isFull();
  bool isEmpty();
  void enQ(int elt);
  int deQ();
  private:
    int q[SIZE];
    int f,r;
    
};
//==========================================
class Stack{
  private:
     int stk[SIZE]={0};
     int top=-1;
  public:
     bool isFull();
     bool isEmpty();
     void push(int elt);
     int pop();
};
//========================================
class Graph{
  private:
  int adj[SIZE][SIZE];
  int v,e,w;
  public:
  Graph(){
      fo(i,SIZE){
          fo(j,SIZE){
              adj[i][j]=0;
          }
      }
  }
  void addDist();
  void displayGraph();
  void displayBFS();
  void displayDFS();
  
};
//=======================================================================================
int main(){
    Graph ob;
    ob.addDist();
    //ob.displayGraph();
    ob.displayBFS();
    ob.displayDFS();
    
    return 0;
}

//======================================================================================
void Graph::addDist(){
    cin>>v>>e;
    fo(i,e){
        cin>>k>>j>>w;
        k--;
        j--;
        adj[k][j]=w;
        adj[j][k]=w;
        
    }
}
void Graph::displayGraph(){
    fo(i,v){
        fo(j,v){
            cout<<adj[i][j]<<"\t";
        }
        cout<<"\n";
    }
}
void Graph::displayBFS(){
    int visited[v]={0};
    int z=0;
    cout<<"BFS ";
    cin>>z;
    Queue q;
    z--;
    q.enQ(z);
    while(!q.isEmpty()){
        int x=q.deQ();
        if(visited[x]==1) continue;
        
        cout<<x+1<<" ";
        visited[x]=1;
        fo(i,v){
            if(adj[x][i]!=0&&visited[i]==0){
                q.enQ(i);
            }
        }
    }
    cout<<endl;
}

void Graph::displayDFS(){
 int visited[v]={0};
 int v1=0;
 cin>>v1;
 v1--;
 Stack s;
 s.push(v1);
 cout<<"DFS ";
 while(!s.isEmpty()){
  int x=s.pop();
  if(visited[x]==1) continue;
  cout<<x+1<<" ";
  visited[x]=1;
  for(int i=v-1;i>=0;i--){
   if(adj[x][i]!=0&&visited[i]==0){
       s.push(i);
   }
  }
 }
 cout<<endl;
}
//=======================================================================================
bool Queue::isFull(){
    if(r==SIZE-1) return true;
    else return false;
}

bool Queue::isEmpty(){
    if(f>r||f==-1) return true;
    else return false;
}

void Queue::enQ(int elt){
    if(isFull()) cout<<"Full\n";
    else{
        q[++r]=elt;
        if (f==-1) f=0;
    }
}

int Queue::deQ(){
    int x=-1;
    if(isEmpty()) cout<<"Empty\n";
    else{
         x=q[f];
         f++;
    }
    return x;
}
//====================================================================================
bool Stack::isFull(){
 if(top==SIZE-1) return true;
 return false;
}
bool Stack::isEmpty(){
 if(top==-1) return true;
 else return false;
}
void Stack::push(int elt){
 if(!isFull()){
  stk[++top]=elt;
 }
 else cout<<"Full ";
}
int Stack::pop(){
 if(!isEmpty()){
  top--;
  return stk[top+1];
 }
 else return -1;
}