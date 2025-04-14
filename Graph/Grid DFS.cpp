// DFS
//           U  D  R   L   1   2   3  4
int dx[] = {-1, 1, 0,  0, -1, -1,  1, 1};
int dy[] = { 0, 0, 1, -1,  1, -1, -1, 1};

int n, m;
vector<vector<int>> grid, vis;

bool check(int x, int y) {
    return (x >= 0 and x < n) and (y >= 0 and y < m);
}

int dfs(int x, int y) {
    if (grid[x][y] == 0) return 0;

    vis[x][y] = 1;
    int count = 1;

    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i], yy = y + dy[i];

        if (!vis[xx][yy])
            count += dfs(xx, yy);
    }

    return count;
}

// prepare grid and vis
// cin >> n >> m;
// grid.assign(n, vector<int>(m, 0));
// vis.assign(n, vector<int>(m, 0));