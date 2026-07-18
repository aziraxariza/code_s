class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        const int max = n;
        vector<bool> isPrime(max + 1, true);

        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= max; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= max; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        int start = 1, end = n;
        vector<vector<int>> result;
        if (n == 1)
            return {};
        while (start <= end) {
            while (!isPrime[start])
                start++;
            while (!isPrime[end])
                end--;

            if (!(start <= end))
                return result;

            if (start + end == n)
                result.push_back({start++, end--});
            else if (start + end > n)
                end--;
            else
                start++;
        }
        return result;
    }
};