/* Grades Calcualtion */

#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<stdexcept>
#include<cmath>
#include<iomanip>
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

int length(int &i)
{
  int count1 = 1;
  while (i /= 10)
    {
      count1++;
    }
  return count1;
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
  double lower_A;
  double lower_B;
  double lower_C;
  double lower_D;


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
   mean = sum / count ;

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
     

   lower_A = mean + 1.5*sd ;
   if (lower_A > 100.0)
     {
       lower_A = 100.0;
     }
   int i1 = lower_A;
   int c1 = length(i1) + 1;
   lower_B = mean + 0.5*sd;
   int i2 = lower_B;
   int c2 = length(i2) + 1;
   lower_C = mean - 0.5*sd;
   int i3 = lower_C;
   int c3 = length(i3) + 1;
   lower_D = mean - 1.5*sd;
   int i4 = lower_D;
   int c4 = length(i4) + 1;


   
   cout << "Grading Scale " << endl;
   cout << "A" << " " << "above" << setprecision(c1) << " " << lower_A  << "%" << '\n' ;
   cout << '\n'; 
   cout << "B" << " "  << setprecision(c2)<< lower_B << "%" << "-" <<setprecision(c1)<<lower_A<< "%" << '\n' ;
   cout<< '\n' ;     
   cout << "C" << " "  <<setprecision(c3)<< lower_C << "%" << "-" <<setprecision(c2)<<lower_B<< "%" << '\n' ;
   cout <<'\n';
   cout << "D" << " "  << setprecision(c4) << lower_D << "%" << "-" <<setprecision(c3) <<lower_C<< "%" <<'\n' ;
   cout<<'\n';
   cout << "F" << " "  << "below" << setprecision(c4) << " " << lower_D << "%" << '\n' ;


  
 

for (int i=0 ; i < count ; i++)
  {
    if (i == 0)
      {
	cout<< "Name" <<"                       " << "Score" <<"                     " << "Grades" <<endl;
      }
    cout << i+1 << "." << s1[i]  ;
    int i7 = s2[i];
    int c7 = length(i7) + 1;
    cout <<"               "<< setprecision(c7) << s2[i] << "%";
    if (s2[i] > lower_A )
      {
	cout <<"                    "<< "A" << '\n'   ;
	  }
    else if ((s2[i] >  lower_B ) && (s2[i] < lower_A ) )
      {
	cout <<"                    "<< "B" << '\n' ;
      }
    else if ((s2[i] > lower_C )  && (s2[i] < lower_B) )
      {
	cout <<"                    "<< "C" << '\n'  ;
      }
    else if ((s2[i] > lower_D ) && (s2[i] < lower_C))
      {
	cout <<"                    "<< "D" << '\n' ;
      }
    else if (s2[i] < lower_D )
      {
	cout <<"                    "<< "F" << '\n' ;
      }
    cout << '\n' ;

 
  }

 int i5 = mean;
 int c5 = length(i5) + 2;
 cout << "Class Average " << "=" << " " <<  setprecision(c5)<< mean << "%" << '\n'; 
 int i6= sd;
 int c6 = length(i6) + 2;
 cout << "Standard Deviation " << "=" <<" " << setprecision(c6) <<sd << endl; 
 

}


