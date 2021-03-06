#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
using namespace std ;

int main()
{
  /* data declaration */
  int i,j ,k ,l ;   /* Declaring matrix dimensions */
  vector<vector<int> > a, b; /* Declaring multi dimensional vectors  for storing matrixes */
  int factor  ;    /*  Varaiable For Matrix A formation*/
  int f;          /*  Variable For Matrix B formation */
       
  string           s;       /*Variable for getting the input text file */
  vector<string>   s1;      /*vector declaration  for storing the input data */ 
 
  /* Pushing the input data in s1 */
while (getline(cin,s))
     {
     s1.push_back(s);
      } 

 /* If there is a dimension mismatch between the two matrixes  A and B (number of columns of A is not equal to number of rows of matrix B   */
if (s1[1] != s1[2] ) 
	{
	  cout << "Error in the input text " << '\t' <<  "Kindly give the correct input " << '\n' ;  
}


/* atoi function is used to covert string data type into integer data type */

 i = atoi(s1[0].c_str());    /* Number of Rows for Matrix A */ 
 j = atoi(s1[1].c_str());    /* Number of columns for Matrix A*/
 k = atoi(s1[2].c_str());    /*Number of rows for Matrix B */
 l = atoi(s1[3].c_str());   /*Number of columns for Matrix B*/ 

 /* Matrix A i*j  Formation (Data Fetch)  from the input data set*/
 if (j == k)
   {  
 factor = 4;
  for (int n1 = 0 ; n1 < i ; n1++ )
    {
      if ( n1 != 0 ) 
	{
	factor = factor + j;
        }
      a.push_back(vector<int>());
     for (int n2 = 0 ; n2 < j ; n2++ )
	{
	  a[n1].push_back(atoi(s1[n2+factor].c_str()));
	  cout <<  a[n1][n2]   ;
          if (n2 < j-1 )
	    {
	      cout << " ";
	    }  
                         }
 
        cout << '\n' ;     
}
   }

 cout << '\n' ;
  f = 4+i*j;
  
  /* Matrix B k*l Formation (Data Fetch) from the input data set*/

  if (j == k)
    {  
for (int n1 = 0 ; n1 < k ; n1++)
    {  
      if ( n1 != 0 ) 
	{
	  f = f + l;
        }
      b.push_back(vector<int>());
     for (int n2 = 0 ; n2 < l ; n2++ )
	{
	  b[n1].push_back(atoi(s1[n2+f].c_str()));
	  cout <<  b[n1][n2]  ;
	  if (n2 < l-1) 
	    {
	      cout << " ";
            } 
                         }
 
      cout << '\n'  ;    
}

    }

  
  /* Matrix Multiplication [i][k]*[k][l]*/
  if (j == k) 
    {
      vector<vector<int> > c (i,vector<int>(l,0)) ;
  for (int n1 = 0 ; n1 < i ; n1++ )
    {
      for (int n3 = 0; n3 < l ; n3++ )
	{ 
          c[n1][n3] = 0;	  
	  for (int n2 = 0; n2 < k ; n2++ )
	    {
	      c[n1][n3] = c[n1][n3] + a[n1][n2]*b[n2][n3] ;
	   
	    }
              
	      }
    }

  cout << '\n' ; 
  for ( int n1=0; n1<i;n1++)
    {
      for (int n3=0; n3<l;n3++)
	{
	  cout << c[n1][n3]  ;
	  if (n3 < l-1)
            {
	      cout << " ";
	    }
	}
      cout << '\n' ;
    }
   
    }

} 
