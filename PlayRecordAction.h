#pragma once
#include"Actions\Action.h"
class PlayRecordAction :
	public Action
{
public:
	PlayRecordAction(ApplicationManager *pApp);	//constructor

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters();
	
	//Execute action (code depends on action type)
	virtual void Execute(bool readpara=true);


	~PlayRecordAction(void);
};

