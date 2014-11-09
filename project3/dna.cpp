#include<iostream>
#include<string>
#include<fstream>
#include<map>
#include<vector>
#include<tuple>
#include<sstream>
using namespace std;
tuple<vector<string>,vector<string>,vector<string> > parseFastfile(string s)
{
  ifstream file(s);
  string f1; 
  vector <string> h;
  vector <string> c;
  vector <string> se;    
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
	      se.push_back(f1);
            }
	    

	}

 
      return make_tuple(h,c,se);
		  	  
    }

}
int main()
{
  string filepath;
  cout << "Enter the Fasta file to be parsed " <<endl;
  cin  >> filepath;
  tuple<vector<string>,vector<string>,vector<string> > t1;
  t1 =  parseFastfile(filepath);
   for ( int i =0; i< get<2>(t1).size();i++)
  {
    cout << get<2>(t1)[i] << endl;
  }
  
}
