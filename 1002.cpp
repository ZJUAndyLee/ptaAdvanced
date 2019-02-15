//测试点3没过应该是小数位数保留的问题

#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

struct poly {
        int exp;
        double coe;
};

struct sum {
        int exp;
        double coe;
        sum *ptr;
};

typedef sum *ssum;

void insert(ssum *p,double coe,int exp) {
        sum *tmp_p = new sum;
        sum *tp = new sum;
        tp->coe = coe;
        tp->exp = exp;
        tp->ptr = NULL;
        if (!(*p))*p = tp;
        else {
                tmp_p = *p;
                if (tp->exp > tmp_p->exp) {
                        tp->ptr = *p;
                        *p = tp;
                }
                else {
                        while (tmp_p->ptr) {
                                if (tp->exp > tmp_p->ptr->exp && tp->exp < tmp_p->exp) {
                                        tp->ptr = tmp_p->ptr;
                                        tmp_p->ptr = tp;
                                        break;
                                }
                                tmp_p = tmp_p->ptr;
                        }
                        if (tmp_p->ptr == NULL) {
                                if (tmp_p->exp > tp->exp) {
                                        tmp_p->ptr = tp;
                                }
                        }
                }
        }
}

int main() {
        int n, m, i, j;
        cin >> m;
        poly *tmp1 = new poly[m];
        for (i = 0; i < m; i++) {
                cin >> tmp1[i].exp >> tmp1[i].coe;
        }
        cin >> n;
        poly *tmp2 = new poly[n];
        for (i = 0; i < m; i++) {
                cin >> tmp2[i].exp >> tmp2[i].coe;
        }
        sum *p = new sum;
        p=NULL;
        sum *tmp_p;
        for (i = 0; i < m; i++) {
                for (j = 0; j < n; j++) {
                        if (tmp1[i].exp == tmp2[j].exp) {
                                insert(&p, tmp1[i].coe + tmp2[j].coe, tmp1[i].exp);
                                break;
                        }
                }
                if (j == n) {
                        insert(&p, tmp1[i].coe, tmp1[i].exp);
                }
        }
        for (j = 0; j < n; j++) {
                insert(&p, tmp2[j].coe, tmp2[j].exp);
        }
        int num=0;
        tmp_p=p;
        while(tmp_p){
                if(abs(tmp_p->coe) >= 0.05){
                num++;}
                tmp_p=tmp_p->ptr;
        }
        cout<<num;
        while (p) {
                if(abs(p->coe) >= 0.05){
                cout <<" "<<p->exp <<" " <<fixed<<setprecision(1)<< p->coe;}
                p = p->ptr;
        }
}
