#include "StartRecordAction.h"

#include "ApplicationManager.h"
#include "Figures\CFigure.h"

#include "GUI\input.h"
#include "GUI\Output.h"



StartRecordAction::StartRecordAction(ApplicationManager * pApp):Action(pApp)
{
}
 void StartRecordAction::ReadActionParameters() 
{
}
 void StartRecordAction::Execute(bool readpara)
{
	 // Get a pointer to the 
 Output* pOut = pManager->GetOutput();
 
pManager->setstartrecord();
bool validstart = pManager->getstartrecord();

 if(validstart)  //if validstart is true start recording 
 pOut->PrintMessage("start recording ");
 else
 pOut->PrintMessage("can not start recording clear all then start ");
}

StartRecordAction::~StartRecordAction(void)
{
}
