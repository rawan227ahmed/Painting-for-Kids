#include "Actions/Action.h"
class undoAction : public Action
{
public:
	undoAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();


};

