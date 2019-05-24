
#ifndef HISTOGRAM_HPP
#define HISTOGRAM_HPP

#include "incl.hpp"

using namespace std;

class Histogram
{
    private:
	static char* hTitle;
	TH1F* h;
	TF1* f;
//	TLegend* l;
//	TCanvas* c;
	
    unsigned int hEntries;
    unsigned int hBinNum;
    double hMin;
    double hMax;
    unsigned int hDistribution;
	bool hFit;
    unsigned int hFitType;
    unsigned int hFitLineStyle;
    unsigned int hFitLineColor;
    unsigned int hFitLineWidth;
    unsigned int hMarkerStyle;
    double hMarkerSize;
    unsigned int hMarkerColor;
    static TString histFile;
	
	public:
	Histogram();
	void Filler();
	void Fitter();
	void FitCosmetics();
	void Cosmetics();
	void Drawer();
	//Getter
	char*  GetTitle();
	TH1F* GetHistogram();
	TF1* GetFunction();
	unsigned int GetEntries();
	unsigned int GetBinNum();
	double GetMin();
	double GetMax();
	unsigned int GetDistribution();
	bool GetFit();
	unsigned int GetFitType();
	unsigned int GetFitLineStyle();
	unsigned int GetFitLineColor();
	unsigned int GetFitLineWidth();
	unsigned int GetMarkerStyle();
	double GetMarkerSize();
	unsigned int GetMarkerColor();
	//Setter
	void SetTitle(const char*);
	void SetHistogram(TH1F*);
	void SetFunction(TF1*);
	void SetEntries(unsigned int);
	void SetBinNum(unsigned int);
	void SetMin(double);
	void SetMax(double);
	void SetDistribution(unsigned int);
	void SetFit(bool);
	void SetFitType(unsigned int);
	void SetFitLineStyle(unsigned int);
	void SetFitLineColor(unsigned int);
	void SetFitLineWidth(unsigned int);
	void SetMarkerStyle(unsigned int);
	void SetMarkerSize(double);
	void SetMarkerColor(unsigned int);


};


#endif
