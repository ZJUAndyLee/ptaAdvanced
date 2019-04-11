//这个题也是贪心思路 只要在对应被寻找的序列中尽可能靠前的找到对应的子序列的元素即可
class Solution {
public:
    bool isSubsequence(string s, string t) {
     int sSz=s.size(),tSz=t.size(),idx=-1;   
     for(int i=0;i<sSz;i++){
         idx++;
        while(idx<tSz){
            if(s[i]==t[idx]){
                break;
            }
            idx++;
        }
        if(idx==tSz) return false;
     }
    return true;
    }
};
