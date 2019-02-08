#include<iostream>
#include<stack>
using namespace std;

int main(){
    int a,b,sum,yu,i=1;
    char ch;
    stack<char> num;
    cin>>a>>b;
    sum=a+b;
    if(sum<0){
        cout<<'-';
        sum=-sum;
    }
    while(sum/10){
        yu=sum%10;
        ch='0'+yu;
        num.push(ch);
        sum=sum/10;
    }
    num.push('0'+sum);
    while(!num.empty()){
        ch=num.top();
        num.pop();
        cout<<ch;
        i=num.size();
        if(i%3==0&& i!=0)cout<<',';
    }
}
