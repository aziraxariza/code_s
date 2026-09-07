class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0; // initially no profir
        int buy = prices[0]; // initially first val buy kiya

        for(int r = 1; r < prices.size(); r++){
            int sell = prices[r];

            maxProfit = max(maxProfit, sell-buy);
            if(sell < buy){
                buy = sell; // kum daam humara buy hoga
            }
        }
        return maxProfit;
    }
}; 

/* brute force mein do for loops chalaye i -> 0 to n-2 and j -> i+1 to n-1 jisse profit max aaya woh ans*/