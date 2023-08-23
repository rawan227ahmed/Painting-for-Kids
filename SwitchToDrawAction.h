#pragma once
#include"Actions\Action.h"
class SwitchToDrawAction :
	public Action
{
public:
	SwitchToDrawAction(ApplicationManager * pApp);
		virtual void ReadActionParameters();
	virtual void Execute(bool readpara=true) ;
	~SwitchToDrawAction(void);
};
