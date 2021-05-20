#pragma GCC optimize "trapv"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fab(a, b, i) for (int i = a; i <= b; ++i)
#define deb(x) cout << #x << "=" << x << endl
#define pb push_back
#define mp make_pair
#define f first
#define se second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define endl '\n'
#define blaze ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long int ll;
//=======================
const int N = 2e6 + 13, M = N;
//=======================
int a[N];
int c, k, m, n, t, x, y;
//=======================

void primeCheck(int n)
{
    if (n == 1)
    {
        cout << "Not Prime" << endl;
        return;
    }
    else if (n == 2 or n == 3)
    {
        cout << "Prime" << endl;
        return;
    }
    vector<int> a;
    a.push_back(1);
    fab(1, sqrt(n), i)
    {
        if (n % i == 0)
        {
            if (i == n / i)
            {
                a.push_back(i);
            }
            else
            {
                a.push_back(i);
                a.push_back(n / i);
            }
        }
    }
    if (a.size() > 2)
        cout << "Not Prime" << endl;
    else
        cout << "Prime" << endl;
    return;
}

int main()
{
    blaze;
    int n;
    cin >> n;
    primeCheck(n);
    return 0;
}