// Mainframe macro generated from application: /home/marco/root/bin/root.exe
// By ROOT version 6.12/06 on 2018-05-04 17:18:31
#ifndef ROOT_TGDockableFrame
#include "TGDockableFrame.h"
#endif
#ifndef ROOT_TGMenu
#include "TGMenu.h"
#endif
#ifndef ROOT_TGMdiDecorFrame
#include "TGMdiDecorFrame.h"
#endif
#ifndef ROOT_TG3DLine
#include "TG3DLine.h"
#endif
#ifndef ROOT_TGMdiFrame
#include "TGMdiFrame.h"
#endif
#ifndef ROOT_TGMdiMainFrame
#include "TGMdiMainFrame.h"
#endif
#ifndef ROOT_TGMdiMenu
#include "TGMdiMenu.h"
#endif
#ifndef ROOT_TGListBox
#include "TGListBox.h"
#endif
#ifndef ROOT_TGNumberEntry
#include "TGNumberEntry.h"
#endif
#ifndef ROOT_TGScrollBar
#include "TGScrollBar.h"
#endif
#ifndef ROOT_TGComboBox
#include "TGComboBox.h"
#endif
#ifndef ROOT_TGuiBldHintsEditor
#include "TGuiBldHintsEditor.h"
#endif
#ifndef ROOT_TGuiBldNameFrame
#include "TGuiBldNameFrame.h"
#endif
#ifndef ROOT_TGFrame
#include "TGFrame.h"
#endif
#ifndef ROOT_TGFileDialog
#include "TGFileDialog.h"
#endif
#ifndef ROOT_TGShutter
#include "TGShutter.h"
#endif
#ifndef ROOT_TGButtonGroup
#include "TGButtonGroup.h"
#endif
#ifndef ROOT_TGCanvas
#include "TGCanvas.h"
#endif
#ifndef ROOT_TGFSContainer
#include "TGFSContainer.h"
#endif
#ifndef ROOT_TGuiBldEditor
#include "TGuiBldEditor.h"
#endif
#ifndef ROOT_TGColorSelect
#include "TGColorSelect.h"
#endif
#ifndef ROOT_TGButton
#include "TGButton.h"
#endif
#ifndef ROOT_TGFSComboBox
#include "TGFSComboBox.h"
#endif
#ifndef ROOT_TGLabel
#include "TGLabel.h"
#endif
#ifndef ROOT_TGMsgBox
#include "TGMsgBox.h"
#endif
#ifndef ROOT_TRootGuiBuilder
#include "TRootGuiBuilder.h"
#endif
#ifndef ROOT_TGTab
#include "TGTab.h"
#endif
#ifndef ROOT_TGListView
#include "TGListView.h"
#endif
#ifndef ROOT_TGSplitter
#include "TGSplitter.h"
#endif
#ifndef ROOT_TGStatusBar
#include "TGStatusBar.h"
#endif
#ifndef ROOT_TGListTree
#include "TGListTree.h"
#endif
#ifndef ROOT_TGuiBldGeometryFrame
#include "TGuiBldGeometryFrame.h"
#endif
#ifndef ROOT_TGToolTip
#include "TGToolTip.h"
#endif
#ifndef ROOT_TGToolBar
#include "TGToolBar.h"
#endif
#ifndef ROOT_TGuiBldDragManager
#include "TGuiBldDragManager.h"
#endif

