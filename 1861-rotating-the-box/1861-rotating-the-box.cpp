class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size(), m = box[0].size();

        vector<vector<char>> res(m, vector<char>(n, '.'));

        for (int i = 0; i < n; i++) 
        {
            for (int j = m - 1; j >= 0; j--) 
            {
                if (box[i][j] == '#') 
                {
                    int k = j;
                    while (k + 1 < m && box[i][k + 1] == '.') 
                    {
                        swap(box[i][k], box[i][k + 1]);
                        k++;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                res[j][n - 1 - i] = box[i][j]; 
            }
        }

        return res;
    }
};
