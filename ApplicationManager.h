#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include"Actions\Action.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum {
		MaxFigCount = 200,

		MaxRecordAction = 20
	};	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	int RecordActioncount;
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	Action* RecordedAction[MaxRecordAction];    //List of recorded action
	CFigure* SelectedFig; //Pointer to the selected figure
	Action* LastAction;  //Pointer to last action execut
	bool stoprecord;      //to know if the user stopped recording or not
	bool startrecord;
	//Pointers to Input and Output classes
	Input* pIn;
	Output* pOut;

public:
	ApplicationManager();
	~ApplicationManager();

	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType); //Creates an action and executes it
	void setstoprecord(bool);        //set the stop record flag 
	void setstartrecord();        //set the stop record flag true if the figcount==0
	bool  getstartrecord();            //get the start record flag 
		// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	void AddRecordAction(Action* rAction);   //Adds a recorded Action
	void removeRecordAction(Action* rAction);  //remove a recorded action
	int getRecordActioncount();     //get number of action count 
	int getFigCount();
	CFigure* returnFigure(int count);
	void ReExecuteActions();                 //reexecute actions while playing the record 
	Action* GetLastAction();                //get the last action executed
	CFigure* GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	void SetSelectedFig(CFigure* fig);   //set the selected figure 
	void UnSelectedFig(CFigure* fig);
	void movefigure(CFigure*, int, int);
	CFigure* Getselected();
	void del(CFigure*);
	void ClearFig();                        // clear all figures in FigList   
	void clearRecordingActions();           //clear all recorded actions 
	// -- Interface Management Functions
	Input* GetInput() const; //Return pointer to the input
	Output* GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
	void SaveAll(ofstream& file) const;

};

#endif