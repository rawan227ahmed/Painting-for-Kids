#ifndef ADD_DEL_ACTION_H
#define ADD_DEL_ACTION_H
#include "Actions/Action.h"
#include "DEFS.h"
#include "Figures/CFigure.h"
class AddDeleteAction :public Action
{
private:
public:
	AddDeleteAction (ApplicationManager* pApp);

	//Reads parameter
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute(bool readpara=true);

	//void undoAct();


};
#endif
