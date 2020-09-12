#include <string>
#include <vector>
#include <sstream>
#include<iostream>
using namespace std;

string changeToValidNumber(const string& card) {
   ostringstream str;
   for (char ch : card) {
      if (ch >= '0' && ch <= '9') {
         str << ch;
      }
   }
   return str.str();
}

bool validation(const string& card) {
   int count = 0;
   for (char c : card) {
      if (c == '-')
         count++;
   }
   return count == 3 && card[4] == '-' && card[9] == '-' && card[14] == '-';
}

vector<int> solution(vector<string> card_numbers) {
   vector<int> answer;
   for (auto s : card_numbers) {      
      if (validation(s)) {//regex_match(s, r)
         s = changeToValidNumber(s);
      }
      else {
         if(s.find('-') == string::npos)
            s = changeToValidNumber(s);
         else {
            answer.push_back(0);
            continue;
         }
      }

      int size = s.size();

      if (size != 16) {
         answer.push_back(0);
         continue;
      }

      int a = 0;
      int b = 0;

      int n = 0;
      for (int i = 0; i < size; i += 2) {
         n = ((s[i] - '0') * 2);
         if (n >= 10) {
            n = n % 10 + n / 10;
         }
         a += n;
      }

      for (int i = 1; i <size; i += 2) {
         b += (s[i] - '0');
      }
      if ((a + b) % 10 == 0) {
         answer.push_back(1);
      }
      else {
         answer.push_back(0);
      }      
   }
   return answer;
}

int main() {
   auto t = solution({"3285-3764-9934-2453", "3285376499342453", "3285-3764-99342453", "328537649934245", "3285376499342459", "3285-3764-9934-2452"});
   //3+4+4+9+4+7+5+2 = 짝수 = 6 + 8 + 8 + 9 + 8 + 5 + 1 + 4 = 49
   //5+2+3+9+6+3+8+3 = 홀수 = 39
   for (auto a : t) {
        cout << a << endl;
   }
}