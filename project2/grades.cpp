/* Grades Calcualtion */
/**Curve Grading ****** */
/* Header Include Files */
#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<stdexcept>
#include<cmath>
#include<iomanip>
using namespace std;

/*Function Module to Catch The Range Error for student marks*/
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
  int count ;     /* Counting the number of data enteries*/
  double sum;     /*for total marks*/ 
  double sum1; 
  double mean;    /*for mean*/
  double sd;     /*for standard deviation*/
  string  name;   
  string  score;
  vector<string> s1;  /*for storing name in a vector array */
  vector<double> s2;  /*for storing student marks*/
  vector<double> s3;
  double lower_A;    
  double lower_B;
  double lower_C;
  double lower_D;


  count = 0;
cout << " Enter the First and Last name of the student or None to Quit  :"<< '\n' ;

 while (getline(cin,name))  /* Getting Student Name */
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
     s2.push_back(atof(score.c_str())); /*converting string to float*/ 
     cout << " Enter the First and Last name of the student or None to Quit  :"<< '\n' ;
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
     
   /*Grade Ranges Calculation*/
   lower_A = mean + 1.5*sd ;
   if (lower_A > 100.0)
     {
       lower_A = 100.0 ;
     }
   lower_B = mean + 0.5*sd;
 
   lower_C = mean - 0.5*sd;
   
   lower_D = mean - 1.5*sd;
 
   if (count != 0)
     {  
   /*Setprecison and fixed to round the percentage marks in given number of decimal points : 1 or 2 as per the required output*/ 
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
     }

  
   if (count != 0)
     {
for (int i=0 ; i < count ; i++)
  {
    if (i == 0)
      {
	cout<< "Name" <<"                            " << "Score" <<"                     " << "Grade" <<endl;
      }
    cout << i+1 << "." << s1[i]  ;

    cout <<"                      "<< setprecision(1) << fixed << s2[i] << "%";
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

   if (count == 0 )
     {
       cout << " Insufficient Data to compute the statistical result " << endl;
     }
  


}
