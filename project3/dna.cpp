#include<iostream>
#include<string>
#include<fstream>
#include<map>
#include<vector>
#include<tuple>
#include<sstream>
using namespace std;
string comb[]= {"AA","AG","AC","AT","GA","GG","GC","GT","CA","CG","CC","CT","TA","TG","TC","TT"}; 
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

  for (int i =0; i < si.size() ;i++)
    {
      
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
  cout << get<2> (t1)<< endl;
  /*  for ( int i =0; i< get<0>(t1).size();i++)
  {
    cout << get<0>(t1)[i] << endl; 
    
    }*/

  map <string , int > scores = digramFreqScores(get<2> (t1));


    

  
}
