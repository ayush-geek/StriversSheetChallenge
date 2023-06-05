class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        // using 1st row and 1st col to mark
        int fgr = 0;
        int fgc = 0;

        // Explicit 1st row
        for (int j = 0; j < m; j++)
        {
            if (matrix[0][j] == 0)
                fgr = 1;
        }

        // expliict checking for 1st col
        for (int i = 0; i < n; i++)
        {
            if (matrix[i][0] == 0)
                fgc = 1;
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = n - 1; i >= 1; i--)
        {
            for (int j = m - 1; j >= 1; j--)
            {
                if (matrix[0][j] == 0 || matrix[i][0] == 0)
                    matrix[i][j] = 0;
            }
        }

        if (fgr == 1)
        {
            for (int j = 0; j < m; j++)
            {
                matrix[0][j] = 0;
            }
        }

        if (fgc == 1)
        {
            for (int i = 0; i < n; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};