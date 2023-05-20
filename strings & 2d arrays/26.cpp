// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int matrixSize = matrix.size();
        if(!matrixSize) return;
        
        for(int i = 0; i < matrixSize; i++)
        {   reverse(matrix[i].begin(), matrix[i].end());    }
        
        for(int i = 0; i < matrixSize; i++ )
        {
            for(int j = 0; j < (matrixSize - i - 1); j++)
            {   swap(matrix[i][j], matrix[matrixSize - j - 1][matrixSize - i - 1]); }
        }
    }
};