#include "Protein.h"
#include "Sequence.h"
#include"CodonsTable.h"
#include<iostream>
using namespace std;


Protein::Protein():Sequence()
{
//    type=Hormon;
    //ctor
}
Protein::Protein(char*p,int length)
{
 this->length=length;
p=new char [length];
for(int i=0;i<length;i++)
{
    seq[i]=p[i];
}

}

void Protein::Print()
{
    cout<<"Your Protein Sequence is ";
    for(int i=0;i<length;i++)
    {
        cout<<seq[i];
    }

}




string Protein::LoadSequenceFromFile(string filename )
{
    string loaded_data;
    ifstream input;

    filename +=".txt";
    input.open(filename.c_str());

    input >>  loaded_data ;
    input.close();

    return loaded_data;

}


void Protein::SaveSequenceToFile(char* data,string filename)
{
    filename += ".txt";
    ofstream outfile;
    outfile.open(filename.c_str());

    outfile << data;

    outfile.close();


}

Protein::~Protein()
{
    //dtor
}
