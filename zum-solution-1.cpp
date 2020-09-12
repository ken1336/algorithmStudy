#include <iostream>
#include <vector>
#include <algorithm>

/*
그룹을 나눌 수 있는 경우의 수는 combination 
ex) {1,2,3,4} => {1}, {2},{3,4}
                 {1}, {2,3}, {4]}
                 {1,2},{3}, {4}
공식 => (n-1)Ck
*/

int solution(std::vector<int> scores, int k)
{
    int result = 0;
    if (scores.size() == 1){
        return 0;
    }
    std::vector<std::pair<int, int>> isolationValue{};
    for (auto i = 0; i < scores.size(); i++)
    {
        if (i != scores.size() - 1)
        {
            isolationValue.emplace_back(scores[i + 1] - scores[i], i);
        }
    }
    sort(isolationValue.begin(), isolationValue.end(), std::greater<std::pair<int, int>>());
    
    for (auto i = k-1; i < isolationValue.size(); i++)
    {
        result+=isolationValue[i].first;
    }
    return result;
}

int main()
{
                            //  2    3     2        8      2       4       3
    auto answer = solution({1,2,3,5,7,10,}, 3);
    std::cout<<answer<<std::endl;
    return 0;
}