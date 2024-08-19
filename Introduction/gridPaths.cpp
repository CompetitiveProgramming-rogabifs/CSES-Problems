#include <bits/stdc++.h>
using namespace std;

bool isValid(int x, int y, int n, bool visited[7][7]) {
    return (x >= 0 && x < n && y >= 0 && y < n && !visited[x][y]);
}

void backtrack(string &path, char dir[],int n, int x, int y, int idx, bool visited[7][7], int& result) {
    if (idx + abs(x - (n - 1)) + abs(y - 0) > 48) return;
    
    if(x == n - 1 && y == 0) {
        if (idx == 48) result++;
        return;
    }

    if(idx == 48) return;
    visited[x][y] = true;

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    if(path[idx] == '?') {
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(isValid(nx,ny,n,visited))
            backtrack(path, dir,n, nx,ny,idx+1, visited,result);
        }
    } else {
        for(int i = 0; i < 4; i++) {
            if(path[idx] == dir[i]) {
                int nx = x + dx[i], ny = y + dy[i];
                if(isValid(nx,ny,n,visited))
                backtrack(path, dir,n, nx,ny,idx+1, visited,result);
            }
        }
    }

    visited[x][y] = false;
}




int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 7, result = 0;
    bool visited[7][7] = {false};

    char dir[] = {'D', 'U', 'R', 'L'};


    string in;
    cin >> in;

    backtrack(in,dir,n,0,0,0,visited, result);

    cout << result << endl;

    return 0;
}