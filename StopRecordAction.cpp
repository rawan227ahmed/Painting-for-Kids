#include "StopRecordAction.h"
#include "ApplicationManager.h"
#include "Figures\CFigure.h"

#include "GUI\input.h"
#include "GUI\Output.h"



StopRecordAction::StopRecordAction(ApplicationManager * pApp):Action(pApp)
{
}

void StopRecordAction::ReadActionParameters() 
{
}

void StopRecordAction::Execute(bool readpara)
{
	pManager->setstoprecord(true);
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("stop recording");
}
StopRecordAction::~StopRecordAction(void)
{
}
