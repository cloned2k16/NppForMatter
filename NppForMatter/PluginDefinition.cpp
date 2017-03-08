	#include	"PluginDefinition.h"
	#include	"menuCmdID.h"

	#include	<stdio.h>

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
//	-----------------------------------	---------------------------	---------------------------------
	HWND								sciCurr;
//	-----------------------------------	---------------------------	---------------------------------
	void								getScintilla				()								{
		int which = -1;
		::SendMessage(nppData._nppHandle
			, NPPM_GETCURRENTSCINTILLA
			, 0
			, (LPARAM)	&which);

		if (which == -1) return;

		sciCurr = (which == 0)
				? nppData._scintillaMainHandle
				: nppData._scintillaSecondHandle;
	}
//	-----------------------------------	---------------------------	---------------------------------
	int									sciCmmnd					( int cmd )						{
		return ::SendMessage(sciCurr,cmd,0,0);
	}
//	-----------------------------------	---------------------------	---------------------------------
	void								hello						()								{
		
		::SendMessage(	nppData._nppHandle
						, NPPM_MENUCOMMAND
						, 0
						, IDM_FILE_NEW);							// Open a new document

		getScintilla();

		::SendMessage(	sciCurr
						, SCI_SETTEXT
						, 0
						, (LPARAM)	"Hello I'm ForMatter ..\n");
	}
//	-----------------------------------	---------------------------	---------------------------------
	void								helloDlg					()								{
		getScintilla();
		int textSz	=	sciCmmnd( SCI_GETTEXTLENGTH);

		char msg[1024];

		wsprintf((LPWSTR)&msg, TEXT("text len: [%d]"), textSz);

		::MessageBox(	NULL
						, (LPCWSTR)&msg
						, TEXT("ForMatter:")						//	Title!
						, MB_OK);
	}
//	-----------------------------------	---------------------------	---------------------------------
