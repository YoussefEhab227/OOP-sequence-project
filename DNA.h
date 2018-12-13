#ifndef DNA_H
#define DNA_H
#include "Sequence.h"
#include<iostream>
using namespace std;

class RNA;

enum DNA_Type{promoter, motif, tail, noncoding};

class DNA : public Sequence
{
  	private:
        DNA_Type type;
        DNA * complementary_strand;
        int startIndex;
        int endIndex;
    public:
 	 	// constructors and destructor
        DNA();
        DNA(int length,char * se_q, DNA_Type atype);
        DNA(DNA& rhs);
        ~DNA();
 	 	// function printing DNA sequence information to user
        void Print();
//        void LoadFromFile (string filename);
//        void SaveToFile (string filename);
        // function to convert the DNA sequence to RNA sequence
        // It starts by building the complementary_strand of the current
        // DNA sequence (starting from the startIndex to the endIndex), then,
        // it builds the RNA corresponding to that complementary_strand.
        RNA ConvertToRNA();
 	 	// function to build the second strand/pair of DNA sequence
	    // To build a complementary_strand (starting from the startIndex to
        // the endIndex), convert each A to T, each T to A, each C to G, and
        // each G to C. Then reverse the resulting sequence.
        string LoadSequenceFromFile(string filename);
        void SaveSequenceToFile(char* data,string filename);
        void BuildComplementaryStrand();
        friend char* Align(Sequence * s1, Sequence * s2);
       DNA operator+(DNA obj);
       bool operator!=(DNA obj);
      bool operator==(DNA obj);
       friend istream& operator>> (istream& in,DNA obj);
       friend ostream& operator<< (ostream& out,DNA obj);

  };
#endif // DNA_H
