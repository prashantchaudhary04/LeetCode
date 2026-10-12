
class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].size();
        int sr = 0, sc = 0, cnt = 0;

        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                } else if (classroom[i][j] == 'L') {
                    id[i][j] = cnt++;
                }
            }
        }

        if (cnt == 0)
            return 0;

        int fullMask = (1 << cnt) - 1;
        vector<vector<vector<vector<bool>>>> vis(
            m, vector<vector<vector<bool>>>(
                   n, vector<vector<bool>>(energy + 1,
                                           vector<bool>(1 << cnt, false))));

        queue<array<int, 5>> q;
        q.push({sr, sc, energy, fullMask, 0});
        vis[sr][sc][energy][fullMask] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r, c, e, mask, moves] = q.front();
            q.pop();

            if (mask == 0)
                return moves;
            if (e == 0)
                continue;

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n ||
                    classroom[nr][nc] == 'X') {
                    continue;
                }

                int ne = classroom[nr][nc] == 'R' ? energy : e - 1;
                int nm = mask;

                if (classroom[nr][nc] == 'L') {
                    nm &= ~(1 << id[nr][nc]);
                }

                if (!vis[nr][nc][ne][nm]) {
                    vis[nr][nc][ne][nm] = true;
                    q.push({nr, nc, ne, nm, moves + 1});
                }
            }
        }

        return -1;
    }
};
