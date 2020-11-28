#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include<set>
using namespace std;

//핵심 소스코드의 설명을 주석으로 작성하면 평가에 큰 도움이 됩니다.
class Solution
{
public:
    template <typename Container_, typename value_type = typename Container_::value_type>
    set<vector<value_type>> Combination(Container_ container, int r)
    {
        int n = container.size();
        if (n < r)
            return {};
        if (r < 0)
            return {};

        set<std::vector<value_type>> totVec; //return 2d-vector
        
        
        std::vector<bool> v(n);
        std::fill(v.end() - r, v.end(), true);
        int idx;
        do
        {
            std::vector<value_type> tempVec(r);          //saves temporary combination

            idx = 0;
            for (int i = 0; i < n; ++i)
            {
                if (v[i])
                {
                    tempVec[idx++] = *(container.begin() + i);
                }
            }
            totVec.insert(tempVec);
        } while (std::next_permutation(v.begin(), v.end()));

        return totVec;
    }

    int rough(string s)
    {

        vector<int> count('z' - 'a' + 1);
        fill(count.begin(), count.end(), 0);

        for (auto character : s)
        {

            count[character - 'a']++;
        }
        sort(count.begin(), count.end(), greater<>());
        for (auto element : count)
        {
            //cout << element << endl;
        }

        for (auto i = 0; i < count.size(); i++)
        {

            if (count[i] == 0)
            {

                return count[0] - count[i - 1];
            }
        }
    }
    int rough(vector<char> s)
    {

        vector<int> count('z' - 'a' + 1);
        fill(count.begin(), count.end(), 0);

        for (auto character : s)
        {

            count[character - 'a']++;
        }
        sort(count.begin(), count.end(), greater<>());
        for (auto element : count)
        {
            //cout << element << endl;
        }

        for (auto i = 0; i < count.size(); i++)
        {

            if (count[i] == 0)
            {

                return count[0] - count[i - 1];
            }
        }
    }

    int solution(string s, int n)
    {

        int result = s.size();

        for (auto f = 0; f < n; f++)
        {
            auto re = Combination(s, s.size() - f);
            for (auto& vec : re) {
                for (auto& ele : vec)
                    std::cout << ele << ' ';
                cout << endl;
            }
            

            for (auto &vec : re)
            {

                auto a = rough(vec);
                if (a < result)
                {
                    cout<<a<<endl;
                    result = a;
                }
            }
        }
        
        // cout<<result<<endl;
        return result;
    }
};

int main()
{


    Solution sol{};


    cout<<sol.solution("aaaaabbc", 1)<<endl;
    //cout<<sol.solution("aaaabbbbc", 5)<<endl;
    return 0;
}