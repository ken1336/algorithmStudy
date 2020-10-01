//https://programmers.co.kr/learn/courses/30/lessons/49190 문제

#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
using namespace std;

// int solution(const std::vector<int> & arrows) {
//     int answer = 0;
//     std::pair<int,int> curr{0,0};
//     std::vector<std::pair<int,int>> direction{{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1}};
//     std::set<std::pair<int,int>> store{{0,0}};
//     for(auto &i : arrows){
//         curr.first+=direction[i].first;
//         curr.second+=direction[i].second;
//         auto  hit = store.find(curr);
//         if(hit!=store.end()){
//             answer++;
//         }
//         store.insert({curr.first,curr.second});
//     }
//     return answer;
// }

int solution(std::vector<int> arrows)
{
    int answer = 0;
    pair<int, int> curr{0, 0};
    vector<pair<int, int>> direction{{0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}};
    set<pair<int, int>> store{{0, 0}};
    map<pair<int, int>, int> line{make_pair(make_pair(0, 0), 1)};

    for (auto &i : arrows)
    {
        for (auto t = 0; t < 2; t++)
        {

            curr.first += direction[i].first;
            curr.second += direction[i].second;

            //auto hit = store.find(curr);
            auto hit = line.find(curr);
            if (hit != line.end()) //지나간 적 있을때
            {
                
                if (hit->second == 1)
                {
                    cout<<hit->first.first<<","<<hit->first.second<<": "<<hit->second<<endl;
                    answer++;
                }
                hit->second++;
            }
            else
            { // 지나간 적 없을때

                line.insert(make_pair(make_pair(curr.first, curr.second), 1));
            }
        }
    }

    return answer;
}

void test(int testresult, int answer)
{

    if (testresult == answer)
    {
        cout << "통과: "<<testresult<< endl;
    }
    else
    {
        cout << "실패: " <<testresult<<" != "<<answer<< endl;
    }
}

int main()
{
    vector<int> testcase = {6, 6, 6, 4, 4, 4, 2, 2, 2, 0, 0, 0, 1, 6, 5, 5, 3, 6, 0}; //3
    vector<int> testcase1 = {2, 4, 6, 0, 6, 4, 2, 0};                                 // 2
    vector<int> testcase2 = {4, 2, 7, 4, 2, 7};                                       //1
    vector<int> testcase3 = {4, 0};                                                   // 0
    vector<int> testcase4 = {2, 5, 2, 7};
    auto result = solution(testcase2);
    test(solution(testcase), 3);
    test(solution(testcase1), 2);
    test(solution(testcase2), 1);
    test(solution(testcase3), 0);
    test(solution(testcase4), 2);
    return result;
}