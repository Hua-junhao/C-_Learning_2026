#include<iostream>
using namespace std;
#include<cmath>
#include<string>
#include<vector>
#include <algorithm> 

bool issushu(int a)
{
	if (a <= 1) return 0;
	for (int i = 2; i <=sqrt(a); i++)
	{
		if (a % i == 0)
		{
			return 0;
		}
	}
	return 1;
}
int power(int i)
{
	int sum=0;
	while(i > 0)
	{
		int a = i % 10;
		sum += pow(a, 2);
		i /= 10;
	}
	return sum;
}
vector<int>arr;
vector<int>arr2;
vector<int> dependent;
bool xinfushu(int i)
{
	vector<int>visited;
	int c = i;
	bool flag = 0;
	int  a= 0;
	while (true)
	{
		
		if (find(visited.begin(), visited.end(), c) != visited.end())
		{
			// 死循环，不是幸福数
			return false;
		}
		visited.push_back(c);
		if (c == 1)
		{
			for (int num : visited)
			{
				if (num != i)
				{
					dependent.push_back(num);
				}
			}
			int a = visited.size() - 1;
			if (find(arr.begin(), arr.end(), i) == arr.end())
			{
				arr.push_back(i);
				arr2.push_back(a);
				flag = 1;
			}
			return true;
		}
		c = power(c);
	}
}
vector<int> independent_arr;
vector<int> independent_arr2;
int main()
{
	int a, b;
	cin >> a >> b;
	vector<int>x;
	for (int i = a; i <= b; i++)
	{
		if (xinfushu(i))
		{
			if (issushu(i))
				arr2[arr.size() - 1] = arr2[arr.size() - 1] * 2;
		}
	}
	for (int i = 0; i < arr.size(); i++)
	{
		int num = arr[i];
		// 检查这个幸福数是否依附于其他数字
		if (find(dependent.begin(), dependent.end(), num) == dependent.end())
		{
			independent_arr.push_back(num);
			independent_arr2.push_back(arr2[i]);
		}
	}
	vector<pair<int, int>> result;
	for (int i = 0; i < independent_arr.size(); i++)
	{
		result.push_back({ independent_arr[i], independent_arr2[i] });
	}
	sort(result.begin(), result.end());
	if (result.empty())
	{
		cout << "SAD";
	}
	else
	{
		for (auto& p : result)
		{
			cout << p.first << " " << p.second << endl;
		}
	}

}