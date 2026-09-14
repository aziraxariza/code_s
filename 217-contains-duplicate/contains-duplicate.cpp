class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st; // single freq rahegi har ek ki 
        for(int x : nums){
            if(st.count(x)){ // check karo alr hai kya andar st mein
                return true;
            }
            st.insert(x); // nahi tha set mein so dalo
        }
        return false;
    }
};