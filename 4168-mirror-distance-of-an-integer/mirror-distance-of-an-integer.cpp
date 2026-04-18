class Solution {
public:
    int mirrorDistance(int n) {
        int num=0,temp=n;
        while(temp){
            int rem = temp%10;
            num = num*10 + rem;
            temp /= 10;
        }
        return abs(num-n);
    }
};