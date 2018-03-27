#include "tree.h"
#include <string>
#include <iostream>

using namespace std;
Tree::Tree(){}
Tree::Tree(const Tree&){}
Tree::Tree(const string & treedata){ 
	//cout << "The fuck " << endl;
	 string allInfo = treedata;
	 stringstream iss(treedata);
	 vector<string> splitString;
	 string quote = "\"";
	 
	
   	    string singlePart; 
 	   while(getline(iss,singlePart)){
 	    const char *stringStart = singlePart.c_str();
 	    bool instring{false};
 	    for(const char* start = stringStart; *start; start++){
		if(*start == '"') instring = !instring; 
		else if (*start == ',' && !instring) { splitString.push_back(string(stringStart, start-stringStart)); stringStart = start + 1;}
	    
	    }
	    splitString.push_back(string(stringStart));
	   }
	 //23 - 24, 25, 26, 37, 38 , 25
	 stringstream(splitString[0]) >> tree_id ;
	 stringstream(splitString[3]) >> tree_dbh;
	 status = status = splitString[6];
	 health = splitString[7];
	 spc_common = splitString[9];
	 address = splitString[24];
	 stringstream(splitString[25]) >> zipcode ;
	 boroname = splitString[26];
   	 stringstream(splitString[38]) >> longitude;
	 stringstream(splitString[37]) >> latitude;
	
}

ostream& operator<< (ostream & os, const Tree & t){
	os << t.spc_common << "," << t.tree_id << ","<< t.tree_dbh << "," << t.status << "," <<  t.health << "," << t.address 
	<< "," << t.boroname << "," << t.zipcode << "," << t.latitude << "," << t.longitude << endl;
}

string Tree::write(){
	ospecInfo << spc_common << "\t" << tree_id << "\t"<< tree_dbh << "\t" << status << "\t" <<  health << "\t" << address 
	<< "\t" << boroname << "\t" << zipcode << "\t" << latitude << "\t" << longitude << "\n";
	string specInfoWrite = ospecInfo.str();
	return specInfoWrite;
}
bool operator==(const Tree & t1, const Tree & t2)
{
      if((t1.spc_common==t2.spc_common )&&(t1.tree_id==t2.tree_id))
      return true;
      else
      return false;
       
}

bool operator<(const Tree & t1, const Tree & t2)
{
      if((t1.spc_common<t2.spc_common )&&(t1.tree_id<t2.tree_id))
      return true;
      else
      return false;
}
/*Tree& Tree::operator=(const Tree& other){
	cout << "Test" << endl;
}*/
