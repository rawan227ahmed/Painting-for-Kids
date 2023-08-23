#include"CHexagon.h"
#include<string>


CHexagon::CHexagon(Point P1, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Center = P1;
}


void CHexagon::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawHexa(Center,FigGfxInfo, Selected);
}

void CHexagon::PrintInfo(Output* pOut)const
{
	string id= to_string(ID);
	string cx= to_string(Center.x);
	string cy= to_string(Center.y);
	string L=to_string(100);
	string fillco;
	/*if(FigGfxInfo.isFilled)
	fillco=;
	else */

	pOut->PrintMessage("ID="+ id+"  "+"side length ="+ L+"  " +"Center("+cx+','+cy+')');

}
double CHexagon::Area(double x1, double y1, double x2, double y2,double x3,double y3)const
{
	return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}
bool  CHexagon::posFig(int x,int y)const //I devided the hexagon into rectangle and two triangles to find the position of the point 
{
	double L=100;
	double n=(sqrt(3))*L/2.0;
	bool position = (x>=(Center.x-(L/2))&&x<=(Center.x+(L/2))&&y>=(Center.y-n)&&y<=(Center.y+n));
	if(position )
		return true;
	else
	{
		float a=0.5*L*n;
		float a1=Area(x,y,(Center.x+L),(Center.y),(Center.x+L/2.0),Center.y-n);
		float a2=Area(x,y,(Center.x+L/2.0),Center.y-n,Center.x+L/2.0,Center.y+n);
		float a3=Area(x,y,(Center.x+L),(Center.y),Center.x+L/2.0,Center.y+n);
		position =(a==a1+a2+a3);
		if(position)
			return true;
		else
		{
		a1=Area(x,y,(Center.x-L),(Center.y),(Center.x-L/2.0),Center.y-n);
		a2=Area(x,y,(Center.x-L/2.0),Center.y-n,Center.x-L/2.0,Center.y+n);
		a3=Area(x,y,(Center.x-L),(Center.y),Center.x-L/2.0,Center.y+n);
		position =(a==a1+a2+a3);
			if(position)
				return true;
			else
			return false;
		}
	}
}
void CHexagon::movefig(int x, int y)
{
	Center.x = x;
	Center.y = y;
}


void CHexagon::Save(ofstream& OutFile)
{
	OutFile << "Hexagon" << " ";
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

void CHexagon::Load(ifstream& Infile)
{
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


