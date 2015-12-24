#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void parse(vector<string> &lines, string f)
{
  fstream file(f);
  string line;
  if (file.is_open())
  {

    while (getline(file,line))
    {
      lines.push_back(line);
    }
  }
  file.close();
}


int main()
{
  vector<string> ls;
  parse(ls,"input0.txt");
  int sum =0;
  for (int i =0; i < ls.size(); i++)
  {
    sum += 2;
    string temp ="";
    for (int j =0; j < ls[i].size()-1; j++)
    {
      if (!(ls[i][j] == '\\' && ls[i][j+1] == '\\') &&
          !(ls[i][j] == '\\' && ls[i][j+1] == '\"'))
      {
        temp += ls[i][j];
      }
    }
    string final = "";
    for (int j =0; j < temp.size()-1; j++)
    {
      if (temp[j]=='\\' && temp[j] =='x')
      {
        j+=3;
      }
      else
      {
        final+=temp[j];
      }
    }
    sum += (ls[i].size() - final.size());
  }
  cout << sum << endl;
}
