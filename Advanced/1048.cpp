//两数之和 经典哈希思路题

#include<stdio.h>
#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<algorithm>
#include<unordered_set>
using namespace std;

int num, val;
vector<int> M;

void Input() {
	scanf("%d %d", &num, &val);
	for (int i = 0; i < num; i++) {
		int tmpi;
        scanf("%d", &tmpi);
        M.push_back(tmpi);
	}
}

void StudentListforCourse() {
   int MINnum = 100000;
   unordered_set<int> hs;
   pair<int,int> res(MINnum,MINnum);
   for(auto x:M){
       int tmp=val - x;
       if(hs.find(tmp)!=hs.end()){
            tmp = tmp<x?tmp:x;
            if(tmp<res.first){
                res.first=tmp;
                res.second = val-tmp;
            }
       }
       hs.insert(x);
   }
   if(res.first<MINnum){
       cout<<res.first<<" "<<res.second;
   }
   else
       cout<<"No Solution";
}




int main() {
	Input();
	StudentListforCourse();
	//system("pause");
}
