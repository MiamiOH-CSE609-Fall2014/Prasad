#include<iostream>
#include<string>
#include<fstream>
#include<map>
#include<vector>
#include<tuple>
#include<sstream>
#include<algorithm>
using namespace std;
string  comb[]= {"AA","AG","AC","AT","GA","GG","GC","GT","CA","CG","CC","CT","TA","TG","TC","TT"};
vector<string> co (comb, comb + sizeof(comb) / sizeof(string) ); 
tuple<vector<string>,vector<string>,string > parseFastfile(string s)
{
  ifstream file(s);
  string f1; 
  vector <string> h;
  vector <string> c;
  string se = "";  
  if (file.is_open())
    {   
  while (getline(file,f1))
        {
	  if (f1.substr(0,1) == ">")
	    {  
	    h.push_back(f1);
	    }
	  else if (f1.substr(0,1) == ";")
            {
	      c.push_back(f1);
            }
	  else 
            {   
	      se = se + f1;
              }
	    

	}
  
      return make_tuple(h,c,se);
		  	  
    }

}


map <string , int > digramFreqScores(string si)
{
  map <string , int > m;
  int c;
string ::size_type i = 0;
for (int j =0; j < co.size(); j++)
   {
     i = 0; 
     c = 0;   
while ((i = si.find(co[j],i)) != string::npos) 
{
   ++c;
   if ((j == 0) or (j == 5) or (j == 10) or (j == 15))
     {
   i = i + 1;
     } 
   else 
     {
       i = i + 2;
     }
 }
   
 m[co[j]] = c;
}

 return m;
}

vector< vector<int> > digramFreqMatrix( map<string,int>  scores)
{
  vector<vector<int> > c ;
  vector<int> c1;
  int l;
  int l1;
  l = 0;
  l1 = 4 ;
  while (l1 < 20) 
    {
    
 for (int n2 = l ; n2 < l1 ; n2++)
	{
	  if (n2 == 16)
	    {
	      break;
	    } 	 
	 c1.push_back(scores[co[n2]]);
	 if ((n2 == 3)or (n2 == 7) or (n2 == 11) or (n2 == 15)  )
	   {
	     c.push_back(c1);
             c1.clear();
	   }
	}
 l = l + 4;
 l1 = l1 + 4;
    }
         	
  return c;     
}


vector< vector<int> >  parseScoringFile(string line)
{
  vector< vector <int> > l;
  ifstream file1(line);
  string f;
  string f1;
  string f2;
  string f3;
  string f4;
  vector<int> g1;

  if (file1.is_open())
    {
      while (getline(file1,f))
     {

 stringstream i(f);
 getline(i,f1,',') ;
 g1.push_back(atoi(f1.c_str()));
 getline(i,f2,',') ;
 g1.push_back(atoi(f2.c_str()));
 getline(i,f3,',') ;
 g1.push_back(atoi(f3.c_str()));
 getline(i,f4,',') ;
 g1.push_back(atoi(f4.c_str()));
 l.push_back(g1);
 g1.clear();
 

    }
    }
  /*     for (int n1 = 0 ; n1 < l.size() ;n1++)
    {
      for (int n3=0 ; n3 < l[n1].size()  ; n3++ )
      {
      cout << l[n1][n3] << "\t" ;
      }
      cout << "\n";
      } */

  return l;

}


int main()
{
  string filepath;
  string scorepath;
  cout << "Enter the Fasta file to be parsed " <<endl;
  cin  >> filepath;
  tuple<vector<string>,vector<string>,string> t1;
  t1 =  parseFastfile(filepath);
  map <string , int > scores = digramFreqScores(get<2> (t1));
  vector< vector <int> > m5 =  digramFreqMatrix(scores);
  cout << " Enter the score CSV file  " << endl;
  cin >> scorepath ;
  vector< vector <int> > m6 = parseScoringFile(scorepath);

 
  /*  for (int n1 = 0 ; n1 < m5.size() ;n1++)
    {
      for (int n3=0 ; n3 < m5[n1].size()  ; n3++ )
      {
      cout << m5[n1][n3] << "\t" ;
      }
      cout << "\n";
      } */
  
  

    

  
}
