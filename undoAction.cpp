#include "undoAction.h"
#include "GUI/Output.h"
#include "ApplicationManager.h"
undoAction::undoAction(ApplicationManager* pApp) :Action(pApp)
{
}

void undoAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("undo the action");
}

void undoAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();


}
