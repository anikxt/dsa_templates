#pragma GCC optimize "trapv"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define deb(x) cout << #x << "=" << x << endl
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long int ll;
//=======================
const int N = 2e6 + 13, M = N;
//=======================
int a[N];
int c, k, m, n, t, x, y;
//=======================

bool vis[100][100];
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

bool valid(int i, int j, int n, int m, vector<vector<int>> &v)
{
    return (i >= 0 and i < n and j >= 0 and j < n and v[i][j] == 1 and vis[i][j] == 0);
}

bool go(vector<vector<int>> &v, int sx, int sy, int n, int m)
{
    if (sx == n - 1 and sy == m - 1)
        return true;
    vis[sx][sy] = true;

    // auto valid = [&](int i, int j) -> bool
    // {
    //     return (i >= 0 and i < n and j >= 0 and j < n and v[i][j] == 1 and vis[i][j] == 0);
    // };
    // int ok = 0;
    // backtracking
    for (int k = 0; k < 4; ++k)
    {
        int newsx = sx + dx[k];
        int newsy = sy + dy[k];
        if (valid(newsx, newsy, n, m, v))
        {
            if (go(v, newsx, newsy, n, m))
                return true;
            // ok |= go(v, newsx, newsy, n, m);
        }
        // if (valid(newsx, newsy)) // LAMBDA FUNCTION
        // {
        //     if (go(v, newsx, newsy, n, m))
        //         return true;
        // }
    }
    return false;
    // return ok;
}

int main()
{
    blaze;
#ifndef ONLINE_JUDGE
    freopen("/media/blaze/Data/Ember/input.txt", "r", stdin);
    freopen("/media/blaze/Data/Ember/output.txt", "w", stdout);
#endif
    int r, c;
    cin >> r >> c;
    vector<vector<int>> v(r, vector<int>(c));
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
            cin >> v[i][j];
    }
    memset(vis, false, sizeof(vis));
    cout << go(v, 0, 0, r, c) << endl;
    return 0;
}

/* Test Case
4 4
1 0 0 0
1 1 1 0
0 1 1 0
1 1 1 1
*/
