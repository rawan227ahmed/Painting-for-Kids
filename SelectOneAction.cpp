#include"SelectOneAction.h"

#include "ApplicationManager.h"
#include "Figures\CFigure.h"

#include "GUI\input.h"
#include "GUI\Output.h"
SelectOneAction::SelectOneAction(ApplicationManager * pApp):Action(pApp)
{}

void SelectOneAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Select item:click on a figure to be selected");
	//Read a point 
	pIn->GetPointClicked(P.x, P.y);
	pOut->ClearStatusBar();

}

//Execute the action
void SelectOneAction::Execute(bool readpara) 
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//This action needs to read some parameters first
	if(readpara)     //if it is executed for the first time read parameters  
	{
		ReadActionParameters();
	}
	if (pManager->getstartrecord())       //if the recording operation started add this action 
	{
		pManager->AddRecordAction(this);
	}
	CFigure* f= pManager->GetFigure(P.x, P.y);
	if(f!=NULL)
	{
		if(f->IsSelected())         //if this figure is already selected unselect it 
		{
			f->SetSelected(false);
			pManager->SetSelectedFig(NULL);
		}
		else
		{
			f->SetSelected(true);           //if it is not selected select it 
			pManager->SetSelectedFig(f);
			pManager->UnSelectedFig(f);
			f->PrintInfo(pOut);           //print information of the selected figure

		}
	}
}


