#include<iostream>
#include<stack>
using namespace std;

void exchang(int num){
    stack<int> sk;
    int ct=0;
    while(ct<2){
        sk.push(num%13);
        num=num/13;
        ct++;
    }
    while(!sk.empty()){
        int tmp=sk.top();
        sk.pop();
        if(tmp<10)
            cout<<tmp;
        else{
            char c='A'+tmp-10;
            cout<<c;    
        }
    }
}

int main(){
    int r,g,b;
    cin>>r>>g>>b;
    cout<<"#";
    exchang(r),exchang(g),exchang(b);
}
