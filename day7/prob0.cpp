#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <locale>
using namespace std;

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


class Node
{
public:
  Node(string n, uint16_t v): name(n),val(v)
  {
    next = NULL;
    prev = NULL;
    answer = true;
    rule1 =NULL;
    rule2 = NULL;
  }
  Node(string n, vector<string> relation): name(n)
  {
    if (relation.size() == 2)
    {
      op = relation[0];
      info.push_back(relation[1]);
      answer = false;
    }
    else if (relation.size() == 1)
    {
      string temp = relation[0];
      if (isdigit(temp[0]))
      {
        val = atoi(temp);
        answer = true;
      }
      else
      {
        op = "SAME";
        info.push_back(temp);
        answer = false;
      }
    }
    else if (relation.size() == 3)
    {
      info.push_back(relation[0]);
      info.push_back(relation[2]);
      op = relation[1];
      answer= false;
    }
    next = NULL;
    prev = NULL;
    rule1 = NULL;
    rule2 = NULL;
    //cout << "done!" << endl;
  }



  string name;
  uint16_t val;
  vector<string> info;
  string op;
  Node *next;
  Node *prev;
  Node *rule1;
  Node *rule2;

  bool answer;

};

class LinkedNodes
{
public:
  LinkedNodes():head(NULL),tail(head),size(0){}

  ~LinkedNodes()
  {
    tail->next = NULL;
    head->prev = NULL;
    del(head);
  }

  void add(Node *n)
  {
    if (size == 0)
    {
      head = tail = n;
    }
    else
    {
      tail->next = n;
      n->prev = tail;
      n->next = head;
      head->prev = n;
      tail = n;
    }



    size++;
  }

  void del(Node *n)
  {
    if (n != NULL)
    {
      del(n->next);
      delete n;
      n = NULL;
    }
  }
  uint16_t num(){return size;}

  void link()
  {
    Node * itr0 = head;
    for (uint16_t i =0; i < size; i++)
    {
      //cout << i << endl;
      if (!(itr0->answer))
      {
        //cout << itr0->op <<endl;
        for (uint16_t j =0; j < (itr0->info).size(); j++)
        {
          //cout << "SIZE: " << size << endl;
          string find = (itr0->info)[j];
          //cout << itr0->name << " LOOKING FOR: " << find << endl;
          Node * itr1 = head;
          if (isdigit((itr0->info)[j][0]))
          {
            Node * n = new Node((itr0->info)[j],atoi((itr0->info)[j]));
            cout <<"NAME: "<<(itr0->name)<< " VALUE: " << n->val << endl;

            if (j == 0) itr0->rule1 = n;
            else itr0->rule2 = n;
          }
          else
          {
            for (uint16_t k =0; k < size; k++)
            {
              //cout << (itr1->name) << endl;
              if ((itr1->name) == find)
              {
                if (j == 0) itr0->rule1 = itr1;
                else itr0->rule2 = itr1;
                //if (j ==0 && i ==1) cout << "HERE: " <<itr1->name << endl;
                break;
              }
              itr1 = itr1->next;
            }
          }

        }
      }
      itr0= itr0->next;
    }
  }

  void solve()
  {
    bool change = true;
    while (change)
    {
      change = false;
      Node * itr = head;
      uint16_t i=0;
      while (i < size)
      {
        //cout << itr->name << "\t" << i << endl;
        if (!(itr->answer))
        {
          //cout << "test0" << endl;
          cout << itr->name << "\t" << itr->op << ":\t" <<(itr->rule1)->name;
          if (itr->name == "e")
          {
            cout << "testtesttest " << (itr->rule1)->val << " " <<  (itr->rule2)->val << endl;
          }
          if (itr->op == "NOT" || itr->op == "RSHIFT" || itr->op == "LSIGHT")
          {
            //cout << "test1" << endl;
            //cout << (itr->rule1)->answer << endl;
            cout << endl;
            if (itr->op == "NOT" && (itr->rule1)->answer)
            {
              //cout << "test2" << endl;

              itr->val = ~((itr->rule1)->val);

              itr->answer = true;
            }
            else if ((itr->rule1)->answer)
            {
              if (itr->op == "RSHIFT")
              {
                itr->val = ((itr->rule1)->val) >> (itr->rule2)->val;
                itr->answer = true;
              }
              else
              {
                itr->val = ((itr->rule1)->val) << (itr->rule2)->val;
                itr->answer = true;
              }
            }
          }
          else if (itr->op == "AND" && (itr->rule1)->answer && (itr->rule2)->answer)
          {
            cout << "\t" <<(itr->rule2)->name<<endl;
            itr->val = (itr->rule1)->val & (itr->rule2)->val;
            itr->answer = true;
          }
          else if (itr->op == "OR" && (itr->rule1)->answer && (itr->rule2)->answer)
          {
            cout << "\t" <<(itr->rule2)->name<<endl;
            itr->val = (itr->rule1)->val | (itr->rule2)->val;
            itr->answer = true;
          }
          else if (itr->op == "SAME" && (itr->rule1)->answer)
          {
            cout << endl;
            itr->val = (itr->rule1)->val;
            itr->answer = true;
          }

          if (itr->answer)
          {
            change = true;
          }
          else
          {
            cout << endl;
          }
        }

        i++;
        itr = itr->next;
      }
    }
  }
  uint16_t find(string name)
  {
    Node * finder = head;
    for (uint16_t i =0; i < size; i++)
    {
      if (finder->name == name)
      {
        return finder->val;
      }
      finder=finder->next;
    }

  }
  Node * start() const {return  head;}
  Node * end() const {return tail;}

private:
  Node * head;
  Node * tail;
  uint16_t size;
};




int main()
{
  vector<vector<string> > rules = parse("input0.txt");
  vector<string> names;
  LinkedNodes l;
  for (uint16_t i =0; i < rules.size(); i++)
  {
    names.push_back(rules[i].back());
    rules[i].pop_back();
    l.add( new Node(names[i],rules[i]));
  }
  l.link();
  l.solve();

  Node * itr = l.start();
  for (uint16_t i =0; i < l.num(); i++)
  {
    cout << itr->name << ":\t"<< itr->val <<endl;
    itr=itr->next;
    if (itr->name == "e")
    {
      cout << itr->op << " "<<(itr->rule2)->val<< endl;
    }
  }
  cout << "a: " << l.find("a") << endl;

}
