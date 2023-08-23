#ifndef CLEAR_ACTION_H
#define CLEAR_ACTION_H

#include"Actions\Action.h"
class ClearAction :
	public Action
{
public:
	ClearAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
  	virtual void Execute(bool readpara=true);
	~ClearAction(void);
};
#endif

