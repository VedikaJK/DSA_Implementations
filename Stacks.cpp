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

class STACK{
private:
    vector <int> v;
public:
    int size(){
        return v.size();
    }
    bool isEmpty(){
        return v.size()==0;
    }
    void push(int data){
        v.push_back(data);
        return;
    }
    int pop(){
    	int tmp;
        if(!isEmpty()){
        	tmp=v[v.size()-1];
            v.pop_back();
            return tmp;
        }
        return -1;
    }
    int top(){
        if(!isEmpty()){
            return v[v.size()-1];
        }
        return -1;
    }
    void Display(){
        for(int i=v.size()-1;i>=0;i--){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
};



int main()
{
    STACK s;

	s.push(1);
	s.push(2);
	s.push(3);
    s.pop();
	s.push(4);
	s.push(5);
	s.push(6);
    s.pop();
    s.Display();
	cout << "Top element is: " << s.top() << endl;
	cout << "Stack size is " << s.size() << endl;

	s.pop();
    s.pop();
    s.pop();
    s.pop();
	if (s.isEmpty())
		cout << "Stack Is Empty\n";
	else
		cout << "Stack Is Not Empty\n";

  	return 0;
}
