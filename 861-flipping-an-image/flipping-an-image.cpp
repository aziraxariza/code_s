class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size(); // no. of rows and cols

        for(int i = 0; i < n; i++){ // har row ko traverse
            int l = 0; // first col
            int r = n-1; // last col

            while(l < r){
                swap(image[i][l], image[i][r]); // reverse
                l++;
                r--;
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                image[i][j] = 1 - image[i][j]; // values ulti karo 
            }
        }
        return image;
    }
};