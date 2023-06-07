class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {

        int n = matrix.size();
        int m = matrix[0].size();

        int l = 0;
        int h = n * m - 1;
        while (l <= h)
        {
            int mid = (l + h) / 2;

            int nr = mid / m;
            int nc = mid % m;

            if (matrix[nr][nc] == target)
            {
                return true;
            }
            else if (matrix[nr][nc] < target)
            {
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }
        return false;
    }
};