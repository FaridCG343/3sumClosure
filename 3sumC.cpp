#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
bool sum3(vector<int> v, map<int, bool> m)
{
    bool x = true;
    int suma;
    for (int i = 0; i < v.size() - 2; i++)
    {
        for (int j = i + 1; j < v.size() - 1; j++)
        {
            for (int k = j + 1; k < v.size(); k++)
            {
                suma = v[i] + v[j] + v[k];
                if (!m[suma])
                {
                    x = false;
                }
            }
        }
    }
    return x;
}
int main(int argc, char const *argv[])
{
    int tc, n, n2, pos = 0, neg = 0;
    vector<int> num;
    map<int, bool> valores;
    cin >> tc;
    while (tc--)
    {
        num.clear();
        valores.clear();
        cin >> n;
        pos = 0, neg = 0;
        while (n--)
        {
            cin >> n2;
            if (n2 == 0 && !valores[0])
            {
                num.push_back(n2);
            }
            if (n2 > 0)
            {
                num.push_back(n2);
                pos++;
            }
            if (n2 < 0)
            {
                num.push_back(n2);
                neg++;
            }
            valores[n2] = true;
        }
        if (pos > 2 || neg > 2 || ((pos == 2 || neg == 2) && valores[0]))
        {
            cout << "NO" << endl;
        }
        else
        {
            if (num.size() < 3)
            {
                cout << "Yes"<<endl;
            }
            else
            {
                if (sum3(num, valores))
                {
                    cout << "YES" << endl;
                }
                else
                {
                    cout << "NO" << endl;
                }
            }
        }
    }

    return 0;
}
