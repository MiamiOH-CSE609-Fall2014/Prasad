#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<stdexcept>
#include<cmath>
using namespace std;

void getmarks(string &m)
{
  double marks;
  cout << " Enter the Student Mark's  :" << '\n' ;
  getline(cin,m);
  marks = atof(m.c_str());
  if ((marks < 0.0) or (marks > 100.0))
    {
      throw range_error ("Range error Score Not Between 0 and 100 ");
    }

}
int main()
{
  int count ;
  double sum;
  double sum1; 
  double mean;
  double sd; 
  string  name;
  string  score;
  vector<string> s1;
  vector<double> s2;
  vector<double> s3;

  count = 0;
cout << " Enter the name of the student or None to Quit  :"<< '\n' ;

  while (getline(cin,name))
    { 
      if (name == "none" or  name == "None")
	{
	  break;
	}
      s1.push_back(name);
     try
       {
	 getmarks(score);
       }
     catch (range_error)
       {
	 cout << " Range error: Enter Score between 0 and 100 " << '\n';
         getmarks(score);
       	
        }
     s2.push_back(atof(score.c_str()));  
     cout << " Enter the name of the student or None to Quit  :"<< '\n' ;
     count = count +1;
    }
  cout << '\n' ;

   sum = 0;

   for (int n=0 ; n < count ; n++) 
    {
      sum = sum + s2[n] ;
    } 
   mean = sum / count;

   for (int n=0 ; n < count ; n++)
     {
       s3.push_back(pow((s2[n]-mean),2));
     }
   
   sum1 =0;  
   for (int n=0 ; n < count ; n++)
     {
       sum1 = sum1 + s3[n];
     }
 
   sd = sqrt(sum1 / count );
   

 

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


