//1st approach
//O(n*m+n*m) and O(n) space
// void zeroRowCol(vector<vector<int>>&v,vector<vector<int>> matrix,vector<pair<int,int>>vec)
// {
//     for(int i=0;i<vec.size();i++)
//     {
//         for(int j=0;j<matrix[0].size();j++)
//             v[vec[i].first][j]=0;
        
//         for(int k=0;k<matrix.size();k++)
//             v[k][vec[i].second]=0;
//     }
// }

// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         vector<vector<int>>v=matrix;
        
//         for(int i=0;i<matrix.size();i++)
//         {
//             vector<pair<int,int>>vec;
//             for(int j=0;j<matrix[0].size();j++)
//             {
//                 if(matrix[i][j]==0)
//                     vec.push_back(make_pair(i,j));
//             }
//             zeroRowCol(v,matrix,vec);
//             vec.clear();
//         }
        
//         matrix=v;
//     }
// };



class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int col0=1;
        
        for(int i=0;i<rows;i++)
        {
            if(matrix[i][0]==0)
                col0=0;
            for(int j=1;j<cols;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        
        for(int i=rows-1;i>=0;i--)
        { 
            for(int j=cols-1;j>=1;j--)
            {
                if(matrix[i][0]==0 || matrix[0][j]==0)
                    matrix[i][j]=0;
            }
            
            if(col0==0)
                matrix[i][0]=0;
        }
        
    }
};
