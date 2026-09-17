class Solution { //nums1 walo ke liye nge nikalo nums2 se
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st; //nums2 ke eles peeche se jayenge
        unordered_map<int, int> mp; // sab ele -> uska nge // mp[ele] = nge

        for(int i = nums2.size()-1; i >= 0; i--){

            while(!st.empty() && st.top() < nums2[i]){
                st.pop(); // didnt clear the nge criteria
            }
            if(st.empty()){
                mp[nums2[i]] = -1; // has no nge
            }
            else{
                mp[nums2[i]] = st.top(); // nge mil gaya
            }
            st.push(nums2[i]); // push to st
        }

        vector<int> ans; // ans for each x in nums1
        for(int x : nums1){ // sirf nums1 ke nums ki nge chahiye
            ans.push_back(mp[x]);
        }
        return ans;
    }
};