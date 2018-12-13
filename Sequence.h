#ifndef SEQUENCE_H
#define SEQUENCE_H
#include<iostream>
using namespace std;

class Sequence
{
  	protected:
        char * seq;
        int length;
    public:
 	 	// constructors and destructor
        Sequence();
        Sequence(int length,char* se_q);
        Sequence(Sequence& rhs);
        virtual ~Sequence();
 	 	// pure virtual function that should be overridden because every
        // type of sequence has its own details to be printed
        virtual void Print()=0;
 	 	// friend function that will find the LCS (longest common
        // subsequence) between 2 sequences of any type, according to
        // polymorphism

        virtual string LoadSequenceFromFile(string filename)=0;
        virtual void SaveSequenceToFile(char* data,string filename)=0;
        friend char* Align(Sequence * s1, Sequence * s2);

        friend istream& operator>> (istream& in,Sequence* obj);
       friend ostream& operator<< (ostream& out,Sequence* obj);




};
#endif // SEQUENCE_H
