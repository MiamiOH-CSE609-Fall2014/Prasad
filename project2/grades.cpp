#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
using namespace std;

int main()
{
  int count ;
  string  name;
  char  score[256];
  string score1;
  vector<string> s1;
  vector<double> s2;
  count = 0;
  cout << " Enter the name of the student or None to Quit  :"<< '\n' ;

  while (getline(cin,name))
    { 
      if (name == "none" or  name == "None")
	{
	  break;
	}
     s1.push_back(name);
     cout << " Enter the Student Mark's  :" << '\n' ;
     cin.getline(score,256);
     score1 = score;
     s2.push_back(atof(score1.c_str()));  
     cout << " Enter the name of the student or None to Quit  :"<< '\n' ;
     count = count +1;
    }
  cout << '\n' ;


 for (int i=0 ; i < count ; i++)
  {
    if (i == 0)
      {
	cout<< "Name" << " " << "Score" <<endl;
      }
    cout << i+1 << "." << s1[i] << " " ;
    cout <<" "<< s2[i]<< '\n'<< '\n' ;

  } 

}


