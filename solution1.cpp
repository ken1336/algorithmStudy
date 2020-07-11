#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

#include <vector>
#include <unordered_set>
#include <utility>
#include <tuple>
#include <set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <unistd.h>
using namespace std;
int solution(vector< vector<int> > &A)
{
   vector<int> rowAddVec;
   vector<int> columnAddVec;
   {
      size_t columnSize = A.back().size();
      columnAddVec.resize(columnSize);

      for (const auto& row : A)
      {
         int totalRow{};
         int i = 0;
         for (const auto& element : row)
         {
            totalRow += element;
            columnAddVec[i] += element;
            i++;
         }
         rowAddVec.push_back(totalRow);
      }
   }

   vector <int> expectSuccessColumn;
   {
      for (size_t j = 0; j < A[0].size(); j++)
      {
         if (j == 0)
         {
            // 오른쪽 column의 합이 제로가 나와야 함
            size_t k = 0;
            int columnTotalVal = 0;
            for (const auto& columnTotalElement : columnAddVec)
            {
               if (k == 0)
               {
                  k++;
                  continue;
               }

               columnTotalVal += columnTotalElement;
               k++;
            }

            if (columnTotalVal == 0)
            {
               expectSuccessColumn.push_back(j);
            }
            else
            {

            }
         }
         else if (j == A[0].size() - 1)
         {
            // 왼쪽 column의 합이 제로가 나와야 함
            size_t k = 0;
            int columnTotalVal = 0;
            for (const auto& columnTotalElement : columnAddVec)
            {
               columnTotalVal += columnTotalElement;

               if (k == columnAddVec.size() - 1)
                  break;

               k++;
            }

            if (columnTotalVal == 0)
            {
               expectSuccessColumn.push_back(j);
            }
            else
            {

            }
         }
         else
         {
            // 양쪽 column의 합이 제로가 나와야 함

            // i, j
            size_t k = 0;
            int columnTotalLeft = 0;
            int columnTotalRight = 0;
            for (const auto& columnTotalElement : columnAddVec)
            {
               if (k == j)
               {
                  k++;
                  continue;
               }
               else if (k > j)
               {
                  columnTotalRight += columnTotalElement;
               }
               else
               {
                  columnTotalLeft += columnTotalElement;
               }

               k++;
            }

            if (columnTotalLeft == columnTotalRight)
            {
               expectSuccessColumn.push_back(j);
            }
            else
            {

            }
         }
      }
   }

   vector <int> expectSuccessRow;
   {
      for (size_t i = 0; i < A.size(); i++)
      {
         if (i == 0)
         {
            // 아래쪽 row의 합이 제로가 나와야 함
            size_t k = 0;
            int rowTotalVal = 0;
            for (const auto& rowTotalElement : rowAddVec)
            {
               if (k == 0)
               {
                  k++;
                  continue;
               }

               rowTotalVal += rowTotalElement;
               k++;
            }

            if (rowTotalVal == 0)
            {
               expectSuccessRow.push_back(i);
            }
            else
            {

            }
         }
         else if (i == A.size() - 1)
         {
            // 위쪽 row의 합이 제로가 나와야 함
            size_t k = 0;
            int rowTotalVal = 0;
            for (const auto& rowTotalElement : rowAddVec)
            {
               rowTotalVal += rowTotalElement;

               if (k == rowAddVec.size() - 1)
                  break;

               k++;
            }

            if (rowTotalVal == 0)
            {
               expectSuccessRow.push_back(i);
            }
            else
            {

            }
         }
         else
         {
            // 양쪽 column의 합이 제로가 나와야 함

            // i, j
            size_t k = 0;
            int rowTotalLeft = 0;
            int rowTotalRight = 0;
            for (const auto& rowTotalElement : rowAddVec)
            {
               if (k == i)
               {
                  k++;
                  continue;
               }
               else if (k > i)
               {
                  rowTotalRight += rowTotalElement;
               }
               else
               {
                  rowTotalLeft += rowTotalElement;
               }

               k++;
            }

            if (rowTotalLeft == rowTotalRight)
            {
               expectSuccessRow.push_back(i);
            }
            else
            {

            }
         }
      }
   }

   // result
   size_t expectSuccessRowSize = expectSuccessRow.size();
   size_t expectSuccessColumnSize = expectSuccessColumn.size();

   return expectSuccessRowSize * expectSuccessColumnSize;
}

int main()
{

    vector<int> a{5, 5, 1};
    vector<int> b{1, 1, 1};
    vector<int> c{1, 5, 5};



    // vector<int> d{0, 2, 1};
    // vector<int> e{1, 6, 8};

    vector<vector<int>> val;
    val.push_back(a);
    val.push_back(b);
    val.push_back(c);
    // val.push_back(d);
    // val.push_back(e);

    // for(int  i = 0; i<val.size(); i++){

    //     for(int t = 0; t<val[i].size(); t++){
    //         cout<<val[i][t]<<endl;
    //     }
    
    // }
    //solution(val);
    cout << solution(val) << endl;
    return 0;
}