#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
  ifstream myfile("input0.txt");
  string line;
  int count =0;
  if (myfile.is_open())
  {
    while (getline(myfile,line))
    {
      bool onebetween = false;
      for (int i =0 ; i < line.size()-2; i++)
      {
        if (line[i] == line[i+2]) onebetween = true;
      }
      bool doubledouble = false;
      for (int i =0; i < line.size()-1; i++)
      {
        for (int j =i+2; j < line.size()-1;j++)
        {
          if (line[i] == line[j] && line[i+1] == line[j+1]) doubledouble=true;
        }
      }

      if (doubledouble && onebetween) count++;
    }
    myfile.close();
    cout << count << endl;
  }
}
