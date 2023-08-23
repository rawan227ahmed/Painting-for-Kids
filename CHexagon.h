#pragma once
#include "Figures\CFigure.h"


class CHexagon : public CFigure
{
private:
	Point Center;
public:
	CHexagon(Point ,GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual bool posFig(int x,int y)const; 
	double Area(double x1, double y1, double x2, double y2,double x3,double y3)const;
	virtual void PrintInfo(Output* pOut)const ;
	virtual void movefig(int, int);
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
};


