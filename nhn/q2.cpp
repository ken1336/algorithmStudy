#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

//핵심 소스코드의 설명을 주석으로 작성하면 평가에 큰 도움이 됩니다.
class Solution{
public:

    bool isContain(int el,vector<int> vec){
        for(auto & i : vec){
            if( i == el){
                return true;
            }
            else{
                return false;
            }
        }
    }
    int solution(int page, vector<int> broken){
        int cnt = 0;
        vector<int> intPage;

        while(page != 0){
            intPage.push_back(page % 10);
            page/=10;

        }

        for(auto &t : intPage){
            cout<<t<<endl;
        }


        

        for(auto i = intPage.size(); i>0; --i){

            cout<<i<<":"<<intPage[i]<<endl;
            if(isContain(intPage[i],broken)){

            }
        }

       
  


        return 0;


    }
};


int main(){

    Solution sol{};
    auto broken = vector<int>({6,7,8});
    
    sol.solution(5457,broken);
    // sol.solution(100,{1,0,5});
    // sol.solution(99999,{0,2,3,4,5,6,7,8,9});
    // sol.solution(158,{1,9,2,5,4});
    // sol.solution(151241,{0,1,2,3,4,7,8,9});

}