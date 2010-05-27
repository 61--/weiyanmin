// Machine generated IDispatch wrapper class(es) created with ClassWizard
/////////////////////////////////////////////////////////////////////////////
// _Application wrapper class

class _Application : public COleDispatchDriver
{
public:
	_Application() {}		// Calls COleDispatchDriver default constructor
	_Application(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	_Application(const _Application& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	LPDISPATCH GetActiveCell();
	LPDISPATCH GetActiveChart();
	CString GetActivePrinter();
	void SetActivePrinter(LPCTSTR lpszNewValue);
	LPDISPATCH GetActiveSheet();
	LPDISPATCH GetActiveWindow();
	LPDISPATCH GetActiveWorkbook();
	LPDISPATCH GetAddIns();
	LPDISPATCH GetAssistant();
	void Calculate();
	LPDISPATCH GetCells();
	LPDISPATCH GetCharts();
	LPDISPATCH GetColumns();
	LPDISPATCH GetCommandBars();
	long GetDDEAppReturnCode();
	void DDEExecute(long Channel, LPCTSTR String);
	long DDEInitiate(LPCTSTR App, LPCTSTR Topic);
	void DDEPoke(long Channel, const VARIANT& Item, const VARIANT& Data);
	VARIANT DDERequest(long Channel, LPCTSTR Item);
	void DDETerminate(long Channel);
	VARIANT Evaluate(const VARIANT& Name);
	VARIANT _Evaluate(const VARIANT& Name);
	VARIANT ExecuteExcel4Macro(LPCTSTR String);
	LPDISPATCH Intersect(LPDISPATCH Arg1, LPDISPATCH Arg2, const VARIANT& Arg3, const VARIANT& Arg4, const VARIANT& Arg5, const VARIANT& Arg6, const VARIANT& Arg7, const VARIANT& Arg8, const VARIANT& Arg9, const VARIANT& Arg10, 
		const VARIANT& Arg11, const VARIANT& Arg12, const VARIANT& Arg13, const VARIANT& Arg14, const VARIANT& Arg15, const VARIANT& Arg16, const VARIANT& Arg17, const VARIANT& Arg18, const VARIANT& Arg19, const VARIANT& Arg20, 
		const VARIANT& Arg21, const VARIANT& Arg22, const VARIANT& Arg23, const VARIANT& Arg24, const VARIANT& Arg25, const VARIANT& Arg26, const VARIANT& Arg27, const VARIANT& Arg28, const VARIANT& Arg29, const VARIANT& Arg30);
	LPDISPATCH GetNames();
	LPDISPATCH GetRange(const VARIANT& Cell1, const VARIANT& Cell2);
	LPDISPATCH GetRows();
	VARIANT Run(const VARIANT& Macro, const VARIANT& Arg1, const VARIANT& Arg2, const VARIANT& Arg3, const VARIANT& Arg4, const VARIANT& Arg5, const VARIANT& Arg6, const VARIANT& Arg7, const VARIANT& Arg8, const VARIANT& Arg9, 
		const VARIANT& Arg10, const VARIANT& Arg11, const VARIANT& Arg12, const VARIANT& Arg13, const VARIANT& Arg14, const VARIANT& Arg15, const VARIANT& Arg16, const VARIANT& Arg17, const VARIANT& Arg18, const VARIANT& Arg19, 
		const VARIANT& Arg20, const VARIANT& Arg21, const VARIANT& Arg22, const VARIANT& Arg23, const VARIANT& Arg24, const VARIANT& Arg25, const VARIANT& Arg26, const VARIANT& Arg27, const VARIANT& Arg28, const VARIANT& Arg29, 
		const VARIANT& Arg30);
	VARIANT _Run2(const VARIANT& Macro, const VARIANT& Arg1, const VARIANT& Arg2, const VARIANT& Arg3, const VARIANT& Arg4, const VARIANT& Arg5, const VARIANT& Arg6, const VARIANT& Arg7, const VARIANT& Arg8, const VARIANT& Arg9, 
		const VARIANT& Arg10, const VARIANT& Arg11, const VARIANT& Arg12, const VARIANT& Arg13, const VARIANT& Arg14, const VARIANT& Arg15, const VARIANT& Arg16, const VARIANT& Arg17, const VARIANT& Arg18, const VARIANT& Arg19, 
		const VARIANT& Arg20, const VARIANT& Arg21, const VARIANT& Arg22, const VARIANT& Arg23, const VARIANT& Arg24, const VARIANT& Arg25, const VARIANT& Arg26, const VARIANT& Arg27, const VARIANT& Arg28, const VARIANT& Arg29, 
		const VARIANT& Arg30);
	LPDISPATCH GetSelection();
	void SendKeys(const VARIANT& Keys, const VARIANT& Wait);
	LPDISPATCH GetSheets();
	LPDISPATCH GetThisWorkbook();
	LPDISPATCH Union(LPDISPATCH Arg1, LPDISPATCH Arg2, const VARIANT& Arg3, const VARIANT& Arg4, const VARIANT& Arg5, const VARIANT& Arg6, const VARIANT& Arg7, const VARIANT& Arg8, const VARIANT& Arg9, const VARIANT& Arg10, const VARIANT& Arg11, 
		const VARIANT& Arg12, const VARIANT& Arg13, const VARIANT& Arg14, const VARIANT& Arg15, const VARIANT& Arg16, const VARIANT& Arg17, const VARIANT& Arg18, const VARIANT& Arg19, const VARIANT& Arg20, const VARIANT& Arg21, 
		const VARIANT& Arg22, const VARIANT& Arg23, const VARIANT& Arg24, const VARIANT& Arg25, const VARIANT& Arg26, const VARIANT& Arg27, const VARIANT& Arg28, const VARIANT& Arg29, const VARIANT& Arg30);
	LPDISPATCH GetWindows();
	LPDISPATCH GetWorkbooks();
	LPDISPATCH GetWorksheetFunction();
	LPDISPATCH GetWorksheets();
	LPDISPATCH GetExcel4IntlMacroSheets();
	LPDISPATCH GetExcel4MacroSheets();
	void ActivateMicrosoftApp(long Index);
	void AddChartAutoFormat(const VARIANT& Chart, LPCTSTR Name, const VARIANT& Description);
	void AddCustomList(const VARIANT& ListArray, const VARIANT& ByRow);
	BOOL GetAlertBeforeOverwriting();
	void SetAlertBeforeOverwriting(BOOL bNewValue);
	CString GetAltStartupPath();
	void SetAltStartupPath(LPCTSTR lpszNewValue);
	BOOL GetAskToUpdateLinks();
	void SetAskToUpdateLinks(BOOL bNewValue);
	BOOL GetEnableAnimations();
	void SetEnableAnimations(BOOL bNewValue);
	LPDISPATCH GetAutoCorrect();
	long GetBuild();
	BOOL GetCalculateBeforeSave();
	void SetCalculateBeforeSave(BOOL bNewValue);
	long GetCalculation();
	void SetCalculation(long nNewValue);
	VARIANT GetCaller(const VARIANT& Index);
	BOOL GetCanPlaySounds();
	BOOL GetCanRecordSounds();
	CString GetCaption();
	void SetCaption(LPCTSTR lpszNewValue);
	BOOL GetCellDragAndDrop();
	void SetCellDragAndDrop(BOOL bNewValue);
	double CentimetersToPoints(double Centimeters);
	BOOL CheckSpelling(LPCTSTR Word, const VARIANT& CustomDictionary, const VARIANT& IgnoreUppercase);
	VARIANT GetClipboardFormats(const VARIANT& Index);
	BOOL GetDisplayClipboardWindow();
	void SetDisplayClipboardWindow(BOOL bNewValue);
	long GetCommandUnderlines();
	void SetCommandUnderlines(long nNewValue);
	BOOL GetConstrainNumeric();
	void SetConstrainNumeric(BOOL bNewValue);
	VARIANT ConvertFormula(const VARIANT& Formula, long FromReferenceStyle, const VARIANT& ToReferenceStyle, const VARIANT& ToAbsolute, const VARIANT& RelativeTo);
	BOOL GetCopyObjectsWithCells();
	void SetCopyObjectsWithCells(BOOL bNewValue);
	long GetCursor();
	void SetCursor(long nNewValue);
	long GetCustomListCount();
	long GetCutCopyMode();
	void SetCutCopyMode(long nNewValue);
	long GetDataEntryMode();
	void SetDataEntryMode(long nNewValue);
	CString Get_Default();
	CString GetDefaultFilePath();
	void SetDefaultFilePath(LPCTSTR lpszNewValue);
	void DeleteChartAutoFormat(LPCTSTR Name);
	void DeleteCustomList(long ListNum);
	LPDISPATCH GetDialogs();
	BOOL GetDisplayAlerts();
	void SetDisplayAlerts(BOOL bNewValue);
	BOOL GetDisplayFormulaBar();
	void SetDisplayFormulaBar(BOOL bNewValue);
	BOOL GetDisplayFullScreen();
	void SetDisplayFullScreen(BOOL bNewValue);
	BOOL GetDisplayNoteIndicator();
	void SetDisplayNoteIndicator(BOOL bNewValue);
	long GetDisplayCommentIndicator();
	void SetDisplayCommentIndicator(long nNewValue);
	BOOL GetDisplayExcel4Menus();
	void SetDisplayExcel4Menus(BOOL bNewValue);
	BOOL GetDisplayRecentFiles();
	void SetDisplayRecentFiles(BOOL bNewValue);
	BOOL GetDisplayScrollBars();
	void SetDisplayScrollBars(BOOL bNewValue);
	BOOL GetDisplayStatusBar();
	void SetDisplayStatusBar(BOOL bNewValue);
	void DoubleClick();
	BOOL GetEditDirectlyInCell();
	void SetEditDirectlyInCell(BOOL bNewValue);
	BOOL GetEnableAutoComplete();
	void SetEnableAutoComplete(BOOL bNewValue);
	long GetEnableCancelKey();
	void SetEnableCancelKey(long nNewValue);
	BOOL GetEnableSound();
	void SetEnableSound(BOOL bNewValue);
	VARIANT GetFileConverters(const VARIANT& Index1, const VARIANT& Index2);
	LPDISPATCH GetFileSearch();
	LPDISPATCH GetFileFind();
	BOOL GetFixedDecimal();
	void SetFixedDecimal(BOOL bNewValue);
	long GetFixedDecimalPlaces();
	void SetFixedDecimalPlaces(long nNewValue);
	VARIANT GetCustomListContents(long ListNum);
	long GetCustomListNum(const VARIANT& ListArray);
	VARIANT GetOpenFilename(const VARIANT& FileFilter, const VARIANT& FilterIndex, const VARIANT& Title, const VARIANT& ButtonText, const VARIANT& MultiSelect);
	VARIANT GetSaveAsFilename(const VARIANT& InitialFilename, const VARIANT& FileFilter, const VARIANT& FilterIndex, const VARIANT& Title, const VARIANT& ButtonText);
	void Goto(const VARIANT& Reference, const VARIANT& Scroll);
	double GetHeight();
	void SetHeight(double newValue);
	void Help(const VARIANT& HelpFile, const VARIANT& HelpContextID);
	BOOL GetIgnoreRemoteRequests();
	void SetIgnoreRemoteRequests(BOOL bNewValue);
	double InchesToPoints(double Inches);
	VARIANT InputBox(LPCTSTR Prompt, const VARIANT& Title, const VARIANT& Default, const VARIANT& Left, const VARIANT& Top, const VARIANT& HelpFile, const VARIANT& HelpContextID, const VARIANT& Type);
	BOOL GetInteractive();
	void SetInteractive(BOOL bNewValue);
	VARIANT GetInternational(const VARIANT& Index);
	BOOL GetIteration();
	void SetIteration(BOOL bNewValue);
	double GetLeft();
	void SetLeft(double newValue);
	CString GetLibraryPath();
	void MacroOptions(const VARIANT& Macro, const VARIANT& Description, const VARIANT& HasMenu, const VARIANT& MenuText, const VARIANT& HasShortcutKey, const VARIANT& ShortcutKey, const VARIANT& Category, const VARIANT& StatusBar, 
		const VARIANT& HelpContextID, const VARIANT& HelpFile);
	void MailLogoff();
	void MailLogon(const VARIANT& Name, const VARIANT& Password, const VARIANT& DownloadNewMail);
	VARIANT GetMailSession();
	long GetMailSystem();
	BOOL GetMathCoprocessorAvailable();
	double GetMaxChange();
	void SetMaxChange(double newValue);
	long GetMaxIterations();
	void SetMaxIterations(long nNewValue);
	BOOL GetMouseAvailable();
	BOOL GetMoveAfterReturn();
	void SetMoveAfterReturn(BOOL bNewValue);
	long GetMoveAfterReturnDirection();
	void SetMoveAfterReturnDirection(long nNewValue);
	LPDISPATCH GetRecentFiles();
	CString GetName();
	LPDISPATCH NextLetter();
	CString GetNetworkTemplatesPath();
	LPDISPATCH GetODBCErrors();
	long GetODBCTimeout();
	void SetODBCTimeout(long nNewValue);
	void OnKey(LPCTSTR Key, const VARIANT& Procedure);
	void OnRepeat(LPCTSTR Text, LPCTSTR Procedure);
	void OnTime(const VARIANT& EarliestTime, LPCTSTR Procedure, const VARIANT& LatestTime, const VARIANT& Schedule);
	void OnUndo(LPCTSTR Text, LPCTSTR Procedure);
	CString GetOnWindow();
	void SetOnWindow(LPCTSTR lpszNewValue);
	CString GetOperatingSystem();
	CString GetOrganizationName();
	CString GetPath();
	CString GetPathSeparator();
	VARIANT GetPreviousSelections(const VARIANT& Index);
	BOOL GetPivotTableSelection();
	void SetPivotTableSelection(BOOL bNewValue);
	BOOL GetPromptForSummaryInfo();
	void SetPromptForSummaryInfo(BOOL bNewValue);
	void Quit();
	void RecordMacro(const VARIANT& BasicCode, const VARIANT& XlmCode);
	BOOL GetRecordRelative();
	long GetReferenceStyle();
	void SetReferenceStyle(long nNewValue);
	VARIANT GetRegisteredFunctions(const VARIANT& Index1, const VARIANT& Index2);
	BOOL RegisterXLL(LPCTSTR Filename);
	void Repeat();
	BOOL GetRollZoom();
	void SetRollZoom(BOOL bNewValue);
	void SaveWorkspace(const VARIANT& Filename);
	BOOL GetScreenUpdating();
	void SetScreenUpdating(BOOL bNewValue);
	void SetDefaultChart(const VARIANT& FormatName, const VARIANT& Gallery);
	long GetSheetsInNewWorkbook();
	void SetSheetsInNewWorkbook(long nNewValue);
	BOOL GetShowChartTipNames();
	void SetShowChartTipNames(BOOL bNewValue);
	BOOL GetShowChartTipValues();
	void SetShowChartTipValues(BOOL bNewValue);
	CString GetStandardFont();
	void SetStandardFont(LPCTSTR lpszNewValue);
	double GetStandardFontSize();
	void SetStandardFontSize(double newValue);
	CString GetStartupPath();
	VARIANT GetStatusBar();
	void SetStatusBar(const VARIANT& newValue);
	CString GetTemplatesPath();
	BOOL GetShowToolTips();
	void SetShowToolTips(BOOL bNewValue);
	double GetTop();
	void SetTop(double newValue);
	long GetDefaultSaveFormat();
	void SetDefaultSaveFormat(long nNewValue);
	CString GetTransitionMenuKey();
	void SetTransitionMenuKey(LPCTSTR lpszNewValue);
	long GetTransitionMenuKeyAction();
	void SetTransitionMenuKeyAction(long nNewValue);
	BOOL GetTransitionNavigKeys();
	void SetTransitionNavigKeys(BOOL bNewValue);
	void Undo();
	double GetUsableHeight();
	double GetUsableWidth();
	BOOL GetUserControl();
	void SetUserControl(BOOL bNewValue);
	CString GetUserName_();
	void SetUserName(LPCTSTR lpszNewValue);
	CString GetValue();
	LPDISPATCH GetVbe();
	CString GetVersion();
	BOOL GetVisible();
	void SetVisible(BOOL bNewValue);
	void Volatile(const VARIANT& Volatile);
	double GetWidth();
	void SetWidth(double newValue);
	BOOL GetWindowsForPens();
	long GetWindowState();
	void SetWindowState(long nNewValue);
	long GetDefaultSheetDirection();
	void SetDefaultSheetDirection(long nNewValue);
	long GetCursorMovement();
	void SetCursorMovement(long nNewValue);
	BOOL GetControlCharacters();
	void SetControlCharacters(BOOL bNewValue);
	BOOL GetEnableEvents();
	void SetEnableEvents(BOOL bNewValue);
	BOOL Wait(const VARIANT& Time);
	BOOL GetExtendList();
	void SetExtendList(BOOL bNewValue);
	LPDISPATCH GetOLEDBErrors();
	CString GetPhonetic(const VARIANT& Text);
	LPDISPATCH GetCOMAddIns();
	LPDISPATCH GetDefaultWebOptions();
	CString GetProductCode();
	CString GetUserLibraryPath();
	BOOL GetAutoPercentEntry();
	void SetAutoPercentEntry(BOOL bNewValue);
	LPDISPATCH GetLanguageSettings();
	LPDISPATCH GetAnswerWizard();
	void CalculateFull();
	BOOL FindFile();
	long GetCalculationVersion();
	BOOL GetShowWindowsInTaskbar();
	void SetShowWindowsInTaskbar(BOOL bNewValue);
	long GetFeatureInstall();
	void SetFeatureInstall(long nNewValue);
	BOOL GetReady();
	LPDISPATCH GetFindFormat();
	void SetRefFindFormat(LPDISPATCH newValue);
	LPDISPATCH GetReplaceFormat();
	void SetRefReplaceFormat(LPDISPATCH newValue);
	LPDISPATCH GetUsedObjects();
	long GetCalculationState();
	long GetCalculationInterruptKey();
	void SetCalculationInterruptKey(long nNewValue);
	LPDISPATCH GetWatches();
	BOOL GetDisplayFunctionToolTips();
	void SetDisplayFunctionToolTips(BOOL bNewValue);
	long GetAutomationSecurity();
	void SetAutomationSecurity(long nNewValue);
	LPDISPATCH GetFileDialog(long fileDialogType);
	void CalculateFullRebuild();
	BOOL GetDisplayPasteOptions();
	void SetDisplayPasteOptions(BOOL bNewValue);
	BOOL GetDisplayInsertOptions();
	void SetDisplayInsertOptions(BOOL bNewValue);
	BOOL GetGenerateGetPivotData();
	void SetGenerateGetPivotData(BOOL bNewValue);
	LPDISPATCH GetAutoRecover();
	long GetHwnd();
	long GetHinstance();
	void CheckAbort(const VARIANT& KeepAbort);
	LPDISPATCH GetErrorCheckingOptions();
	BOOL GetAutoFormatAsYouTypeReplaceHyperlinks();
	void SetAutoFormatAsYouTypeReplaceHyperlinks(BOOL bNewValue);
	LPDISPATCH GetSmartTagRecognizers();
	LPDISPATCH GetNewWorkbook();
	LPDISPATCH GetSpellingOptions();
	LPDISPATCH GetSpeech();
	BOOL GetMapPaperSize();
	void SetMapPaperSize(BOOL bNewValue);
	BOOL GetShowStartupDialog();
	void SetShowStartupDialog(BOOL bNewValue);
	CString GetDecimalSeparator();
	void SetDecimalSeparator(LPCTSTR lpszNewValue);
	CString GetThousandsSeparator();
	void SetThousandsSeparator(LPCTSTR lpszNewValue);
	BOOL GetUseSystemSeparators();
	void SetUseSystemSeparators(BOOL bNewValue);
	LPDISPATCH GetThisCell();
	LPDISPATCH GetRtd();
	BOOL GetDisplayDocumentActionTaskPane();
	void SetDisplayDocumentActionTaskPane(BOOL bNewValue);
	void DisplayXMLSourcePane(const VARIANT& XmlMap);
	BOOL GetArbitraryXMLSupportAvailable();
};
/////////////////////////////////////////////////////////////////////////////
// _Worksheet wrapper class

class _Worksheet : public COleDispatchDriver
{
public:
	_Worksheet() {}		// Calls COleDispatchDriver default constructor
	_Worksheet(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	_Worksheet(const _Worksheet& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	void Activate();
	void Copy(const VARIANT& Before, const VARIANT& After);
	void Delete();
	CString GetCodeName();
	CString Get_CodeName();
	void Set_CodeName(LPCTSTR lpszNewValue);
	long GetIndex();
	void Move(const VARIANT& Before, const VARIANT& After);
	CString GetName();
	void SetName(LPCTSTR lpszNewValue);
	LPDISPATCH GetNext();
	LPDISPATCH GetPageSetup();
	LPDISPATCH GetPrevious();
	void PrintPreview(const VARIANT& EnableChanges);
	BOOL GetProtectContents();
	BOOL GetProtectDrawingObjects();
	BOOL GetProtectionMode();
	BOOL GetProtectScenarios();
	void Select(const VARIANT& Replace);
	void Unprotect(const VARIANT& Password);
	long GetVisible();
	void SetVisible(long nNewValue);
	LPDISPATCH GetShapes();
	BOOL GetTransitionExpEval();
	void SetTransitionExpEval(BOOL bNewValue);
	BOOL GetAutoFilterMode();
	void SetAutoFilterMode(BOOL bNewValue);
	void SetBackgroundPicture(LPCTSTR Filename);
	void Calculate();
	BOOL GetEnableCalculation();
	void SetEnableCalculation(BOOL bNewValue);
	LPDISPATCH GetCells();
	LPDISPATCH ChartObjects(const VARIANT& Index);
	void CheckSpelling(const VARIANT& CustomDictionary, const VARIANT& IgnoreUppercase, const VARIANT& AlwaysSuggest, const VARIANT& SpellLang);
	LPDISPATCH GetCircularReference();
	void ClearArrows();
	LPDISPATCH GetColumns();
	long GetConsolidationFunction();
	VARIANT GetConsolidationOptions();
	VARIANT GetConsolidationSources();
	BOOL GetEnableAutoFilter();
	void SetEnableAutoFilter(BOOL bNewValue);
	long GetEnableSelection();
	void SetEnableSelection(long nNewValue);
	BOOL GetEnableOutlining();
	void SetEnableOutlining(BOOL bNewValue);
	BOOL GetEnablePivotTable();
	void SetEnablePivotTable(BOOL bNewValue);
	VARIANT Evaluate(const VARIANT& Name);
	VARIANT _Evaluate(const VARIANT& Name);
	BOOL GetFilterMode();
	void ResetAllPageBreaks();
	LPDISPATCH GetNames();
	LPDISPATCH OLEObjects(const VARIANT& Index);
	LPDISPATCH GetOutline();
	void Paste(const VARIANT& Destination, const VARIANT& Link);
	LPDISPATCH PivotTables(const VARIANT& Index);
	LPDISPATCH PivotTableWizard(const VARIANT& SourceType, const VARIANT& SourceData, const VARIANT& TableDestination, const VARIANT& TableName, const VARIANT& RowGrand, const VARIANT& ColumnGrand, const VARIANT& SaveData, 
		const VARIANT& HasAutoFormat, const VARIANT& AutoPage, const VARIANT& Reserved, const VARIANT& BackgroundQuery, const VARIANT& OptimizeCache, const VARIANT& PageFieldOrder, const VARIANT& PageFieldWrapCount, const VARIANT& ReadData, 
		const VARIANT& Connection);
	LPDISPATCH GetRange(const VARIANT& Cell1, const VARIANT& Cell2);
	LPDISPATCH GetRows();
	LPDISPATCH Scenarios(const VARIANT& Index);
	CString GetScrollArea();
	void SetScrollArea(LPCTSTR lpszNewValue);
	void ShowAllData();
	void ShowDataForm();
	double GetStandardHeight();
	double GetStandardWidth();
	void SetStandardWidth(double newValue);
	BOOL GetTransitionFormEntry();
	void SetTransitionFormEntry(BOOL bNewValue);
	long GetType();
	LPDISPATCH GetUsedRange();
	LPDISPATCH GetHPageBreaks();
	LPDISPATCH GetVPageBreaks();
	LPDISPATCH GetQueryTables();
	BOOL GetDisplayPageBreaks();
	void SetDisplayPageBreaks(BOOL bNewValue);
	LPDISPATCH GetComments();
	LPDISPATCH GetHyperlinks();
	void ClearCircles();
	void CircleInvalid();
	LPDISPATCH GetAutoFilter();
	BOOL GetDisplayRightToLeft();
	void SetDisplayRightToLeft(BOOL bNewValue);
	LPDISPATCH GetScripts();
	void PrintOut(const VARIANT& From, const VARIANT& To, const VARIANT& Copies, const VARIANT& Preview, const VARIANT& ActivePrinter, const VARIANT& PrintToFile, const VARIANT& Collate, const VARIANT& PrToFileName);
	LPDISPATCH GetTab();
	LPDISPATCH GetMailEnvelope();
	void SaveAs(LPCTSTR Filename, const VARIANT& FileFormat, const VARIANT& Password, const VARIANT& WriteResPassword, const VARIANT& ReadOnlyRecommended, const VARIANT& CreateBackup, const VARIANT& AddToMru, const VARIANT& TextCodepage, 
		const VARIANT& TextVisualLayout, const VARIANT& Local);
	LPDISPATCH GetCustomProperties();
	LPDISPATCH GetSmartTags();
	LPDISPATCH GetProtection();
	void PasteSpecial(const VARIANT& Format, const VARIANT& Link, const VARIANT& DisplayAsIcon, const VARIANT& IconFileName, const VARIANT& IconIndex, const VARIANT& IconLabel, const VARIANT& NoHTMLFormatting);
	void Protect(const VARIANT& Password, const VARIANT& DrawingObjects, const VARIANT& Contents, const VARIANT& Scenarios, const VARIANT& UserInterfaceOnly, const VARIANT& AllowFormattingCells, const VARIANT& AllowFormattingColumns, 
		const VARIANT& AllowFormattingRows, const VARIANT& AllowInsertingColumns, const VARIANT& AllowInsertingRows, const VARIANT& AllowInsertingHyperlinks, const VARIANT& AllowDeletingColumns, const VARIANT& AllowDeletingRows, 
		const VARIANT& AllowSorting, const VARIANT& AllowFiltering, const VARIANT& AllowUsingPivotTables);
	LPDISPATCH GetListObjects();
	LPDISPATCH XmlDataQuery(LPCTSTR XPath, const VARIANT& SelectionNamespaces, const VARIANT& Map);
	LPDISPATCH XmlMapQuery(LPCTSTR XPath, const VARIANT& SelectionNamespaces, const VARIANT& Map);
};
/////////////////////////////////////////////////////////////////////////////
// _Workbook wrapper class

class _Workbook : public COleDispatchDriver
{
public:
	_Workbook() {}		// Calls COleDispatchDriver default constructor
	_Workbook(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	_Workbook(const _Workbook& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	BOOL GetAcceptLabelsInFormulas();
	void SetAcceptLabelsInFormulas(BOOL bNewValue);
	void Activate();
	LPDISPATCH GetActiveChart();
	LPDISPATCH GetActiveSheet();
	long GetAutoUpdateFrequency();
	void SetAutoUpdateFrequency(long nNewValue);
	BOOL GetAutoUpdateSaveChanges();
	void SetAutoUpdateSaveChanges(BOOL bNewValue);
	long GetChangeHistoryDuration();
	void SetChangeHistoryDuration(long nNewValue);
	LPDISPATCH GetBuiltinDocumentProperties();
	void ChangeFileAccess(long Mode, const VARIANT& WritePassword, const VARIANT& Notify);
	void ChangeLink(LPCTSTR Name, LPCTSTR NewName, long Type);
	LPDISPATCH GetCharts();
	void Close(const VARIANT& SaveChanges, const VARIANT& Filename, const VARIANT& RouteWorkbook);
	CString GetCodeName();
	CString Get_CodeName();
	void Set_CodeName(LPCTSTR lpszNewValue);
	VARIANT GetColors(const VARIANT& Index);
	void SetColors(const VARIANT& Index, const VARIANT& newValue);
	LPDISPATCH GetCommandBars();
	long GetConflictResolution();
	void SetConflictResolution(long nNewValue);
	LPDISPATCH GetContainer();
	BOOL GetCreateBackup();
	LPDISPATCH GetCustomDocumentProperties();
	BOOL GetDate1904();
	void SetDate1904(BOOL bNewValue);
	void DeleteNumberFormat(LPCTSTR NumberFormat);
	long GetDisplayDrawingObjects();
	void SetDisplayDrawingObjects(long nNewValue);
	BOOL ExclusiveAccess();
	long GetFileFormat();
	void ForwardMailer();
	CString GetFullName();
	BOOL GetHasPassword();
	BOOL GetHasRoutingSlip();
	void SetHasRoutingSlip(BOOL bNewValue);
	BOOL GetIsAddin();
	void SetIsAddin(BOOL bNewValue);
	VARIANT LinkInfo(LPCTSTR Name, long LinkInfo, const VARIANT& Type, const VARIANT& EditionRef);
	VARIANT LinkSources(const VARIANT& Type);
	LPDISPATCH GetMailer();
	void MergeWorkbook(const VARIANT& Filename);
	BOOL GetMultiUserEditing();
	CString GetName();
	LPDISPATCH GetNames();
	LPDISPATCH NewWindow();
	void OpenLinks(LPCTSTR Name, const VARIANT& ReadOnly, const VARIANT& Type);
	CString GetPath();
	BOOL GetPersonalViewListSettings();
	void SetPersonalViewListSettings(BOOL bNewValue);
	BOOL GetPersonalViewPrintSettings();
	void SetPersonalViewPrintSettings(BOOL bNewValue);
	LPDISPATCH PivotCaches();
	void Post(const VARIANT& DestName);
	BOOL GetPrecisionAsDisplayed();
	void SetPrecisionAsDisplayed(BOOL bNewValue);
	void PrintPreview(const VARIANT& EnableChanges);
	void ProtectSharing(const VARIANT& Filename, const VARIANT& Password, const VARIANT& WriteResPassword, const VARIANT& ReadOnlyRecommended, const VARIANT& CreateBackup, const VARIANT& SharingPassword);
	BOOL GetProtectStructure();
	BOOL GetProtectWindows();
	BOOL GetReadOnly();
	void RefreshAll();
	void Reply();
	void ReplyAll();
	void RemoveUser(long Index);
	long GetRevisionNumber();
	void Route();
	BOOL GetRouted();
	LPDISPATCH GetRoutingSlip();
	void RunAutoMacros(long Which);
	void Save();
	void SaveCopyAs(const VARIANT& Filename);
	BOOL GetSaved();
	void SetSaved(BOOL bNewValue);
	BOOL GetSaveLinkValues();
	void SetSaveLinkValues(BOOL bNewValue);
	void SendMail(const VARIANT& Recipients, const VARIANT& Subject, const VARIANT& ReturnReceipt);
	void SendMailer(const VARIANT& FileFormat, long Priority);
	void SetLinkOnData(LPCTSTR Name, const VARIANT& Procedure);
	LPDISPATCH GetSheets();
	BOOL GetShowConflictHistory();
	void SetShowConflictHistory(BOOL bNewValue);
	LPDISPATCH GetStyles();
	void Unprotect(const VARIANT& Password);
	void UnprotectSharing(const VARIANT& SharingPassword);
	void UpdateFromFile();
	void UpdateLink(const VARIANT& Name, const VARIANT& Type);
	BOOL GetUpdateRemoteReferences();
	void SetUpdateRemoteReferences(BOOL bNewValue);
	VARIANT GetUserStatus();
	LPDISPATCH GetCustomViews();
	LPDISPATCH GetWindows();
	LPDISPATCH GetWorksheets();
	BOOL GetWriteReserved();
	CString GetWriteReservedBy();
	LPDISPATCH GetExcel4IntlMacroSheets();
	LPDISPATCH GetExcel4MacroSheets();
	BOOL GetTemplateRemoveExtData();
	void SetTemplateRemoveExtData(BOOL bNewValue);
	void HighlightChangesOptions(const VARIANT& When, const VARIANT& Who, const VARIANT& Where);
	BOOL GetHighlightChangesOnScreen();
	void SetHighlightChangesOnScreen(BOOL bNewValue);
	BOOL GetKeepChangeHistory();
	void SetKeepChangeHistory(BOOL bNewValue);
	BOOL GetListChangesOnNewSheet();
	void SetListChangesOnNewSheet(BOOL bNewValue);
	void PurgeChangeHistoryNow(long Days, const VARIANT& SharingPassword);
	void AcceptAllChanges(const VARIANT& When, const VARIANT& Who, const VARIANT& Where);
	void RejectAllChanges(const VARIANT& When, const VARIANT& Who, const VARIANT& Where);
	void ResetColors();
	LPDISPATCH GetVBProject();
	void FollowHyperlink(LPCTSTR Address, const VARIANT& SubAddress, const VARIANT& NewWindow, const VARIANT& AddHistory, const VARIANT& ExtraInfo, const VARIANT& Method, const VARIANT& HeaderInfo);
	void AddToFavorites();
	BOOL GetIsInplace();
	void PrintOut(const VARIANT& From, const VARIANT& To, const VARIANT& Copies, const VARIANT& Preview, const VARIANT& ActivePrinter, const VARIANT& PrintToFile, const VARIANT& Collate, const VARIANT& PrToFileName);
	void WebPagePreview();
	LPDISPATCH GetPublishObjects();
	LPDISPATCH GetWebOptions();
	void ReloadAs(long Encoding);
	LPDISPATCH GetHTMLProject();
	BOOL GetEnvelopeVisible();
	void SetEnvelopeVisible(BOOL bNewValue);
	long GetCalculationVersion();
	BOOL GetVBASigned();
	BOOL GetShowPivotTableFieldList();
	void SetShowPivotTableFieldList(BOOL bNewValue);
	long GetUpdateLinks();
	void SetUpdateLinks(long nNewValue);
	void BreakLink(LPCTSTR Name, long Type);
	void SaveAs(const VARIANT& Filename, const VARIANT& FileFormat, const VARIANT& Password, const VARIANT& WriteResPassword, const VARIANT& ReadOnlyRecommended, const VARIANT& CreateBackup, long AccessMode, const VARIANT& ConflictResolution, 
		const VARIANT& AddToMru, const VARIANT& TextCodepage, const VARIANT& TextVisualLayout, const VARIANT& Local);
	BOOL GetEnableAutoRecover();
	void SetEnableAutoRecover(BOOL bNewValue);
	BOOL GetRemovePersonalInformation();
	void SetRemovePersonalInformation(BOOL bNewValue);
	CString GetFullNameURLEncoded();
	void CheckIn(const VARIANT& SaveChanges, const VARIANT& Comments, const VARIANT& MakePublic);
	BOOL CanCheckIn();
	void SendForReview(const VARIANT& Recipients, const VARIANT& Subject, const VARIANT& ShowMessage, const VARIANT& IncludeAttachment);
	void ReplyWithChanges(const VARIANT& ShowMessage);
	void EndReview();
	CString GetPassword();
	void SetPassword(LPCTSTR lpszNewValue);
	CString GetWritePassword();
	void SetWritePassword(LPCTSTR lpszNewValue);
	CString GetPasswordEncryptionProvider();
	CString GetPasswordEncryptionAlgorithm();
	long GetPasswordEncryptionKeyLength();
	void SetPasswordEncryptionOptions(const VARIANT& PasswordEncryptionProvider, const VARIANT& PasswordEncryptionAlgorithm, const VARIANT& PasswordEncryptionKeyLength, const VARIANT& PasswordEncryptionFileProperties);
	BOOL GetPasswordEncryptionFileProperties();
	BOOL GetReadOnlyRecommended();
	void SetReadOnlyRecommended(BOOL bNewValue);
	void Protect(const VARIANT& Password, const VARIANT& Structure, const VARIANT& Windows);
	LPDISPATCH GetSmartTagOptions();
	void RecheckSmartTags();
	LPDISPATCH GetPermission();
	LPDISPATCH GetSharedWorkspace();
	LPDISPATCH GetSync();
	void SendFaxOverInternet(const VARIANT& Recipients, const VARIANT& Subject, const VARIANT& ShowMessage);
	LPDISPATCH GetXmlNamespaces();
	LPDISPATCH GetXmlMaps();
	long XmlImport(LPCTSTR Url, LPDISPATCH* ImportMap, const VARIANT& Overwrite, const VARIANT& Destination);
	LPDISPATCH GetSmartDocument();
	LPDISPATCH GetDocumentLibraryVersions();
	BOOL GetInactiveListBorderVisible();
	void SetInactiveListBorderVisible(BOOL bNewValue);
	BOOL GetDisplayInkComments();
	void SetDisplayInkComments(BOOL bNewValue);
	long XmlImportXml(LPCTSTR Data, LPDISPATCH* ImportMap, const VARIANT& Overwrite, const VARIANT& Destination);
	void SaveAsXMLData(LPCTSTR Filename, LPDISPATCH Map);
	void ToggleFormsDesign();
};
/////////////////////////////////////////////////////////////////////////////
// Workbooks wrapper class

class Workbooks : public COleDispatchDriver
{
public:
	Workbooks() {}		// Calls COleDispatchDriver default constructor
	Workbooks(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	Workbooks(const Workbooks& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	LPDISPATCH Add(const VARIANT& Template);
	void Close();
	long GetCount();
	LPDISPATCH GetItem(const VARIANT& Index);
	LPUNKNOWN Get_NewEnum();
	LPDISPATCH Get_Default(const VARIANT& Index);
	LPDISPATCH Open(LPCTSTR Filename, const VARIANT& UpdateLinks, const VARIANT& ReadOnly, const VARIANT& Format, const VARIANT& Password, const VARIANT& WriteResPassword, const VARIANT& IgnoreReadOnlyRecommended, const VARIANT& Origin, 
		const VARIANT& Delimiter, const VARIANT& Editable, const VARIANT& Notify, const VARIANT& Converter, const VARIANT& AddToMru, const VARIANT& Local, const VARIANT& CorruptLoad);
	void OpenText(LPCTSTR Filename, const VARIANT& Origin, const VARIANT& StartRow, const VARIANT& DataType, long TextQualifier, const VARIANT& ConsecutiveDelimiter, const VARIANT& Tab, const VARIANT& Semicolon, const VARIANT& Comma, 
		const VARIANT& Space, const VARIANT& Other, const VARIANT& OtherChar, const VARIANT& FieldInfo, const VARIANT& TextVisualLayout, const VARIANT& DecimalSeparator, const VARIANT& ThousandsSeparator, const VARIANT& TrailingMinusNumbers, 
		const VARIANT& Local);
	LPDISPATCH OpenDatabase(LPCTSTR Filename, const VARIANT& CommandText, const VARIANT& CommandType, const VARIANT& BackgroundQuery, const VARIANT& ImportDataAs);
	void CheckOut(LPCTSTR Filename);
	BOOL CanCheckOut(LPCTSTR Filename);
	LPDISPATCH OpenXML(LPCTSTR Filename, const VARIANT& Stylesheets, const VARIANT& LoadOption);
};
/////////////////////////////////////////////////////////////////////////////
// Range wrapper class

class Range : public COleDispatchDriver
{
public:
	Range() {}		// Calls COleDispatchDriver default constructor
	Range(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	Range(const Range& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	VARIANT Activate();
	VARIANT GetAddIndent();
	void SetAddIndent(const VARIANT& newValue);
	CString GetAddress(const VARIANT& RowAbsolute, const VARIANT& ColumnAbsolute, long ReferenceStyle, const VARIANT& External, const VARIANT& RelativeTo);
	CString GetAddressLocal(const VARIANT& RowAbsolute, const VARIANT& ColumnAbsolute, long ReferenceStyle, const VARIANT& External, const VARIANT& RelativeTo);
	VARIANT AdvancedFilter(long Action, const VARIANT& CriteriaRange, const VARIANT& CopyToRange, const VARIANT& Unique);
	VARIANT ApplyNames(const VARIANT& Names, const VARIANT& IgnoreRelativeAbsolute, const VARIANT& UseRowColumnNames, const VARIANT& OmitColumn, const VARIANT& OmitRow, long Order, const VARIANT& AppendLast);
	VARIANT ApplyOutlineStyles();
	LPDISPATCH GetAreas();
	CString AutoComplete(LPCTSTR String);
	VARIANT AutoFill(LPDISPATCH Destination, long Type);
	VARIANT AutoFilter(const VARIANT& Field, const VARIANT& Criteria1, long Operator, const VARIANT& Criteria2, const VARIANT& VisibleDropDown);
	VARIANT AutoFit();
	VARIANT AutoFormat(long Format, const VARIANT& Number, const VARIANT& Font, const VARIANT& Alignment, const VARIANT& Border, const VARIANT& Pattern, const VARIANT& Width);
	VARIANT AutoOutline();
	VARIANT BorderAround(const VARIANT& LineStyle, long Weight, long ColorIndex, const VARIANT& Color);
	LPDISPATCH GetBorders();
	VARIANT Calculate();
	LPDISPATCH GetCells();
	LPDISPATCH GetCharacters(const VARIANT& Start, const VARIANT& Length);
	VARIANT CheckSpelling(const VARIANT& CustomDictionary, const VARIANT& IgnoreUppercase, const VARIANT& AlwaysSuggest, const VARIANT& SpellLang);
	VARIANT Clear();
	VARIANT ClearContents();
	VARIANT ClearFormats();
	VARIANT ClearNotes();
	VARIANT ClearOutline();
	long GetColumn();
	LPDISPATCH ColumnDifferences(const VARIANT& Comparison);
	LPDISPATCH GetColumns();
	VARIANT GetColumnWidth();
	void SetColumnWidth(const VARIANT& newValue);
	VARIANT Consolidate(const VARIANT& Sources, const VARIANT& Function, const VARIANT& TopRow, const VARIANT& LeftColumn, const VARIANT& CreateLinks);
	VARIANT Copy(const VARIANT& Destination);
	long CopyFromRecordset(LPUNKNOWN Data, const VARIANT& MaxRows, const VARIANT& MaxColumns);
	VARIANT CopyPicture(long Appearance, long Format);
	long GetCount();
	VARIANT CreateNames(const VARIANT& Top, const VARIANT& Left, const VARIANT& Bottom, const VARIANT& Right);
	VARIANT CreatePublisher(const VARIANT& Edition, long Appearance, const VARIANT& ContainsPICT, const VARIANT& ContainsBIFF, const VARIANT& ContainsRTF, const VARIANT& ContainsVALU);
	LPDISPATCH GetCurrentArray();
	LPDISPATCH GetCurrentRegion();
	VARIANT Cut(const VARIANT& Destination);
	VARIANT DataSeries(const VARIANT& Rowcol, long Type, long Date, const VARIANT& Step, const VARIANT& Stop, const VARIANT& Trend);
	VARIANT Get_Default(const VARIANT& RowIndex, const VARIANT& ColumnIndex);
	void Set_Default(const VARIANT& RowIndex, const VARIANT& ColumnIndex, const VARIANT& newValue);
	VARIANT Delete(const VARIANT& Shift);
	LPDISPATCH GetDependents();
	VARIANT DialogBox_();
	LPDISPATCH GetDirectDependents();
	LPDISPATCH GetDirectPrecedents();
	VARIANT EditionOptions(long Type, long Option, const VARIANT& Name, const VARIANT& Reference, long Appearance, long ChartSize, const VARIANT& Format);
	LPDISPATCH GetEnd(long Direction);
	LPDISPATCH GetEntireColumn();
	LPDISPATCH GetEntireRow();
	VARIANT FillDown();
	VARIANT FillLeft();
	VARIANT FillRight();
	VARIANT FillUp();
	LPDISPATCH Find(const VARIANT& What, const VARIANT& After, const VARIANT& LookIn, const VARIANT& LookAt, const VARIANT& SearchOrder, long SearchDirection, const VARIANT& MatchCase, const VARIANT& MatchByte, const VARIANT& SearchFormat);
	LPDISPATCH FindNext(const VARIANT& After);
	LPDISPATCH FindPrevious(const VARIANT& After);
	LPDISPATCH GetFont();
	VARIANT GetFormula();
	void SetFormula(const VARIANT& newValue);
	VARIANT GetFormulaArray();
	void SetFormulaArray(const VARIANT& newValue);
	long GetFormulaLabel();
	void SetFormulaLabel(long nNewValue);
	VARIANT GetFormulaHidden();
	void SetFormulaHidden(const VARIANT& newValue);
	VARIANT GetFormulaLocal();
	void SetFormulaLocal(const VARIANT& newValue);
	VARIANT GetFormulaR1C1();
	void SetFormulaR1C1(const VARIANT& newValue);
	VARIANT GetFormulaR1C1Local();
	void SetFormulaR1C1Local(const VARIANT& newValue);
	VARIANT FunctionWizard();
	BOOL GoalSeek(const VARIANT& Goal, LPDISPATCH ChangingCell);
	VARIANT Group(const VARIANT& Start, const VARIANT& End, const VARIANT& By, const VARIANT& Periods);
	VARIANT GetHasArray();
	VARIANT GetHasFormula();
	VARIANT GetHeight();
	VARIANT GetHidden();
	void SetHidden(const VARIANT& newValue);
	VARIANT GetHorizontalAlignment();
	void SetHorizontalAlignment(const VARIANT& newValue);
	VARIANT GetIndentLevel();
	void SetIndentLevel(const VARIANT& newValue);
	void InsertIndent(long InsertAmount);
	VARIANT Insert(const VARIANT& Shift, const VARIANT& CopyOrigin);
	LPDISPATCH GetInterior();
	VARIANT GetItem(const VARIANT& RowIndex, const VARIANT& ColumnIndex);
	void SetItem(const VARIANT& RowIndex, const VARIANT& ColumnIndex, const VARIANT& newValue);
	VARIANT Justify();
	VARIANT GetLeft();
	long GetListHeaderRows();
	VARIANT ListNames();
	long GetLocationInTable();
	VARIANT GetLocked();
	void SetLocked(const VARIANT& newValue);
	void Merge(const VARIANT& Across);
	void UnMerge();
	LPDISPATCH GetMergeArea();
	VARIANT GetMergeCells();
	void SetMergeCells(const VARIANT& newValue);
	VARIANT GetName();
	void SetName(const VARIANT& newValue);
	VARIANT NavigateArrow(const VARIANT& TowardPrecedent, const VARIANT& ArrowNumber, const VARIANT& LinkNumber);
	LPUNKNOWN Get_NewEnum();
	LPDISPATCH GetNext();
	CString NoteText(const VARIANT& Text, const VARIANT& Start, const VARIANT& Length);
	VARIANT GetNumberFormat();
	void SetNumberFormat(const VARIANT& newValue);
	VARIANT GetNumberFormatLocal();
	void SetNumberFormatLocal(const VARIANT& newValue);
	LPDISPATCH GetOffset(const VARIANT& RowOffset, const VARIANT& ColumnOffset);
	VARIANT GetOrientation();
	void SetOrientation(const VARIANT& newValue);
	VARIANT GetOutlineLevel();
	void SetOutlineLevel(const VARIANT& newValue);
	long GetPageBreak();
	void SetPageBreak(long nNewValue);
	VARIANT Parse(const VARIANT& ParseLine, const VARIANT& Destination);
	LPDISPATCH GetPivotField();
	LPDISPATCH GetPivotItem();
	LPDISPATCH GetPivotTable();
	LPDISPATCH GetPrecedents();
	VARIANT GetPrefixCharacter();
	LPDISPATCH GetPrevious();
	VARIANT _PrintOut(const VARIANT& From, const VARIANT& To, const VARIANT& Copies, const VARIANT& Preview, const VARIANT& ActivePrinter, const VARIANT& PrintToFile, const VARIANT& Collate);
	VARIANT PrintPreview(const VARIANT& EnableChanges);
	LPDISPATCH GetQueryTable();
	LPDISPATCH GetRange(const VARIANT& Cell1, const VARIANT& Cell2);
	VARIANT RemoveSubtotal();
	BOOL Replace(const VARIANT& What, const VARIANT& Replacement, const VARIANT& LookAt, const VARIANT& SearchOrder, const VARIANT& MatchCase, const VARIANT& MatchByte, const VARIANT& SearchFormat, const VARIANT& ReplaceFormat);
	LPDISPATCH GetResize(const VARIANT& RowSize, const VARIANT& ColumnSize);
	long GetRow();
	LPDISPATCH RowDifferences(const VARIANT& Comparison);
	VARIANT GetRowHeight();
	void SetRowHeight(const VARIANT& newValue);
	LPDISPATCH GetRows();
	VARIANT Run(const VARIANT& Arg1, const VARIANT& Arg2, const VARIANT& Arg3, const VARIANT& Arg4, const VARIANT& Arg5, const VARIANT& Arg6, const VARIANT& Arg7, const VARIANT& Arg8, const VARIANT& Arg9, const VARIANT& Arg10, 
		const VARIANT& Arg11, const VARIANT& Arg12, const VARIANT& Arg13, const VARIANT& Arg14, const VARIANT& Arg15, const VARIANT& Arg16, const VARIANT& Arg17, const VARIANT& Arg18, const VARIANT& Arg19, const VARIANT& Arg20, 
		const VARIANT& Arg21, const VARIANT& Arg22, const VARIANT& Arg23, const VARIANT& Arg24, const VARIANT& Arg25, const VARIANT& Arg26, const VARIANT& Arg27, const VARIANT& Arg28, const VARIANT& Arg29, const VARIANT& Arg30);
	VARIANT Select();
	VARIANT Show();
	VARIANT ShowDependents(const VARIANT& Remove);
	VARIANT GetShowDetail();
	void SetShowDetail(const VARIANT& newValue);
	VARIANT ShowErrors();
	VARIANT ShowPrecedents(const VARIANT& Remove);
	VARIANT GetShrinkToFit();
	void SetShrinkToFit(const VARIANT& newValue);
	VARIANT Sort(const VARIANT& Key1, long Order1, const VARIANT& Key2, const VARIANT& Type, long Order2, const VARIANT& Key3, long Order3, long Header, const VARIANT& OrderCustom, const VARIANT& MatchCase, long Orientation, long SortMethod, 
		long DataOption1, long DataOption2, long DataOption3);
	VARIANT SortSpecial(long SortMethod, const VARIANT& Key1, long Order1, const VARIANT& Type, const VARIANT& Key2, long Order2, const VARIANT& Key3, long Order3, long Header, const VARIANT& OrderCustom, const VARIANT& MatchCase, 
		long Orientation, long DataOption1, long DataOption2, long DataOption3);
	LPDISPATCH GetSoundNote();
	LPDISPATCH SpecialCells(long Type, const VARIANT& Value);
	VARIANT GetStyle();
	void SetStyle(const VARIANT& newValue);
	VARIANT SubscribeTo(LPCTSTR Edition, long Format);
	VARIANT Subtotal(long GroupBy, long Function, const VARIANT& TotalList, const VARIANT& Replace, const VARIANT& PageBreaks, long SummaryBelowData);
	VARIANT GetSummary();
	VARIANT Table(const VARIANT& RowInput, const VARIANT& ColumnInput);
	VARIANT GetText();
	VARIANT TextToColumns(const VARIANT& Destination, long DataType, long TextQualifier, const VARIANT& ConsecutiveDelimiter, const VARIANT& Tab, const VARIANT& Semicolon, const VARIANT& Comma, const VARIANT& Space, const VARIANT& Other, 
		const VARIANT& OtherChar, const VARIANT& FieldInfo, const VARIANT& DecimalSeparator, const VARIANT& ThousandsSeparator, const VARIANT& TrailingMinusNumbers);
	VARIANT GetTop();
	VARIANT Ungroup();
	VARIANT GetUseStandardHeight();
	void SetUseStandardHeight(const VARIANT& newValue);
	VARIANT GetUseStandardWidth();
	void SetUseStandardWidth(const VARIANT& newValue);
	LPDISPATCH GetValidation();
	VARIANT GetValue(const VARIANT& RangeValueDataType);
	void SetValue(const VARIANT& RangeValueDataType, const VARIANT& newValue);
	VARIANT GetValue2();
	void SetValue2(const VARIANT& newValue);
	VARIANT GetVerticalAlignment();
	void SetVerticalAlignment(const VARIANT& newValue);
	VARIANT GetWidth();
	LPDISPATCH GetWorksheet();
	VARIANT GetWrapText();
	void SetWrapText(const VARIANT& newValue);
	LPDISPATCH AddComment(const VARIANT& Text);
	LPDISPATCH GetComment();
	void ClearComments();
	LPDISPATCH GetPhonetic();
	LPDISPATCH GetFormatConditions();
	long GetReadingOrder();
	void SetReadingOrder(long nNewValue);
	LPDISPATCH GetHyperlinks();
	LPDISPATCH GetPhonetics();
	void SetPhonetic();
	CString GetId();
	void SetId(LPCTSTR lpszNewValue);
	VARIANT PrintOut(const VARIANT& From, const VARIANT& To, const VARIANT& Copies, const VARIANT& Preview, const VARIANT& ActivePrinter, const VARIANT& PrintToFile, const VARIANT& Collate, const VARIANT& PrToFileName);
	LPDISPATCH GetPivotCell();
	void Dirty();
	LPDISPATCH GetErrors();
	LPDISPATCH GetSmartTags();
	void Speak(const VARIANT& SpeakDirection, const VARIANT& SpeakFormulas);
	VARIANT PasteSpecial(long Paste, long Operation, const VARIANT& SkipBlanks, const VARIANT& Transpose);
	BOOL GetAllowEdit();
	LPDISPATCH GetListObject();
	LPDISPATCH GetXPath();
};
/////////////////////////////////////////////////////////////////////////////
// Worksheets wrapper class

class Worksheets : public COleDispatchDriver
{
public:
	Worksheets() {}		// Calls COleDispatchDriver default constructor
	Worksheets(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	Worksheets(const Worksheets& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	LPDISPATCH Add(const VARIANT& Before, const VARIANT& After, const VARIANT& Count, const VARIANT& Type);
	void Copy(const VARIANT& Before, const VARIANT& After);
	long GetCount();
	void Delete();
	void FillAcrossSheets(LPDISPATCH Range, long Type);
	LPDISPATCH GetItem(const VARIANT& Index);
	void Move(const VARIANT& Before, const VARIANT& After);
	LPUNKNOWN Get_NewEnum();
	void PrintPreview(const VARIANT& EnableChanges);
	void Select(const VARIANT& Replace);
	LPDISPATCH GetHPageBreaks();
	LPDISPATCH GetVPageBreaks();
	VARIANT GetVisible();
	void SetVisible(const VARIANT& newValue);
	LPDISPATCH Get_Default(const VARIANT& Index);
	void PrintOut(const VARIANT& From, const VARIANT& To, const VARIANT& Copies, const VARIANT& Preview, const VARIANT& ActivePrinter, const VARIANT& PrintToFile, const VARIANT& Collate, const VARIANT& PrToFileName);
};
