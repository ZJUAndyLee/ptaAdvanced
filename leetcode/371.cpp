//两整数之和，运用位运算实现加法
   int getSum(int a, int b) {
        while(b!=0){
            int s=a^b;
            auto c=((unsigned)(a&b))<<1;
            a=s;
            b=c;
        }
        return a;
    }
//首先是进行位的异或运算也就是二进制下无需进位的运算，即每一位是不相同的情况就是1否则就是0
//然后进行且运算并且左移一位得到进位之后的结果也就是相加进位的结果两整数之和