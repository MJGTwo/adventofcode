#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main()
{
  string line;
  int sum=0;
  ifstream myfile("file0.txt");
  if (myfile.is_open())
  {
    getline(myfile,line);
    cout << line.size() << endl;
  }
  for (int i =0; i < line.size(); i++)
  {
    if (line[i] == '(')
    {
      sum ++;
    }
    else
    {
      sum --;
    }

  }
  cout << sum << endl;
  myfile.close();
}
