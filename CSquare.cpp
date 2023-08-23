#include "CSquare.h"
#include "Figures/CFigure.h"
CSquare::CSquare(Point P, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P;
}

void CSquare::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawSqur(Center, FigGfxInfo, Selected);
}

void CSquare::movefig(int x, int y)
{
	Center.x = x;
	Center.y = y;
}
bool CSquare::posFig(int x, int y)const
{
	int L = 80;
	Point p1;
	p1.x = Center.x - L / 2;
	p1.y = Center.y + L / 2;
	Point p2;
	p2.x = Center.x + L / 2;
	p2.y = Center.y - L / 2;
	Point p3;
	p3.x = Center.x - L / 2;
	p3.y = Center.y - L / 2;
	Point p4;
	p4.x = Center.x + L / 2;
	p4.y = Center.y + L / 2;
	if((x>=min(p3.x,p4.x)&&x<=max(p3.x,p4.x))&&(y>=min(p3.y,p4.y)&&y<=max(p3.y,p4.y)))
	{
		return true;
	}
	else
		return false;

}
void CSquare::PrintInfo(Output* pOut)const 
{
	string id=to_string(ID);
	string L= to_string(80);
	string cx=to_string(Center.x);
	string cy=to_string(Center.y);
	/*if(FigGfxInfo.isFilled)
	fillco=;
	else */

	pOut->PrintMessage("ID="+ id+"  " +"the side Length ="+ L+"  "+"center is "+'('+cx+','+cy+')');
}




void CSquare::Save(ofstream& OutFile)
{
	OutFile << "Square" << " ";
	OutFile << ID << " ";
	OutFile << Center.x << " ";
	OutFile << Center.y << " ";
	OutFile << color_to_string(FigGfxInfo.DrawClr) << " ";
	if (FigGfxInfo.isFilled)
		OutFile << color_to_string(FigGfxInfo.FillClr) << " ";
	else
		OutFile << "NO fill";
	OutFile << "\n";
}

void CSquare::Load(ifstream& Infile)
{
	//Rect 1 123 123 312 4143 blue red
	Infile >> ID;
	Infile >> Center.x;
	Infile >> Center.y;
	string drawColor, fillColor;
	Infile >> drawColor >> fillColor;
	FigGfxInfo.DrawClr = string_to_color(drawColor);
	if (fillColor == "No fill")
	{
		FigGfxInfo.isFilled = false;
	}
	else
	{
		FigGfxInfo.FillClr = string_to_color(fillColor);
	}
}



