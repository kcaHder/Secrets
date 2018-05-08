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
#include "TGClient.h"

#include "Riostream.h"

const char *filetypes[] = { 
   "TXT files",    "*.txt",
   "All files",     "*",
   0,               0 
};
TString dir(".");
TGMainFrame *fMainFrame1447;
TGTextEntry *titlegraph;
TGTextEntry *path;
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
TGComboBox *fComboBox1230;
TGCheckButton *fitbut;
TGComboBox *fittype;
TGTextEntry *fitform;
TGCheckButton *fitcosm;
TGNumberEntry *xfitmin;
TGNumberEntry *xfitmax;
TGNumberEntry *fitlst;
TGNumberEntry *fitlcol;
TGNumberEntry *fitlwd;
void Gui()
{
   // main frame
   fMainFrame1447 = new TGMainFrame(gClient->GetRoot(),10,10,kMainFrame | kVerticalFrame);
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
   loadchoice->Show();
   fMainFrame1012->AddFrame(loadchoice, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   loadchoice->MoveResize(296,24,150,80);

   path = new TGTextEntry(fMainFrame1012, new TGTextBuffer(14),-1,uGC->GetGC(),ufont->GetFontStruct(),kSunkenFrame | kOwnBackground);
   path->SetMaxLength(4096);
   path->SetAlignment(kTextLeft);
   path->SetText("/path");
   path->Resize(184,path->GetDefaultHeight());
   path->SetToolTipText("title");
   fMainFrame1012->AddFrame(path, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   path->MoveResize(296,110,150,23);

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
   markcolor->SetNumber(4);
   markstyle = new TGNumberEntry(cosmetics, (Double_t) 0,6,-1,(TGNumberFormat::EStyle) 0, (TGNumberFormat::EAttribute) 1,(TGNumberFormat::ELimit) 3,1,34);
   cosmetics->AddFrame(markstyle, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   markstyle->MoveResize(8,40,60,23);
   markstyle->SetNumber(20);
   marksize = new TGNumberEntry(cosmetics, (Double_t) 0,6,-1,(TGNumberFormat::EStyle) 0, (TGNumberFormat::EAttribute) 1,(TGNumberFormat::ELimit) 1,1);
   cosmetics->AddFrame(marksize, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   marksize->MoveResize(82,40,60,23);
   marksize->SetNumber(1);
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
   linestyle->SetNumber(1);
   linecolor = new TGNumberEntry(cosmetics, (Double_t) 0,6,-1,(TGNumberFormat::EStyle) 0, (TGNumberFormat::EAttribute) 1,(TGNumberFormat::ELimit) 3,0,40);
   cosmetics->AddFrame(linecolor, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   linecolor->MoveResize(82,90,60,23);
   linecolor->SetNumber(1);
   linewidth = new TGNumberEntry(cosmetics, (Double_t) 0,6,-1,(TGNumberFormat::EStyle) 0, (TGNumberFormat::EAttribute) 1,(TGNumberFormat::ELimit) 3,1,10);
   cosmetics->AddFrame(linewidth, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   linewidth->MoveResize(160,90,60,23);
   linewidth->SetNumber(1);
   TGLabel *fLabel1043 = new TGLabel(cosmetics,"Style");
   fLabel1043->SetTextJustify(36);
   fLabel1043->SetMargins(0,0,0,0);
   fLabel1043->SetWrapLength(-1);
   cosmetics->AddFrame(fLabel1043, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel1043->MoveResize(8,70,64,19);
   TGLabel *fLabel1050 = new TGLabel(cosmetics,"Colour");
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



 // "fit" group frame
   TGGroupFrame *fitframe = new TGGroupFrame(fMainFrame1012,"fitframe");
   fitframe->SetLayoutBroken(kTRUE);
   fitbut = new TGCheckButton(fitframe,"Fit");
   fitbut->SetTextJustify(36);
   fitbut->SetMargins(0,0,0,0);
   fitbut->SetWrapLength(-1);
   fitframe->AddFrame(fitbut, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fitbut->MoveResize(16,24,136,24);


   // combo box
   fittype = new TGComboBox(fitframe,-1,kHorizontalFrame | kSunkenFrame | kOwnBackground);
   fittype->AddEntry("Costante",0);
   fittype->AddEntry("Polinom. 1",1);
   fittype->AddEntry("Gaussiano ",2);
   fittype->AddEntry("Esponenziale ",3);
   fittype->AddEntry("Personal. ",4);
   fittype->AddEntry("Polinom. 2 ",5);
   fittype->AddEntry("Polinom. 3 ",6);
   fittype->AddEntry("Polinom. -1 ",-1);
   fittype->AddEntry("Polinom. -2 ",-2);
   fittype->AddEntry("Polinom. -3 ",-3);
   fittype->Resize(144,23);
   fittype->Select(-1);
   fitframe->AddFrame(fittype, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fittype->MoveResize(16,60,144,23);
   fittype->Select(0);

   ufont = gClient->GetFont("-*-helvetica-medium-r-*-*-12-*-*-*-*-*-iso8859-1");

   // graphics context changes
   GCValues_t valEntry1163;
   valEntry1163.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
   gClient->GetColorByName("#000000",valEntry1163.fForeground);
   gClient->GetColorByName("#e8e8e8",valEntry1163.fBackground);
   valEntry1163.fFillStyle = kFillSolid;
   valEntry1163.fFont = ufont->GetFontHandle();
   valEntry1163.fGraphicsExposures = kFALSE;
   uGC = gClient->GetGC(&valEntry1163, kTRUE);
   //fit formula
   fitform = new TGTextEntry(fitframe, new TGTextBuffer(14),-1,uGC->GetGC(),ufont->GetFontStruct(),kSunkenFrame | kOwnBackground);
   fitform->SetMaxLength(4096);
   fitform->SetAlignment(kTextLeft);
   fitform->SetText("Fit Formula");
   fitform->Resize(176,fitform->GetDefaultHeight());
   fitframe->AddFrame(fitform, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fitform->MoveResize(16,100,176,23);

   fitcosm = new TGCheckButton(fitframe,"Default fit settings");
   fitcosm->SetTextJustify(36);
   fitcosm->SetMargins(0,0,0,0);
   fitcosm->SetWrapLength(-1);
   fitframe->AddFrame(fitcosm, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fitcosm->MoveResize(16,150,136,24);
   fitcosm->SetOn();

   fitlst = new TGNumberEntry(fitframe, (Double_t) 0,6,-1,(TGNumberFormat::EStyle) 0, (TGNumberFormat::EAttribute) 1,(TGNumberFormat::ELimit) 3,0,10);
   fitframe->AddFrame(fitlst, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fitlst->MoveResize(16,264,60,23);
   fitlcol = new TGNumberEntry(fitframe, (Double_t) 0,6,-1,(TGNumberFormat::EStyle) 0, (TGNumberFormat::EAttribute) 1,(TGNumberFormat::ELimit) 3,0,40);
   fitframe->AddFrame(fitlcol, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fitlcol->MoveResize(88,264,64,23);
   fitlwd = new TGNumberEntry(fitframe, (Double_t) 0,6,-1,(TGNumberFormat::EStyle) 0, (TGNumberFormat::EAttribute) 1,(TGNumberFormat::ELimit) 3,0,10);
   fitframe->AddFrame(fitlwd, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fitlwd->MoveResize(160,264,60,23);

   TGLabel *fLabel1218 = new TGLabel(fitframe,"Style");
   fLabel1218->SetTextJustify(36);
   fLabel1218->SetMargins(0,0,0,0);
   fLabel1218->SetWrapLength(-1);
   fitframe->AddFrame(fLabel1218, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel1218->MoveResize(16,240,64,19);
   TGLabel *fLabel1247 = new TGLabel(fitframe,"Colour");
   fLabel1247->SetTextJustify(36);
   fLabel1247->SetMargins(0,0,0,0);
   fLabel1247->SetWrapLength(-1);
   fitframe->AddFrame(fLabel1247, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel1247->MoveResize(88,240,64,19);
   TGLabel *fLabel1254 = new TGLabel(fitframe,"Width");
   fLabel1254->SetTextJustify(36);
   fLabel1254->SetMargins(0,0,0,0);
   fLabel1254->SetWrapLength(-1);
   fitframe->AddFrame(fLabel1254, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel1254->MoveResize(160,240,64,19);


   xfitmin = new TGNumberEntry(fitframe, (Double_t) 0,6,-1,(TGNumberFormat::EStyle) 5);
   fitframe->AddFrame(xfitmin, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   xfitmin->MoveResize(88,190,60,23);
   xfitmax = new TGNumberEntry(fitframe, (Double_t) 0,6,-1,(TGNumberFormat::EStyle) 5);
   fitframe->AddFrame(xfitmax, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   xfitmax->MoveResize(160,190,60,23);
   TGLabel *xran = new TGLabel(fitframe,"X range:");
   xran->SetTextJustify(36);
   xran->SetMargins(0,0,0,0);
   xran->SetWrapLength(-1);
   fitframe->AddFrame(xran, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   xran->MoveResize(16,192,64,19);



   fitframe->SetLayoutManager(new TGVerticalLayout(fitframe));
   fitframe->Resize(240,320);
   fMainFrame1012->AddFrame(fitframe, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fitframe->MoveResize(496,24,240,320);



//fileup

   
   



















   fMainFrame1447->AddFrame(fMainFrame1012, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY));
   fMainFrame1012->MoveResize(0,0,800,371);

   fMainFrame1447->SetMWMHints(kMWMDecorAll,
                        kMWMFuncAll,
                        kMWMInputModeless);
   fMainFrame1447->MapSubwindows();

   fMainFrame1447->Resize(fMainFrame1447->GetDefaultSize());
   fMainFrame1447->MapWindow();
   fMainFrame1447->Resize(800,371);
}  



void fileup()
{

   TGFileInfo fi;
   fi.fFileTypes = filetypes;

   new TGFileDialog(gClient->GetRoot(), fMainFrame1447, kFDOpen, &fi);
   dir = fi.fFilename;
}