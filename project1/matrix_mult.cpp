#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std ;
int main()
{
  int i,j ,k ,l ;
  int a[10] [10] , b[10] [10];
  int factor ;
       
  string           s;
  vector<string>   s1;
 int  count = 0;

 while (getline(cin,s))
     {
     count = count + 1;
     s1.push_back(s);
      } 

if (s1[1] != s1[2] ) 
	{
	  cout << "Error in the input text " << '\t' <<  "Kindly give the correct input " << '\n' ;  
}

 i = atoi(s1[0].c_str());
 j = atoi(s1[1].c_str());
 k = atoi(s1[2].c_str());
 l = atoi(s1[3].c_str());

  
  for (int n1 = 0 ; n1 < i ; n1++ )
    {
      factor = 4 ;
      if ( n1 != 0 ) 
	{
	factor = factor + j;
        }
     for (int n2 = 0 ; n2 < j ; n2++ )
	{
	  a[n1][n2] = atoi(s1[n2+factor].c_str());
	  cout <<  a[n1][n2] << '\t' ;
                         }
 
     cout << '\n' ;    
}

  


} 
