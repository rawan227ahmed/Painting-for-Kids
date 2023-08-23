#ifndef ADD_CIRC_ACTION_H
#define ADD_CIRC_ACTION_H
#include "Actions/Action.h"
class AddCircAction :
    public Action
{
private:
	Point P1, P2; //Circle Corners
	GfxInfo RectGfxInfo;
public:
	AddCircAction(ApplicationManager* pApp);

	//Reads Circle parameters
	virtual void ReadActionParameters();

	//Add Circle to the ApplicationManager
	virtual void Execute(bool readpara=true);


};
#endif
