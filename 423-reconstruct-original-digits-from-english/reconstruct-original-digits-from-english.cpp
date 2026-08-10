class Solution { 
public:
    string originalDigits(string s) {
        vector<int> count(10);
        for(auto &ch : s){
            if(ch == 'z') count[0]++;
            if(ch == 'o') count[1]++;
            if(ch == 'w') count[2]++;
            if(ch == 'h') count[3]++;
            if(ch == 'u') count[4]++;
            if(ch == 'f') count[5]++;
            if(ch == 'x') count[6]++;
            if(ch == 's') count[7]++;
            if(ch == 'g') count[8]++;
            if(ch == 'i') count[9]++;
        }
        count[1] = count[1] - count[2] - count[4] - count[0];
        count[3] = count[3] - count[8];
        count[5] = count[5] - count[4];
        count[7] = count[7] - count[6];
        count[9] = count[9] - count[5] - count[6] - count[8];
        
        string ans = "";
        for(int i = 0; i < 10; i++){
            while(count[i] > 0){
                ans += to_string(i);
                count[i]--;
            }
        }
        return ans;
    }
};
/*
Taking letters:
0=z
1=o-[2]-[4]-[0]
2=w
3=h-[8]
4=u
5=f-[4]
6=x
7=s-[6]
8=g
9=i-[5]-[6]-[8]
--------
e-1,3,5,7,8,9.0
f-4,5
g-8
h-3,8
i-5,6,8,9
n-1,7,9
o-1,2,4,0
r-3,4,0
s-6,7
t-2,3,8
u-4
v-5,7
w-2
x-6
z-0
The even digits all have a unique letter while the odd digits all don't:
zero: Only digit with z
two: Only digit with w
four: Only digit with u
six: Only digit with x
eight: Only digit with g
*/