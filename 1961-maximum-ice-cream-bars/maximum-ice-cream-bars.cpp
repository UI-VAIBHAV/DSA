class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int count=0;
        for(int num:costs){
            coins -= num;
            if(coins>=0) count++;
            else return count;
        }
        return count;
    }
};