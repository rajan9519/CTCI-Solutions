/*
    ** Note all these function have the same name,so before running the program
    ** comment out the other functions

    ** Book: Cracking the coding Interview by GAYLE LAAKMANN McDowELL.

    ** Code: Rajan Kumar Singh(rajan9519)

    ** Email: rajankumarsinghvnit@gmail.com
*/

/*
  Q: One Away: There are three types of edits that can be performed on strings:
      insert a character, remove a character, or replace a character. Given two
      strings, write a function to check if they are one edit (or zero edits) away.
    EXAMPLE
      pale, ple -> true
      pales, pale -> true
      pale, bale -> true
      pale, bake -> false
*/

#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;
/*
  if length of strings differ by a margin of more than 1 then they cannot by one
  or zero edits away.
  if both the string have the same length, that means there can only be replacement
  operation.
  if they differ by one then Insertion and Deletion is possible cases.
  Now Deletion and Insertion can be checked at the same time by taking the bigger
  size string and check for Deletion in it.

  Time complexity O(N)
  Space Complexity O(N)
*/

bool oneAway(string str1,string str2)
{
  int index1 = 0,index2 = 0;
  if(labs(str1.length()-str2.length()) > 1){
    return false;
  }
  string s1 = str1.length()>str2.length()?str1:str2;
  string s2 = str1.length()>str2.length()?str2:str1;
  bool foundDifference = false;

  while (index1 < s1.length() && index2 < s2.length()) {
    if (s1[index1] != s2[index2]) {
      /* Ensure that this the first differnce*/
      if(foundDifference){
        return false;
      }
      foundDifference = true;
      /* if both strings have same length then replacement operation
        So increment both index
      */
      if (s1.length() == s2.length()) {
        index2++;
      }
    } else {
      // increment both the pointers
      index2++;
    }
    index1++;
  }
  return true;
}

int main()
{
  string str1 = "pale",str2 = "bale";
  if (oneAway(str1,str2)) {
    cout<<"Yes";
  } else {
    cout<<"No";
    return 0;
  }
}
