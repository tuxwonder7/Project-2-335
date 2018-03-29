#include "tree.h"
#include <string>
#include <iostream>

using namespace std;
Tree::Tree(){}
Tree::Tree ( int id, int diam, string status, string health, string spc, int zip, string addr, string boro, double latitude, double longitude ) : tree_id(id), tree_dbh(diam), status(status), health(health),spc_common(spc), zipcode(zip), address(addr), boroname(boro), latitude(latitude), longitude(longitude){}
Tree::Tree(string currSPC, int treeID) : spc_common(currSPC){
 	specInfo =  " ";
	 tree_id = 0;
	 tree_dbh = 0;
	 status = " ";
	 health =  " ";
	 address =  " ";
	 boroname =  " ";
	 zipcode =  0;
	 latitude = 0;
	 longitude = 0;

}
Tree::Tree(const Tree& x){
	 allInfo = x.allInfo;
	 spc_common =  x.spc_common;
	 specInfo =  x.specInfo;
	 tree_id = x.tree_id;
	 tree_dbh = x.tree_dbh;
	 status = x.status;
	 health = x.health;
	 address = x.address;
	 boroname = x.boroname;
	 zipcode =  x.zipcode;
	 latitude = x.latitude;
	 longitude = x.longitude;
	
}
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
	 boroname = splitString[29];
   	 stringstream(splitString[38]) >> longitude;
	 stringstream(splitString[37]) >> latitude;
	
}

ostream& operator<< (ostream & os, const Tree & t){
	//cout << " <<< ree?" << endl;
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
     	string temp1 = t1.spc_common;
	string temp2 = t2.spc_common;
	transform(temp1.begin(), temp1.end(), temp1.begin(), ::tolower);
	transform(temp2.begin(), temp2.end(), temp2.begin(), ::tolower);
	if(temp1==temp2 ) return true;
	 else return false;
}

bool operator<(const Tree & t1, const Tree & t2)
{
	string temp1 = t1.spc_common;
	string temp2 = t2.spc_common;
	transform(temp1.begin(), temp1.end(), temp1.begin(), ::tolower);
	transform(temp2.begin(), temp2.end(), temp2.begin(), ::tolower);
	//cout << "temp1 " << temp1 << " and temp2 " << temp2 << endl;
      if(temp1 < temp2){
	return true;
      }
      else if(temp1 == temp2){
	if (t1.tree_id < t2.tree_id)
		return true;
	else 
		return false;
      }
      else{
		return false;}
}
Tree& Tree::operator=(const Tree& rhs){
	cout << "Test" << endl;
}

bool samename(const Tree & t1,const Tree & t2){
	string temp1 = t1.spc_common;
	string temp2 = t2.spc_common;
	transform(temp1.begin(), temp1.end(), temp1.begin(), ::tolower);
	transform(temp2.begin(), temp2.end(), temp2.begin(), ::tolower);
	 if(temp1==temp2 ) return true;
	 else return false;
}
bool islessname(const Tree & t1,const Tree & t2){
	string temp1 = t1.spc_common;
	string temp2 = t2.spc_common;
	transform(temp1.begin(), temp1.end(), temp1.begin(), ::tolower);
	transform(temp2.begin(), temp2.end(), temp2.begin(), ::tolower);
	
	if(temp1 < temp2) return true;
	else return false;
}
string Tree::common_name() const{
	return this->spc_common;
}
string Tree::borough_name() const{
	return this->boroname;
}

string Tree::nearest_address() const{
	return this->address;
}	
int Tree::diameter() const{
	return this->tree_dbh;
}
int Tree::zip() const{
	return this->zipcode;
}
void Tree::get_position(double & latitude,double & longitude) const{
	latitude = this->latitude;
	longitude = this->longitude;
}

int Tree::currID() const{ return this->tree_id;}










