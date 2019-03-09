#include <bits/stdc++.h>
using namespace std;

using ci = const int;
using ld = long double;
using llint = long long;
using ullint = unsigned long long;
using pii = pair <int,int>;
using vi = vector <int>;
using vb = vector <bool>;
using vii = vi::iterator;

#define INF (1<<30)
#define MOD 1000000007
#define all(c) c.begin(), c.end()
#define ms(name,val) memset(name, val, sizeof name)


inline bool bopen(const char &c)
{
    return (c == '<' || c == '(' || c == '[' || c == '{') ? 1:0;
}

inline bool bclose(const char &c)
{
    return (c == '>' || c == ')' || c == ']' || c == '}') ? 1:0;
}

inline char opposite(const char &c)
{
    if (c == '<') return '>';
    if (c == '>') return '<';

    if (c == '(') return ')';
    if (c == ')') return '(';

    if (c == '[') return ']';
    if (c == ']') return '[';

    if (c == '{') return '}';
    if (c == '}') return '{';
}

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    string s;
    cin >> s;
    int ans = 0, cl = 0, op = 0;
    stack <char> st;

    for (const char &c: s)
    {
        if (bopen(c)) // push all opening brackets to stack
            st.push(c), ++op;
        else
        {
            // see if closing brackets match the opening ones
            ++cl;

            if (st.empty())
            {
                ans = -1;
                break;
            }

            char prev = st.top();
            st.pop();
            if (bopen(prev) && opposite(prev)!=c) ++ans;
        }
    }

    if (ans == -1 || cl != op || !st.empty())
        cout << "Impossible\n";
    else
        cout << ans << '\n';


    return 0;
}
