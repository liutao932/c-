#include"vector.h"
using namespace bit;
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> vv;
		vv.resize(numRows);
		for (size_t i = 0; i < numRows; ++i)
		{
			vv[i].resize(i + 1);
			vv[i][0] = vv[i][vv[i].size() - 1] = 1;
		}

		for (size_t i = 0; i < vv.size(); ++i)
		{
			for (size_t j = 0; j < vv[i].size(); ++j)
			{
				if (vv[i][j] == 0)
				{
					vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
				}
			}
		}

		return vv;
	}
};
int main()
{
	//vector_test1();
	vector<vector<int>> vv = Solution().generate(5);
	for (size_t i = 0; i < vv.size(); ++i)
	{
		for (size_t j = 0; j < vv[i].size(); ++j)
		{
			std::cout << vv[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout <<std::endl;
}