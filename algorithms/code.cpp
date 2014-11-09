#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<stdexcept>
#include<cstdlib>
#include<iomanip>
using namespace std;
/* This is a Program to demonstrate the spectrum assignment problem */
/*Process/Alogorithm is in sync with the Resource Management Strategies */
/*Below spectrum assignment is done for a: 4*4 MIMO (Multi Input and Output )system */
/* such that :Number of Source Nodes =4 and Destination Nodes = 4*/
/* Specifications
Input :
Spectrum  Available = 3200GHz - 3600GHz
Total Available  Capacity  = 400 GHz (3600 - 3200 )
Guard Band Between each traffic demand  = 5GHz
New Available Spectrum = 3215GHZ - 3615GHz
Traffic Input Demand Matrix --->[ User Input: For 4 source input Nodes :ti ]
Size[4 * 1]
Total Calculated Capacity = (t1 + t2 + t3 + t4 + 3*5(Guard Band in between) )
------->( t1--- 5 -- t2 --- 5 -- t3 --5--  t4)
*/
void  gettraffic(string &s2) 
{
  double tn;
   
  tn = atof(s2.c_str());
  if ((tn < 800.0 ) or (tn > 900.0)) 
  {
    throw range_error ("Range error Traffic Data Not Between 800GHz and 900GHZ ") ;
  }
 

}

int main()
{
  
  string s ;
  int c;
  vector<double>  t;
    
  cout << "Input Spectrum Available For a 4*4 MIMO OFDM system with a guard band of 5GHz is : " << endl;
  cout<<" <----Spectrum :(3215GHz - 3615GHz) ------------------------------------------------------->" << endl;
  cout<<"To ensure Spectrum Contiguity Constraint : Total Divison Should be as per available spectrum " << endl ; 
  cout << "Traffic Demand Ranges : Min Demand  = (3200/4 = 800 GHz) and  Max Demand = (3600/4 = 900GHz)" << endl ;
  cout << '\n' ;
  
  cout << "Enter the User Traffic Demand  in GHZ for a 4*4 MIMO OFDM system " << endl; 
  while (getline(cin,s,'\n'))
    {    
try 
  {
   gettraffic(s);
   }


 catch(range_error)
   {
     cout << "Enter traffic data : between 800 and 900 GHz (:Spectrum Contiguity Constraint) " << '\n';
     
     continue;
   }
    
 t.push_back(atof(s.c_str()));
 if (t.size()  == 4)
   {
     cout << " Sufficient Input Spectrum Traffic Data For a 4*4 MIMO OFDM system " << endl;
     break;
   }

 
 cout << " Enter the input Traffic Demand Spectrum Requirement in GHZ for a 4*4 MIMO OFDM system " << endl;


    }

for ( int i = 0; i < t.size()  ; i++)
    {
      for (int j = 0 ; j < t.size() ; j++) 
	{
	  if (i != j)
	    {       
	      if (t[i] == t[j])
		{ 
		  c = 1;
		   }
	    }
	    }
    }

 
  if (c == 1)
    {
      cout << " Non-Overlap Spectrum Constraint Situation " << endl;
      cout << " Traffic Demand  Data Values Can't Be Repeated or Duplicated " << endl;
      cout << " ----> Spectrum Assignment Process Denied " << endl;   
    }
  double sum;
  sum = 0.0;
  double  sum1;
  double  saved;
if(c != 1)
    {
  for (int n=0 ; n< t.size();n++)
    {
      sum = sum + t[n];

    }
    
  sum1 = sum + 15.0;
  
  if ((sum1 >= 3215.0) or (sum1 <= 3615.0))
    {
      cout << "Node Number" << "   " << "Demand Assigned" << endl ; 
      for (int j =0 ; j < t.size(); j++) 
	{
	  cout << j+1 << "            " <<  t[j] << "GHz" << endl; 
	}
      cout << " Spectrum Used With Guard Band:" << sum1 << "GHz" << endl;
      saved = 3615 - sum1;
      cout << " Total  Capacity Saved  out of available 400 GHz :" << saved << "GHz" << endl; 
      cout << " Actual Capacity Used   out of available 400 GHz :" << 400 - saved << "GHz" << endl;
      cout << "Spectrum Assignement Complete" << endl; 
      cout << "Note : This is just a demo of Spectrum Assignemnt Process Behaviour  " << endl;
      cout << "Actual Assignemnt Process is complex to ensure effective spectrum utilization " << endl;  
    }


}
 
}
