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
      for (int i =0; i < line.size(); i++)
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


class Node
{
public:
  Node(string n, int v): name(n),val(v)
  {
    next = NULL;
    prev = NULL;
    answer = true;
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
    nodes = NULL;
    //cout << "done!" << endl;
  }



  string name;
  int val;
  vector<string> info;
  Node*** nodes;
  string op;
  Node *next;
  Node *prev;

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
  int num(){return size;}

  void link()
  {
    Node * itr0 = head;
    for (int i =0; i < size; i++)
    {
      //cout << i << endl;
      if (!(itr0->answer))
      {
        //cout << itr0->op <<endl;
        if ((itr0->op)!= "RSHIFT" && (itr0->op) != "LSHIFT")
        {
          itr0->nodes = new Node**[2];
          for (int j =0; j < (itr0->info).size(); j++)
          {
            //cout << "SIZE: " << size << endl;
            string find = (itr0->info)[j];
            //cout << "LOOK: " << find << endl;
            Node * itr1 = head;

            for (int k =0; k < size; k++)
            {
              //cout << (itr1->name) << endl;
              if ((itr1->name) == find)
              {
                *(itr0->nodes+j) = &itr1;
                //cout << "found!" << endl;
                break;
              }
              itr1 = itr1->next;
            }
          }
        }
        else
        {
          itr0->nodes = new Node**[1];
          Node * itr1 = head;
          for (int k =0; k < size; k++)
          {
            if ((itr1->name) == (itr0->info)[0])
            {
              *(itr0->nodes) = &itr1;
              break;
            }
            itr1= itr1->next;
          }
        }
      }
    }
  }

  void solve()
  {
    bool change = true;
    while (change)
    {
      change = false;
      Node * itr = head;
      int i=0;
      while (i < size)
      {
        cout << itr->name << "\t" << i << endl;
        cout << (*(*(itr->nodes)))->name << endl;
        if (!(itr->answer))
        {
          cout << "yes" <<endl;
          if (itr->op == "NOT" && (*(*(itr->nodes)))->answer)
          {
            cout << "#0" << endl;
            itr->val = ~(*(*(itr->nodes)))->val;
            itr->answer = true;
          }
          else if (itr->op == "AND" && (*(*(itr->nodes)))->answer && (*(*(itr->nodes+1)))->answer)
          {
            cout << "#1" << endl;
            itr->val = (*(*(itr->nodes)))->val & (*(*(itr->nodes+1)))->val;
            itr->answer = true;
          }
          else if (itr->op == "OR" && (*(*(itr->nodes)))->answer && (*(*(itr->nodes+1)))->answer)
          {
            cout << "#2" << endl;
            itr->val = (*(*(itr->nodes)))->val | (*(*(itr->nodes+1)))->val;
            itr->answer = true;
          }
          else if (itr->op == "RSHIFT" && (*(*(itr->nodes)))->answer)
          {
            cout << "#3" << endl;
            itr->val = (*(*(itr->nodes)))->val << atoi(itr->info[1]);
            itr->answer = true;
          }
          else if (itr->op == "LSHIFT" && (*(*(itr->nodes)))->answer)
          {
            cout << "#4" << endl;
            itr->val = (*(*(itr->nodes)))->val >> atoi(itr->info[1]);
            itr->answer = true;
          }

          if (itr->answer)
          {
            change = true;
          }
        }

        i++;
        itr = itr->next;
      }
    }
  }

  Node * start() const {return  head;}
  Node * end() const {return tail;}

private:
  Node * head;
  Node * tail;
  int size;
};




int main()
{
  vector<vector<string> > rules = parse("input0.txt");
  vector<string> names;
  LinkedNodes l;
  for (int i =0; i < rules.size(); i++)
  {
    names.push_back(rules[i].back());
    rules[i].pop_back();
    l.add( new Node(names[i],rules[i]));
  }
  l.link();
  l.solve();



}
