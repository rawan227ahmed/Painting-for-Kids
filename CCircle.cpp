#include "CCircle.h"
#include "Figures/CFigure.h"
#include<string>
#include <fstream>


CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center= P1;
	point = P2;
}


void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawCirc to draw a rectangle on the screen	
	pOut->DrawCIRC(Center, point, FigGfxInfo, Selected);
}

bool CCircle::posFig(int x, int y)const
{
	int d = sqrt(((Center.x - x) * (Center.x - x) + (point.y-y) * (point.y-y)));
	int z = abs(Center.x - point.x);
	if (d<=z)
	{
		return true;
	}
	return false;
}
 void CCircle::PrintInfo(Output* pOut)const
{
	string id=to_string(ID);
	string cx =to_string(Center.x);
	string cy =to_string(Center.y);
	string r=to_string(sqrt(pow((Center.x-point.x),2)+pow((Center.y-point.y),2)));
	pOut->PrintMessage("ID="+ id+"  " +"center is "+'('+cx+','+cy+')'+"  "+"radius="+r);

}
void CCircle::movefig(int x, int y)
{
	int z = abs(Center.x - point.x);
	int d = z * z;
	Center.x = x;
	Center.y = y;
	point.x = x + z;
	point.y = 0;
}


void CCircle::Save(ofstream& OutFile)
{
	OutFile << "circle" << " ";
	OutFile << ID << " ";
	OutFile << Center.x << " ";
	OutFile << Center.y << " ";
	OutFile << point.x << " ";
	OutFile << point.y << " ";
	OutFile << color_to_string(FigGfxInfo.DrawClr) << " ";
	if (FigGfxInfo.isFilled)
		OutFile << color_to_string(FigGfxInfo.FillClr) << " ";
	else
		OutFile << "NO fill";
}

void CCircle::Load(ifstream& Infile)
{
	//Rect 1 123 123 312 4143 blue red
	Infile >> ID;
	Infile >> Center.x;
	Infile >> Center.y;
	Infile >> point.x;
	Infile >> point.y;
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