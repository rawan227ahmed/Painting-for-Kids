#include "ClearAction.h"
#include"ApplicationManager.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\Output.h"

ClearAction::ClearAction(ApplicationManager *pApp):Action(pApp)
{
}
void ClearAction::ReadActionParameters()
{}
void ClearAction::Execute(bool readpara)
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pManager->ClearFig();                    //clear all figures

	pManager->clearRecordingActions();       //clear all recorded Action
	pManager->setstoprecord(false);         
	pOut->ClearDrawArea(); 
	pOut->PrintMessage("cleared the draw Area ");
}

ClearAction::~ClearAction(void)
{
}
