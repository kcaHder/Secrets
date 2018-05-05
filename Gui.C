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
TGVButtonGroup *cosmchoice;
TGGroupFrame *cosmetics;
TGRadioButton *load[2];
TGRadioButton *cosm[2];
TGNumberEntry *markstyle;
TGNumberEntry *marksize;
TGNumberEntry *markcolor;
TGNumberEntry *linestyle;
TGNumberEntry *linecolor;
TGNumberEntry *linewidth;
//TGVButtonGroup *errorchoice;
//TGRadioButton *err[3];
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
   loadchoice->SetLayoutBroken(kTRUE);
   load[0] = new TGRadioButton(loadchoice,"upload");
   load[0]->SetTextJustify(36);
   load[0]->SetMargins(0,0,0,0);
   load[0]->SetWrapLength(-1);
   loadchoice->AddFrame(load[0], new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   load[0]->MoveResize(20,40,106,20);
   load[1] = new TGRadioButton(loadchoice,"filename.txt",-1,uGC->GetGC(),ufont->GetFontStruct(),1);
   load[1]->SetTextJustify(36);
   load[1]->SetMargins(0,0,0,0);
   load[1]->SetWrapLength(-1);
   load[1]->SetOn();
   loadchoice->AddFrame(load[1], new TGLayoutHints(kLHintsLeft | kLHintsTop,1,2,2,2));
   load[1]->MoveResize(20,20,106,20);

   //datainput->SetLayoutManager(new TGVerticalLayout(datainput));
   //loadchoice->Resize(168,112);
   loadchoice->Show();
   //datainput->AddFrame(loadchoice, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fMainFrame1012->AddFrame(loadchoice, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   loadchoice->MoveResize(296,24,150,80);

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



   //cosmeticframe
   cosmchoice = new TGVButtonGroup(fMainFrame1012,"Cosmetic preferences");
   cosmchoice->SetLayoutBroken(kTRUE);
   cosm[0] = new TGRadioButton(cosmchoice,"Personilized");
   cosm[0]->SetTextJustify(36);
   cosm[0]->SetMargins(0,0,0,0);
   cosm[0]->SetWrapLength(-1);
   cosmchoice->AddFrame(cosm[0], new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   cosm[0]->MoveResize(20,40,106,20);
   cosm[1] = new TGRadioButton(cosmchoice,"Default",-1,uGC->GetGC(),ufont->GetFontStruct(),1);
   cosm[1]->SetTextJustify(36);
   cosm[1]->SetMargins(0,0,0,0);
   cosm[1]->SetWrapLength(-1);
   cosm[1]->SetOn();
   cosmchoice->AddFrame(cosm[1], new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   cosm[1]->MoveResize(20,20,106,20);

   //datainput->SetLayoutManager(new TGVerticalLayout(datainput));
   //cosmchoice->Resize(168,112);
   cosmchoice->Show();
   //datainput->AddFrame(loadchoice, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fMainFrame1012->AddFrame(cosmchoice, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   cosmchoice->MoveResize(8,150,150,80);


// "cosmetics" group frame
   cosmetics = new TGGroupFrame(fMainFrame1012,"Cosmetics");
   cosmetics->SetLayoutBroken(kTRUE);
   markcolor = new TGNumberEntry(cosmetics, (Double_t) 0,6,-1,(TGNumberFormat::EStyle) 0, (TGNumberFormat::EAttribute) 1,(TGNumberFormat::ELimit) 3,0,40);
   cosmetics->AddFrame(markcolor, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   markcolor->MoveResize(160,40,60,23);
   markstyle = new TGNumberEntry(cosmetics, (Double_t) 0,6,-1,(TGNumberFormat::EStyle) 0, (TGNumberFormat::EAttribute) 1,(TGNumberFormat::ELimit) 3,1,34);
   cosmetics->AddFrame(markstyle, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   markstyle->MoveResize(8,40,60,23);
   marksize = new TGNumberEntry(cosmetics, (Double_t) 0,6,-1,(TGNumberFormat::EStyle) 0, (TGNumberFormat::EAttribute) 1,(TGNumberFormat::ELimit) 1,1);
   cosmetics->AddFrame(marksize, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   marksize->MoveResize(82,40,60,23);
   TGLabel *fLabel940 = new TGLabel(cosmetics,"Style");
   fLabel940->SetTextJustify(36);
   fLabel940->SetMargins(0,0,0,0);
   fLabel940->SetWrapLength(-1);
   cosmetics->AddFrame(fLabel940, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel940->MoveResize(8,20,57,19);
   TGLabel *fLabel947 = new TGLabel(cosmetics,"Size");
   fLabel947->SetTextJustify(36);
   fLabel947->SetMargins(0,0,0,0);  
   fLabel947->SetWrapLength(-1);
   cosmetics->AddFrame(fLabel947, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel947->MoveResize(80,20,57,19);
   TGLabel *fLabel954 = new TGLabel(cosmetics,"Color");
   fLabel954->SetTextJustify(36);
   fLabel954->SetMargins(0,0,0,0);
   fLabel954->SetWrapLength(-1);
   cosmetics->AddFrame(fLabel954, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel954->MoveResize(160,20,57,19);
   linestyle = new TGNumberEntry(cosmetics, (Double_t) 0,6,-1,(TGNumberFormat::EStyle) 0, (TGNumberFormat::EAttribute) 1,(TGNumberFormat::ELimit) 3,1,10);
   cosmetics->AddFrame(linestyle, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   linestyle->MoveResize(8,90,60,23);
   linecolor = new TGNumberEntry(cosmetics, (Double_t) 0,6,-1,(TGNumberFormat::EStyle) 0, (TGNumberFormat::EAttribute) 1,(TGNumberFormat::ELimit) 3,0,40);
   cosmetics->AddFrame(linecolor, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   linecolor->MoveResize(82,90,60,23);
   linewidth = new TGNumberEntry(cosmetics, (Double_t) 0,6,-1,(TGNumberFormat::EStyle) 0, (TGNumberFormat::EAttribute) 1,(TGNumberFormat::ELimit) 3,1,10);
   cosmetics->AddFrame(linewidth, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   linewidth->MoveResize(160,90,60,23);
   TGLabel *fLabel1043 = new TGLabel(cosmetics,"Style");
   fLabel1043->SetTextJustify(36);
   fLabel1043->SetMargins(0,0,0,0);
   fLabel1043->SetWrapLength(-1);
   cosmetics->AddFrame(fLabel1043, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel1043->MoveResize(8,70,64,19);
   TGLabel *fLabel1050 = new TGLabel(cosmetics,"Color");
   fLabel1050->SetTextJustify(36);
   fLabel1050->SetMargins(0,0,0,0);
   fLabel1050->SetWrapLength(-1);
   cosmetics->AddFrame(fLabel1050, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel1050->MoveResize(80,70,64,19);
   TGLabel *fLabel1057 = new TGLabel(cosmetics,"Width");
   fLabel1057->SetTextJustify(36);
   fLabel1057->SetMargins(0,0,0,0);
   fLabel1057->SetWrapLength(-1);
   cosmetics->AddFrame(fLabel1057, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel1057->MoveResize(160,70,64,19);
   TGLabel *fLabel1172 = new TGLabel(cosmetics,"Marker");
   fLabel1172->SetTextJustify(36);
   fLabel1172->SetMargins(0,0,0,0);
   fLabel1172->SetWrapLength(-1);
   cosmetics->AddFrame(fLabel1172, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel1172->MoveResize(226,40,40,19);
   TGLabel *fLabel1211 = new TGLabel(cosmetics,"Line");
   fLabel1211->SetTextJustify(36);
   fLabel1211->SetMargins(0,0,0,0);
   fLabel1211->SetWrapLength(-1);
   cosmetics->AddFrame(fLabel1211, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel1211->MoveResize(222,90,48,19);

   cosmetics->SetLayoutManager(new TGVerticalLayout(cosmetics));
   cosmetics->Resize(280,136);
   fMainFrame1012->AddFrame(cosmetics, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   cosmetics->MoveResize(8,232,280,136);



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
