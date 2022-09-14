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
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n,m, ans;
const int MX = 52;
char board[MX][MX];
bool vis[MX][MX][4][2][2];
pair<int, int> start; // 시작 좌표
struct Move {
    int x;
    int y;
    int cnt;
    int dir;
    bool cVisit;
    bool dVisit;
};
void bfs() {
    queue<Move> q;
    q.push({start.X, start.Y, 0, -1, 0, 0});
    vis[start.X][start.Y][4][0][0] = 1;
    while (!q.empty()) {
        auto [x, y, cnt ,dir , cVisit, dVisit] = q.front();
        q.pop();

        if (cVisit == 1 && dVisit == 1) {
            ans = cnt;
            return;
        }

        for (int i = 0; i < 4; i++) {
            if (i == dir) continue;
            int nx = x + dx[i];
            int ny = y + dy[i];
            bool ncVisit = cVisit;
            bool ndVisit = dVisit;

            // if (nx <0 || ny < 0 || nx >= n || ny >= m) continue;
            if (nx < n && ny < m && nx >= 0 && ny >= 0) {
                if (!vis[nx][ny][i][cVisit][dVisit] && board[nx][ny] != '#') {
                    if (board[nx][ny] == 'C') ncVisit = 1;
                    if (board[nx][ny] == 'D') ndVisit = 1;

                    vis[nx][ny][i][ncVisit][ndVisit] = 1;
                    q.push({nx, ny, cnt + 1, i, ncVisit, ndVisit});
                }
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'S') {
                start.X = i;
                start.Y = j;
                board[i][j] = '.';
            }
            else if (board[i][j] == 'C') {
                idx++;
                if (idx == 2) {
                    board[i][j] = 'D';
                }
            }
        }
    }

    bfs();
    if (ans == 0) cout << -1;
    else cout << ans;

    return 0;
}