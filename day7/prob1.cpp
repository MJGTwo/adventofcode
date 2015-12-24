#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <locale>
#include <utility>
#include <map>
using namespace std;

typedef map< string, pair< vector<string>,string> > table;
typedef pair<string, pair< vector<string>,string> > entry;


vector<vector<string> > parse(string name)
{
  ifstream myfile(name);
  string line;
  vector< vector<string> > result;
  if (myfile.is_open())
  {

    while (getline(myfile,line))
    {
      vector<string> temp;
      string word = "";
      for (uint16_t i =0; i < line.size(); i++)
      {
        if (line[i] == ' ')
        {
          if (word != "->") temp.push_back(word);
          word = "";
        }
        else
        {
          word += line[i];
        }
      }
      temp.push_back(word);
      result.push_back(temp);


    }
    myfile.close();
  }
  return result;

}

uint16_t atoi(string val)
{
  uint16_t result = 0;
  for (uint16_t i =0;i < val.size();i++)
  {
    result = result * 10;
    result += (val[i]-'0');
  }
  return result;
}

string reverse(string str)
{
  string result = "";
  for (int i =str.size()-1; i>=0; i--)
  {
    result += str[i];
  }
  return result;
}

string itoa(uint16_t val)
{
  int i =0;
  if (val == 0)
  {
    return "0";
  }
  string result="";
  while (val != 0)
  {
    uint16_t r = val % 10;
    result += (r+'0');
    val = val/10;
  }
  return reverse(result);

}

bool ops(string word)
{
  return (word == "AND"     ||
          word == "OR"      ||
          word == "RSHIFT"  ||
          word == "LSHIFT"  ||
          word == "NOT"     );
}

vector<string> convert(vector<string> info, string op)
{
  if (op == "SAME")
  {
    return info;
  }
  else if (op == "NOT")
  {
    uint16_t result = ~atoi(info[0]);
    info[0] = itoa(result);
    return info;
  }
  else if (op == "AND")
  {
    uint16_t result = atoi(info[0]) & atoi(info[1]);
    info.pop_back();
    info[0] = itoa(result);
    return info;

  }
  else if (op == "OR")
  {
    uint16_t result = atoi(info[0]) | atoi(info[1]);
    info.pop_back();
    info[0] = itoa(result);
    return info;
  }
  else if (op == "RSHIFT")
  {
    uint16_t result = atoi(info[0]) >> atoi(info[1]);
    info.pop_back();
    info[0] = itoa(result);
    return info;
  }
  else if (op == "LSHIFT")
  {
    uint16_t result = atoi(info[0]) << atoi(info[1]);
    info.pop_back();
    info[0] = itoa(result);
    return info;
  }
}

void solve(table &w)
{

    bool change = true;
    while (change){
      change = !change;
      for (table::iterator itr=w.begin(); itr != w.end(); ++itr)
      {
        //cout << itr->first << endl;



        if ((itr->second).second == "NUM")
        {
          cout << (itr->first) << ":\t";
          for (int i =0; i < (itr->second).first.size(); i++)
          {
            cout << ((itr->second).first)[i] << " ";
          }
          cout << endl;
          for (table::iterator finder=w.begin(); finder != w.end(); ++finder)
          {
            pair<vector<string>, string> facts = finder->second;
            vector<string> vals = facts.first;
            for (int i =0; i < vals.size(); i++)
            {
              if (vals[i] == itr->first) vals[i] = ((itr->second).first)[0];
            }
            facts.first = vals;
            finder->second = facts;
            bool allnum = true;
            for (int i=0;i < vals.size(); i++)
            {
              if (!isdigit(vals[i][0])) allnum=false;
            }
            if (allnum && (finder->second).second != "NUM")
            {
              change = true;
              cout << (finder->second).second << endl;
              facts.first = convert(vals,(finder->second).second);
              finder->second = facts;
              (finder->second).second = "NUM";
            }
          }
        }
      }
      cout <<"*****************" << endl;
    }
}

int main()
{
  vector<vector<string> > rules = parse("input0.txt");
  table wires;
  table wires2;
  for (int i =0; i < rules.size(); i++)
  {
    string name;
    vector<string> vals;
    string op = "none";
    for (int j =0; j < rules[i].size(); j++)
    {
      if (j == rules[i].size()-1)
      {
        name = rules[i][j];
      }
      else if(ops(rules[i][j]))
      {
        op = rules[i][j];
      }
      else
      {
        vals.push_back(rules[i][j]);
      }

    }
    if (op == "none" && !isdigit(vals[0][0])) op = "SAME";
    else if (op == "none") op = "NUM";
    pair< vector<string>, string> p;
    p.first = vals;
    p.second = op;
    wires.insert(entry(name,p));
    wires2.insert(entry(name,p));
  }
  solve(wires);
  cout << ((wires.find("a")->second).first)[0] << endl;
  ((wires2.find("b")->second).first)[0] = ((wires.find("a")->second).first)[0];

  solve(wires2);
  cout << ((wires2.find("a")->second).first)[0] << endl;

}
