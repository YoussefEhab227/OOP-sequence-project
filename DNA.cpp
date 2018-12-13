#include "DNA.h"
#include "Sequence.h"
#include "RNA.h"
#include<iostream>
#include<cstring>
using namespace std;


DNA::DNA():Sequence()
{
//    startIndex=0;
//    endIndex=0;
//    type=promoter;
    //Default constructor
}
DNA::DNA(int length,char* se_q,DNA_Type atype):Sequence(length,se_q)///Constructor
{
    type=atype;
}
DNA::DNA(DNA& rhs)
{
  length=rhs.length;
  seq=new char[length];
  for(int i=0;i<length;i++)
        seq[i]=rhs.seq[i];
  this->type=type;
}
void DNA::BuildComplementaryStrand()
      /// Function that converts each A to T, each T to A, each C to G, and
        /// each G to C. Then reverse the resulting sequence to make the second strand.
{
    int x,y;
    cout<<"Enter your first index and end index "<<endl;
    cin>>x;
    cin>>y;

    if(x==-1 && y==-1)
    {

        startIndex=0;
        endIndex=length;
        char*temp=new char [length];
        for(int i=0;i<length;i++)
            temp[i]=seq[i];
        for(int i=startIndex;i<endIndex;i++)
    {
        if(temp[i]=='A')
            temp[i]='T';
        else if(temp[i]=='T')
                temp[i]='A';
        else if(temp[i]=='C')
            temp[i]='G';
        else if(temp[i]=='G')
            temp[i]='C';

    }
   char *temp1=new char[1];
    for (int i=0; i<=length/2; i++)
    {
        temp1[0] = temp[i];
        temp[i] = temp[length-i-1];
        temp[length-i-1] = temp1[0];
    }
    strcpy(seq,temp);


    }
    else
    {
        startIndex=x;
        endIndex=y;
           char*temp=new char [length];
        for(int i=0;i<length;i++)
            temp[i]=seq[i];
        for(int i=startIndex;i<=endIndex;i++)
    {
        if(temp[i]=='A')
            temp[i]='T';
        else if(temp[i]=='T')
                temp[i]='A';
        else if(temp[i]=='C')
            temp[i]='G';
        else if(temp[i]=='G')
            temp[i]='C';

    }
   char *temp1=new char[1];
    for (int i=0; i<=length/2; i++)
    {
        temp1[0] = temp[i];
        temp[i] = temp[length-i-1];
        temp[length-i-1] = temp1[0];
    }


}
}
void DNA::Print(){ ///Function to print DNA sequence to the user...
cout<<"The DNA Sequence from 3' to 5' is : "<<endl;
for(int i=0;i<length;i++)
    cout<<seq[i];
cout<<endl;
///BuildComplementaryStrand();
//cout<<"The DNA sequence from 5' to 3' is "<<endl;
//
//for(int i=0;i<length;i++)
//    cout<<seq[i];
if(this->type == 0)
    {
        cout<<" \nThe type of DNA is Promoter." << endl;
    }
else if(this->type == 1)
    {
        cout<<" \nThe type of DNA is Motif." << endl;
    }
else if(this->type == 2)
    {
        cout<<" \nThe type of DNA is nail." << endl;
    }
else if(this->type == 3)
    {
        cout<<" \nThe type of DNA is noncoding." << endl;
    }
else
    {
        cout<<" \nThis type is undefined." << endl;
    }


}
//char* Align(Sequence * s1, Sequence * s2)
//{
//  int Length1 = s1->length;
//   int Length2 = s2->length;
//  char* S1=new char[Length1];
//  char* S2=new char[Length2];
//  int se_q [Length1][Length2];
//
//
//  for(int i=0;i<Length1;i++)
//  {
//      S1[i] = s1->seq[i];
//  }
//  S1[Length1]='\0';
//
//  for(int i=0;i<Length2;i++)
//  {
//      S2[i]= s2->seq[i];
//  }
//  S2[Length2]='\0';
//
//  for(int i=0;i<Length1;i++)
//  {
//      for(int j=0;j<Length2;j++)
//      {
//          se_q[i][j]=0;
//      }
//  }
//
//  for(int i=1;i<Length1;i++)
//  {
//      for(int j=1;j<Length2;j++)
//      {
//           if(S1[i] == S2[j])
//            se_q[i][j]=se_q[i-1][j]+1;
//          else
//            se_q[i][j]=max(se_q[i-1][j],se_q[i][j-1]);
//      }
//  }
//
//      int index = se_q [Length1][Length2];
//      char lcs [index+1];
//      lcs[index]=' ';
//      int i = Length1-1 , j = Length2-1;
//      while (i>0 && j>0)
//      {
//             if (S1[i] == S2[j])
//      {
//          lcs[index] = S1[i]; // Put current character in result
//          i--; j--; index--;     // reduce values of i, j and index
//      }
//          // If not same, then find the larger of two and
//      // go in the direction of larger value
//      else if (se_q[i-1][j] > se_q[i][j-1])
//         i--;
//      else
//         j--;
//   }

   // Print the lcs
