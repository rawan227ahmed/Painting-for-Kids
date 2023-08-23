#include "AddTriAction.h"
#include "GUI/Output.h"
#include "ApplicationManager.h"
#include "CTriangle.h"

AddTriAction::AddTriAction(ApplicationManager* pApp) :Action(pApp)
{
}

void AddTriAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at first corner");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Triangle: Click at second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	pOut->PrintMessage("New Triangle: Click at third corner");

	//Read 3nd corner and store in point P3
	pIn->GetPointClicked(P3.x, P3.y);


	RectGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

void AddTriAction::Execute(bool readpara)
{
	if(readpara)
	{
	//This action needs to read some parameters first
	ReadActionParameters();
	}
	if (pManager->getstartrecord())
	{
		pManager->AddRecordAction(this);
	}
	//Create a Triangle with the parameters read from the user
	CTriangle* T = new CTriangle(P1, P2,P3, RectGfxInfo);
	T->ChngDrawClr(RectGfxInfo.DrawClr);
	T->ChngFillClr(RectGfxInfo.FillClr);
	//Add theTriangle to the list of figures
	pManager->AddFigure(T);
}
