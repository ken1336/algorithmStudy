#include <string>
#include <vector>
#include <iostream>
using namespace std;

int ParseToSec(string time)
{

    int result;
    string temp = time;

    auto hour = stoi(temp.substr(0, 2));
    auto min = stoi(temp.substr(3, 5));
    auto sec = stoi(temp.substr(6, 8));
    result = hour * 60 * 60 + min * 60 + sec;

    return result;
}
string ParseToTime(int time)
{

    string result;
    int temp = time;
    
    auto sec = to_string(temp % 60);
    temp /= 60;
    
    auto min = to_string(temp%60);
    temp /=60;
    auto hour = to_string(temp%60);
    

    if(stoi(hour) < 10){
        result +='0';
    }
    result +=hour;
    result +=":";
    if(stoi(min) < 10){
        result +='0';
    }
    result +=min;
    result +=":";
    if(stoi(sec) < 10){
        result +='0';
    }
    result +=sec;
    
    return result;
}
pair<int, int> ParseRange(string time)
{
    string temp = time;
    int first = ParseToSec(&temp.at(0));
    int second = ParseToSec(&temp.at(9));
    return pair<int, int>(first, second);
}

class TimeData
{
    int start;
    int end;
    int cnt;
    

public:
    TimeData(int start, int end, int cnt = 0) : start(start), end(end), cnt(cnt){};
    int getStart()
    {
        return start;
    }
    int getEnd()
    {
        return end;
    }
    int getCnt()
    {
        return cnt;
    }
    void setCnt(int input)
    {
        cnt = input;
    }
};

void FillValue (vector<int> & vector,int  first, int last){
    while (first != last) {
        vector[first]++;
        ++first;
  }
}

string solution(string play_time, string adv_time, vector<string> logs)
{
    vector<int> play;
    vector<TimeData> date;
    vector<pair<string, int>> cand;
    string answer = "00:00:00";
    play.assign(ParseToSec(play_time),0);
    if(ParseToSec(play_time) <= ParseToSec(adv_time)){
        return answer;
    }

    for (auto &log : logs)
    {
        auto sec = ParseRange(log);
        date.emplace_back(sec.first, sec.second);
        FillValue(play,sec.first,sec.second);
        
    }

    
    for(int i = 0; i< ParseToSec(play_time);  i++){
        
        for(auto& t : date){
            if(i == t.getStart()){
                
                int value = 0;
                
                if(ParseToSec(adv_time)+i<play.capacity()){
                    for(int f = i; f<i+ParseToSec(adv_time); f++){
                        value+=play[f];
                    }
                }

                cand.emplace_back(ParseToTime(t.getStart()),value);
                
            }
        }
        
    }
     
    int max = 0;
    for(auto& i : cand){
        if(i.second > max){
            max = i.second;
        }
    }

    for(auto& i : cand){
        if(i.second == max){
            answer =  i.first;
            break;
        }
    }

    


    
    return answer;
}

int main()
{

    vector<string> logs{"01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30"};
    vector<string> logs2{"69:59:59-89:59:59", "01:00:00-21:00:00", "79:59:59-99:59:59", "11:00:00-31:00:00"};
    //cout<<solution("02:03:55", "00:14:15",logs )<<endl;
    //cout<<solution("99:59:59", "25:00:00",logs2)<<endl;
    cout<<solution("99:59:59", "25:00:00",logs2)<<endl;
    //ParseRange("01:20:15-01:45:14");
}