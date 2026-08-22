class Solution {
public:
    bool checkDivisibility(int n) {
        int num1=0,num2=1;
        int temp = n;
        while(temp){
            num1 += temp%10;
            num2 *= temp%10;
            temp /= 10;
        }
        int num = num1+num2;
        if(n%num==0) return true;
        return false;
    }
};