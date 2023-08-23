#include "AddSqrAction.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include "ApplicationManager.h"
#include "CSquare.h"

AddSqrAction::AddSqrAction(ApplicationManager* pApp) :Action(pApp)
{
}

void AddSqrAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Square: Click at the center");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	RectGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void AddSqrAction::Execute(bool readpara)
{
	//This action needs to read some parameters first
	if(readpara)
	{
	ReadActionParameters();
	}
	if (pManager->getstartrecord())
	{
		pManager->AddRecordAction(this);
	}
	//Create a square with the parameters read from the user
	CSquare* R = new CSquare(P1, RectGfxInfo);
	R->ChngDrawClr(RectGfxInfo.DrawClr);
	R->ChngFillClr(RectGfxInfo.FillClr);
	//Add the square  to the list of figures
	pManager->AddFigure(R);
}
