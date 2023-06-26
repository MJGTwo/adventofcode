#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
  ifstream myfile("input0.txt");
  string line;
  int countVFlag =0;
  int count =0;
  bool doubleFlag = false;
  string vowels = "aeuoi";
  string bad[4] = {"ab", "cd", "pq", "xy"};
  bool badFlag = true;
  if (myfile.is_open())
  {
    while (getline(myfile,line))
    {
      doubleFlag=false;
      badFlag=true;
      countVFlag=0;
      for (int i =0; i < vowels.size(); i++)
      {
        if (line[0] == vowels[i])
        {
          countVFlag++;
        }
      }

      for (int i =0; i < line.size()-1; i++)
      {
        if (!doubleFlag)
        {
          if (line[i] == line[i+1]) doubleFlag = true;
        }

        string sub = "";
        sub += line[i];
        sub += line[i+1];
        if (badFlag)
        {
          for (int j =0; j < 4; j++)
          {
            if (sub == bad[j])
            {
              badFlag=false;
            }
          }
        }

        if (countVFlag < 3)
        {
          for(int j =0; j < vowels.size(); j++)
          {
            if (line[i+1] == vowels[j])
            {
              countVFlag++;
            }
          }
        }


      }



      if (countVFlag == 3 && badFlag && doubleFlag)
      {
        count++;
      }

    }
    myfile.close();
    cout << count << endl;
  }
}
