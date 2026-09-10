class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {

        set<string> food;
        set<int> tableNo;

        int n = orders.size();

        for (int i = 0; i < n; i++) {
            food.insert(orders[i][2]);

            int no = stoi(orders[i][1]);
            tableNo.insert(no);
        }

        map<string, int> mpFood;
        map<int, int> mpTableNo;

        int i = 0;

        for (auto& it : food) {
            mpFood[it] = i;
            i++;
        }

        i = 0;

        for (auto& it : tableNo) {
            mpTableNo[it] = i;
            i++;
        }

        vector<vector<string>> ans;
        vector<string> temp;
        temp.push_back("Table");
        for (auto& it : food)
            temp.push_back(it);

        ans.push_back(temp);

        int r = tableNo.size();
        int c = food.size();
        vector<vector<int>> val(r, vector<int>(c, 0));
        for (int i = 0; i < n; i++) {
            int tableNo = stoi(orders[i][1]);
            string foodType = orders[i][2];
            int row = mpTableNo[tableNo];
            int col = mpFood[foodType];
            val[row][col]++;
        }
        for (auto& it : mpTableNo) {
            string table = to_string(it.first);
            vector<string> temp;
            temp.push_back(table);
            for (int i = 0; i < c; i++) {
                string s = to_string(val[it.second][i]);
                temp.push_back(s);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};