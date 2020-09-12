#include <iostream>
#include <vector>
#include <algorithm>



bool combination(int t, int cnt, int max){


    if(t == max){
        return false;
    }
    for(auto i = t; i<cnt; i++){
        std::cout<<i<<std::endl;
    }
    std::cout<<std::endl;
    if(cnt<max)
        combination(t,cnt+1, max);
    if(cnt == max){
        combination(t+1,0,max);
    }

}


int solution(const std::string tuple[][4])
{
    int result;

    for(auto i = 0; i<6; i++){
        for(auto t = 0; t<4; t++){
            std::cout<<tuple[i][t]<<std::endl;
        }
    }

    


    return result;
}

int main()
{
    // std::string testCase[][4] = {
    //     {"100","ryan","music","2"},
    //     {"200","apeach","math","2"},
    //     {"300","tube","computer","3"},
    //     {"400","con","computer","4"},
    //     {"500","muzi","music","3"},
    //     {"600","apeach","music","2"}
    // };

    // auto answer = solution(testCase);
    combination(0,0,4);
    // std::cout << answer << std::endl;
    return 0;
}
