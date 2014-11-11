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
  int c;
 vector<int> n;
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
   
 n.push_back(c);
}

 for (int i =0; i< n.size();i++)
   {
     cout << n[i] << endl;
   } 
}

vector< vector<int> > digramFreqMatrix( map< string, int > M1)
{

}

int main()
{
  string filepath;
  cout << "Enter the Fasta file to be parsed " <<endl;
  cin  >> filepath;
  tuple<vector<string>,vector<string>,string> t1;
  t1 =  parseFastfile(filepath);
  map <string , int > scores = digramFreqScores(get<2> (t1));
 
  
    

  
}
