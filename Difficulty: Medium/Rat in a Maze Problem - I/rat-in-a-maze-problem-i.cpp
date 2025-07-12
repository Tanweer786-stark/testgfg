class Solution {
private:
    bool isSafe(int x, int y, int n, vector<vector<int>> &visited, vector<vector<int>> &maze) {
        return (x >= 0 && y >= 0 && x < n && y < n && visited[x][y] == 0 && maze[x][y] == 1);
    }

    void solve(vector<vector<int>> &maze, int n, vector<string>& ans, int x, int y, vector<vector<int>> &visited, string path) {
        if (x == n - 1 && y == n - 1) {
            ans.push_back(path);
            return;
        }

        visited[x][y] = 1;

        // Down
        int newx = x + 1, newy = y;
        if (isSafe(newx, newy, n, visited, maze)) {
            path.push_back('D');
            solve(maze, n, ans, newx, newy, visited, path);
            path.pop_back();
        }

        // Left
        newx = x, newy = y - 1;
        if (isSafe(newx, newy, n, visited, maze)) {
            path.push_back('L');
            solve(maze, n, ans, newx, newy, visited, path);
            path.pop_back();
        }

        // Right
        newx = x, newy = y + 1;
        if (isSafe(newx, newy, n, visited, maze)) {
            path.push_back('R');
            solve(maze, n, ans, newx, newy, visited, path);
            path.pop_back();
        }

        // Up
        newx = x - 1, newy = y;
        if (isSafe(newx, newy, n, visited, maze)) {
            path.push_back('U');
            solve(maze, n, ans, newx, newy, visited, path);
            path.pop_back();
        }

        visited[x][y] = 0;  // Backtrack
    }

public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> ans;
        int n = maze.size();

        if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0)
            return ans;

        vector<vector<int>> visited(n, vector<int>(n, 0));
        string path = "";
        solve(maze, n, ans, 0, 0, visited, path);
        sort(ans.begin(), ans.end());
        return ans;
    }
};