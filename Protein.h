#ifndef PROTEIN_H
#define PROTEIN_H
#include "Sequence.h"
#include "DNA.h"
#include "CodonsTable.h"
#include "RNA.h"


enum Protein_Type {Hormon, Enzyme, TF, Cellular_Function};
class RNA;
class Protein : public Sequence
{
  	private:
        Protein_Type type;
      public:
 	 	// constructors and destructor
 	 	Protein();
 	 	Protein(char * p,int length);
 	 	~Protein();
 	 	void Print();
// 	 	void LoadFromFile (string filename);
// 	 	void SaveToFile (string filename);
 	 	// return an array of DNA sequences that can possibly
                // generate that pr111otein sequence
           DNA* GetDNAStrandsEncodingMe(const DNA & bigDNA);
            string LoadSequenceFromFile(string filename);
         void SaveSequenceToFile(char* data,string filename);

};

#endif // PROTEIN_H
