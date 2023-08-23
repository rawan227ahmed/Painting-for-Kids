#include "SwitchToDrawAction.h"
#include "GUI\input.h"
#include "GUI\Output.h"
#include "ApplicationManager.h"



SwitchToDrawAction::SwitchToDrawAction(ApplicationManager * pApp):Action(pApp)
{
}
void SwitchToDrawAction::ReadActionParameters()
{
}
void SwitchToDrawAction::Execute(bool readpara)
{
	Output* pOut = pManager->GetOutput();
	pOut->CreateDrawToolBar();
	pOut->PrintMessage("Switched To Draw mode");
	pManager->UpdateInterface();
}
SwitchToDrawAction::~SwitchToDrawAction(void)
{
}
