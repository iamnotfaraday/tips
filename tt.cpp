#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;

struct DSU {
    // 用法: DSU dsu(n);
    std::vector<int > s, sz1, sz2; // sz1并查集点的数量, sz2边的数量
    DSU(int n) : s(n + 1), sz1(n + 1, 1), sz2(n + 1, 0) {
        iota(s.begin(), s.end(), 0);
    }

    int find(int x) {
        return x == s[x] ? x : s[x] = find(s[x]);
    }

    bool merge(int x, int y) {
        int xx = find(x), yy = find(y);
        // 以xx作为父亲, 那么xx下的边数增加1
        sz2[xx] += 1;
        if(xx == yy) {
            return false;
        }
        // 这里判断一下大小, 我们将小的给大的
        if(sz1[xx] < sz2[yy]) {
            std::swap(xx, yy);
        }
        sz1[xx] += sz1[yy];
        sz2[xx] += sz2[yy];
        s[yy] = xx;
        return true;
    }
};


int main() {
    IOS
    
}