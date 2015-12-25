#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
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

void parse(set<string> &cs, map<int,pair<string,string> > &ps)
{
  fstream f("input0.txt");
  string line;
  if (f.is_open())
  {

    while (getline(f,line))
    {
      string word = "";
      pair<string,string> p;
      int dist;
      int count=0;
      for (int i=0;i<line.size();i++)
      {
        if(line[i] == ' ')
        {
          if (word != "to" && word != "=")
          {
            if (!isdigit(word[0]))
            {
              cs.insert(word);
              if (count ==0)
              {
                p.first = word;
                count ++;
              }
              else p.second=word;
            }
          }
          word = "";

        }
        else
        {
          word+=line[i];
        }
      }
      dist = atoi(word);
      //cout << dist << "\t" << p.first << "\t" << p.second << endl;
      pair<int, pair<string,string> > q;
      q.first = dist;
      q.second = p;
      ps.insert(q);
    }
  }
  f.close();
  cout << "SIZE: " << ps.size() << endl;
}

class Node
{
public:
  Node(string n): name(n) {;}



  string name;
  vector<pair<Node*,int> > ns;
  Node * next;
  Node * prev;
};

class Edges
{
public:
  Edges():head(NULL),tail(NULL),count(0){;}
  Edges(Node n)
  {
    head = tail = &n;
    count++;
  }
  Edges(Node *n)
  {
    head = tail = n;
    count++;
  }
  ~Edges()
  {
    Node * n= head;
    while(n->next)
    {
      del(head);
      head = n;
      n=n->next;
    }
  }


  int size() const {return count;}

private:
  void del(Node *n)
  {
    delete n;
    n = NULL;
    count--;
  }
  Node *head;
  Node *tail;
  int count;
};

int main()
{
  set<string> cities;
  map<int,pair<string,string> > paths;
  map<int,pair<string,string> > used;
  parse(cities,paths);
  int numC = cities.size();
  cities.clear();
  int count =0;
  int oldcount =cities.size();
  int sum =0;
  for (map<int,pair<string,string> >::iterator itr = paths.begin(); itr != paths.end(); ++itr)
  {
    if (oldcount == numC) break;
    else oldcount=count;
    cities.insert((itr->second).first);
    cities.insert((itr->second).second);
    //cout << itr->first << ":\t" << (itr->second).first << ", " << (itr->second).second<< endl;
    count = cities.size();
    if (count!=oldcount)
    {
      cout << itr->first << ":\t" << (itr->second).first << ", " << (itr->second).second<< endl;
      used.insert(*itr);
      sum += itr->first;
    }
  }
  cout << count << endl;
  cout << sum << endl;


}
