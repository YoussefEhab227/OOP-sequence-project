#include "RNA.h"
#include "Protein.h"
#include "Sequence.h"
#include "DNA.h"
#include "CodonsTable.h"
#include<iostream>
#include <cstring>
using namespace std;


RNA::RNA():Sequence()
{
//    type=mRNA;
    //constructor
}

RNA::RNA(char * seq, RNA_Type atype,int length):Sequence(length,seq)
{
    type=atype;
}
RNA::RNA(RNA& rhs)
{
    length=rhs.length;
    seq=new char [length];
    for(int i=0;i<length;i++)
        seq[i]=rhs.seq[i];
    type=rhs.type;
}
void RNA::Print() ///Function to print RNA sequence
{
    cout<<" RNA sequence is "<<endl;
    for(int i=0;i<length;i++)
        cout<<*(seq+i);
}

/// function to convert the RNA sequence back to DNA
DNA  RNA::ConvertToDNA()
        {
    char* temp=new char[length];
    for(int i=0;i<length;i++)
        temp[i]=seq[i];

    for (int i=0; i<length; i++)
    {

         if (temp[i] == 'U')
        {
            temp[i] = 'T';
        }
        else
            {
             continue;
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
    for (int i=0; i<length; i++){
        cout << temp[i];
        }

    DNA obj(length,temp ,promoter );
    return obj;
        }

 Protein* RNA::ConvertToProtein( CodonsTable& table){
// cout<<"Here"<<endl;
// char* subseq=new char [4];
// char newseq  [length/ 3 +  1];
// int j=0;
// if(length%3==0){
// for (int i=0 ; i<length;i+=3)
// {
//    subseq[0]=seq[i];
//    subseq[1]=seq[i+1];
//    subseq[2]=seq[i+2];
//    subseq[3]='\0';
//    newseq[j]=table.getAminoAcid(subseq);
//    j++;
//    if(j>2){j=0;}
//cout<<"INloop"<<endl;
// }
// cout<<"Hi"<<endl;
// int i=length/3;
// Protein* ob=new Protein(newseq,i);
//   return ob;
//   cout<<"Hi again"<<endl;
// }
int len = strlen(seq);
int part_len=len/3 +1;
int j=0;
if(len%3==0)
{
            char value[4];
    char* pr=new char [part_len];
    for(int i=0;i<len;i=i+3)
    {
        value[3] = 0;
        for(int c=0;j<3;++c){
            value[c] = seq[i+c];
        }

//        pass[0]=seq[i];
//        pass[1]=seq[i+1];
//        pass[2]=seq[i+2];
//        pass[3]='/0';
        pr[j]=table.getAminoAcid(value);
        j++;
        if(j>2){j=0;}

    }

    Protein* ob= new Protein(pr,part_len);

     return ob;

    }



 }

        istream& operator>> (istream& in,RNA obj)
       {
               cout<<"Enter the RNA sequence: ";
               for(int i=0; i< obj.length ; i++)
               in >> obj.seq[i];
                return in;
       }
        ostream& operator<< (ostream& out,RNA obj)
       {
              out<<"RNA Sequence: ";
    for(int i=0;i<obj.length;i++)
        out<<obj.seq[i];
    out<<"The type of DNA is: "<<obj.type;
    return out;
       }
       RNA RNA::operator+(RNA obj)
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

bool RNA::operator!=(RNA obj)
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

bool RNA::operator==(RNA obj)
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

string RNA::LoadSequenceFromFile(string filename )
{
    string loaded_data;
    ifstream input;

    filename +=".txt";
    input.open(filename.c_str());

    input >>  loaded_data ;
    input.close();

    return loaded_data;

}


void RNA::SaveSequenceToFile(char* data,string filename)
{
    filename += ".txt";
    ofstream outfile;
    outfile.open(filename.c_str());

    outfile << data;

    outfile.close();


}

//
//istream& operator >>(istream& in , RNA obj)
//{
//
//   string temp;
//   in>> temp ;
//   obj.seq=new char [temp.size()];
////for(int i=0;i<temp.length();i++)
////{
////    obj.seq[i]=temp[i];
////}
//    strcpy(obj.seq , temp.c_str());
//
//    return in;
//}
//
//ostream& operator<<(ostream& out,RNA obj)
//{
//    out<<"RNA Sequence: ";
//    for(int i=0;i<obj.length;i++)
//        out<<obj.seq[i];
//    out<<"The type of RNA is: "<<obj.type;
//    return out;
//}










RNA::~RNA()
{
    ///destructor
}
