#include <bits/stdc++.h>

using namespace std;

set<pair<int, int>> solu;
char arr[1000][1000];


void dfs(int i, int j, int n, int m) {
    bool visited[1000][1000] = {false};
    stack<pair<int, int>> stack;
    visited[i][j] = true;
    stack.push({i, j});
    while (!stack.empty()) {
        pair<int, int> cur = stack.top();
        stack.pop();
        if (cur.first > 0 && cur.second < m - 1 && arr[cur.first - 1][cur.second] == '-') { //bala
            if (!visited[cur.first - 1][cur.second]) {
                visited[cur.first - 1][cur.second] = true;
                stack.push({cur.first - 1, cur.second});
                solu.insert({cur.first - 1, cur.second});
            }
        }
        if (cur.first < n - 1 && cur.second < m - 1 && arr[cur.first + 1][cur.second] == '-') { //payin
            if (!visited[cur.first + 1][cur.second]) {
                visited[cur.first + 1][cur.second] = true;
                stack.push({cur.first + 1, cur.second});
                solu.insert({cur.first + 1, cur.second});
            }
        }
        if (cur.second > 0 && arr[cur.first][cur.second - 1] == '-') { //chap
            if (!visited[cur.first][cur.second - 1]) {
                visited[cur.first][cur.second - 1] = true;
                stack.push({cur.first, cur.second - 1});
                solu.insert({cur.first, cur.second - 1});
            }
        }
        if (cur.second < m - 2 && arr[cur.first][cur.second + 1] == '-') { //rast
            if (!visited[cur.first][cur.second + 1]) {
                visited[cur.first][cur.second + 1] = true;
                stack.push({cur.first, cur.second + 1});
                solu.insert({cur.first, cur.second + 1});
            }
        }

    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char ch;
            cin >> ch;
            arr[i][j] = ch;
        }
    }

    for (int i = 0; i < n; i++) {
        if (arr[i][m - 1] == '-') {
            dfs(i, m - 1, n, m);
        }
    }
    cout << solu.size();

    return 0;
}
