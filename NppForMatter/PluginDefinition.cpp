	#include "PluginDefinition.h"
	#include "menuCmdID.h"

//	-----------------------------------	---------------------------	---------------------------------
	FuncItem	funcItem				[nbFunc];
	NppData		nppData;
//	-----------------------------------	---------------------------	---------------------------------
	void								pluginInit					(HANDLE hModule)				{
	}
//	-----------------------------------	---------------------------	---------------------------------
	void								pluginCleanUp				()								{
	}
//	-----------------------------------	---------------------------	---------------------------------
	void								commandMenuInit				()								{
	    setCommand(0, TEXT("Hello Notepad++"), hello, NULL, false);
	    setCommand(1, TEXT("Hello (with dialog)"), helloDlg, NULL, false);
	}
//	-----------------------------------	---------------------------	---------------------------------
	void								commandMenuCleanUp			()								{
		// Don't forget to deallocate your shortcut here
	}
//	-----------------------------------	---------------------------	---------------------------------
	bool								setCommand					( size_t			index
																	, TCHAR	*			cmdName
																	, PFUNCPLUGINCMD	pFunc
																	, ShortcutKey *		sk
																	, bool				check0nInit){
		if (index >= nbFunc)	return false;
		if (!pFunc)				return false;

		lstrcpy(funcItem[index]._itemName, cmdName);
				funcItem[index]._pFunc = pFunc;
				funcItem[index]._init2Check = check0nInit;
				funcItem[index]._pShKey = sk;
	    return true;
	}
//	-----------------------------------	---------------------------	---------------------------------
	void								hello						()								{
		// Open a new document
		::SendMessage(	nppData._nppHandle
						, NPPM_MENUCOMMAND
						, 0
						, IDM_FILE_NEW);

		// Get the current scintilla
		int which = -1;
		::SendMessage(	nppData._nppHandle
						, NPPM_GETCURRENTSCINTILLA
						, 0
						, (LPARAM)	&which);

		if (which == -1) return;
		
		HWND curScintilla = (which == 0)
							?	nppData._scintillaMainHandle
							:	nppData._scintillaSecondHandle;

		::SendMessage(	curScintilla
						, SCI_SETTEXT
						, 0
						, (LPARAM)	"Hello I'm ForMatter!");
	}

//	-----------------------------------	---------------------------	---------------------------------
	void								helloDlg					()								{
		::MessageBox(	NULL
						, TEXT("Hello guys!")						
						, TEXT("ForMatter:")						//	Title!
						, MB_OK);
	}
//	-----------------------------------	---------------------------	---------------------------------
