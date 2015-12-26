#include <iostream>
#include <string>
using namespace std;

bool rules(string password,string start)
{
  if (start == password){
    return false;
  }
  bool r1,r2,r3;
  r1=r2=r3=false;
  for (int i =0; i < password.size()-3;i++)
  {
    if ((password[i]+2) == (password[i+1]+1) && (password[i+1]+1) == (password[i+2]+0))
    {
      r1 = true;
      break;
    }
  }
  for (int i =0; i < password.size();i++)
  {
    if (password[i] == 'l' || password[i] == 'i' || password[i] == 'o')
    {
      r2= true;
      break;
    }
  }
  string p1, p2;
  p1 = p2 = "";
  int j;
  for (int i =0; i < password.size()-1; i++)
  {
    if (p1 == "")
    {
      if (password[i]==password[i+1])
      {
        p1=password.substr(i,2);
        j=i+1;
      }

    }
    else
    {
      if (password[i]==password[i+1] && i > j)
      {
        p2 = password.substr(i,2);
        if (p2 != p1) break;
      }
    }
  }
  if (p2 != p1 && p1.size() ==2  && p2.size() == 2) r3 = true;
  //cout << p1 << "\t" << p2 << endl;
  //cout << r1 << "\t"<< !r2 << "\t" << r3 << "\t" << endl;
  return (r1 && !r2 && r3);

}


int main()
{
  string input = "hepxxyzz";
  string start = input;
  int size = input.size();
  while(!rules(input,start))
  {
    int index = 0;
    bool carry = false;
    do
    {
      carry = false;
      if (input[size-1-(index%size)]== 'z')
      {
        input[size-1-(index%size)] = 'a';
        carry = true;
        index++;
      }
      else
      {
        input[size-1-(index%size)] = input[size-1-(index%size)] +1;
        cout << input << endl;
      }

    }while(carry && index != size);
  }

  //cout << 'a'+2 << 'b'+1 << 'c'+0 << endl;
}
