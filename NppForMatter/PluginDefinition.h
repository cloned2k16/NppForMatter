#ifndef PLUGINDEFINITION_H
#define PLUGINDEFINITION_H
///////////////////////////////////////

	#include "PluginInterface.h"
//	-----------------------------------	---------------------------	-----------------------------------------------------
	const 
	TCHAR								NPP_PLUGIN_NAME[]			= TEXT("ForMatter (++)");
	
	const 
	int									nbFunc						= 2;													//	Here define the number of your plugin commands

	void								pluginInit					(HANDLE hModule);										//	It will be called while plugin loading

	void								pluginCleanUp				();														//	It will be called while plugin unloading

	void								commandMenuInit				();														//	Initialization of plugin commands

	void								commandMenuCleanUp			();														//	Clean up plugin commands allocation (if any)
	
	bool								setCommand					( size_t			index
																	, TCHAR	*			cmdName
																	, PFUNCPLUGINCMD	pFunc
																	, ShortcutKey *		sk				= NULL
																	, bool				check0nInit		= false);

//	-----------------------------------	---------------------------	-----------------------------------------------------
	void								hello						();
	void								helloDlg					();
//	-----------------------------------	---------------------------	-----------------------------------------------------
///////////////////////////////////////
#endif //PLUGINDEFINITION_H
