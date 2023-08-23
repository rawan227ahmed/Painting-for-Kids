#pragma once
#include"Actions\Action.h"
class StopRecordAction :
	public Action
{
public:
	StopRecordAction(ApplicationManager * pApp);
	virtual void ReadActionParameters() ;
	virtual void Execute(bool readpara=true);
	~StopRecordAction(void);
};

