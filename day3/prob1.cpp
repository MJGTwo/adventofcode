#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <utility>
using namespace std;

int hashfun(int x, int y)
{
  return abs(x+y);
}

int main()
{
  int size =0;
  set<pair<int,int> > houses;
  ifstream myfile("input0.txt");
  vector<string> dims;
  string line;
  if (myfile.is_open())
  {
    getline(myfile,line);
    myfile.close();
  }
  pair<int,int> santaPos(0,0);
  pair<int,int> roboPos(0,0);
  houses.insert(santaPos);
  houses.insert(roboPos);
  pair<int,int> pos;
  for (int i =0; i < line.size(); i++)
  {
    if(i%2==0)  pos = santaPos;
    else  pos = roboPos;
    if (line[i] == 'v')
    {
      pos.second += -1;
    }
    else if (line[i] == '^')
    {
      pos.second += 1;
    }
    else if (line[i] == '>')
    {
      pos.first += 1;
    }
    else
    {
      pos.first += -1;
    }

    cout << pos.first << ", " << pos.second << endl;

    //cout << table.size() << endl;
    houses.insert(pos);
    if(i%2==0) santaPos=pos;
    else roboPos = pos;
  }
  cout << houses.size() << endl;
}
