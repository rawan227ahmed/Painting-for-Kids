#include "ChangefillColorAction.h"
#include "ApplicationManager.h"
ChangefillColorAction::ChangefillColorAction(ApplicationManager* pApp, ActionType ActType) :Action(pApp), ActTypecolor(ActType)
{
}

void ChangefillColorAction::ReadActionParameters()
{
}

void ChangefillColorAction::Execute(bool readpara)	
{
	coloredfig = pManager->Getselected();
	switch (ActTypecolor)
	{
	case COLOR_RED:
		coloredfig->ChngFillClr(UI.REDColor);
		UI.FillColor = UI.REDColor;
		break;
	case COLOR_GREEN:
		coloredfig->ChngFillClr(UI.GREENColor);
		break;
	case COLOR_BLACK:
		coloredfig->ChngFillClr(UI.BLACKColor);
		break;
	case COLOR_BLUE:
		coloredfig->ChngFillClr(UI.BLUEColor);
		break;
	case COLOR_YELLOW:
		coloredfig->ChngFillClr(UI.YELLOWColor);
		break;
	case COLOR_ORANGE:
		coloredfig->ChngFillClr(UI.ORANGEColor);
		break;
	}
	if (pManager->getstartrecord())
	{
		pManager->AddRecordAction(this);
	}
	//pManager->addundoAction(this);
}
/*void ChangefillColorAction::undoAct()
{
	pManager->delundoAction(this);
}*/