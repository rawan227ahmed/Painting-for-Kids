#ifndef ADD_SQR_ACTION_H
#define ADD_SQR_ACTION_H
#include "Actions/Action.h"

class AddSqrAction :public Action
{
private:
	Point P1; //Square Corner
	GfxInfo RectGfxInfo;
public:
	AddSqrAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute(bool readpara=true);
    
};
#endif
