// https://leetcode.com/problems/permutations/submissions/

// Time complexity: O(n * n!)
// Space complexity: O(n!)


// METHOD - 1
class Solution
{
public:
	vector<vector<int>> res;
	void fun(vector<int> &nums, int i)
	{
		int n = nums.size();
		if (i == n - 1)
		{
			res.push_back(nums);
			return;
		}

		for (int j = i; j < n; j++)
		{
			swap(nums[i], nums[j]);
			fun(nums, i + 1);
			swap(nums[i], nums[j]);
		}
	}
	vector<vector<int>> permute(vector<int> &nums)
	{
		fun(nums, 0);
		sort(res.begin(), res.end());
		return res;
	}
};

// METHOD - 2
class Solution
{
public:
	int fact(int n)
	{
		int f = 1;
		for (int i = 1; i <= n; i++)
			f *= i;

		return f;
	}
	void nextPermutation(vector<int> &nums)
	{
		if (nums.size() <= 1)
			return;
		int i = nums.size() - 2;
		while (i >= 0 and nums[i] >= nums[i + 1])
			i--;
		if (i >= 0)
		{
			int j = nums.size() - 1;
			while (nums[j] <= nums[i])
				j--;
			swap(nums[i], nums[j]);
		}

		reverse(nums.begin() + i + 1, nums.end());
	}
	vector<vector<int>> permute(vector<int> &nums)
	{
		vector<vector<int>> v;
		v.push_back(nums);
		int n = nums.size();
		for (int i = 0; i < fact(n) - 1; i++)
		{
			nextPermutation(nums);
			v.push_back(nums);
		}
		return v;
	}
};