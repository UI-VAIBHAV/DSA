class Solution {
public:
    bool checkPerfectNumber(int num) {
        int ans=num;
        for(int i=1;i<=num/2;i++){
            if(num%i==0){
                ans -= i;
            }
        }
        if(ans==0){
            return true;
        }
        return false;
    }
};