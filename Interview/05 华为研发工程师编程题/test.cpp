#include <iostream>
using namespace std;

int main() {
    int a = 0;
    scanf("%x", &a);
    cout << a << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")
#include <cstdlib>
#include <iostream>

#include <set>

#include  <random>

using namespace std;

int main()
{

    set<int> s;
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a = 0;
        cin >> a;
        s.insert(a);
    }
    for (auto e : s)
        cout << e << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    while (cin >> n)
    {
        int count = 0;
        while (true)
        {
            count += n / 3;
            n = n % 3 + n / 3;
            if (n == 2)
            {
                count++;
                break;
            }
            if (n < 2)
            {
                break;
            }
        }
        if (count)
            cout << count << endl;
    }

}
// 64 位输出请用 printf("%lld")