//   cout << "LCS of " << S1 << " and " << S2 << " is " << lcs;
//   return lcs;
//
//
//      }








/**
* function to convert the DNA sequence to RNA sequence
* It starts by building the complementary_strand of the current
* DNA sequence (starting from the startIndex to the endIndex), then,
* it builds the RNA corresponding to that complementary_strand.
**/
RNA DNA::ConvertToRNA()
{
 char* temp=new char[length];
    for(int i=0;i<length;i++)
        temp[i]=seq[i];
    for (int i=0; i<length; i++)
    {
//        if (temp[i] == 'A')
//        {
//            temp[i] = 'A';
//        }
         if (temp[i] == 'T')
        {
            temp[i] = 'U';
        }
        else if (temp[i] == 'G')
        {
            temp[i] = 'C';
        }
        else if (temp[i] == 'C')
        {
            temp[i] = 'G';
        }
    }

    char *temp1=new char[1];
    for (int i=0; i<length/2; i++)
    {
        temp1[0] = temp[i];
        temp[i] = temp[length-i-1];
        temp[length-i-1] = temp1[0];
    }

    cout << "mRNA Sequence: ";
    for (int i=0; i<length; i++)
        cout << temp[i];

    RNA obj(temp , mRNA,length);
    return obj;

}


DNA DNA::operator+(DNA obj)
{
    char *temp=new char[length];
    for(int i=0;i<length;i++)
        temp[i]=seq[i];
    seq=new char[length+obj.length];
    for(int i=0;i<length;i++)
        seq[i]=temp[i];
    int index=0;
    for(int i=length;i<(length+obj.length);i++)
    {
        seq[i]=obj.seq[index];
        index++;
    }
    length+=obj.length;
    return *this;
}

bool DNA::operator!=(DNA obj)
{
    if(length!=obj.length){return true;}
    else
    {
        for(int i=0;i<length;i++)
        {
            if(seq[i]!=obj.seq[i])
            return true;
        }
        return false;
    }
}

bool DNA::operator==(DNA obj)
{
    if(length!=obj.length){return false;}
    else
    {
        for(int i=0;i<length;i++)
        {
            if(seq[i]!=obj.seq[i])
            return false;
        }
    return true;
    }
}

istream& operator>>(istream& in , DNA obj)
{

   string temp;
   in>> temp ;
   obj.seq=new char [temp.size()];
//for(int i=0;i<temp.length();i++)
//{
//    obj.seq[i]=temp[i];
//}
    strcpy(obj.seq , temp.c_str());

    return in;
}

ostream& operator<<(ostream& out,DNA obj)
{
    out<<"DNA Sequence: ";
    for(int i=0;i<obj.length;i++)
        out<<obj.seq[i];
    out<<"The type of DNA is: "<<obj.type;
    return out;
}

string DNA::LoadSequenceFromFile(string filename )
{
    string loaded_data;
    ifstream input;

    filename +=".txt";
    input.open(filename.c_str());

    input >>  loaded_data ;
    input.close();

    return loaded_data;

}


void DNA::SaveSequenceToFile(char* data,string filename)
{
    filename += ".txt";
    ofstream outfile;
    outfile.open(filename.c_str());

    outfile << data;

    outfile.close();


}

DNA::~DNA()
{
    ///destructor
}
