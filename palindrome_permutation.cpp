/*
    ** Note all these function have the same name,so before renning the program
    ** comment out the other functions

    ** Book: Cracking the coding Interview by GAYLE LAAKMANN McDowELL.

    ** Code: Rajan Kumar Singh(rajan9519)

    ** Email: rajankumarsinghvnit@gmail.com
*/

/*
  Q: Palindrome Permutation: Given a string, write a function to check if it is a
    permutation of a palindrome. A palindrome is a word or phrase that is the
    same forwards and backwards. A permutation is a rearrangement of letters.
    The palindrome does not need to be limited to just dictionary words.

    EXAMPLE
    Input: Tact Coa
    Output: True (permutations: "taco cat", "atco eta", etc.)
*/

#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
/*
  For having a palindrome atmost one character in the string can have odd
  frequency and all other charaters should have even frequencies
*/
/*
  By using hashtable and counting frequency of each character.
  Neglecting spaces(' ') in the string.
*/
// this is case sensitive solution where 'T' is not same as 't'
bool isPermutaionOfPalindrome(string str)
{
  // getting frequencies of each character and neglecting spaces
  unordered_map<char,int> frequency;
  unordered_map<char,int>::iterator itr;
  int count = 0;
  for(int i=0;i<str.length();i++)
  {
      if(str[i] != ' ')
      {
        frequency[str[i]]++;
      }
  }
  // check if more than one character have odd frequency;
  for(itr = frequency.begin();itr != frequency.end(); ++itr)
  {
    if(itr->second % 2)
    {
      count++;
    }
  }
  if(count > 1)
  {
    return false;
  }
  return true;
}

/*
 Assuming only lowercase alphabet character and spaces are only in the string.
 using bitvector to get the odd and even frequencies.
 XOR table
 0 0 => 0
 0 1 => 1
 1 0 => 1
 1 1 => 0

 from the above table it can be observed that if of the bit is set i.e 1
 then the XOR will generator negation of other bit.
 0 => 1
 1 => 0

* here we can use a 32 bit interger because we can have atmost 26 different
 characters
* Determining number of set bits in the the bit vector
 if only one charater has odd count then we will be having something like this
 bitvector
  0000001000000
  now subtracting 1 from this bitvector will give
  0000001000000 - 1 = 0000000111111
  now taking bitwise and will give 0.

  So by this operation we can see that is there is only one bit is set i.e 1
  then the above operation will give 0 otherwise some interger.
*/

bool isPermutaionOfPalindrome(string str)
{
    int frequency = 0,index;
    // storing only the information about odd and even count
    for(int i=0;i<str.length();i++)
    {
      // get the index of the character
      if(str[i] != ' ')
      {
        index = str[i]-'a';
        frequency ^= (1<<index);
      }
    }
    if(frequency & (frequency -1))
    {
      return false;
    }
    return true;
}


int main()
{
  string str = "tact coa";
  if(isPermutaionOfPalindrome(str))
  {
    cout<<"Yes";
  }
  else
  {
    cout<<"No";
  }
  return 0;
}
