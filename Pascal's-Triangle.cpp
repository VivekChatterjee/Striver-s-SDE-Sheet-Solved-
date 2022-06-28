class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int c=1;
        
        vector<vector<int>>v;
        
        
        for(int i=0;i<numRows;i++)
        {
            vector<int>vec(i);
            vec[0]=vec[i]=1;
            
            for(int j=1;j<i-1;j++)
            {
                vec[j]=v[i-1-1][j-1]+v[i-1-1][j];
            }
            
            v.push_back(vec);            
            vec.clear();
        }
        
        return v;
    }
};
