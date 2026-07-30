class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0;

        for(int i = 0; i < word.size(); i++){
            ans += (i / 8) + 1;     // har 8 letters ke baad push cost +1
        }

        return ans;
    }
};;