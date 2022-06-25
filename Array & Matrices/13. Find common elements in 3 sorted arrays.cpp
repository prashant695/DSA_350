// https://practice.geeksforgeeks.org/problems/common-elements1132/1/#

//Method-1
//Time - o(nlogn)
//Space - O(1)
vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
    vector<int> res;
    for (int i = 0; i < n1; i++)
    {
        bool flag1 = binary_search(B, B + n2, A[i]);
        bool flag2 = binary_search(C, C + n3, A[i]);
        if (i > 0 and A[i] == A[i - 1])
            flag1 = 0;
        if (flag1 and flag2)
            res.push_back(A[i]);
    }
    return res;
}

// Method-2
// Time-O(n1+n2+n3)
// Space-O(n1+n2+n3)

vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
    vector<int> res;
    unordered_map<int, int> ump2, ump3;
    for (int i = 0; i < n2; i++)
        ump2[B[i]]++;
    for (int i = 0; i < n3; i++)
        ump3[C[i]]++;

    for (int i = 0; i < n1; i++)
    {
        if (ump2[A[i]] and ump3[A[i]] and !(res.size() and res.back() == A[i]))
        {
            res.push_back(A[i]);
        }
    }
    return res;
}

//Method-3
// Time-O(n1+n2+n3)
// Space-O(1)

vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
    vector<int> res;
    int i = 0, j = 0, k = 0;
    while (i < n1 and j < n2 and k < n3)
    {
        if (A[i] == B[j] and B[j] == C[k] and !(res.size() and res.back() == A[i]))
        {
            res.push_back(A[i]);
            i++, j++, k++;
        }
        else if (A[i] < B[j])
            i++;
        else if (B[j] < C[k])
            j++;
        else
            k++;
    }
    return res;
}
