#include <bits/stdc++.h>
using namespace std;

using ci = const int;
using llint = long long;
using vi = vector <int>;
using vb = vector <bool>;

#define all(c) c.begin(), c.end()
#define ms(name,val) memset(name, val, sizeof name)


ci MX = 300005;
bool isOver[MX]; // is it finished by operation 2
int unreadCnt[MX];
deque <int> notif;
vector <list <int>> id;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q, ans = 0, lastRead = -1;
    cin >> n >> q;
    id.resize(n+1);

    while (q)
    {
        --q;
        int type, x;
        cin >> type >> x;

        // application x generates a notification
        if (type == 1)
        {
            ++unreadCnt[x];
            ++ans; // number of unread notifications
            notif.push_back(x);
            id[x].push_back(notif.size()-1);
        }
        else if (type == 2)
        {
            // read all notifications generated
            // so far by application x
            ans -= unreadCnt[x];
            unreadCnt[x] = 0;

            while (!id[x].empty())
            {
                int i = id[x].back();
                isOver[i] = 1;
                id[x].pop_back();
            }
        }
        else
        {
            // read first x notifications generated
            // by phone applications
            if (lastRead+1 >= x)
            {
                cout << ans << '\n';
                continue;
            }

            for (int i = lastRead+1; i < x; ++i)
            {
                if (isOver[i]) continue;
                // read notif[i]
                --unreadCnt[notif[i]];
                --ans;

                int x = notif[i];

                // remove indices because notification is read
                while (!id[x].empty())
                {
                    if (id[x].front() > i) break;
                    id[x].pop_front();
                }
            }

            lastRead = x-1;
        }

        cout << ans << '\n'; // number of unread notifications
    }

    return 0;
}
