class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;
        int n = nums.size();

        arr1.push_back(nums[0]); // 1st operation
        arr2.push_back(nums[1]); // 2nd operation

        for(int i = 2; i < n; i++){
            if(arr1[arr1.size()-1] > arr2[arr2.size()-1]){
                arr1.push_back(nums[i]); // rule2
            }
            else{
                arr2.push_back(nums[i]);
            }
        }
        arr1.insert(arr1.end(), arr2.begin(), arr2.end()); // added arr2 to arr1's end
        return arr1; 
    }
};