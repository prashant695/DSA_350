
// Union

// Method - 1
// Using set
// Time -> O(mlogm + nlogn)

void getUnion(int a[], int n, int b[], int m)
{
    set<int> s;
    for (int i = 0; i < n; i++)
        s.insert(a[i]);

    for (int i = 0; i < m; i++)
        s.insert(b[i]);

    for (auto itr = s.begin(); itr != s.end(); itr++)
        cout << *itr << " ";
}

// Method - 2
// Using map
// Time -> O(m+n)

void getUnion(int a[], int n, int b[], int m)
{
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[a[i]]++;

    for (int i = 0; i < m; i++)
        mp[b[i]]++;

    for (auto itr = mp.begin(); itr != mp.end(); itr++)
        cout << itr->first << " ";
}

// Method - 3
// Naive
// Time -> O(mn)

// Initialize union U as empty.
// Copy all elements of the first array to U.
// Do the following for every element x of the second array:
// If x is not present in the first array, then copy x to U.

// Method - 4
// Sorting
// Time -> O(mlogm + nlogn)

// Method - 5
// Sorting and searching
// Time -> O(min(mlogm + nlogm, mlogn + nlogn))

// Initialize union U as empty.
// Find smaller m and n and sort the smaller array.
// Copy the smaller array to U.
// For every element x of a larger array, do the following
// Binary Search x in the smaller array. If, x is not present, then copy it to U.

// Intersection

// Method - 1
// Naive
// Time -> O(mn)

// Initialize Intersection I as empty.
// Copy all elements of the first array to I.
// Do the following for every element x of the second array:
// If x is present in the first array, then copy x to I.

// Method - 2
// Sorting and searching
// Time -> O(min(mlogm + nlogm, mlogn + nlogn))

// Initialize Intersection I as empty.
// Find smaller m and n and sort the smaller array.
// Copy the smaller array to I.
// For every element x of a larger array, do the following
// Binary Search x in the smaller array. If, x is present, then copy it to I.

// When elements in the arrau may not be distinct

void intersection(int a[], int b[], int n, int m)
// Provided a[] and b[] are sorted
{
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (a[i] > b[j])
        {
            j++;
        }
        else if (b[j] > a[i])
        {
            i++;
        }
        else
        {

            cout << a[i] << " ";
            i++;
            j++;
        }
    }
}
