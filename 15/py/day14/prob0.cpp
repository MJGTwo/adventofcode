#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Reindeer
{
public:
  Reindeer(string n, int s, int t, int r): mName(n), mSpeed(s),mTravel(t),mRest(r),mTime(0),mDist(0){;}

  void move()
  {
    if (mTime % (mTravel+mRest) <= mTravel)
    {
      mDist += mSpeed;
    }
    mTime++;
  }
  int location()const{return mDist;}
  string name()const{return mName;}
private:
  string mName;
  int mSpeed;
  int mTravel;
  int mRest;
  int mTime;
  int mDist;
};

int atoi(string val)
{
  int result = 0;
  for (int i =0;i < val.size();i++)
  {
    result = result * 10;
    result += (val[i]-'0');
  }
  return result;
}

void parse(string file, vector<Reindeer> &rndrs)
{
  fstream f(file);
  string line;
  if(f.is_open())
  {
    while(getline(f,line))
    {
      int wordCount =0;
      string word ="";
      string name;
      int speed,travel, rest;
      for (int i =0; i < line.size(); i++)
      {
        char let = line[i];
        if (let == ' ')
        {
          wordCount++;
          if (wordCount ==1)
          {
            name = word;
          }
          else if (wordCount == 4)
          {
            speed = atoi(word);
          }
          else if (wordCount == 7)
          {
            travel = atoi(word);
          }
          else if (wordCount == 14)
          {
            rest = atoi(word);
          }
          word = "";
        }
        else
        {
          word += let;
        }
      }
      Reindeer temp(name,speed,travel,rest);
      rndrs.push_back(temp);
    }
  }
}


int main()
{
  vector<Reindeer> rndrs;
  parse("input0.txt",rndrs);

  int clock =0;
  while (clock <= 2503)
  {
    for (int i =0; i < rndrs.size(); i++)
    {
      rndrs[i].move();
    }
    clock++;
  }
  Reindeer *winner = &rndrs[0];
  for (int i =0; i < rndrs.size(); i++)
  {
    if (winner->location() < rndrs[i].location()) winner = &rndrs[i];
    cout << rndrs[i].name() <<":\t" << rndrs[i].location() << endl;
  }
  cout << "The winner is: " << winner->name() << endl;


}
