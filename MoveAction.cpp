#include "MoveAction.h"
#include "ApplicationManager.h"
#include "Figures/CRectangle.h"
#include "CCircle.h"
#include "CTriangle.h"


MoveAction::MoveAction(ApplicationManager* pApp, CFigure* p) :Action(pApp), moved(p)
{
}

void MoveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage(" Click at a point");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P.x, P.y);
	pOut->ClearStatusBar();
}

void MoveAction::Execute(bool readpara)
{
	Output* pOut = pManager->GetOutput();
	if(readpara)
	{
	ReadActionParameters();
	}
	if (pManager->getstartrecord())
	{
		pManager->AddRecordAction(this);
	}
	pManager->movefigure(moved, P.x, P.y);
	pOut->ClearDrawArea();
	pManager->UpdateInterface();
	//pManager->addundoAction(this);
}
/*void  MoveAction::undoAct()
{
	pManager->delundoAction(this);
}*/