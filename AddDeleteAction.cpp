#include "AddDeleteAction.h"
#include "ApplicationManager.h"
#include "GUI\Output.h"
#include "GUI/Input.h"
#include "Figures/CFigure.h"


AddDeleteAction::AddDeleteAction(ApplicationManager* pApp) :Action(pApp)
{
}

void AddDeleteAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage( "Delete the selected figure");

}

void AddDeleteAction::Execute(bool readpara)
{
	if(readpara)
	{
	ReadActionParameters();
	}
	if (pManager->getstartrecord())
	{
		pManager->AddRecordAction(this);
	}
	Output* pOut = pManager->GetOutput();
	pManager->del(pManager->Getselected());
	pOut->ClearDrawArea();
	pManager->UpdateInterface();
	//pManager->addundoAction(this);
}
/*void AddDeleteAction::undoAct()
{
	pManager->delundoAction(this);
}*/
