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
  cout<< "Minimizing the maximum lateness Program  -->>c++ code "  << endl; 
  cout << "Enter the processing time of job " << endl; 
  while (getline(cin,s))
    {
    if (s == "none" or s == "None")
	{
	  break;
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
	cout << "tj"  << " ";
    }
      cout << s1[i] << " ";
    
        

    }


  cout << '\n';   
for (int i =0 ; i < s2.size() ; i++) 
    {
      if (i == 0)
	{
	cout << "dj"  << " ";
    }
      cout << s2[i] << " ";
    
        

    }

 map <double,double> m;
 for (int i =0 ; i < s2.size(); i++)
   {
     m[s2[i]] = s1[i];

   }


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
	 cout << "tj"  << " ";
       }
     cout << m[s2[i]] << " ";

   }  

 cout << '\n' ;
 for (int i =0 ; i < s2.size() ; i++)
   {
     if (i == 0)
       {
         cout << "dj"  << " ";
       }
     cout << s2[i] << " ";

   }



}






























