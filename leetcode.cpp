class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prevRowCount = 0;
        int total = 0;

        for (int i = 0; i < bank.size(); i++)
        {
            int curRowCount = 0;
            for (int j = 0; j < bank[i].length(); j++)
            {
                if (bank[i][j] == '1')
                    curRowCount++;

            }

            if (curRowCount == 0)
                continue;

            total += curRowCount * prevRowCount;
            prevRowCount = curRowCount;
        }
        return total;
    }
};