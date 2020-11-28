#include <vector>
#include <iostream>
using namespace std;

//핵심 소스코드의 설명을 주석으로 작성하면 평가에 큰 도움이 됩니다.


class Solution{
public:
    int solution(vector<int> goods){

        auto result = 0;

        for(auto i =0; i< goods.size();i++){
            cout<<goods[i] << endl;
            if(goods[i]>=50){

                goods.erase(goods.begin()+i);
                i--;
                result += goods[i]-10;
            }
        }
        cout<<"  "<<endl;
        for(auto i =0; i< goods.size();i++){
            cout<<goods[i] << endl;

        }


        return 0;
    }
};

int main(){

    Solution sol{};
    auto goods = vector<int>({46,62,9});
    
    sol.solution(goods);
}