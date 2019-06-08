
#include "histogui.hpp"
#include "hGui.cpp"
#include "TVectorF.h"

using namespace std;
Histogram* H = new Histogram();

#ifdef __linux__

int8_t OS = 1;

#elif __APPLE__ || __MACH__

int8_t OS = 0;

#elif _WIN32 || _WIN64
int8_t OS = 2;

#else
int8_t OS = 32;

#endif


//Histogram
//static
//  private

char* Histogram:: hTitle = new char[50];
TString Histogram:: histFile;
//public

//non static
//  public

Histogram::Histogram()
{}

void Histogram::Filler()
{
	cin.clear();
		//	char c;
	//cout << "Dimmi il titolo dell'istogramma." << endl;
		//  cin.get(c);
    hTitle = const_cast<char*>(titlehist->GetDisplayText().Data());


    hBinNum = HBin->GetNumber();
    hMin = HMin->GetNumber();
    hMax = HMax->GetNumber();
    h = new TH1F("h", hTitle, hBinNum, hMin, hMax);
    //cout << "Vuoi una generazione uniforme tra 0 e 1 (0), uniforme con estremi assegnati (1), gaussiana (2), esponenziale (3), poissoniana (4), binomiale (5) o di Landau (6)?" << endl;
    if (genbut->IsOn())
    {
        
            hEntries = En->GetNumber();

        hDistribution = fComboBox1230->GetSelected();
        switch(hDistribution)
        {
            default: cout << "coglionazzo, ora ti becchi la prima opzione e non discuti" << endl;
            case 0:
            {
                for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Rndm());
                break;
            }
            case 1:
            {
                double UniformMin,UniformMax;
                UniformMin = UMin->GetNumber();
                UniformMax = UMax->GetNumber();
                for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Uniform(UniformMin, UniformMax));
                break;
            }
            case 2:
            {
                double GausMean, GausRMS;
                GausMean = GMean->GetNumber();
                GausRMS = GSigma->GetNumber();
                for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Gaus(GausMean, GausRMS));
                break;
            }
            case 3:
            {
                double ExpMean;
                ExpMean = EMean->GetNumber();
                for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Exp(ExpMean));
                break;
            }
            case 4:
            {
                double PoissonMean;
                PoissonMean = PMean->GetNumber();
                for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->PoissonD(PoissonMean));
                break;
            }
            case 5:
            {
                double BinomialProbability;
               BinomialProbability = BProb->GetNumber();
                for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Binomial(hEntries, BinomialProbability));
                break;
            }
	   	    case 6:
	   	    {
	   	    	double LandauLocation, LandauScale;
	   	    	LandauLocation = LLoc->GetNumber();
	   	    	LandauScale = LScale->GetNumber();
	   	    	for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Landau(LandauLocation, LandauScale));
	   	    	break;
	   	    }
                
        }
    }
    else 
    {
        if(load[0]->IsOn())
        {
            histFile = dir;
        }
        else
        {
        if(OS == 0) auto a = system("touch filename.txt | open -a TextEdit filename.txt");
        else if (OS == 1) auto a = system("gedit filename.txt");
        else if (OS == 2) auto a = system("echo \"\" > filename.txt || Notepad filename.txt");
        else cerr << "UNABLE TO IDENTIFY OS, ONLY LOADING DATA IS AVAILABLE\n LOADING FILE filename.txt...\n";
        histFile = "filename.txt";
        }
        ifstream file(histFile);
        vector<float> a;

        TString tdat;
        while(!file.eof())
        {
            file >> tdat;
            a.push_back(tdat.Atof());
            tdat = "0";
        }
            

        for (std::vector<float>::iterator i = a.begin(); i != a.end(); ++i)
        {
            h->Fill(*i);
        }
        a.clear();

    }
}


void Histogram::Fitter()
{

    if(fitbut->IsOn())
    {
        
        switch(fittype->GetSelected())
        {
            default:
            {
                cout << "coglionazzo, ora ti becchi la prima opzione e non discuti" << endl;
            }
            case -3:
            {
                f = new TF1("f", "[0]+[1]/x+[2]/(x*x)+[3]/(x*x*x)");
                break;
            }
            case -2:
            {
                f = new TF1("f", "[0]+[1]/x+[2]/(x*x)");
                break;
            }
            case -1:
            {
                f = new TF1("f", "[0]+[1]/x");
                break;
            }
            case 0:
            {
                f = new TF1("f", "pol0");
                break;
            }
            case 1:
            {   
                f = new TF1("f", "[0]+[1]*x");
                break;
            }
            case 2:
            {
                f = new TF1("f", "gaus");
                break;
            }
            case 3:
            {
                f = new TF1("f", "expo");
                break;
            }
            case 4:
            {
				char formula[40];
				//cout << "Inserisci la formula" << endl;
				//cin >> formula;
				f = new TF1("f", fitform->GetDisplayText());
				break;
            }
            case 5:
            {
                f = new TF1("f", "[0]+[1]*x+[2]*(x*x)");
                break;
            }
            case 6:
            {
                f = new TF1("f", "[0]+[1]*x+[2]*(x*x)+[3]*(x*x*x)");
                break;
            }
        }

		h->Fit("f", "", "", hMin, hMax);
		if(!(fitcosm->IsOn())) FitCosmetics();
		//h->FitPanel();
    }
}

