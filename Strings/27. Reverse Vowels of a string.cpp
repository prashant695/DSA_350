// https://leetcode.com/problems/reverse-vowels-of-a-string/

bool isvowel(char ch)
{
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return 1;
    if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        return 1;
    return 0;
}
string reverseVowels(string s)
{
    int i = 0, j = s.size() - 1;
    while (i < j)
    {
        while (i < j and !isvowel(s[i]))
        {
            i++;
        }
        while (i < j and !isvowel(s[j]))
        {
            j--;
        }
        swap(s[i++], s[j--]);
    }
    return s;
}