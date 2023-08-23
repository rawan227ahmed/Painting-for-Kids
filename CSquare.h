
#ifndef CSQ_H
#define CSQ_H
#include "Figures/CFigure.h"
#include "DEFS.h"
#include "GUI/Output.h"
class CSquare : public CFigure
{
private:
	Point Center;
public:
	virtual bool posFig(int, int)const;
	CSquare( Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual void PrintInfo(Output* pOut)const ;
	virtual void movefig(int, int);
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);

};
#endif
