#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int Num,idx;

//cin cout 超时只能用C的格式化输入输出 

struct person{
    int Id,grade;
    string name;
    person(int n,string str,int g):Id(n),name(str),grade(g){

    };
    
};

bool cmp(person &p1,person &p2){
    return p1.Id>p2.Id?false:true;
}

void Input(vector<person> &vec){
    scanf("%d %d",&Num,&idx);
    for(int i=0;i<Num;i++){
        int id,gra;
        char s[10];
        string str;
        scanf("%d %s %d",&id,s,&gra);
        str=s;//可以直接将char[]类型转换为string
        vec.push_back(person(id,str,gra));
    }
    //cout<<endl;
}

void ListSorting(vector<person> &vec){
  if(idx==1){
        sort(vec.begin(),vec.end(),cmp);
        for(auto x:vec){
            printf("%06d %s %d\n",x.Id,x.name.c_str(),x.grade);
        }
    }
    else if(idx==2){
        map<string,vector<person>> mp1;
        for(auto &x:vec){
            mp1[x.name].push_back(x);
        }
        for(auto &x:mp1){
            sort(x.second.begin(),x.second.end(),cmp);
            for(auto y:x.second){
                printf("%06d %s %d\n",y.Id,y.name.c_str(),y.grade);//格式化输出必须将string 转换为char[] 调用c_str()函数
            }
        }
    }
    else if(idx==3){
        map<int,vector<person>> mp2;
        for(auto &x:vec){
            mp2[x.grade].push_back(x);
        }
        for(auto &x:mp2){
            sort(x.second.begin(),x.second.end(),cmp);
            for(auto y:x.second){
                printf("%06d %s %d\n",y.Id,y.name.c_str(),y.grade);
            }
        }
    }
} 

int main(){
    vector<person> v;
    Input(v);
    ListSorting(v);
}
