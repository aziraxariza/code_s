class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        // bas pata lagao isme jo smallestOdd no. hai jo har even se chhota hona chahiye

        int mn = INT_MAX;
        int odd = 0; // if any odd found or not
        for(int x : nums1){
            if(x%2 == 1){
                mn = min(mn, x); // sabse chhota odd pakda
                odd++; // odd no. mila
            }  
        }

        if(odd == 0) return true; // full even arr

        for(int x : nums1){
            if(x%2 == 0 && x < mn){
                return false; // even no. hai aur mn se chhota nikla i.e e-odd < 1 hoga 
            }
        }
        return true;
    }
};