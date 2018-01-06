//
//  histograph.h
//  
//
//  Created by Michele Iannello on 13/11/17.
//
//
#ifndef HISTOGRAM2_HPP
#define HISTOGRAM2_HPP

#include "incl.hpp"

using namespace std;

class Histogram2
{
private:
	static char* hTitle;
	TH1D *h_1;
	TH1D *h_2;
	TH1D *h_3;
	TH1D *h_4;
	TH2F* h;
	TF1* fX;
	TF1* fY;
	TLegend* l;
	//	TCanvas* c;
	
	unsigned int hEntries;
	unsigned int hXBinNum;
	double hXMin;
	double hXMax;
	unsigned int hYBinNum;
	double hYMin;
	double hYMax;
	unsigned int hXDistribution;
	unsigned int hYDistribution;
	bool hFit;
	unsigned int hXFitType;
	unsigned int hYFitType;
	unsigned int hXFitLineStyle;
	unsigned int hXFitLineColor;
	unsigned int hXFitLineWidth;
	unsigned int hMarkerStyle;
	double hMarkerSize;
	unsigned int hMarkerColor;
	unsigned int hYFitLineStyle;
	unsigned int hYFitLineColor;
	unsigned int hYFitLineWidth;
	
public:
	Histogram2();
	void Filler();
	void Fitter();
	void FitCosmetics();
	void Cosmetics();
	void Drawer();
	//Getter
	char*  GetTitle();
	unsigned int GetEntries();
	unsigned int GetXBinNum();
	double GetXMin();
	double GetXMax();
	unsigned int GetYBinNum();
	double GetYMin();
	double GetYMax();
	unsigned int GetXDistribution();
	unsigned int GetYDistribution();
	bool GetFit();
	unsigned int GetXFitType();
	unsigned int GetYFitType();
	unsigned int GetXFitLineStyle();
	unsigned int GetXFitLineColor();
	unsigned int GetXFitLineWidth();
	unsigned int GetMarkerStyle();
	double GetMarkerSize();
	unsigned int GetMarkerColor();
	unsigned int GetYFitLineStyle();
	unsigned int GetYFitLineColor();
	unsigned int GetYFitLineWidth();

	//Setter
	void SetTitle(const char*);
	void SetEntries(unsigned int);
	void SetXBinNum(unsigned int);
	void SetXMin(double);
	void SetXMax(double);
	void SetYBinNum(unsigned int);
	void SetYMin(double);
	void SetYMax(double);
	void SetXDistribution(unsigned int);
	void SetYDistribution(unsigned int);
	void SetFit(bool);
	void SetXFitType(unsigned int);
	void SetYFitType(unsigned int);
	void SetXFitLineStyle(unsigned int);
	void SetXFitLineColor(unsigned int);
	void SetXFitLineWidth(unsigned int);
	void SetMarkerStyle(unsigned int);
	void SetMarkerSize(double);
	void SetMarkerColor(unsigned int);
	void SetYFitLineStyle(unsigned int);
	void SetYFitLineColor(unsigned int);
	void SetYFitLineWidth(unsigned int);

	
	
};

#endif
