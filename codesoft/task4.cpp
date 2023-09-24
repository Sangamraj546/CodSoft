#include <iostream>
#include <fstream>
using namespace std;
int main()
{
 ifstream fin("word.txt"); 
 int word=1; 
 char ch;

 fin.seekg(0,ios::beg);
 
 while(fin)
 {
  fin.get(ch);
  if(ch==' '||ch=='\n')
   word++;
 } 
 
 cout<<"\nWords="<<word<<"\n";
 fin.close(); //closing file
 
 return 0;
}

