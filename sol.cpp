int val = 1000000007;
class Solution {
public:
    vector<vector<vector<int>>> map;
    int max;
    int getRecord(int a, int l, int d) {
        if (d == max) { return 1; }
        if (map[a][l][d] == -1) {
            long tally = 0;
            if (a == 0) {
                tally += (getRecord(a + 1, 0, d + 1) % val);
            }
            if (l < 2) {
                tally += (long)(getRecord(a, l + 1, d + 1)  % val);
                tally = tally % val;
            }
            tally += (long)(getRecord(a, 0, d + 1)  % val);
            tally = tally % val;
            map[a][l][d] = tally;
        }
        return map[a][l][d];
    }
    int checkRecord(int n) {
        max = n;
        for (int a = 0; a < 2; a++) {
            vector<vector<int>> map1;
            for (int l = 0; l < 3; l++) {
                vector<int> map2;
                map2.resize(n, -1);
                map1.push_back(map2);
            }
            map.push_back(map1);
        }
        return getRecord(0, 0, 0);
    }
};
