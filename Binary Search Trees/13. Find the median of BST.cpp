// https://practice.geeksforgeeks.org/problems/median-of-bst/1

// Method - 1
// Bruteforce
// Traverse the tree, store the nodes values in array, sort the array, return median
// TC: O(n logn)
// SC: O(n)

// Method - 2
// Inorder Traversal
// Traverse the tree, store the nodes values in array, return the median
// TC: O(n)
// SC: O(n)

// Method - 3
// Morris Traversal
// Count the number of nodes in given BST
// Perform Morris Traversal to find the kth smallest element
// where k = count / 2 (for count = odd)
// and k + 1, (for count = even)
// TC: O(n)
// SC: O(1)
