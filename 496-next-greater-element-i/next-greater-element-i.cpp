class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st; // nums2 ke elements store karega peeche se
        unordered_map<int, int> nxt; // ele --> nge se map karne ke liye; nums2 ke saaro ke nge map karlo nums1 subset hai toh req. hum nikal lenge  map se

        for(int i = nums2.size()-1; i >= 0; i--){ // right to left traverse agar right se ele chahiye

            while(!st.empty() && st.top() < nums2[i]){ // top chhota hai nums2[i] se
                st.pop(); // nikalte raho jab tak bada na aaye cur se
            }
            if(st.empty()){ // st khaali hai yaani curr se bada nahi mila right side koi
                nxt[nums2[i]] = -1;
            }
            else{
                nxt[nums2[i]] = st.top(); // cur ke right mein ye sabse paas mein bada hai
            }
            st.push(nums2[i]); // curr ko ab add in st so that ye right mein aaye curr - 1 ele ke liye
        }
        vector<int> ans; // final ans
        for(int x : nums1){ // nums1 ke eles ke sirf nge chahiye
            ans.push_back(nxt[x]); // unhe hum nxt se extract karenge
        }

        return ans;
    }
};