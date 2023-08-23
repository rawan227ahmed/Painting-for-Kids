#pragma once
#include"Actions\Action.h"
class SwitchToPlayAction :
	public Action
{
public:
	SwitchToPlayAction(ApplicationManager * pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool readpara=true) ;
	~SwitchToPlayAction(void);
};

