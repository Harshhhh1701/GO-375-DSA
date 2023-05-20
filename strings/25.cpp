//spiral matrix

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int row = matrix.size();
        if (row == 0)
            return ret;
        int col = matrix[0].size();
        if (col == 0)
            return ret;
            
        vector<vector<int>> isVisit(row, vector<int>(col, 0));
        int i = 0, j = 0;
        
        while (i >= 0 && i < row && j >= 0 && j < col && isVisit[i][j] == 0)
        {
            //toward right
            while (j < col && isVisit[i][j] == 0)
            {
                isVisit[i][j] = 1;
                ret.push_back(matrix[i][j++]);
            }
            j--;
            i++;
            
            //toward down
            while (i < row && isVisit[i][j] == 0)
            {
                isVisit[i][j] = 1;
                ret.push_back(matrix[i++][j]);
            }
            i--;
            j--;
                
            //toward left
            while (j >= 0 && isVisit[i][j] == 0)
            {
                isVisit[i][j] = 1;
                ret.push_back(matrix[i][j--]);
            }
            j++;
            i--;
            
            //toward up
            while (i >= 0 && isVisit[i][j] == 0)
            {
                isVisit[i][j] = 1;
                ret.push_back(matrix[i--][j]);
            }
            i++;
            j++;
        }
        
        return ret;
    }
};