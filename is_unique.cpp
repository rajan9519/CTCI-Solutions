#include <iostream>

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
    str.sort();
    for (int i = 0; i < str.length() - 1; i++)
    {
        if (str[i] == str[i + 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
}