//
//  histograph.h
//  
//
//  Created by Michele Iannello on 13/11/17.
//
//
#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "incl.hpp"

using namespace std;

class Graph
{
    private:
	static char* graphTitle;
	static TGraphErrors* g;
	TF1* f;
//	TLegend* l;
	TCanvas* c;
	bool graphFill;
	static TString graphFile;
	unsigned int graphWoW;
//	bool graphInputType;
//  unsigned int graphEntries;
//	static double* graphEntriesX;
//	static double* graphEntriesY;
//	static double* graphEntriesEX;
//	static double* graphEntriesEY;
	bool graphwannaFit;
    unsigned int graphFitType;
    unsigned int graphFitLineStyle;
    unsigned int graphFitLineColor;
    unsigned int graphFitLineWidth;
	unsigned int graphLineStyle;
	unsigned int graphLineColor;
	unsigned int graphLineWidth;
	double graphFitMin;
	double graphFitMax;
    unsigned int graphMarkerStyle;
    double graphMarkerSize;
    unsigned int graphMarkerColor;
    unsigned int graphMin;
    unsigned int graphMax;
	
	public:
	Graph();
	Graph(int);
//	Graph(char);
	Graph(double);
	void Filler();
	void Fitter();
	void FitCosmetics();
	void Cosmetics(bool);
	void Drawer();
	//Getter
	char*  GetTitle();
	TGraphErrors* GetGraph();
	TF1* GetFunction();
	bool GetFill();
	TString GetFile();
	unsigned int GetWoW();
//	bool GetInputType();
//	unsigned int GetEntries();
	bool GetWannaFit();
	unsigned int GetFitType();
	unsigned int GetFitLineStyle();
	unsigned int GetFitLineColor();
	unsigned int GetFitLineWidth();
	double GetFitMin();
	double GetFitMax();
	double GetFitRange();
	unsigned int GetLineStyle();
	unsigned int GetLineColor();
	unsigned int GetLineWidth();
	unsigned int GetMarkerStyle();
	double GetMarkerSize();
	unsigned int GetMarkerColor();
	double GetMin();
	double GetMax();
	//Setter
	void SetTitle(const char*);
	void SetGraph(TGraphErrors*);
	void SetFunction(TF1*);
	void SetFill(bool);
	void SetFile(char*);
	void SetWoW(unsigned int);
//	void SetInputType(bool);
//	void SetEntries(unsigned int);
	void SetWannaFit(bool);
	void SetFitType(unsigned int);
	void SetFitLineStyle(unsigned int);
	void SetFitLineColor(unsigned int);
	void SetFitLineWidth(unsigned int);
	void SetFitMin(double);
	void SetFitMax(double);
	void SetFitRange(double, double);
	void SetLineStyle(unsigned int);
	void SetLineColor(unsigned int);
	void SetLineWidth(unsigned int);
	void SetMarkerStyle(unsigned int);
	void SetMarkerSize(double);
	void SetMarkerColor(unsigned int);
	void SetMin(double);
	void SetMax(double);

};

#endif
