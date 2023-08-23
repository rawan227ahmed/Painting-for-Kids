#ifndef CTRI_H
#define CTRI_H
#include "Figures/CFigure.h"
#include "DEFS.h"
#include "GUI/Output.h"
class CTriangle :public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool posFig(int x, int y)const;
	virtual void PrintInfo(Output* pOut)const;
	double Area(int, int, int, int, int, int)const;
	void movefig(int, int);
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
};
#endif
