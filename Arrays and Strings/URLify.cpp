/*
    ** Note all these function have the same names,so before running the program
    ** comment out the other functions

    ** Book: Cracking the coding Interview by GAYLE LAAKMANN McDowELL.

    ** Code: Rajan Kumar Singh(rajan9519)

    ** Email: rajankumarsinghvnit@gmail.com
*/

/*
   Q: URLify: Write a method to replace all spaces in a string with '%20'. You may assume that the string
        has sufficient space at the end to hold the additional characters, and that you are given the "true"
        length of the string. (Note: if implementing in Java, please use a character array so that you can
        perform this operation in place.)
        EXAMPLE
        Input: "Mr John Smith ", 13
        Output: "Mr%20John%20Smith"
*/
#include <iostream>
#include <algorithm>

using namespace std;

string URLify(string s,int length)
{
// count number of spaces in the given string
  int space_count = 0,new_legth ;
  for(int i=0;i<length;i++)
  {
    if(s[i] == ' ')
    {
      space_count++;
    }
  }
// "%20" is of legth 3 and we already have on character
// space for the replacing spaces(' ');
// the length of the new string will be (true_length + space_count*2)
new_legth = length + space_count*2;
  for(int i=length-1;i>=0;i--)
  {
    if(s[i] == ' ')
    {
      s[new_legth-1] = '0';
      s[new_legth-2] = '2';
      s[new_legth-3] = '%';
      new_legth -= 3;
    }
    else
    {
      s[--new_legth] = s[i];
    }
  }
  return s;
}

int main()
{
  string s = "Mr John Smith            ";
  int length =13;
  s = URLify(s,length);
  cout<<s;
  return 0;
}
