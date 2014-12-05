#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<stdexcept>
#include<cmath>
#include<iomanip>
#include<map>
using namespace std;
void getdeadline(string &s1 , string &s2)
{
  double d1;
  d1 = atof(s1.c_str());
  double d2;
  d2 = atof(s2.c_str());
  
  if (d1 < d2 )
    {

      throw out_of_range(" Deadline Can't be less than the actual job processing time ") ;
    }


}

int partition(vector<double>& co, int left,int right);
void quickSort(vector<double>& co, int left,int right)
{
  int r;
  if(left<right)
    {
      r = partition(co, left ,right);
      quickSort(co,left,r);
      quickSort(co,r+1,right);
    }
}


int partition(vector<double>& co, int left,int right)
{
  int x= co[left];
  int i=left;
  int j;

  for(j=left+1; j<right; j++)
    {
      if(co[j]<=x)
        {
	  i=i+1;
	  swap(co[i],co[j]);
        }

    }

  swap(co[i],co[left]);
  return i;
}


int main()
{
  string s;
  string l;
  vector <double> s1;
  vector <double> s2;
  vector <double> s3;
  vector <double> start;
  vector <double> end;
  vector <double> l1;
  vector <double> start1;
  vector <double> end1;
  vector <double> l2;
  cout<< "Minimizing the maximum lateness Program  -->>c++ code "  << endl; 
  cout << "Enter the processing time of job " << endl; 
  while (getline(cin,s))
    {
        
if (s == "none" or s == "None")
	{
	  break;
	} 

 if (s.empty())
	{
	  cout << "Processing time  can't be left blank " << endl; 
	cout << "Enter the processing time of job " << endl;  
        continue;
        }

 if (!isdigit(s[0]))
   {
     cout << "Processing time can't be a string " << endl;
     cout << "Enter the processing time of job " << endl;
     continue;
   } 
    
    cout << "Enter the time deadline of job  " << endl ;
    getline(cin,l);
    try 
      {
	getdeadline(l,s);
      }
    catch (out_of_range)
      {
	cout << " Deadline Can't be less than actual job procesing time " << '\n';
        cout << "Enter the processing time of job " << endl;
        continue;
      }
    s1.push_back(atof(s.c_str()));
    s2.push_back(atof(l.c_str()));
    cout << "Enter the processing time of job" << endl; 
    }

  cout << "The given List of Processing Time and Job Deadline " << endl;
  for (int i =0 ; i < s1.size() ; i++) 
    {
      if (i == 0)
	{
	cout << "ProcessingTime :"  << " ";
    }
      cout << s1[i] << " ";
    
        

    }


  cout << '\n';   
for (int i =0 ; i < s2.size() ; i++) 
    {
      if (i == 0)
	{
	  cout << "Deadline :"  << "       ";
    }
      cout << s2[i] << " ";
    
        

    }

 map <double,double> m;
 for (int i =0 ; i < s2.size(); i++)
   {
     m[s2[i]] = s1[i];

   }


 double st;
 double en;
 double t = 0;
 
for (int i =0 ; i < s2.size() ; i++)
   {
    
     st = t;
     en = st + m[s2[i]];
     start.push_back(st);
     end.push_back(en);
     t = t + m[s2[i]] ;
   }   
 

 double sub;
 double sum = 0;  
 for (int i =0 ; i < end.size() ; i++)
   {
     sub = end[i] - s2[i];
     if (sub < 0) 
       {
	 sub = 0;
       }
     l1.push_back(sub);
     sum = sum + l1[i]; 
   }
 
 cout << '\n'; 
 cout << "The job scheduling without the greedy approach of picking early deadline" << endl;
 cout <<'\n';
 for (int i=0 ; i < s2.size(); i++)
   {
     if (i == 0)
       {
	 cout << setw(2)<< left << "Jobs" << right << setw(15) << "Start Time" <<right << setw(12)<< "End Time" << right << setw(11) << "Lateness ";
         cout<< '\n';
       }
     cout <<setw(2)<<left<< i+1 <<right<<setw(10)<<start[i] <<right<< setw(12)<<end[i] << right << setw(10)<<l1[i] ;
       cout << '\n';
}

 cout << " The totatl lateness here in(units of time) :" << sum ;



 /*Quick Sort Logic Implementation */ 

 int left = 0;
 int right = s2.size();
 quickSort(s2 , left , right);
 cout << '\n';  
 cout << "The List of Processing Time and Job Deadline after Quick sorted by time dealine " << endl;
 for (int i =0 ; i < s2.size() ; i++)
   {
     if (i == 0)
       {
	 cout << "ProcessingTime:"  << " ";
       }
     cout << m[s2[i]] << " ";

   }  

 cout << '\n' ;
 for (int i =0 ; i < s2.size() ; i++)
   {
     if (i == 0)
       {
         cout << "Deadline :"  << "      ";
       }
     cout << s2[i] << " ";

   }

 double st1;
 double en1;
 double t1 = 0;
 for (int i =0 ; i < s2.size() ; i++)
   {

     st1 = t1;
     en1 = st1 + m[s2[i]];
     start1.push_back(st1);
     end1.push_back(en1);
     t1 = t1 + m[s2[i]] ;
   }



 double sub1;
 double sum1 = 0;
 for (int i =0 ; i < end1.size() ; i++)
   {
    
     sub1 = end1[i] - s2[i];
     if (sub1 < 0)
       {
         sub1 = 0;
       }
     l2.push_back(sub1);
     sum1 = sum1 + l2[i];
   }

 cout << '\n';
 cout << "The job scheduling with the greedy approach of picking early deadline first"  << endl;
 cout << '\n' ;
 for (int i=0 ; i < s2.size(); i++)
   {
     if (i == 0)
       {
	 cout << setw(2) << "Jobs" << setw(15) << "Start Time" <<setw(12)<< "End Time" << setw(11) << "Lateness ";


         cout<< '\n';
       }
     cout <<setw(2)<< i+1 <<setw(10)<<start1[i] << setw(12)<<end1[i] <<setw(10)<<l2[i] ;

 
     cout << '\n';
   }

  cout << " The totatl lateness here in(units of time) :" << sum1 ;

 
  double answer = ((sum - sum1)/sum)*100;
  cout << '\n';

  if (answer == 0.00)
    {
      cout << "Case : User Input deadline data time is already sorted " << endl; 
    }


  if (sum == 0.00)
    {

      cout << " Case : Difference between deadline time and processing time is higher .Lateness is already optimized " << endl;
    } 
      else 
	{
	  cout << " Percentage reduction in Lateness Time " << setprecision(2) << fixed << answer << "%" << endl;


	}

    

}




























