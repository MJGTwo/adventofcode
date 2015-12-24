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
    string temp ="";
    for (int j =0; j < ls[i].size()-1; j++)
    {
      if (!(ls[i][j] == '\\' && ls[i][j+1] == '\\') &&
          !(ls[i][j] == '\\' && ls[i][j+1] == '\"'))
      {
        temp += ls[i][j];
      }
      else if ((ls[i][j] == '\\' && ls[i][j+1] == '\\'))
      {
        j++;
        temp += '\\';
      }
      else if (!(ls[i][j] == '\\' && ls[i][j+1] == '\"'))
      {
        j++;
        temp += '\"';
      }

    }
    temp += ls[i][ls[i].size()-1];
    string final = "";
    for (int j =0; j < temp.size()-1; j++)
    {
      if (temp[j]=='\\' && temp[j+1] =='x' && ishexd(temp[j+2])&& ishexd(temp[j+3]))
      {
        int num = atoi(temp.substr(j+2,1))*16 + atoi(temp.substr(j+3,1));
        char h = num;
        final += h;
        j+=3;
      }
      else
      {
        final+=temp[j];
      }
    }
    final+=temp[temp.size()-1];
    temp = final;
    final="";
    for (int j=0; j < temp.size(); j++)
    {
      if (temp[j]!='"' || (j != 0 && j != temp.size()-1)) final+=temp[j];
    }

    sum += (ls[i].size() - final.size());
  }
  cout << sum << endl;
}
