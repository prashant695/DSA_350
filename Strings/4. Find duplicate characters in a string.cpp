// Method - 1
// Hashing

// Hashing involves the use of an array of fixed size each time no matter whatever the string is. 
// s = “aaaaaaaaaa”. 

// An array of size 256 is used for str, 
// only 1 block out of total size (256) will be utilized to store the number of occurrences of ‘a’

// Rest 256 – 1 = 255 blocks remain unused. 

// Thus, Space Complexity is high for such cases. So, to avoid any discrepancies and to improve Space Complexity, 
// maps are generally preferred over long-sized arrays. 



// Method - 2
// Sorting

