#ifndef RNA_H
#define RNA_H
#include "Sequence.h"
#include "Protein.h"
#include "DNA.h"
#include "CodonsTable.h"


class Protein;

enum RNA_Type {mRNA, pre_mRNA, mRNA_exon, mRNA_intron};

class RNA : public Sequence
{
  	private:
        RNA_Type type;
  	public:
 	 	// constructors and destructor
 	 	friend class CodonsTable;
        RNA();
        RNA(char * seq, RNA_Type atype,int length);
        RNA(RNA& rhs);
        ~RNA();
 	 	// function to be overridden to print all the RNA information
     void Print();
//     void LoadFromFile (string filename);
//     void SaveToFile (string filename);
 	 	// function to convert the RNA sequence into protein sequence
        /// using the codonsTable object
        Protein* ConvertToProtein(CodonsTable& table);
 	 	/// function to convert the RNA sequence back to DNA
        DNA ConvertToDNA();
        RNA operator+(RNA obj);
       bool operator!=(RNA obj);
      bool operator==(RNA obj);
       friend istream& operator>> (istream& in,RNA obj);
       friend ostream& operator<< (ostream& out,RNA obj);
       string LoadSequenceFromFile(string filename);
       void SaveSequenceToFile(char* data,string filename);
};

#endif // RNA_H
