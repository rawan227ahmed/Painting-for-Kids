#pragma once
#include"Actions\Action.h"
class StartRecordAction :
	public Action
{
public:
	StartRecordAction(ApplicationManager * pApp);
	virtual void ReadActionParameters() ;
	virtual void Execute(bool readpara=true);
	~StartRecordAction(void);
};

