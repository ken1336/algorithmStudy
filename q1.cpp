#include <iostream>
#include<map>
#include<vector>
#include<list>

std::string inputString1 = "Hello world!";
std::string inputString2 = "line [(plus)]";
std::string inputString3 = "if(min of war) (hello)";
std::string inputString4 = ">.<"; 
std::string inputString5 = "<<>";


int countBracket(std::string input,std::map<char,int> &map,std::map<char,char> &rMap){
    
    
    int cnt = -1;
    bool succ = false;
    std::vector<char> _wordStack;

    
    for(auto &i  :input){
        //std::cout<<"input: "<<i<<std::endl;
        if(map[i] == -1){

            _wordStack.push_back(i);
    
        }
        else if(map[i] == 1){

            
            if(succ == false){
                succ = true;
                cnt = 0;
            }
            cnt++;
            auto rr = rMap[i];
            //std::cout<<"size: "<<_wordStack.size()<<std::endl;
            for(auto t = _wordStack.begin(); t!=_wordStack.end();){
                
                if(*t == rr){
                    _wordStack.erase(t);
                    
                    break;
                }
                else{
                    t++;
                }
                
            }

                for(auto f =0; f<_wordStack.size();){
                    if(_wordStack[f] == rr){
                        _wordStack.erase(_wordStack.begin()+f);
                        break;
                    }else{
                        f++;
                    }

                }
            
                //_wordStack.erase(t);
            
            //auto iter = std::find(_wordStack.end(),_wordStack.begin(),rr);
            
        }    
    }
    if(_wordStack.empty()){
        return cnt;
    }else{
        //std::cout<<"remain vector: "<<_wordStack.size()<<std::endl;
        for(auto t = _wordStack.begin(); t!=_wordStack.end();){
                
                //std::cout<<": "<<*t<<std::endl;
                t++;
            }
        return -1;
    }
  
}


int main(){

    std::map<char,int> bracketMap; // -1 : left, +1: right
    std::map<char,char> rBracketMap;
    bracketMap.insert(std::pair<char,int>('(',-1));
    bracketMap.insert(std::pair<char,int>('[',-1));
    bracketMap.insert(std::pair<char,int>('{',-1));
    bracketMap.insert(std::pair<char,int>('<',-1));

    bracketMap.insert(std::pair<char,int>(')',1));
    bracketMap.insert(std::pair<char,int>(']',1));
    bracketMap.insert(std::pair<char,int>('}',1));
    bracketMap.insert(std::pair<char,int>('>',1));


    rBracketMap.insert(std::pair<char,char>(')','('));
    rBracketMap.insert(std::pair<char,char>(']','['));
    rBracketMap.insert(std::pair<char,char>('}','{'));
    rBracketMap.insert(std::pair<char,char>('>','<'));

    auto result = countBracket(inputString1, bracketMap,rBracketMap);
    std::cout<<result<<std::endl;
    result = countBracket(inputString2, bracketMap,rBracketMap);
    std::cout<<result<<std::endl;
    result = countBracket(inputString3, bracketMap,rBracketMap);
    std::cout<<result<<std::endl;
    result = countBracket(inputString4, bracketMap,rBracketMap);
    std::cout<<result<<std::endl;
    result = countBracket(inputString5, bracketMap,rBracketMap);
    std::cout<<result<<std::endl;
    
    return result;
}