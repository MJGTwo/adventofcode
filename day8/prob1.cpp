#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int atoi(string val)
{
  uint16_t result = 0;
  for (uint16_t i =0;i < val.size();i++)
  {
    result = result * 10;
    result += (val[i]-'0');
  }
  return result;
}

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

bool ishexd(char c)
{
  string rule = "1234567890abcdef";
  for (int i =0; i < 16; i++)
  {
    if (c == rule[i]) return true;
  }
  return false;
}

int main()
{
  vector<string> ls;
  parse(ls,"input0.txt");
  int sum =0;
  for (int i =0; i < ls.size(); i++)
  {
    int start = ls[i].size();
    string line = ls[i];
    string expand = "\"";
    for (int j=0; j < line.size();j++)
    {
      if (line[j] == '\\' )
      {
        expand+='\\';
        expand+='\\';
      }
      else if (line[j] == '\"')
      {
        expand += '\\';
        expand += '\"';
      }
      else
      {
        expand += line[j];
      }
    }
    expand+="\"";
    //cout << start << "\t" << expand << endl;
    sum += (expand.size() - start);
  }
  cout << sum << endl;
}
