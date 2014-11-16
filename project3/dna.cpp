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

tuple<int, int> scoreSequence(string haystack, string needle, vector< vector<int> > scoring_m)
{
  vector<string> si;
  vector<string> st;
  int i1 = haystack.size();
  int i2 = needle.size();
  int c ;
  c = 0;
  string::iterator c1;

  while (c < haystack.size())
    {
      if ((i1-c == i2-1))
        {
          break;
        }
      string s;
      s = haystack.substr(c,i1-c);
      si.push_back(s);
      c = c + 1;

    }


  for (int i =0; i<si.size();i++)
    {

      string l;
      l = si[i].substr(0,needle.size());
      st.push_back(l);
    }

  int k =0;  
  int value;
  int value1;
  value1 = 0;
  vector<int> v;
  for (int i=0; i < st.size();i++)
    {
      for (c1 = st[i].begin();c1!= st[i].end() ; c1++)

	{

	  string f;
          string z;
	  f = *c1;
          z =  f+needle[k];
          if (z == "AA"){ value = scoring_m[0][0]; }
	  if (z == "AG"){ value = scoring_m[0][1]; }
	  if (z == "AC"){ value = scoring_m[0][2]; }
	  if (z == "AT"){ value = scoring_m[0][3]; } 
	  if (z == "GA"){ value = scoring_m[1][0]; }
	  if (z == "GG"){ value = scoring_m[1][1]; } 
	  if (z == "GC"){ value = scoring_m[1][2]; }
	  if (z == "GT"){ value = scoring_m[1][3]; }
	  if (z == "CA"){ value = scoring_m[2][0]; }   
	  if (z == "CG"){ value = scoring_m[2][1]; } 
	  if (z == "CC"){ value = scoring_m[2][2]; }
	  if (z == "CT"){ value = scoring_m[2][3]; }
	  if (z == "TA"){ value = scoring_m[3][0]; }
	  if (z == "TG"){ value = scoring_m[3][1]; }
	  if (z == "TC"){ value = scoring_m[3][2]; }
	  if (z == "TT"){ value = scoring_m[3][3]; }  
          k++; 
	  value1 = value1 + value;
          value = 0; 
	  if ( k == (needle.size()))
	    {
	      int value_f;
	      k = 0;
              value_f = value1;
              value1 = 0 ;
              v.push_back(value_f);
	      
	    }
	}
    }

  int index;
  int max;
  vector<int>::const_iterator  imax;
   
  imax = max_element(v.begin(), v.end());
  max = *imax;
  vector <int>::iterator pos ;
  pos = find (v.begin(),v.end(), max);
  int npos = distance (v.begin(), pos); 
  index = npos;      
    
  return make_tuple(index,max);



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
  vector< vector <int> > scoring_m = parseScoringFile(scorepath);
  tuple<int, int> max_score = scoreSequence(get<2> (t1), "TAATCTCAGCACTTTGAGAGGCCGAGGCAT", scoring_m );
  cout << get<0> (max_score)<<endl ;
  cout << get<1> (max_score)<<endl ;

  
  /*  for (int n1 = 0 ; n1 < m5.size() ;n1++)
    {
      for (int n3=0 ; n3 < m5[n1].size()  ; n3++ )
      {
      cout << m5[n1][n3] << "\t" ;
      }
      cout << "\n";
      } */
  
  

    

  
}
