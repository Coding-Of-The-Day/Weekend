// ConsoleApplication5.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    for (size_t height = 0; height < triangle.size() - 1; ++height)
    {
        // 자식 데이터
        for (size_t floor_number_index = 0; floor_number_index < triangle[height + 1].size(); ++floor_number_index)
        {
            int left_parent_value   = 0;
            int right_parent_value  = 0;

            if (triangle[height].size() > floor_number_index - 1)
                left_parent_value = triangle[height][floor_number_index - 1];

            if (triangle[height].size() > floor_number_index)
                right_parent_value = triangle[height][floor_number_index];

            triangle[height + 1][floor_number_index] += std::max(left_parent_value, right_parent_value);
        }
    }

    for (size_t i = 0; i < triangle[triangle.size() - 1].size(); ++i)
        answer = std::max(answer, triangle[triangle.size() - 1][i]);

    return answer;
}


int main()
{
    // 갈 수 있는 루트는 내 번호, 내번호 + 1 번 까지임 맞나?

    vector<vector<int>> param = {
          {7},            
         {3,8},          
        {8,1,0},
       {2,7,4,4},
      {4,5,2,6,5},
    };

    solution(param);

    return 0;
}
