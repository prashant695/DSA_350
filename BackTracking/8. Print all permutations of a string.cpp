// https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1/

// Time complexity: O(n * n!)
// Space complexity: O(n!)

// For any given string of length n there are n! possible permutations,
//  and we need to print all of them so Time complexity is O(n * n!).

// The function will be called recursively and 
// will be stored in call stack for all n! permutations, so Space complexity is O(n!).

class Solution
{
public:
	vector<string> v;
	void fun(string s, int i)
	{
		int n = s.size();
		if (i == n - 1)
		{
			v.push_back(s);
			return;
		}

		for (int j = i; j < n; j++)
		{
			swap(s[i], s[j]);
			fun(s, i + 1);
		}
	}
	vector<string> find_permutation(string s)
	{
		fun(s, 0);
		sort(v.begin(), v.end());
		return v;
	}
};