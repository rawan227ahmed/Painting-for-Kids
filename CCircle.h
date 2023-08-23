
#ifndef CCIRC_H
#define CCIRC_H
#include "Figures/CFigure.h"
#include "DEFS.h"
#include "GUI/Output.h"
class CCircle :public CFigure
	
{
private:
	Point Center;
	Point point;
public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool posFig(int, int)const;
	virtual void PrintInfo(Output* pOut)const;	//print all figure info on the status bar
	void movefig(int, int);
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
};
#endif


