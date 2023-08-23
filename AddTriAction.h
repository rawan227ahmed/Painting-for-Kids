#ifndef ADD_TRI_ACTION_H
#define ADD_TRI_ACTION_H
#include "Actions/Action.h"
class AddTriAction : public Action
{
private:
	Point P1, P2, P3; //Triangle Corners
	GfxInfo RectGfxInfo;
public:
	AddTriAction(ApplicationManager* pApp);

	//Reads Triangle  parameters
	virtual void ReadActionParameters();

	//Add Triangle  to the ApplicationManager
	virtual void Execute(bool readpara=true);

};
#endif
