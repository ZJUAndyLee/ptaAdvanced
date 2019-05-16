#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int Num1,Num2;

//卡内存 只能读一组数然后再求中位数 中位数的定义与传统的不同要注意

int main(){
    scanf("%d",&Num1);
    queue<int> v1;
    for(int i=0;i<Num1;i++){
        int tmp;
        scanf(" %d",&tmp);
        v1.push(tmp);
    }
    scanf("%d",&Num2);
    int ct=0,res=0;
    int tmpi=(Num1+Num2+1)/2;
    for(int i=0;i<Num2;i++){
        int n;
        scanf(" %d",&n);
        if(ct<tmpi){
            while(!v1.empty()&&v1.front()<n){
                ct++;
                if(ct==tmpi){
                    res=v1.front();
                }
                v1.pop();
            }  
        }
        ct++;
        if(ct==tmpi){
            res=n;
        }
    }
    if(ct<tmpi){
        while(!v1.empty()){
            ct++;
            if(ct==tmpi){
                res=v1.front();
                break;
            }
            v1.pop();
        }
    }
    cout<<res;
  
}
