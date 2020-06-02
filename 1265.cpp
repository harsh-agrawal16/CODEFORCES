#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

int main() {
    int t;
    cin >> t;
    forn(tt, t) {
        int n;
        cin >> n;
        map<int,int> c;
        forn(i, n) {
            int pi;
            cin >> pi;
            c[-pi]++;
        }
        vector<int> pp;
        for (auto p: c)
            pp.push_back(p.second);
        bool ok = false;
        int g = pp[0];
        int i = 1;
        int s = 0;
        while (s <= g && i < pp.size())
            s += pp[i++];
        if (g < s) {
           int b = 0;
           while (b <= g && i < pp.size())
               b += pp[i++];
           while (i < pp.size() && g + s + b + pp[i] <= n / 2)
               b += pp[i++];
           if (g < b && g + s + b <= n / 2) {
               ok = true;
               cout << g << " " << s << " " << b << endl;
           }
        }
        if (!ok)
            cout << 0 << " " << 0 << " " << 0 << endl;
    }
}