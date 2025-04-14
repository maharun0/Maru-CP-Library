// BFS
//           U  D  R   L   1   2   3  4
int dx[] = {-1, 1, 0,  0, -1, -1,  1, 1};
int dy[] = { 0, 0, 1, -1,  1, -1, -1, 1};

int n, m;
vector<vector<int>> grid, vis;

bool check(int x, int y) {
    return (x >= 0 and x < n) and (y >= 0 and y < m);
}

void bfs(int a, int b) {
    queue<pair<int, int>> q;
    vis[a][b] = 0;
    q.push({a, b});

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i], yy = y + dy[i];
            if (!check(xx, yy)) continue;

            if (grid[xx][yy] == 0 and vis[x][y] + 1 < vis[xx][yy]) {
                vis[xx][yy] = vis[x][y] + 1;
                q.push({xx, yy});
            }
        }
    } 
}

// prepare grid and vis
// cin >> n >> m;
// grid.assign(n, vector<int>(m, 0));
// vis.assign(n, vector<int>(m, (int)1e9));