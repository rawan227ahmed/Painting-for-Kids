#ifndef SELECT_ONE_ACTION_H
#define SELECT_ONE_ACTION_H
#include"Actions\Action.h"

class SelectOneAction: public Action
{
private:
	Point P;
public:
	SelectOneAction(ApplicationManager * pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool readpara = true);
	~SelectOneAction();
};
#endif