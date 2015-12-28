#include <iostream>
#include <string>
#include <fstream>
#include <utility>
#include <vector>
using namespace std;

class Person
{
  friend class Table;

public:
  Person(): left(NULL),right(NULL){;}
  Person(string n): name(n), left(NULL), right(NULL) {;}
  Person(const Person &othr)
  {
    this->name  = othr.name;
    this->left  = othr.left;
    this->right = othr.right;
    for (int i=0; i < othr.size(); i++)
    {
      this->relation.push_back(othr.relation[i]);
    }
  }

  const Person operator=(const Person& othr)
  {
    return Person(othr);
  }

  void add(string n, int happy)
  {
    pair<string, int> p;
    p.first = n;
    p.second = happy;
    relation.push_back(p);
  }
  const int size() const {return relation.size();}
  string getName()const{return name;}

private:
  string name;
  vector<pair<string, int> > relation;
  Person* left;
  Person* right;

};

class Table
{
public:
  Table(int s): chairs(s),seated(0)
  {
    family = new Person[s];
  }

  bool seatPerson(Person p)
  {
    family[seated++] = p;
    return true;
  }

  int size(){return seated;}

private:
  int chairs;
  int seated;
  Person *family;
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

void parse(string file, vector<Person> people)
{
  fstream f(file);
  string line;
  string caps = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  if(f.is_open())
  {
    while(getline(f,line))
    {
      string name = "";
      string other = "";
      string num = "";
      string word="";
      bool first = false;
      bool second = false;
      bool neg = false;
      for(int i =0; i < line.size(); i++)
      {
        char let = line[i];
        word += let;

        if (word == "lose")
        {
          neg = true;
        }
        else if (word == "gain")
        {
          neg = false;
        }
        if (let != ' ' && first)
        {
          name += let;
        }
        else if (let != ' ' && second)
        {
          other += let;
        }
        else if (let == ' ')
        {
          first = second = false;
          word ="";
        }
        else
        {
          for (int j =0; j < caps.size(); j++)
          {
            if (let == caps[j] && name == "")
            {
              name += let;
              first = true;
            }
            if (let == caps[j] && name != "" && other == "")
            {
              other += let;
              second = true;
            }
          }
        }
      }
      Person p(name);
      int k =0;
      for (; k < people.size(); k++)
      {
        if (name == people[k].getName())
        {
          p = people[k];
          break;
        }
      }
      p.add(other,atoi(num));
      people[k]=p;

    }
  }
}



int main()
{
  vector<Person> people;
  parse("input0.txt",people);
  for (int i=0; i< people.size(); i++)
  {
    cout << people[i].getName() << endl;
  }
}
