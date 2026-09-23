class Solution {
public:
    int largestInteger(int num) {
        string s = to_string(num);

        vector<int> even, odd;

        for(char c : s){
            int x = c - '0'; // take num

            if(x % 2 == 0) even.push_back(x);
            else odd.push_back(x); // acc to odd even
        }

        sort(even.rbegin(), even.rend());
        sort(odd.rbegin(), odd.rend()); // sort all odds and evens

        int e = 0, o = 0;

        for(char &c : s){
            int x = c - '0';

            if(x % 2 == 0)
                c = even[e++] + '0'; // even ke liye even lo and move e frwrd
            else
                c = odd[o++] + '0';
        }

        return stoi(s);
    }
};