#include "Riostream.h"
TGTextEntry *titlegraph;
TGVButtonGroup *loadchoice;
TGRadioButton *load[2];
TGVButtonGroup *errorchoice;
TGRadioButton *err[3];
TGComboBox *fComboBox1230;
void Gui()
{
   // main frame
   TGMainFrame *fMainFrame1447 = new TGMainFrame(gClient->GetRoot(),10,10,kMainFrame | kVerticalFrame);
   fMainFrame1447->SetName("fMainFrame1447");
   fMainFrame1447->SetLayoutBroken(kTRUE);

   // composite frame
   TGCompositeFrame *fMainFrame1012 = new TGCompositeFrame(fMainFrame1447,611,451,kVerticalFrame);
   fMainFrame1012->SetName("fMainFrame1012");
   fMainFrame1012->SetLayoutBroken(kTRUE);

   TGFont *ufont;         // will reflect user font changes
   ufont = gClient->GetFont("-*-helvetica-medium-r-*-*-12-*-*-*-*-*-iso8859-1");

   TGGC   *uGC;           // will reflect user GC changes
   // graphics context changes
   GCValues_t valgraph;
   valgraph.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
   gClient->GetColorByName("#000000",valgraph.fForeground);
   gClient->GetColorByName("#e8e8e8",valgraph.fBackground);
   valgraph.fFillStyle = kFillSolid;
   valgraph.fFont = ufont->GetFontHandle();
   valgraph.fGraphicsExposures = kFALSE;
   uGC = gClient->GetGC(&valgraph, kTRUE);
   titlegraph = new TGTextEntry(fMainFrame1012, new TGTextBuffer(14),-1,uGC->GetGC(),ufont->GetFontStruct(),kSunkenFrame | kOwnBackground);
   titlegraph->SetMaxLength(4096);
   titlegraph->SetAlignment(kTextLeft);
   titlegraph->SetText("Graph title");
   titlegraph->Resize(184,titlegraph->GetDefaultHeight());
   titlegraph->SetToolTipText("title");
   fMainFrame1012->AddFrame(titlegraph, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   titlegraph->MoveResize(8,32,184,23);

   // "data input" group frame
   //TGGroupFrame *datainput = new TGGroupFrame(fMainFrame1012,"data input");
   //datainput->SetLayoutBroken(kTRUE);
   loadchoice = new TGVButtonGroup(fMainFrame1012,"Load preference");
   load[0] = new TGRadioButton(loadchoice,"upload");
   load[0]->SetTextJustify(36);
   load[0]->SetMargins(0,0,0,0);
   load[0]->SetWrapLength(-1);
   loadchoice->AddFrame(load[0], new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   load[0]->MoveResize(24,64,106,20);
   load[1] = new TGRadioButton(loadchoice,"filename.txt",-1,uGC->GetGC(),ufont->GetFontStruct(),1);
   load[1]->SetTextJustify(36);
   load[1]->SetMargins(0,0,0,0);
   load[1]->SetWrapLength(-1);
   load[1]->SetOn();
   loadchoice->AddFrame(load[1], new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   load[1]->MoveResize(24,32,106,20);

   //datainput->SetLayoutManager(new TGVerticalLayout(datainput));
   loadchoice->Resize(168,112);
   loadchoice->Show();
   //datainput->AddFrame(loadchoice, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fMainFrame1012->AddFrame(loadchoice, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   loadchoice->MoveResize(296,24,168,112);

   // "Errors" group frame
   //TGGroupFrame *errors = new TGGroupFrame(fMainFrame1012,"Errors");
   //errors->SetLayoutBroken(kTRUE);
   /*errorchoice = new TGVButtonGroup(fMainFrame1012,"Errors");
   err[0] = new TGRadioButton(errorchoice,"both");
   err[0]->SetTextJustify(36);
   err[0]->SetMargins(0,0,0,0);
   err[0]->SetWrapLength(-1);
   errorchoice->AddFrame(err[0], new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   err[0]->MoveResize(24,24,113,20);
   err[1] = new TGRadioButton(errorchoice,"y");
   err[1]->SetTextJustify(36);
   err[1]->SetMargins(0,0,0,0);
   err[1]->SetWrapLength(-1);
   errorchoice->AddFrame(err[1], new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   err[1]->MoveResize(24,48,113,20);
   err[2] = new TGRadioButton(errorchoice,"x");
   err[2]->SetTextJustify(36);
   err[2]->SetMargins(0,0,0,0);
   err[2]->SetWrapLength(-1);
   errorchoice->AddFrame(err[2], new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   err[2]->MoveResize(24,72,113,20);

   //errors->SetLayoutManager(new TGVerticalLayout(errors));
   errorchoice->Resize(152,112);
   errorchoice->Show();
   fMainFrame1012->AddFrame(errorchoice, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   errorchoice->MoveResize(24,104,152,112);*/
   // combo box
   fComboBox1230 = new TGComboBox(fMainFrame1012,-1,kHorizontalFrame | kSunkenFrame | kOwnBackground);
   fComboBox1230->SetName("Errors");
   fComboBox1230->AddEntry("Both",0);
   fComboBox1230->AddEntry("Y",1);
   fComboBox1230->AddEntry("None ",2);
   fComboBox1230->Resize(102,23);
   fComboBox1230->Select(0);
   fMainFrame1012->AddFrame(fComboBox1230, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fComboBox1230->MoveResize(8,104,102,23);
   TGLabel *fLabel833 = new TGLabel(fMainFrame1012,"Errors");
   fLabel833->SetTextJustify(36);
   fLabel833->SetMargins(0,0,0,0);
   fLabel833->SetWrapLength(-1);
   fMainFrame1012->AddFrame(fLabel833, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel833->MoveResize(8,80,88,19);

   //gobutton
   TGTextButton *gobut = new TGTextButton(fMainFrame1012,"Go","graph()",-1,TGTextButton::GetDefaultGC()(),TGTextButton::GetDefaultFontStruct(),kRaisedFrame);
   gobut->SetTextJustify(36);
   gobut->SetMargins(0,0,0,0);
   gobut->SetWrapLength(-1);
   gobut->Resize(120,40);
   fMainFrame1012->AddFrame(gobut, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   gobut->MoveResize(312,216,120,40);

   fMainFrame1447->AddFrame(fMainFrame1012, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY));
   fMainFrame1012->MoveResize(0,0,611,451);

   fMainFrame1447->SetMWMHints(kMWMDecorAll,
                        kMWMFuncAll,
                        kMWMInputModeless);
   fMainFrame1447->MapSubwindows();

   fMainFrame1447->Resize(fMainFrame1447->GetDefaultSize());
   fMainFrame1447->MapWindow();
   fMainFrame1447->Resize(490,371);
}  
