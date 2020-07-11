#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

#include <vector>
#include <unordered_set>
#include <utility>
#include <tuple>
#include <set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <unistd.h>
using namespace std;

string solution(string &S)
{
    // write your code in C++14 (g++ 6.2.0)

    string sol = S;
    cout << sol.size() << endl;
    for (int i = 0; i < sol.size(); i++)
    {
        cout << sol[i] << endl;
    }
}

int main()
{

    //string sol = string("ACCAABBC");
    //string sol = string("ABCBBCBA");
    string sol = string("BABABA");
    cout << sol.size() << endl;

    for (int i = 0; i < sol.size() - 1; i++)
    {
        if (sol.size() < 1)
            break;
        cout << i << ": " << sol[i] << "?" << sol[i + 1] << endl;
        if (sol[i] == sol[i + 1])
        {
            cout << sol[i] << "==" << sol[i + 1] << endl;
            sol.erase(i, 2);
            i = -1;
        }
        
    }

    cout << "for end:" << sol << endl;

    // string abc = string("ACCAABBC");
    // solution(abc);
    //solution("ABCBBCBA");
    // solution("BABABA");
    return 0;
}