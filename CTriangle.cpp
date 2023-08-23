#include "CTriangle.h"

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}

void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTri to draw a rectangle on the screen	
	pOut->DrawTRI(Corner1, Corner2, Corner3, FigGfxInfo, Selected);
}
double CTriangle::Area(int x1, int y1, int x2, int y2, int x3, int y3)const 
{
	return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

void CTriangle::PrintInfo(Output* pOut)const 
{
string id=to_string(ID);
	string c1x=to_string(Corner1.x);
	string c1y=to_string(Corner1.y);
	string c2x=to_string(Corner2.x);
	string c2y=to_string(Corner2.y);
	string c3x=to_string(Corner3.x);
	string c3y=to_string(Corner3.y);

	string fillco;
	/*if(FigGfxInfo.isFilled)
	fillco=;
	else */

	pOut->PrintMessage("ID="+ id+"  " +"corner1 is "+'('+c1x+','+c1y+')'+"  "+"corner2 is "+'('+c2x+','+c2y+')'+"  "+"corner3 is"+'('+c3x+','+c3y+')');
}
bool CTriangle::posFig(int x, int y) const
{
	float A = Area(Corner1.x, Corner1.y, Corner2.x, Corner2.y, Corner3.x, Corner3.y); //calculate the area of the triangle that  
	float A1 = Area(x, y, Corner2.x, Corner2.y, Corner3.x, Corner3.y);                //calculate the areas of tringles the point makes with the tringle corners 
	float A2 = Area(Corner1.x, Corner1.y, x, y, Corner3.x, Corner3.y);
	float A3 = Area(Corner1.x, Corner1.y, Corner2.x, Corner2.y, x, y);

	if (A ==( A1 + A2 + A3))      // if the sum of the small triangles is equal to the big triangle then the point is inside the triangle
	{
		return true;
	}

	return false;
}
void CTriangle::movefig(int x, int y)
{
	float dy, dx;
	dy = (Corner1.y + Corner2.y + Corner3.y) / 3;
	dx = (Corner1.x + Corner2.x + Corner3.x) / 3;
	int Max, Min;
	Max = max(Corner1.x, max(Corner2.x, Corner3.x));
	Min = min(Corner1.x, min(Corner2.x, Corner3.x));

	Point Near, Mid, Far;
	if (Max == Corner1.x)
	{
		Far = Corner1;
	}
	else
	{
		if (Min == Corner1.x)
		{
			Near = Corner1;
		}
		else
		{
			Mid = Corner1;
		}
	}
	if (Max == Corner2.x)
	{
		Far = Corner2;
	}
	else
	{
		if (Min == Corner2.x)
		{
			Near = Corner2;
		}
		else
		{
			Mid = Corner2;
		}
	}
	if (Max == Corner3.x)
	{
		Far = Corner3;
	}
	else
	{
		if (Min == Corner3.x)
		{
			Near = Corner3;
		}
		else
		{
			Mid = Corner3;
		}
	}
	Mid.x = abs(x - (dx - Mid.x));
	Mid.y = abs(y - (dy - Mid.y));
	Near.x = abs(x - (dx - Near.x));
	Near.y = abs(y - (dy - Near.y));
	Far.x = abs(x + (Far.x - dx));
	Far.y = abs(y + (Far.y - dy));
	Corner1 = Mid;
	Corner2 = Near;
	Corner3 = Far;
}



void CTriangle::Save(ofstream& OutFile)
{
	OutFile << " Triangle" << " ";
	OutFile << ID << " ";
	OutFile << Corner1.x << " ";
	OutFile << Corner1.y << " ";
	OutFile << Corner2.x << " ";
	OutFile << Corner2.y << " ";
	OutFile << Corner3.x << " ";
	OutFile << Corner3.y << " ";
	OutFile << color_to_string(FigGfxInfo.DrawClr) << " ";
	if (FigGfxInfo.isFilled)
		OutFile << color_to_string(FigGfxInfo.FillClr) << " ";
	else
		OutFile << "NO fill";
	OutFile << "\n";
}



void CTriangle::Load(ifstream& Infile)
{
	Infile >> ID;
	Infile >> Corner1.x;
	Infile >> Corner1.y;
	Infile >> Corner2.x;
	Infile >> Corner2.y;
	Infile >> Corner3.x;
	Infile >> Corner3.y;
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













