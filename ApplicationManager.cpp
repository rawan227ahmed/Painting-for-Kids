#include "ApplicationManager.h"
#include"Actions\Action.h"
#include "Actions\AddRectAction.h"
#include"AddCircAction.h"
#include"AddHexaAction.h"
#include"AddSqrAction.h"
#include"AddTriAction.h"
#include"SelectOneAction.h"
#include"SwitchToPlayAction.h"
#include"ClearAction.h"
#include"SwitchToDrawAction.h"
#include"StartRecordAction.h"
#include"ChangefillColorAction.h"
#include"PlayRecordAction.h"
#include"StopRecordAction.h"
#include"MoveAction.h"
#include"AddDeleteAction.h"
#include<Windows.h>
#include"Actions/Save.h"
#include"Actions/Load.h"
#include"Actions/AddRectAction.h"
#include "Actions/PickByShape.h"
#include "Actions/PickByColor.h"
#include"ChangeColorAction.h"


//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();

	FigCount = 0;
	RecordActioncount =0;

	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	

	//Create an array of recorded Action pointers and set them to NULL
	for(int i=0; i<MaxRecordAction; i++)
		RecordedAction[i] = NULL;	
	stoprecord=false;
	startrecord = false;

}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;

	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case DRAW_RECT:
		pAct = new AddRectAction(this);
		break;

	case DRAW_HEXA:
		pAct = new AddHexaAction(this);
		break;

	case DRAW_CIRC:
		pAct = new AddCircAction(this);
		break;

	case DRAW_SQUR:
		pAct = new AddSqrAction(this);
		break;

	case DRAW_TRI:
		pAct = new AddTriAction(this);
		break;

	case COLOR_GREEN:
		pAct = new ChangefillColorAction(this, ActType);
		break;

	case COLOR_BLACK:
		pAct = new ChangefillColorAction(this, ActType);
		break;

	case COLOR_YELLOW:
		pAct = new ChangefillColorAction(this, ActType);
		break;

	case COLOR_RED:
		pAct = new ChangefillColorAction(this, ActType);
		break;

	case COLOR_BLUE:
		pAct = new ChangefillColorAction(this, ActType);
		break;

	case COLOR_ORANGE:
		pAct = new ChangefillColorAction(this, ActType);
		break;

	case MOVE:
		pAct = new MoveAction(this, SelectedFig);
		break;

	case FRAMe:
		pAct = new ChangeColorAction(this, SelectedFig, ActType, false);
		break;

	case Delete:
		pAct = new AddDeleteAction(this);
		break;

	case SELECT:
		pAct = new SelectOneAction(this);
		break;

	case START_RECORD:
		pAct = new StartRecordAction(this);
		break;

	case STOP_RECORD:
		pAct = new StopRecordAction(this);
		break;

	case PLAY_RECORD:
		pAct = new PlayRecordAction(this);
		break;

	case CLEAR:
		pAct = new ClearAction(this);
		break;

	case TO_PLAY:
		pAct = new SwitchToPlayAction(this);
		break;

	case TO_DRAW:
		pAct = new SwitchToDrawAction(this);
		break;

	case EXIT:
		///create ExitAction here

		break;

	case STATUS:	//a click on the status bar ==> no action
		return;

	case SAVE:
		pAct = new Save(this);
		break;

	case LOAD:
		pAct = new Load(this);
		break;

	case PCOLOR:
		pAct = new PickByColor(this);
		break;

	case PSHAPE:
		pAct = new PickByShape(this);
		break;

	case PCOLORANDSHAPE:
		pAct = new PickByShape(this);
		break;

	}

	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		//delete pAct;	//You may need to change this line depending to your implementation
		LastAction=pAct;
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
	{
		FigList[FigCount] = pFig;	
		FigList[FigCount]->SetID(FigCount+1);
		FigCount++;
	}
}
////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::movefigure(CFigure*,int x,int y)
{
	for (int i = 0; i < FigCount; i++)
		if (SelectedFig == FigList[i])
			FigList[i]->movefig(x,y);
}
CFigure* ApplicationManager::Getselected()
{
	return SelectedFig;
}
///////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::AddRecordAction(Action* rAction)   //Adds a recorded Action 
{
	if(!stoprecord)
		if(RecordActioncount < MaxRecordAction )
		{
			RecordedAction[RecordActioncount]=rAction;  
			RecordActioncount++;
		}
		else      //if the action is more than 20 shift actions 
		{
			RecordedAction[RecordActioncount-1]=rAction;
			for(int i=0;i<MaxRecordAction-1;i++)
				RecordedAction[i]=RecordedAction[i+1];
		}
}
/////////////////////////////////////////////////////////////////
int ApplicationManager::getRecordActioncount()
{
		return RecordActioncount;
}
int ApplicationManager::getFigCount()
{
	return FigCount;
}
void ApplicationManager::setstoprecord(bool stop)
{
	stoprecord=stop;
}
void ApplicationManager::setstartrecord()
{
	if (FigCount == 0)
	{
		startrecord = true;
	}

}
bool ApplicationManager::getstartrecord()
{
	return startrecord;
}
/////////////////////////////////////////////////////////////////////////////////////


CFigure* ApplicationManager::returnFigure(int count)
{
	return FigList[count];
}


void ApplicationManager::ReExecuteActions()
{
	for(int i=0; i<RecordActioncount; i++)
	{
		RecordedAction[i]->Execute(false);
		Sleep(1000);
		UpdateInterface();
	}
}
/////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::del(CFigure* SelectedFig) {
	for (int i = 0; i < FigCount; i++)
		if (SelectedFig == FigList[i])
		{
			delete FigList[i];
			FigList[i] = NULL;
			FigCount--;
			for (int j = i; j < FigCount; j++)
				FigList[j] = FigList[j + 1];
			break;
		}
}
////////////////////////////////////////////////////////////////////////////////////
Action* ApplicationManager::GetLastAction()
{
	return LastAction;
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	for(int i=FigCount-1;i>=0;i--)
	{
		if(FigList[i]->posFig(x,y))
			return FigList[i];
	}

	return NULL;

	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

}
////////////////////////////////////////////////////////////////////////////////////////
//set the selected figure 
void ApplicationManager::SetSelectedFig(CFigure * fig)
{
	SelectedFig=fig;
}
/////////////////////////////////////////////////////////////////////////////////////////
//unselect the previous selected figure
void ApplicationManager::UnSelectedFig(CFigure * fig)
{
	for(int i=FigCount-1;i>=0;i--)
	{
		if(FigList[i]!=fig)
		{
			FigList[i]->SetSelected(false);
		}
		SelectedFig=fig;
	}
}
/////////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::ClearFig()
{

	for(int i=0;i<FigCount;i++)
	{
		delete FigList[i];
		FigList[i]=NULL;
	}
	FigCount=0;
}
///////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::clearRecordingActions()
{
	for(int i=0;i<RecordActioncount;i++)
	{
		delete RecordedAction[i];
		RecordedAction[i]=NULL;
	}
	RecordActioncount=0;
}
////////////////////////////////////////////////////////////////////////////////////////
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<FigCount; i++)
		if(FigList[i]!=NULL)
			FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
void ApplicationManager::SaveAll(ofstream & file) const
{
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Save(file);
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	for(int i=0; i<RecordActioncount; i++)
		delete RecordedAction[i];
	delete pIn;
	delete pOut;

}
