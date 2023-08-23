#include "SwitchToPlayAction.h"
#include "GUI\input.h"
#include "GUI\Output.h"
#include "ApplicationManager.h"

SwitchToPlayAction::SwitchToPlayAction(ApplicationManager * pApp):Action(pApp)
{
}

void SwitchToPlayAction::ReadActionParameters()
{
}

void SwitchToPlayAction::Execute(bool readpara)
{
	Output* pOut = pManager->GetOutput();
	pOut->CreatePlayToolBar();          //create the play mood tool bar
	pOut->PrintMessage("Switched To play mode");
	pManager->setstoprecord(true);
	pManager->UnSelectedFig(NULL);
}

SwitchToPlayAction::~SwitchToPlayAction(void)
{
}
