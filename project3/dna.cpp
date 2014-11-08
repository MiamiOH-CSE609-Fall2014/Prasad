#include<iostream>
#include<string>
#include<fstream>
#include<map>
#include<vector>
#include<tuple>
#include<sstream>
using namespace std;
void parseFastfile(string &s)
{
  ifstream file(s);
  string f;
  string f1;
  string f2;
  string f3;
  string f4; 
  vector <string> h;
  vector <string> c;
  vector <string> se;
   typedef tuple<vector<string>,vector<string>,vector<string> > t;
   vector <t> v;     
  if (file.is_open())
    {
      getline(file,f,';');     
      h.push_back(f);
      while (getline(file,f1,';'))
	{
	      stringstream i (f1); 
	      getline(i,f2); 
	      f4 = ";" + f2;
	      c.push_back(f4);           
              getline(i,f3,';');
	      se.push_back(f3);
	     

	}
        v.push_back(t(h,c,se));
	/*	for (int i=0 ; i<c.size();i++) 
	  {
	    cout << c[i] << endl;
	    }*/      
        for(t tu : v)
	{
	  for ( int i =0; i< get<1>(tu).size();i++){
	   cout << get<2>(tu)[i] << endl;
	  }
	  
	  }; 
    }

}
int main()
{
  string filepath;
  cout << "Enter the Fasta file to be parsed " <<endl;
  cin  >> filepath;   
 
  parseFastfile(filepath);

   
}
