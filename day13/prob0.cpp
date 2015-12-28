#include <iostream>
#include <string>
#include <fstream>
#include <utility>
#include <vector>
using namespace std;

int atoi(string val);

class Person
{
  friend class Table;

public:
  Person(): mLeft(NULL),mRight(NULL),mMax(0){;}
  Person(string n): mName(n), mLeft(NULL), mRight(NULL),mMax(0) {;}
  Person(const Person &othr)
  {
    this->mName  = othr.mName;
    this->mLeft  = othr.mLeft;
    this->mRight = othr.mRight;
    for (int i=0; i < othr.size(); i++)
    {
      this->mRelation.push_back(othr.mRelation[i]);
    }
  }

  const Person operator=(const Person& othr)
  {
    return Person(othr);
  }

  void add(string n, string happy)
  {
    if (mRelation.size() ==0) mMax =0;
    else if (atoi(happy) > atoi(mRelation[mMax][1])) mMax = mRelation.size();
    vector<string> info;
    info.push_back(n);
    info.push_back(happy);
    info.push_back("0");
    mRelation.push_back(info);
  }

  const int size() const {return mRelation.size();}
  string name()const{return mName;}
  pair<string,string>* ideal() const
  {
    pair<string,string>* p = new pair<string,string>;
    p->first = (mRelation[mMax][0]);
    p->second = (mRelation[mMax][1]);
    return p;
  }

private:
  string mName;
  vector<vector<string> > mRelation;
  Person* mLeft;
  Person* mRight;
  int mMax;

};

class Table
{
public:
  Table(int s): mChairs(s),mSeated(0)
  {
    mFamily = new Person[s];
  }

  bool seatPerson(Person p)
  {
    mFamily[mSeated++] = p;
    return true;
  }

  int size(){return mSeated;}

private:
  int mChairs;
  int mSeated;
  Person *mFamily;
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

void parse(string file, vector<Person> &people)
{
  fstream f(file);
  string line;
  if(f.is_open())
  {
    while(getline(f,line))
    {
      string name = "";
      string other = "";
      string num = "";
      string word="";
      int wordCount=0;
      bool neg = false;
      for(int i =0; i < line.size(); i++)
      {
        char let = line[i];
        if (let == ' ' || let == '.')
        {
          wordCount++;
          if (wordCount == 1)
          {
            name = word;
          }
          else if (wordCount == 3 && word == "lose")
          {
            neg = true;
          }
          else if (wordCount == 4)
          {
            num = word;
          }
          else if (wordCount == 11)
          {
            other = word;
          }
        }
        else
        {
          word += let;
        }
      }
      Person p(name);
      int k =0;
      for (; k < people.size(); k++)
      {
        if (name == people[k].name())
        {
          p = people[k];
          break;
        }
      }
      p.add(other,num);
      if (k == people.size()) people.push_back(p);
      else people[k]=p;

    }
  }
}



int main()
{
  vector<Person> people;
  parse("input0.txt",people);
  Person* itr = &people[0];
  for (int i=0; i< people.size(); i++)
  {
    cout << people[i].name() << endl;
  }

}
