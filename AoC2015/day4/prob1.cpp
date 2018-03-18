#include <iostream>
#include <string>
#include "md5.h"
using namespace std;

string reverse(string a)
{
  string result ="";
  for (int i = a.size() -1; i >= 0; i--)
  {
    result += a[i];
  }
  return result;
}


string itoa(int a)
{
  string result="";

  do{
    result += ((a%10)+'0');
    a=a/10;

  }while (a != 0);
  return reverse(result);
}

string firstsix(string a)
{
  if (a.size() < 5) return "nope";
  else
  {
    string result ="";
    for (int i =0; i < 6; i++)
    {
      result+=a[i];
    }
    return result;
  }
}

int main()
{
  int guess = 0;
  bool notFound = true;
  string key = "iwrupvqb";
  while (notFound)
  {
    string result = md5(key+itoa(guess));
    cout << result << endl;
    if (firstsix(result)=="000000")
    {
      cout << "The answer is: " << guess << endl;
      notFound=false;
    }
    guess++;
  }
}
