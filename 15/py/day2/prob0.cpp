#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int atoi(string a)
{
  int sum = 0;
  for (int i =0; i < a.size(); i++)
  {
    sum = sum * 10;
    sum += a[i] - '0';
  }
  return sum;
}

class box{
public:
  box(string dim)
  {
    string temp = "";
    int count =0;
    for (int i =0; i <= dim.size(); i++)
    {
      if (dim[i] == 'x' || i == dim.size())
      {
        //cout << temp << endl;
        if (count == 0)
        {
          //cout << "C0: " <<count << endl;
          l = atoi(temp);
          //cout << l << endl;
        }
        else if (count == 1)
        {
          //cout << "C1: " <<count << endl;
          w = atoi(temp);
          //cout << w << endl;
        }
        else
        {
        //  cout << "C2: " <<count << endl;
          h = atoi(temp);
          //cout << h << endl;
        }
        count++;
        temp = "";
      }
      else
      {
        temp+=dim[i];
      }
    }
  }
  int* side()
  {
    static int s[4];
    s[0] = 2*l*w;
    s[1] = 2*w*h;
    s[2] = 2*h*l;
    int minm = s[0]/2;
    for (int i = 1; i < 3; i++)
    {
      if (minm > s[i]/2)
      {
        minm = s[i]/2;
      }
    }
    
    s[3] = minm;
    return s;

  }
  int total()
  {
    int sum =0;
    int* sides = side();
    for (int i =0; i < 4; i++)
    {
      sum += *(sides+i);
    }
    return sum;
  }

private:
  int l;
  int w;
  int h;


};

int main()
{


  ifstream myfile("input0.txt");
  vector<string> dims;
  string line;
  if (myfile.is_open())
  {
    while(getline(myfile,line))
    {
      dims.push_back(line);
    }
    myfile.close();
  }
  int wrapping =0;
  for (int i =0; i < dims.size(); i++)
  {
    box a(dims[i]);
    wrapping += a.total();
  }
  cout << wrapping << endl;

}