void Histogram::FitCosmetics()
{
    //cout << "Dimmi i parametri di stile, colore e spessore della linea del fit. Se non sai cosa mettere, guarda qui: \nhttps://root.cern.ch/doc/master/classTAttLine.html\noppure metti 0 e ci penso io. " << endl;
    hFitLineStyle = fitlst->GetIntNumber();
    hFitLineColor = fitlcol->GetIntNumber();
    hFitLineWidth = fitlwd->GetIntNumber();
    if(hFitLineStyle) f->SetLineStyle(hFitLineStyle);
    if(hFitLineColor) f->SetLineColor(hFitLineColor);
    if(hFitLineWidth) f->SetLineWidth(hFitLineWidth);
}

void Histogram::Cosmetics()
{
    cout << "Dimmi i parametri di stile, dimensione e colore del Marker. Se non sai cosa mettere, guarda qui: \nhttps://root.cern.ch/doc/v608/classTAttMarker.html\n oppure metti 0 e ci penso io. " << endl;
    hMarkerStyle = markstyle->GetIntNumber();
    hMarkerSize = marksize->GetIntNumber();
    hMarkerColor = markcolor->GetIntNumber();
    
    if(hMarkerStyle) h->SetMarkerStyle(hMarkerStyle);
    if(hMarkerSize) h->SetMarkerSize(hMarkerSize);
    if(hMarkerColor) h->SetMarkerColor(hMarkerColor);
    
}
void Histogram::Drawer()
{
	bool PersonalizedCosmetics;
	//cout << "Vuoi parametri di cosmetica dell'istogramma standard (0) oppure personalizzati (1)?" << endl;
	PersonalizedCosmetics = cosm[0]->IsOn();
	if(PersonalizedCosmetics) Cosmetics();
//    l = new TLegend (.1, .7, .3, .9, "Legenda");
//	c = new TCanvas("c", hTitle, 10, 20, 400, 600);
//    l->SetFillColor(0);
//    l->AddEntry(h,hTitle);
    if (hFit)
    {
//    	l->AddEntry(f,"Fit");
    	gStyle->SetOptFit();
	}
//	c->cd();
	h->Draw();
	h->DrawPanel();
//    l->Draw();
//	c->Draw();
}

//Getter
char* Histogram:: GetTitle()
{
	return hTitle;
}
TH1F* Histogram:: GetHistogram()
{
	return h;
}
TF1* Histogram:: GetFunction()
{
	return f;
}
unsigned int Histogram:: GetEntries()
{
	return hEntries;
}
unsigned int Histogram:: GetBinNum()
{
	return hBinNum;
}
double Histogram:: GetMin()
{
	return hMin;
}
double Histogram:: GetMax()
{
	return hMax;
}
unsigned int Histogram:: GetDistribution()
{
	return hDistribution;
}
bool Histogram:: GetFit()
{
	return hFit;
}
unsigned int Histogram:: GetFitType()
{
	return hFitType;
}
unsigned int Histogram:: GetFitLineStyle()
{
	return hFitLineStyle;
}
unsigned int Histogram:: GetFitLineColor()
{
	return hFitLineColor;
}
unsigned int Histogram:: GetFitLineWidth()
{
	return hFitLineWidth;
}
unsigned int Histogram:: GetMarkerStyle()
{
	return hMarkerStyle;
}
double Histogram:: GetMarkerSize()
{
	return hMarkerSize;
}
unsigned int Histogram:: GetMarkerColor()
{
	return hMarkerColor;
}
//Setter
void  Histogram:: SetTitle(const char* Title)
{
	hTitle = const_cast<char*>(Title);
}
void Histogram:: SetHistogram(TH1F* H)
{
	h = H;
}
void Histogram:: SetFunction(TF1* F)
{
	f = F;
}
void Histogram:: SetEntries(unsigned int Entries)
{
	hEntries = Entries;
}
void Histogram:: SetBinNum(unsigned int BinNum)
{
	hBinNum = BinNum;
}
void Histogram:: SetMin(double Min)
{
	hMin = Min;
}
void Histogram:: SetMax(double Max)
{
	hMax = Max;
}
void Histogram:: SetDistribution(unsigned int Distribution)
{
	hDistribution = Distribution;
}
void Histogram:: SetFit(bool Fit)
{
	hFit = Fit;
}
void Histogram:: SetFitType(unsigned int FitType)
{
	hFitType = FitType;
}
void Histogram:: SetFitLineStyle(unsigned int FitLineStyle)
{
	hFitLineStyle = FitLineStyle;
}
void Histogram:: SetFitLineColor(unsigned int FitLineColor)
{
	hFitLineColor = FitLineColor;
}
void Histogram:: SetFitLineWidth(unsigned int FitLineWidth)
{
	hFitLineWidth = FitLineWidth;
}
void Histogram:: SetMarkerStyle(unsigned int MarkerStyle)
{
	hMarkerStyle = MarkerStyle;
}
void Histogram:: SetMarkerSize(double MarkerSize)
{
	hMarkerSize = MarkerSize;
}
void Histogram:: SetMarkerColor(unsigned int MarkerColor)
{
	hMarkerColor = MarkerColor;
}

void histogram()
{
    if (load[0]->IsOn()) fileup();
	H->Filler();
	H->Fitter();
	H->Drawer();
	
}

//private



	

