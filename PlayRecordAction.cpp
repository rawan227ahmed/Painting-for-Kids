#include "PlayRecordAction.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"


PlayRecordAction::PlayRecordAction(ApplicationManager * pApp):Action(pApp)
{
}
//Reads parameters required for action to execute (code depends on action type)
 void PlayRecordAction::ReadActionParameters()
 {}
	
	//Execute action (code depends on action type)
void PlayRecordAction::Execute(bool readpara)
{
//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (pManager->getRecordActioncount() != 0)      //if there is recording action play 
	{
		pOut->PrintMessage("playing record");
		pManager->setstoprecord(true);             //stop recording 
		pOut->ClearDrawArea();                    //clear all old operation done 
		pManager->ClearFig();                       
		pManager->ReExecuteActions();             // remake all operations 
		pOut->PrintMessage("record end");
	}
	else
		pOut->PrintMessage("Nothing recorded");
}
PlayRecordAction::~PlayRecordAction(void)
{
}
