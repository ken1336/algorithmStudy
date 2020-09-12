#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

std::vector<std::vector<char>> Combination(vector<char> container, int r)
{

    int n = container.size();
    if (n < r)
        return {};
    if (r < 0)
        return {};

    std::vector<std::vector<char>> totVec; //return 2d-vector
    std::vector<char> tempVec(r);          //saves temporary combination

    std::vector<bool> v(n);
    std::fill(v.end() - r, v.end(), true);
    int idx;
    do
    {
        idx = 0;
        for (int i = 0; i < n; ++i)
        {
            if (v[i])
            {
                tempVec[idx++] = *(container.begin() + i);
            }
        }
        totVec.push_back(tempVec);
    } while (std::next_permutation(v.begin(), v.end()));

    return totVec;
}

vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;
    unordered_map<string, int> comMap;
    for (auto &cour : course)
    {

        for (auto &vec : orders)
        {
            //cout << vec << endl;
            vector<char> order;
            for (auto &i : vec)
                order.push_back(i);
            for (auto &orderCombination : Combination(order, cour))
            {
                //cout<<"combination: "<< orderCombination.size() <<endl;
                sort(orderCombination.begin(),orderCombination.end());
                string conStr;
                for (auto &el : orderCombination)
                {
                    conStr += el;
                }
                //cout<<conStr<<endl;
                if (comMap.find(conStr) != comMap.end())
                {
                    //cout << " dup " << comMap.at(conStr) << endl;
                    comMap.at(conStr)++;
                }
                else
                {
                    comMap.insert(pair<string, int>(conStr, 1));
                }
            }
            // for(auto& re :comMap){
            //     for(auto &f : re.second){
            //         cout<<re.first<<","<<f<<endl;
            //     }

            // }
        }
    }
    //cout<<"result: "<<endl;
    for (auto &re : comMap)
    {
        if (re.second > 1)
        {
            //cout << re.first << "  count: " << re.second << endl;
            //answer.push_back(re.first);
        }
    }
    for (auto &cour : course)
    {
        int max = 0;
        vector<string> cand;
        for (auto &ree : comMap)
        {
            if (ree.first.length()== cour)
            {
                if(ree.second > max){
                    max = ree.second;
                }
                
            }

        }
        for (auto &ree : comMap)
        {
            if (ree.second == max && ree.first.length()== cour && max >1 ){
                answer.push_back(ree.first);
            }

            
        }

        
    }
    sort(answer.begin(),answer.end());
    for(auto & ans : answer){
        cout<<ans<<endl;
    }

    return answer;
}

int main()
{

    vector<string> strVec{"XYZ", "XWY", "WXA"};

    auto result = solution(strVec, {2, 3, 4});

    return 0;
}