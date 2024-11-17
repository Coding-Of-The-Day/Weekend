// ConsoleApplication5.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
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
        // �ڽ� ������
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
    solution(param);
    return 0;
}
