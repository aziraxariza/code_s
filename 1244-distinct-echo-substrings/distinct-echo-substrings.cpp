class Solution {
public:
    int distinctEchoSubstrings(string text) {
        int n = text.size();
        const long long M1 = 1000000007LL, B1 = 131LL;
        const long long M2 = 998244353LL, B2 = 137LL;

        vector<long long> h1(n + 1, 0), h2(n + 1, 0);
        vector<long long> p1(n + 1, 1), p2(n + 1, 1);

        for (int i = 0; i < n; i++) {
            int c = text[i] - 'a' + 1;
            h1[i + 1] = (h1[i] * B1 + c) % M1;
            h2[i + 1] = (h2[i] * B2 + c) % M2;
            p1[i + 1] = (p1[i] * B1) % M1;
            p2[i + 1] = (p2[i] * B2) % M2;
        }

        auto get1 = [&](int l, int r) -> long long { // inclusive, 0-indexed
            long long res = (h1[r + 1] - h1[l] * p1[r - l + 1]) % M1;
            return res < 0 ? res + M1 : res;
        };
        auto get2 = [&](int l, int r) -> long long {
            long long res = (h2[r + 1] - h2[l] * p2[r - l + 1]) % M2;
            return res < 0 ? res + M2 : res;
        };

        unordered_set<unsigned long long> seen;
        seen.reserve(n * 2);

        for (int L = 1; 2 * L <= n; L++) {
            for (int i = 0; i + 2 * L - 1 < n; i++) {
                int mid = i + L;
                int end = i + 2 * L - 1;
                if (get1(i, mid - 1) == get1(mid, end) &&
                    get2(i, mid - 1) == get2(mid, end)) {
                    unsigned long long key =
                        (unsigned long long)get1(i, end) * (unsigned long long)M2 +
                        (unsigned long long)get2(i, end);
                    seen.insert(key);
                }
            }
        }

        return (int)seen.size();
    }
};