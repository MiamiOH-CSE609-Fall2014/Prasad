/* Grades Calcualtion */
/**Curve Grading ****** */
/* Header */
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
       lower_A = 100.0 ;
     }
   lower_B = mean + 0.5*sd;
 
   lower_C = mean - 0.5*sd;
   
   lower_D = mean - 1.5*sd;
   

   cout << "Grading Scale " << endl;
   cout << "A" << " " << "above" << setprecision(1)<<fixed << " " << lower_A  << "%" << '\n' ;
   cout << '\n'; 
   cout << "B" << " "  << setprecision(1)<< fixed << lower_B << "%" << "-" <<setprecision(1)<< fixed <<lower_A<< "%" << '\n' ;
   cout<< '\n' ;     
   cout << "C" << " "  <<setprecision(1)<< fixed << lower_C << "%" << "-" <<setprecision(1)<<fixed << lower_B<< "%" << '\n' ;
   cout <<'\n';
   cout << "D" << " "  << setprecision(1) <<fixed<< lower_D << "%" << "-" <<setprecision(1) <<fixed<< lower_C<< "%" <<'\n' ;
   cout<<'\n';
   cout << "F" << " "  << "below" << setprecision(1) <<fixed<< " " << lower_D << "%" << '\n' ;


  
 

for (int i=0 ; i < count ; i++)
  {
    if (i == 0)
      {
	cout<< "Name" <<"                       " << "Score" <<"                     " << "Grades" <<endl;
      }
    cout << i+1 << "." << s1[i]  ;

    cout <<"               "<< setprecision(1) << fixed << s2[i] << "%";
    if ( sd == 0 )
      {
	cout <<"                    "<< "C" << '\n' ;
      }
    else
      {
    if (s2[i] > lower_A )
      {
	cout <<"                    "<< "A" << '\n'   ;
	  }
    else if ((s2[i] >  lower_B ) && (s2[i] <= lower_A ) )
      {
	cout <<"                    "<< "B" << '\n' ;
      }
    else if ((s2[i] > lower_C )  && (s2[i] <= lower_B) )
      {
	cout <<"                    "<< "C" << '\n'  ;
      }
    else if ((s2[i] >= lower_D ) && (s2[i] <= lower_C))
      {
	cout <<"                    "<< "D" << '\n' ;
      }
    else if (s2[i] < lower_D )
      {
	cout <<"                    "<< "F" << '\n' ;
      }
      }
    cout << '\n' ;

  }
 cout << "Class Average " << "=" << " " <<  setprecision(2)<< fixed <<  mean << "%" << '\n';
 cout << "Standard Deviation " << "=" <<" " << setprecision(2) <<fixed << sd << endl; 
 



}
