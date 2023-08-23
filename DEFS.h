#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	SAVE,
	LOAD,
	DRAW_RECT,		//Draw Rectangle
	DRAW_HEXA,      //Draw Hexagon 
	DRAW_CIRC,      //Draw circle 
	DRAW_SQUR,      //Draw square
	DRAW_TRI,       //Draw triangle
	COLOR_GREEN,
	COLOR_BLACK,    //Colors 
	COLOR_YELLOW,
	COLOR_RED,
	COLOR_BLUE,
	COLOR_ORANGE,
	UNDO,           //UNDO 
	REDO,           //REDO
	MOVE,          //MOVE
	FRAMe,
	Delete,         //DELETE FIGURE
	SELECT,         //Select one 
	START_RECORD,   //start recording
	STOP_RECORD,    //stop  recording
	PLAY_RECORD,   //play  recording
	CLEAR,          //clear draw area 
	EXIT,			//Exit
	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,		//Switch interface to Play mode
	PCOLOR,
	PSHAPE,
	PCOLORANDSHAPE,
	EMPTY,			//A click on empty place in the toolbar
	DRAWING_AREA,	//A click on the drawing area
	STATUS			//A click on the status bar

	///TODO: Add the other action types of the two modes
};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif