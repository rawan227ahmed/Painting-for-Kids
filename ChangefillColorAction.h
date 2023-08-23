#pragma once
#include "DEFS.h"
#include "Figures/CFigure.h"
#include "Actions/Action.h"
class ChangefillColorAction :public Action
    
{
private:
	Point P;
	CFigure* coloredfig;
	ActionType ActTypecolor;
public:


	ChangefillColorAction(ApplicationManager* pApp, ActionType ActType);

	//Reads parameter
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute(bool readpara=true);

	void undoAct();

};

