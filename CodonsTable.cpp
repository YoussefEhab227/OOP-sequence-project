#include "CodonsTable.h"
#include <iostream>
#include<fstream>
#include<cstring>
using namespace std;

CodonsTable::CodonsTable()
{
    //ctor
}

void CodonsTable::LoadCodonsFromFile()  	 	/// function to load all codons from the given text file
{
    int counter=0;
    fstream myfile("RNA_codon_table.txt");
    char *input=new char [4];
    char result;
    while(!myfile.eof())
    {
         myfile >> input >>result;
         if(result=='$')
            result=' ';
         setCodon(input,result,counter);
         counter++;
    }

}
char CodonsTable::getAminoAcid(char * value)
{
 for(int i=0;i<64;i++)
 {
    if (strcmp(value,codons[i].value)==0)
        return codons[i].AminoAcid;
 }
}

void CodonsTable::setCodon(char * value, char AminoAcid, int index)
{
    codons[index].value= value;
    codons[index].AminoAcid=AminoAcid;
}
//void CodonsTable::PrintFile()
//{
//     for(int i=0;i<64;i++)
// {
//
//        cout<< codons[i].AminoAcid;
// }
//}

CodonsTable :: ~CodonsTable()
{

}



