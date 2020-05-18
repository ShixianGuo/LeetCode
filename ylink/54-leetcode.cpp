class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty())
        {
            return vector<int>();
        }
        const int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool>> printed(m);
        for(auto& e : printed)
        {
            e.resize(n);
        }
        int i = 0, j = 0;
        int status = 0;
        vector<int> res;
        for(;;)
        {
            if(canbeprint(matrix, printed, i, j))
            {
                res.push_back(matrix[i][j]);
                printed[i][j] = true;
                switch (status % 4)
                {
                    case 0: j++; break;
                    case 1: i++; break;
                    case 2: j--; break;
                    case 3: i--; break;
                }
            }
            else
            {
                switch (status % 4)
                {
                    case 0: j--; i++; break;
                    case 1: i--; j--; break;
                    case 2: j++; i--; break;
                    case 3: i++; j++; break;
                }
                if(!canbeprint(matrix, printed, i, j))
                {
                    break;
                }
                else
                {
                    status++;
                }
            }
        }
        return res;
    }
     
    bool canbeprint(const vector<vector<int>>& matrix,
                   const vector<vector<bool>>& printed,
                   const int ipos, const int jpos)
    {
        if(ipos < 0 || jpos < 0 || ipos >= matrix.size() || jpos >= matrix[0].size())
        {
            return false;
        }
        else if(printed[ipos][jpos])
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};
