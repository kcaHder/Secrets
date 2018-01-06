//
//  histograph.cpp
//  
//
//  Created by Michele Iannello on 13/11/17.
//
//
#include "histogram.hpp"

using namespace std;
Histogram* H = new Histogram();


//Histogram
//static
//  private

char* Histogram:: hTitle = new char[50];

//public

//non static
//  public

Histogram::Histogram()
{}

void Histogram::Filler()
{
	cin.clear();
		//	char c;
	cout << "Dimmi il titolo dell'istogramma." << endl;
		//  cin.get(c);
	cin.getline(hTitle, 50, '\n');
	cout << "Dammi numero di ingressi, numero di bin, valore minimo e valore massimo." << endl;
	hEntries = InputCheck<unsigned int>();
	hBinNum = InputCheck<unsigned int>();
	hMin = InputCheck<double>();
	hMax = InputCheck<double>();
	h = new TH1F("h", hTitle, hBinNum, hMin, hMax);
	
    cout << "Vuoi una generazione uniforme tra 0 e 1 (0), uniforme con estremi assegnati (1), gaussiana (2), esponenziale (3), poissoniana (4), binomiale (5) o di Landau (6)?" << endl;
    hDistribution = InputCheck<unsigned int>();
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
            double UniformMin, UniformMax;
            cout << "Dammi gli estremi" << endl;
            UniformMin = InputCheck<double>();
            UniformMax = InputCheck<double>();
            for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Uniform(UniformMin, UniformMax));
            break;
        }
        case 2:
        {
            double GausMean, GausRMS;
            cout << "Dammi media e deviazione standard" << endl;
            GausMean = InputCheck<double>();
            GausRMS = InputCheck<double>();
            for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Gaus(GausMean, GausRMS));
            break;
        }
        case 3:
        {
            double ExpMean;
            cout << "Dammi la media" << endl;
            ExpMean = InputCheck<double>();
            for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Exp(ExpMean));
            break;
        }
        case 4:
        {
            double PoissonMean;
            cout << "Dammi la media" << endl;
            PoissonMean = InputCheck<double>();
            for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->PoissonD(PoissonMean));
            break;
        }
        case 5:
        {
            double BinomialProbability;
            cout << "Dammi la probabilità" << endl;
           BinomialProbability = InputCheck<double>();
            for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Binomial(hEntries, BinomialProbability));
            break;
        }
		case 6:
		{
			double LandauLocation, LandauScale;
			cout << "Dammi locazione e scala" << endl;
			LandauLocation = InputCheck<double>();
			LandauScale = InputCheck<double>();
			for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Landau(LandauLocation, LandauScale));
			break;
		}
            
    }
}


void Histogram::Fitter()
{
    cout << "Vuoi fittare l'istogramma (1) oppure no(0)?" << endl;
    hFit = InputCheck<bool>();
    if(hFit)
    {
        cout << "Vuoi un fit costante(0), polinomiale(1), gaussiano(2), esponenziale(3) o personalizzato(4)?" << endl;
		hFitType = InputCheck<unsigned int>();
        switch(hFitType)
        {
            default:
            {
                cout << "coglionazzo, ora ti becchi la prima opzione e non discuti" << endl;
            }
            case 0:
            {
                f = new TF1("f", "pol0");
                break;
            }
            case 1:
            {
                int polDegree;
                cout << "Dammi il grado del polinomio (tra -3 e 3)" << endl;
				polDegree = InputCheck<int>();
                switch(polDegree)
                {
                    default:
                    {
                        cout << "coglionazzo, ora ti becchi la prima opzione e non discuti" << endl;
                        f = new TF1("f", "[0]+x*[1]");
                        break;
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
                        cout << "Ma allora non potevi scegliere il fit costante? Adesso ti becchi un fit di 19esimo grado" << endl;
                        f = new TF1("f", "pol19");
                        break;
                    }
                    case 1:
                    {
                        f = new TF1("f", "[0]+[1]*x");
                        break;
                    }
                    case 2:
                    {
                        f = new TF1("f", "[0]+[1]*x+[2]*(x*x)");
                        break;
                    }
                    case 3:
                    {
                        f = new TF1("f", "[0]+[1]*x+[2]*(x*x)+[3]*(x*x*x)");
                        break;
                    }
                }
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
				cout << "Inserisci la formula" << endl;
				cin >> formula;
				f = new TF1("f", formula);
				break;
            }
        }
		
		bool PersonalizedFitCosmetics;
		cout << "Vuoi parametri di cosmetica del fit standard (0) oppure personalizzati (1)?" << endl;
		PersonalizedFitCosmetics = InputCheck<bool>();
		h->Fit("f", "", "", hMin, hMax);
		if(PersonalizedFitCosmetics) FitCosmetics();
		h->FitPanel();
    }
}

void Histogram::FitCosmetics()
{
    cout << "Dimmi i parametri di stile, colore e spessore della linea del fit. Se non sai cosa mettere, guarda qui: \nhttps://root.cern.ch/doc/master/classTAttLine.html\noppure metti 0 e ci penso io. " << endl;
    hFitLineStyle = InputCheck<unsigned int>();
    hFitLineColor = InputCheck<unsigned int>();
    hFitLineWidth = InputCheck<unsigned int>();
    if(hFitLineStyle) f->SetLineStyle(hFitLineStyle);
    if(hFitLineColor) f->SetLineColor(hFitLineColor);
    if(hFitLineWidth) f->SetLineWidth(hFitLineWidth);
}

void Histogram::Cosmetics()
{
    cout << "Dimmi i parametri di stile, dimensione e colore del Marker. Se non sai cosa mettere, guarda qui: \nhttps://root.cern.ch/doc/v608/classTAttMarker.html\n oppure metti 0 e ci penso io. " << endl;
    hMarkerStyle = InputCheck<unsigned int>();
    hMarkerSize = InputCheck<double>();
    hMarkerColor = InputCheck<unsigned int>();
    
    if(hMarkerStyle) h->SetMarkerStyle(hMarkerStyle);
    if(hMarkerSize) h->SetMarkerSize(hMarkerSize);
    if(hMarkerColor) h->SetMarkerColor(hMarkerColor);
    
}
void Histogram::Drawer()
{
	bool PersonalizedCosmetics;
	cout << "Vuoi parametri di cosmetica dell'istogramma standard (0) oppure personalizzati (1)?" << endl;
	PersonalizedCosmetics = InputCheck<bool>();
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

	H->Filler();
	H->Fitter();
	H->Drawer();
	
}

//private



	

