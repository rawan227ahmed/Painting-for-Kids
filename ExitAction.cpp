#include "ExitAction.h"
#include"ApplicationManager.h"

ExitAction::ExitAction(ApplicationManager* pApp) :Action(pApp)
{
}

void ExitAction::ReadActionParameters()
{

}

void ExitAction::Execute(bool readpara)
{

	pManager->ClearFig();
	pManager->clearRecordingActions();

}

ExitAction::~ExitAction()
{}
