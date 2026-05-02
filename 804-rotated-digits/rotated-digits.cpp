class Solution {
public:
    bool good(int num){
        bool change=0;
        while(num>0){
            int rem = num%10;
            if(rem==3||rem==4||rem==7) return false;
            if(rem==2||rem==5||rem==6||rem==9) change = 1;
            num /= 10;
        }
        return change;
    }
    int rotatedDigits(int n) {
        int count=0;
        for(int i=2;i<=n;i++){
            if(good(i)) count++;
        }
        return count;
    }
};