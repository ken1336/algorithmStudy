#include<iostream>


int getLargeCase(std::string input,int jaje){
    int cnt = 0;
    int bosu = jaje;
    int max = 0;
    int backtracking = 0;

    for(auto i =0;i< input.size();i++){
        if(input[i]=='1'){
            cnt++;
        }else{

            if(backtracking == 0){
                backtracking = i;
            }
            if(bosu>0){
                bosu--;
                cnt++;
            }else{
                
                i = backtracking;
                backtracking = 0;
                bosu = 3;
                if(cnt>max){
                    max = cnt;
                }
                cnt = 0;   
            }
        }
    }
    if(cnt>max){
        max = cnt;
    }

    std::cout<<max<<std::endl;
    return max;
}

int main(){

    std::string load1 = "111011110011111011111100011111";
    std::string load2 = "001100";
    std::string test = "11100001111111110111111110000111";
    std::string test2 = "1110000110110000111";
    std::string test3 = "11100001101110000111";
    getLargeCase(test3,3);

    return 0;
}