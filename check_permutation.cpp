/*
    ** Note all these function have the same name,so before running the program
    ** comment out the other functions

    ** Book: Cracking the coding Interview by GAYLE LAAKMANN McDowELL.

    ** Code: Rajan Kumar Singh(rajan9519)

    ** Email: rajankumarsinghvnit@gmail.com
*/
/*
   Q: Check Permutation: Given two strings, write a method to decide if one is a permutation of the
    other.
*/

/*
    if both of the strings contains same characters and
    have the same length then one can be generated from
     the other string.
*/

#include <iostream>
#include <algorithm>
using namespace std;

/*
    if we sort both the strings and then check if both have same characters
    by iterating over the string.

    Time Complexity O(N*log(N))
    Space Complexity depends on the sorting algorithm.
*/

bool checkPermutation(string str1, string str2)
{
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    if (str1 == str2)
    {
        return true;
    }
    return false;
}
/*
    Insertion time O(1) and Searching time O(1)
    Time Complexity O(N)
    Space Complexity O(N)
*/

bool checkPermutation(string str1, string str2)
{
    if (str1.length() != str2.length())
        return false;
    int checker[str1.length()] = {0};

    for (int i = 0; i < str1.length(); i++)
    {
        checker[str1[i]]++;
    }
    for (int i = 0; i < str2.length(); i++)
    {
        checker[str2[i]]--;
        if (checker[i] < 0)
            return false;
    }
    return true;
}

int main()
{
    string str1 = "dog", str2 = "god", str3 = "doger";
    if (checkPermutation(str1, str2))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    return 0;
}
