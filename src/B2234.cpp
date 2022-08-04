#include <bits/stdc++.h>

using namespace std;
typedef long long ll;  //-2^63 ~ 2^63-1
typedef unsigned long long llu;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<string, int> psi;
typedef pair<int, char> pic;
int INF = 1e9 + 7;
//512MB = 1.2억개 int
//if(nx<0||nx>=n||ny<0||ny>=m) continue;
/*int dz[6]={1,-1,0,0,0,0};
int dx[6]={0,0,1,-1,0,0};
int dy[6]={0,0,0,0,1,-1};*/ // 3차원 bfs
#define X first
#define Y second
// 서쪽, 북쪽, 동쪽, 남쪽 순서로 방문
/**
 * 서쪽, 북쪽, 동쪽, 남쪽 순서로 방문
 * 1. 이 성에 있는 방의 개수
 * 2. 가장 넓은 방의 넓이
 * 3. 하나의 벽을 제거하여 얻을 수 있는 가장 넓은 방의 크기
 */
int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};
int m,n;
int board[52][52];
bool vis[52][52];
int roomCnt, maxRoomSize;
int bfs(int i, int j) {
    queue<pair<int,int>> q;
    q.push({i, j});
    vis[i][j] = 1;
    int size = 1;
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (board[cur.X][cur.Y] & 1 << dir) continue;
            if (vis[nx][ny]) continue;
            vis[nx][ny] = 1;
            q.push({nx, ny});
            size++;
        }
    }
    return size;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j]) {
                maxRoomSize = max(maxRoomSize, bfs(i, j));
                roomCnt++;
            }
        }
    }
    cout << roomCnt << '\n';
    cout << maxRoomSize << '\n';

    // 3. 하나의 벽을 제거하여 얻을 수 있는 가장 넓은 방의 크기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int dir = 0; dir < 4; dir++) {
                memset(vis, false, sizeof(vis));
                board[i][j] = board[i][j] - (1 << dir); // 벽을 제거
                maxRoomSize = max(maxRoomSize, bfs(i, j));
                board[i][j] = board[i][j] + (1 << dir); // 벽을 다시 복구
            }
        }
    }
    cout << maxRoomSize << '\n';


    return 0;
}