#include "ChangeColorAction.h"
#include "ApplicationManager.h"
ChangeColorAction::ChangeColorAction(ApplicationManager* pApp, CFigure* p, ActionType ActType,bool c) :Action(pApp), coloredfig(p), ActTypecolor(ActType)
{
	flag = c;
}

void ChangeColorAction::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	ActTypecolor = pIn->GetUserAction();
}

void ChangeColorAction::Execute(bool readpara)
{
	if (flag)
	{
		switch (ActTypecolor)
		{
		case COLOR_RED:
			coloredfig->ChngFillClr(UI.REDColor);
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
	}
	else
	{
		ReadActionParameters();
		switch (ActTypecolor)
		{
		case COLOR_RED:
			coloredfig->ChngDrawClr(UI.REDColor);
			break;
		case COLOR_GREEN:
			coloredfig->ChngDrawClr(UI.GREENColor);
			break;
		case COLOR_BLACK:
			coloredfig->ChngDrawClr(UI.BLACKColor);
			break;
		case COLOR_BLUE:
			coloredfig->ChngDrawClr(UI.BLUEColor);
			break;
		case COLOR_YELLOW:
			coloredfig->ChngDrawClr(UI.YELLOWColor);
			break;
		case COLOR_ORANGE:
			coloredfig->ChngDrawClr(UI.ORANGEColor);
			break;
		}

	}
	if (pManager->getstartrecord())
	{
		pManager->AddRecordAction(this);
	}

}