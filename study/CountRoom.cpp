//https://programmers.co.kr/learn/courses/30/lessons/49190 문제


#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

int solution(std::vector<int> arrows)
{
    int answer = 0;
    pair<int, int> curr{0, 0};
    vector<pair<int, int>> direction{{0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}};
    set<pair<int, int>> store{{0, 0}};
    for (auto &i : arrows)
    {
        curr.first += direction[i].first;
        curr.second += direction[i].second;
        auto hit = store.find(curr);
        if (hit != store.end())
        {
            answer++;
        }
        store.insert({curr.first, curr.second});
    }

    return answer;
}

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

int main()
{

    auto result = solution({6, 6, 6, 4, 4, 4, 2, 2, 2, 0, 0, 0, 1, 6, 5, 5, 3, 6, 0});
    return result;
}