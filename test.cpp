#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::endl;

 
template<typename Container_, typename value_type = typename Container_::value_type>
std::vector<std::vector<value_type> > Combination(Container_ container, int r) {
    int n = container.size();
    if (n < r) return {};
    if (r < 0) return {};
 
    std::vector<std::vector<value_type> >totVec;//return 2d-vector
    std::vector<value_type> tempVec(r);//saves temporary combination
 
    std::vector<bool> v(n);
    std::fill(v.end() - r, v.end(), true);
    int idx;
    do {
        idx = 0;
        for (int i = 0; i < n; ++i) {
            if (v[i]) {
                tempVec[idx++] = *(container.begin() + i);
            }
        }
        totVec.push_back(tempVec);
    } while (std::next_permutation(v.begin(), v.end()));
 
    return totVec;
}
 

int main() {
    vector<int> intVec{3, 2, 5, 1, 5};
    vector<string> strVec{ "Apple", "Banana", "Car" };
 
    //intVec에 대해 3C2 수행
    for (auto& vec : Combination(intVec, 2)) {
        for (auto& ele : vec)
            std::cout << ele << ' ';
        cout << endl;
    }
    cout << endl;
 
    //strVec에 대해 3C2 수행
    for (auto& vec : Combination(strVec, 2)) {
        for (auto& ele : vec)
            cout << ele << ' ';
        cout << endl;
    }
}