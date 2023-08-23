#ifndef ADD_HEXA_ACTION_H
#define ADD_HEXA_ACTION_H
#include "Actions/Action.h"
//Add Rectangle Action class
class AddHexaAction: public Action
{
private:
	Point P1; //Rectangle Corners
	GfxInfo HexaGfxInfo;
public:
	AddHexaAction(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	
	//Add rectangle to the ApplicationManager
	virtual void Execute(bool readpara=true) ;
	
};
#endif
