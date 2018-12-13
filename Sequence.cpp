#include "Sequence.h"
#include<cstring>
#include<vector>
using namespace std;

Sequence::Sequence()
{
    seq = NULL;

    //ctor
}
Sequence::Sequence(int length, char* se_q)
{
    this->length=length;
    seq = new char [length];
    seq=se_q;
}
Sequence::Sequence(Sequence& rhs)
{
    seq=new char[length];
    for(int i=0;i<length;i++)
         *(seq+i)=*(rhs.seq+i);

}


istream& operator>> (istream& in,Sequence* obj)
{
    string temp=" ";
    in >> temp;
    obj->seq= new char [temp.length()+1];
    strcpy(obj->seq,temp.c_str());
//  cout<<temp;


 return in;
}
ostream& operator <<(ostream& out, Sequence* obj)
{
        for(int i=0;i<obj->length;i++){
          out << obj->seq[i];
        }
        cout<<endl;

    return out;

}

char * Align(Sequence * s1, Sequence * s2)
{
	vector<vector<int> >  myarray(strlen(s1->seq) + 1);

	for (int r = 0; r <= strlen(s1->seq); r++) {
		myarray[r] = vector<int>(strlen(s2->seq) + 1);
		for (int c = 0; c <= strlen(s2->seq); c++) {
			if (r == 0 || c == 0) {
				myarray[r][c] = 0;
			}
			else if (s1->seq[r - 1] == s2->seq[c - 1]) {
				myarray[r][c] = myarray[r - 1][c - 1] + 1;
			}
			else {
				myarray[r][c] = max(myarray[r - 1][c], myarray[r][c - 1]);
			}
		}
	}

	int i = strlen(s1->seq);
	int j = strlen(s2->seq);
	int k = myarray[i][j];

	char* LCS = new char [k + 1];

	LCS[k] = '\0';
	while (i > 0 && j > 0) {
		if (s1->seq[i - 1] == s2->seq[j - 1]) {
			LCS[k - 1] = s1->seq[i - 1];
			k--;
			i--;
			j--;
		}
		else if (myarray[i - 1][j] > myarray[i][j - 1]) {
			i--;
		}
		else {
			j--;

		}
	}
	//print result
	return LCS;
}

Sequence::~Sequence()
{
    delete seq;
    //dtor
}
