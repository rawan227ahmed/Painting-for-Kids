#include "AddCircAction.h"
#include "GUI/Input.h"
#include "ApplicationManager.h"
#include "GUI\Output.h"
#include "CCircle.h"

AddCircAction::AddCircAction(ApplicationManager* pApp) :Action(pApp)
{
}

void AddCircAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("New Circle: Click at first point");
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Circle: Click at second point");
	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	RectGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

void AddCircAction::Execute(bool readpara)
{
	//This action needs to read some parameters first
	if(readpara)
	ReadActionParameters();

	//Create a circle with the parameters read from the user
	CCircle* R = new CCircle(P1, P2, RectGfxInfo);
	R->ChngDrawClr(RectGfxInfo.DrawClr);
	R->ChngFillClr(RectGfxInfo.FillClr);
	//Add the circle  to the list of figures
	pManager->AddFigure(R);
	if (pManager->getstartrecord())
	{
		pManager->AddRecordAction(this);
	}
}

