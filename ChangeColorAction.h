#pragma once
#include "DEFS.h"
#include "Figures/CFigure.h"
#include "Actions/Action.h"
class ChangeColorAction :public Action
    
{
private:
	Point P;
	CFigure* coloredfig;
	ActionType ActTypecolor;
	bool flag;
public:


	ChangeColorAction(ApplicationManager* pApp, CFigure* p, ActionType ActType,bool);

	//Reads parameter
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute(bool readpara=true);

	
};

