/*
    ** Note all these function have the same name,so before running the program
    ** comment out the other functions

    ** Book: Cracking the coding Interview by GAYLE LAAKMANN McDowELL.

    ** Code: Rajan Kumar Singh(rajan9519)

    ** Email: rajankumarsinghvnit@gmail.com
*/

/*
   Q: Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you
    cannot use additional data structures?
*/
#include <iostream>
#include <algorithm>

using namespace std;

//without using extra data structure
// * O(N2) time complexity and O(1) space complexity
bool isUniqueChars(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        for (int j = i + 1; j < str.length(); j++)
        {
            if (str[i] == str[j])
            {
                return false;
            }
        }
    }
    return true;
}
// * O(N*log(N)) time complexity and space depends on sorting algorithm used

bool isUniqueChars(string str)
{
    sort(str.begin(), str.end());
    for (int i = 0; i < str.length() - 1; i++)
    {
        if (str[i] == str[i + 1])
        {
            return false;
        }
    }
    return true;
}
// assuming ASCII characters only i.e 128 characters
// time complexity O(N) space complexity O(1)
bool isUniqueChars(string str)
{
    bool char_set[128];
    for (int i = 0; i < str.length(); i++)
    {
        int index = str[i];
        if (index)
        {
            return false;
        }
        char_set[index] = true;
    }
    return true;
}

// By Bit Manupulation.
// Taking 32 bit interger, consequenty we can have atmost 32 different characters
// we can take any one of lower case or Upper case english alphabets
// as both of then have only 26 different characters
// in this solution taking lower case 'a to z' alphabet

bool isUniqueChars(string str)
{

    int checker = 0;
    int index;
    for (int i = 0; i < str.length(); i++)
    {
        index = (str[i] - 'a');
        if (checker & (1 << index))
        {
            return false;
        }
        checker |= (1 << index);
    }
    return true;
}

int main()
{
    string str1 = "abcde", str2 = "asldkfhadsf";
    if (isUniqueChars(str1))
    {
        cout << "Unique";
    }
    else
    {
        cout << "Not Unique";
    }
    return 0;
}
