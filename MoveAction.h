#pragma once
#include "Actions/Action.h"
#include "Figures/CFigure.h"
class MoveAction : public Action

{
	Point P;
	CFigure* moved;
public:
	MoveAction(ApplicationManager* pApp, CFigure* p);

	//Reads parameter
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute(bool readpara=true);

	void undoAct();




};

