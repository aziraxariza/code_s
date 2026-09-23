class Solution {
public:
    int dayOfYear(string date) {
        vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int yr = stoi(date.substr(0,4));
        if(yr%4 == 0 && yr%100 != 0 || yr%400 == 0){
            days[1] = 29; // leap year
        }

        int ans = 0;

        int month = stoi(date.substr(5,2)); // kaunsa mahina
        int addDays = stoi(date.substr(8,2));

        if(month == 1) return addDays; // for jan
        for(int i = 0; i < month-1; i++){
            ans += days[i];
        }
        ans += addDays;

        return ans;
    }
};