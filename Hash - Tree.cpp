// Compile with c++14
// Hash - Tree
// this code save and restore words . the goal is to present what i call it 'Hash - tree'
// Wrote By Mustafa Ahmed
// mmustafaadn@gmail.com
#include <iostream>
using namespace std;

struct node //node in the Tree ... Every Node Store aword
 {
   string data;
   node* left;
   node* right;
 };



node* create_node(string data);// create new node
bool serch (node* root,string data);// search in the Hash-tree
void insert (node** root,string data);//insert in the Tree a new word



int main()
{
 node* arr_hash[26]={NULL}; // array of pointers with Null value ... 26 elements . one to each character
 string s; //The word to add or Search
 cout<<"Enter words to seve it :"<<endl;
 cout<<"Exit By Enter 0"<<endl;
 for(;;) // infinite Loop .. Break when Enter Number 0
 {
	 cin>>s;
	 if(s=="0")  break;

	 int num = int(s[0]); // First letter in the word
	 if(num>=65&&num<=90) // Apper Cases
	     {
	       int temp = num-65 ;
	       insert(&(arr_hash[temp]) , s );
	     }
	 else if(num>=97&&num<=122)//Lower Cases
	     {
	       int temp = num-97 ;
	       insert(&(arr_hash[temp]) , s );
	     }
	 else // Not a character
     cerr<<"Error .. words must began with letters ."<<endl;
 }

 //============================ Searching

 cout<<"Enter words to search :"<<endl;
 cout<<"Exit By Enter 0"<<endl;
 for(;;)
  {
 	 cin>>s;
 	 if(s=="0")  break ;
 	 int num = int(s[0]);
 	 if(num>=65&&num<=90)
 	     {
 	       int temp = num-65 ;
 	       if(serch(arr_hash[temp] , s ))
 	          cout<<"Found .."<<endl;
 	       else
 	          cout<<"Not Found .."<<endl;
 	     }
 	 else if(num>=97&&num<=122)
 	     {
 	       int temp = num-97 ;
 	       if(serch(arr_hash[temp] , s ))
  	          cout<<"Found .."<<endl;
		   else
 	          cout<<"Not Found .."<<endl;
 	     }
 	 else
      cerr<<"Error .. words must began with letters ."<<endl;
 }



 return 0;
}


// create new node
node* create_node(string data)
{
    node* new_node= new node();
    new_node-> data=data;
    new_node-> left=NULL;
    new_node-> right=NULL;
  return new_node;
}


//insert in the Tree a new word
void insert (node** root,string data)
{
   if(*root==NULL)
   {
      *root=create_node(data);
   }

   else if((*root)->data > data)
   {
    insert(&((*root)->left),data);
   }

   else
   {
    insert(&((*root)->right),data);
   }
}

// search in the Hash-tree
bool serch (node* root,string data)
{
  if(root==NULL)
       return false;
    else if(root->data==data)
            return true;
    else if(root->data > data)
           return serch (root->left,data);
    else
         return serch (root->right,data);
}