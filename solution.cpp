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

using namespace std;

string solution(string& S)
{
    string sol = S;
    for (int i = 0; i < sol.size() - 1; i++)
    {
        if (sol.size() < 1)
            break;
        if (sol[i] == sol[i + 1])
        {
            sol.erase(i, 2);
            i = -1;
        }
    }
    return sol;
}

int main()
{

    //string sol = string("AABBBCBAABC");
    //string sol = string("BBAAACCCCBBBAA");
    //string sol = string("ABCBBCBA");
    //string sol = string("BABABA");
    // string sol = string("CCABCC");
    // string sol = string("CCABCC");
    string sol = string("AABABBABAABBABBBAAACCB");

    // string abc = string("ACCAABBC");
    // solution(abc);
    cout<<solution(sol)<<endl;


    return 0;
}