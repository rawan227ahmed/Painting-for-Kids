#include "GUI\input.h"
#include "AddHexaAction.h"
#include "GUI/Output.h"
#include "ApplicationManager.h"
#include "CHexagon.h"
AddHexaAction::AddHexaAction(ApplicationManager * pApp):Action(pApp)
{}

void AddHexaAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Hexagon: Click at the center ot the hexagon");
	
	//Read the center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	HexaGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	HexaGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HexaGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddHexaAction::Execute(bool readpara) 
{
	//This action needs to read some parameters first
	if(readpara)
	ReadActionParameters();
	
	//Create a rectangle with the parameters read from the user
	CHexagon *H=new CHexagon(P1,HexaGfxInfo);
	H->ChngDrawClr(HexaGfxInfo.DrawClr);
	H->ChngFillClr(HexaGfxInfo.FillClr);
	pManager->AddFigure(H);
	//Add the rectangle to the list of figures
	if (pManager->getstartrecord())
	{
		pManager->AddRecordAction(this);
	}
}


