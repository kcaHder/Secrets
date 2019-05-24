//
//  histograph.cpp
//  
//
//  Created by Michele Iannello on 13/11/17.
//
//

#include "histogram2.hpp"

using namespace std;
/*
// gestione errori input
template <class X> X InputCheck()
{
	X Input;
	do
	{
		cin >> Input;
		if(cin.fail())
		{
			cin.clear();
			char c;
			do; while((c = cin.get()) != '\n');
			cout << "\a";
			cout << "Perchè mi fai questo? Riprova con un input valido.\n";
			continue;
		}
		break;
	} while(true);
	return Input;
}*/

//static
//  private

char* Histogram2:: hTitle = new char[20];

//public

//non static
//  public

Histogram2::Histogram2()
{
	cin.clear();
//	char c;
    cout << "Dimmi il titolo dell'istogramma." << endl;
//  cin.get(c);
    cin.getline(hTitle, 50, '\n');
	cout << "Dammi il numero di ingressi dell'istogramma." << endl;
	hEntries = InputCheck<unsigned int>();
	cout << "Dammi numero di bin, valore minimo e valore massimo sull'asse x" << endl;
	hXBinNum = InputCheck<unsigned int>();
	hXMin = InputCheck<double>();
	hXMax = InputCheck<double>();
	cout << "Dammi  numero di bin, valore minimo e valore massimo sull'asse y" << endl;
	hYBinNum = InputCheck<unsigned int>();
	hYMin = InputCheck<double>();
	hYMax = InputCheck<double>();
	h = new TH2F("h", hTitle, hXBinNum, hXMin, hXMax, hYBinNum, hYMin, hYMax);
}

void Histogram2::Filler()
{
	cout << "Asse X: vuoi una generazione uniforme [0,1] (0), uniforme con estremi assegnati (1), gaussiana (2), esponenziale (3), poissoniana (4), binomiale (5) o di Landau (6)?" << endl;
	hXDistribution = InputCheck<unsigned int>();
	cout << "Asse Y: vuoi una generazione uniforme [0,1] (0), uniforme con estremi assegnati (1), gaussiana (2), esponenziale (3), poissoniana (4), binomiale (5) o di Landau (6)?" << endl;
	hYDistribution = InputCheck<unsigned int>();
	switch(hXDistribution)
	{
		default: cout << "coglionazzo, ora ti becchi la prima opzione e non discuti" << endl;
		//Uniforme tra 0 e 1 sulla X
		case 0:
		{
			switch(hYDistribution)
			{
				default: cout << "coglionazzo, ora ti becchi la prima opzione e non discuti" << endl;
				case 0:
				{
					for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Rndm(), gRandom->Rndm());
					break;
				}
				case 1:
				{
					double UniformMin, UniformMax;
					cout << "Dammi gli estremi sulla Y" << endl;
					UniformMin = InputCheck<double>();
					UniformMax = InputCheck<double>();
					for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Rndm(), gRandom->Uniform(UniformMin, UniformMax));
					break;
				}
				case 2:
				{
					double GausMean, GausRMS;
					cout << "Dammi media e deviazione standard sulla Y" << endl;
					GausMean = InputCheck<double>();
					GausRMS = InputCheck<double>();
					for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Rndm(), gRandom->Gaus(GausMean, GausRMS));
					break;
				}
				case 3:
				{
					double ExpMean;
					cout << "Dammi la media sulla Y" << endl;
					ExpMean = InputCheck<double>();
					for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Rndm(), gRandom->Exp(ExpMean));
					break;
				}
				case 4:
				{
					double PoissonMean;
					cout << "Dammi la media sulla Y" << endl;
					PoissonMean = InputCheck<double>();
					for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Rndm(), gRandom->Poisson(PoissonMean));
					break;
				}
				case 5:
				{
					double BinomialProbability;
					cout << "Dammi la probabilità sulla Y" << endl;
					BinomialProbability = InputCheck<double>();
					for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Rndm(), gRandom->Binomial(hEntries, BinomialProbability));
					break;
				}
				case 6:
				{
					double LandauLocation, LandauScale;
					cout << "Dammi locazione e scala sulla Y" << endl;
					LandauLocation = InputCheck<double>();
					LandauScale = InputCheck<double>();
					for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Rndm(), gRandom->Landau(LandauLocation, LandauScale));
					break;
				}
			}
			break;
		}
		//Uniforme sulla X
		case 1:
		{
			double XUniformMin, XUniformMax;
			cout << "Dammi gli estremi sulla X" << endl;
			XUniformMin = InputCheck<double>();
			XUniformMax = InputCheck<double>();
			switch(hYDistribution)
			{
				default: cout << "coglionazzo, ora ti becchi la prima opzione e non discuti" << endl;
				case 0:
				{
					for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Uniform(XUniformMin, XUniformMax), gRandom->Rndm());
					break;
				}
				case 1:
				{
					double YUniformMin, YUniformMax;
					cout << "Dammi gli estremi sulla Y" << endl;
					YUniformMin = InputCheck<double>();
					YUniformMax = InputCheck<double>();
					for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Uniform(XUniformMin, XUniformMax), gRandom->Uniform(YUniformMin, YUniformMax));
					break;
				}
				case 2:
				{
					double GausMean, GausRMS;
					cout << "Dammi media e deviazione standard sulla Y" << endl;
					GausMean = InputCheck<double>();
					GausRMS = InputCheck<double>();
					for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Uniform(XUniformMin, XUniformMax), gRandom->Gaus(GausMean, GausRMS));
					break;
				}
				case 3:
				{
					double ExpMean;
					cout << "Dammi la media sulla Y" << endl;
					ExpMean = InputCheck<double>();
					for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Uniform(XUniformMin, XUniformMax), gRandom->Exp(ExpMean));
					break;
				}
				case 4:
				{
					double PoissonMean;
					cout << "Dammi la media sulla Y" << endl;
					PoissonMean = InputCheck<double>();
					for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Uniform(XUniformMin, XUniformMax), gRandom->Poisson(PoissonMean));
					break;
				}
				case 5:
				{
					double BinomialProbability;
					cout << "Dammi la probabilità sulla Y" << endl;
					BinomialProbability = InputCheck<double>();
					for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Uniform(XUniformMin, XUniformMax), gRandom->Binomial(hEntries, BinomialProbability));
					break;
				}
				case 6:
				{
					double LandauLocation, LandauScale;
					cout << "Dammi locazione e scala sulla Y" << endl;
					LandauLocation = InputCheck<double>();
					LandauScale = InputCheck<double>();
					for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Uniform(XUniformMin, XUniformMax), gRandom->Landau(LandauLocation, LandauScale));
					break;
				}
			}
			break;
		}
		//Gaussiana sulla X
		case 2:
		{
			double XGausMean, XGausRMS;
			cout << "Dammi media e deviazione standard sulla X" << endl;
			XGausMean = InputCheck<double>();
			XGausRMS = InputCheck<double>();
			switch(hYDistribution)
			{
				default: cout << "coglionazzo, ora ti becchi la prima opzione e non discuti" << endl;
				case 0:
				{
					for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Gaus(XGausMean, XGausRMS), gRandom->Rndm());
					break;
				}
				case 1:
				{
					double UniformMin, UniformMax;
					cout << "Dammi gli estremi sulla Y" << endl;
					UniformMin = InputCheck<double>();
					UniformMax = InputCheck<double>();
					for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Gaus(XGausMean, XGausRMS), gRandom->Uniform(UniformMin, UniformMax));
					break;
				}
				case 2:
				{
					double YGausMean, YGausRMS;
					cout << "Dammi media e deviazione standard sulla Y" << endl;
					YGausMean = InputCheck<double>();
					YGausRMS = InputCheck<double>();
					for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Gaus(XGausMean, XGausRMS), gRandom->Gaus(YGausMean, YGausRMS));
					break;
				}
				case 3:
				{
					double ExpMean;
					cout << "Dammi la media sulla Y" << endl;
					ExpMean = InputCheck<double>();
					for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Gaus(XGausMean, XGausRMS), gRandom->Exp(ExpMean));
					break;
				}
				case 4:
				{
					double PoissonMean;
					cout << "Dammi la media sulla Y" << endl;
					PoissonMean = InputCheck<double>();
					for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Gaus(XGausMean, XGausRMS), gRandom->Poisson(PoissonMean));
					break;
				}
				case 5:
				{
					double BinomialProbability;
					cout << "Dammi la probabilità sulla Y" << endl;
					BinomialProbability = InputCheck<double>();
					for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Gaus(XGausMean, XGausRMS), gRandom->Binomial(hEntries, BinomialProbability));
					break;
				}
				case 6:
				{
					double LandauLocation, LandauScale;
					cout << "Dammi locazione e scala sulla Y" << endl;
					LandauLocation = InputCheck<double>();
					LandauScale = InputCheck<double>();
					for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Gaus(XGausMean, XGausRMS), gRandom->Landau(LandauLocation, LandauScale));
					break;
				}
			}
			break;
		}
		//Esponenziale sulla X
		case 3:
		{
			double XExpMean;
			cout << "Dammi la media sulla X" << endl;
			XExpMean = InputCheck<double>();
			switch(hYDistribution)
			{
				default: cout << "coglionazzo, ora ti becchi la prima opzione e non discuti" << endl;
				case 0:
				{
					for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Exp(XExpMean), gRandom->Rndm());
					break;
				}
				case 1:
				{
					double UniformMin, UniformMax;
					cout << "Dammi gli estremi sulla Y" << endl;
					UniformMin = InputCheck<double>();
					UniformMax = InputCheck<double>();
					for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Exp(XExpMean), gRandom->Uniform(UniformMin, UniformMax));
					break;
				}
				case 2:
				{
					double GausMean, GausRMS;
					cout << "Dammi media e deviazione standard sulla Y" << endl;
					GausMean = InputCheck<double>();
					GausRMS = InputCheck<double>();
					for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Exp(XExpMean), gRandom->Gaus(GausMean, GausRMS));
					break;
				}
				case 3:
				{
					double YExpMean;
					cout << "Dammi la media sulla Y" << endl;
					YExpMean = InputCheck<double>();
					for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Exp(XExpMean), gRandom->Exp(YExpMean));
					break;
				}
				case 4:
				{
					double PoissonMean;
					cout << "Dammi la media sulla Y" << endl;
					PoissonMean = InputCheck<double>();
					for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Exp(XExpMean), gRandom->Poisson(PoissonMean));
					break;
				}
				case 5:
				{
					double BinomialProbability;
					cout << "Dammi la probabilità sulla Y" << endl;
					BinomialProbability = InputCheck<double>();
					for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Exp(XExpMean), gRandom->Binomial(hEntries, BinomialProbability));
					break;
				}
				case 6:
				{
					double LandauLocation, LandauScale;
					cout << "Dammi locazione e scala sulla Y" << endl;
					LandauLocation = InputCheck<double>();
					LandauScale = InputCheck<double>();
					for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Exp(XExpMean), gRandom->Landau(LandauLocation, LandauScale));
					break;
				}
			}
			break;
		}
		//Poissoniana sulla X
		case 4:
		{
			double XPoissonMean;
			cout << "Dammi la media sulla X" << endl;
			XPoissonMean = InputCheck<double>();
			switch(hYDistribution)
			{
				default: cout << "coglionazzo, ora ti becchi la prima opzione e non discuti" << endl;
				case 0:
				{
					for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Poisson(XPoissonMean), gRandom->Rndm());
					break;
				}
				case 1:
				{
					double UniformMin, UniformMax;
					cout << "Dammi gli estremi sulla Y" << endl;
					UniformMin = InputCheck<double>();
					UniformMax = InputCheck<double>();
					for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Poisson(XPoissonMean), gRandom->Uniform(UniformMin, UniformMax));
					break;
				}
				case 2:
				{
					double GausMean, GausRMS;
					cout << "Dammi media e deviazione standard sulla Y" << endl;
					GausMean = InputCheck<double>();
					GausRMS = InputCheck<double>();
					for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Poisson(XPoissonMean), gRandom->Gaus(GausMean, GausRMS));
					break;
				}
				case 3:
				{
					double ExpMean;
					cout << "Dammi la media sulla Y" << endl;
					ExpMean = InputCheck<double>();
					for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Poisson(XPoissonMean), gRandom->Exp(ExpMean));
					break;
				}
				case 4:
				{
					double YPoissonMean;
					cout << "Dammi la media sulla Y" << endl;
					YPoissonMean = InputCheck<double>();
					for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Poisson(XPoissonMean), gRandom->Poisson(YPoissonMean));
					break;
				}
				case 5:
				{
					double BinomialProbability;
					cout << "Dammi la probabilità sulla Y" << endl;
					BinomialProbability = InputCheck<double>();
					for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Poisson(XPoissonMean), gRandom->Binomial(hEntries, BinomialProbability));
					break;
				}
				case 6:
				{
					double LandauLocation, LandauScale;
					cout << "Dammi locazione e scala sulla Y" << endl;
					LandauLocation = InputCheck<double>();
					LandauScale = InputCheck<double>();
					for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Poisson(XPoissonMean), gRandom->Landau(LandauLocation, LandauScale));
					break;
				}
			}
			break;
		}
		//Binomiale sulla X
		case 5:
		{
			double XBinomialProbability;
			cout << "Dammi la probabilità sulla X" << endl;
			XBinomialProbability = InputCheck<double>();
			switch(hYDistribution)
			{
				default: cout << "coglionazzo, ora ti becchi la prima opzione e non discuti" << endl;
				case 0:
				{
					for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Binomial(hEntries, XBinomialProbability), gRandom->Rndm());
					break;
				}
				case 1:
				{
					double UniformMin, UniformMax;
					cout << "Dammi gli estremi sulla Y" << endl;
					UniformMin = InputCheck<double>();
					UniformMax = InputCheck<double>();
					for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Binomial(hEntries, XBinomialProbability), gRandom->Uniform(UniformMin, UniformMax));
					break;
				}
				case 2:
				{
					double GausMean, GausRMS;
					cout << "Dammi media e deviazione standard sulla Y" << endl;
					GausMean = InputCheck<double>();
					GausRMS = InputCheck<double>();
					for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Binomial(hEntries, XBinomialProbability), gRandom->Gaus(GausMean, GausRMS));
					break;
				}
				case 3:
				{
					double ExpMean;
					cout << "Dammi la media sulla Y" << endl;
					ExpMean = InputCheck<double>();
					for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Binomial(hEntries, XBinomialProbability), gRandom->Exp(ExpMean));
					break;
				}
				case 4:
				{
					double PoissonMean;
					cout << "Dammi la media sulla Y" << endl;
					PoissonMean = InputCheck<double>();
					for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Binomial(hEntries, XBinomialProbability), gRandom->Poisson(PoissonMean));
					break;
				}
				case 5:
				{
					double YBinomialProbability;
					cout << "Dammi la probabilità sulla Y" << endl;
					YBinomialProbability = InputCheck<double>();
					for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Binomial(hEntries, XBinomialProbability), gRandom->Binomial(hEntries, YBinomialProbability));
					break;
				}
				case 6:
				{
					double LandauLocation, LandauScale;
					cout << "Dammi locazione e scala sulla Y" << endl;
					LandauLocation = InputCheck<double>();
					LandauScale = InputCheck<double>();
					for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Binomial(hEntries, XBinomialProbability), gRandom->Landau(LandauLocation, LandauScale));
					break;
				}
			}
			break;
		}
		//Landau sulla X
		case 6:
		{
			double XLandauLocation, XLandauScale;
			cout << "Dammi locazione e scala sulla X" << endl;
			XLandauLocation = InputCheck<double>();
			XLandauScale = InputCheck<double>();
			switch(hYDistribution)
			{
				default: cout << "coglionazzo, ora ti becchi la prima opzione e non discuti" << endl;
				case 0:
				{
					for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Landau(XLandauLocation, XLandauScale), gRandom->Rndm());
					break;
				}
				case 1:
				{
					double UniformMin, UniformMax;
					cout << "Dammi gli estremi sulla Y" << endl;
					UniformMin = InputCheck<double>();
					UniformMax = InputCheck<double>();
					for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Landau(XLandauLocation, XLandauScale), gRandom->Uniform(UniformMin, UniformMax));
					break;
				}
				case 2:
				{
					double GausMean, GausRMS;
					cout << "Dammi media e deviazione standard sulla Y" << endl;
					GausMean = InputCheck<double>();
					GausRMS = InputCheck<double>();
					for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Landau(XLandauLocation, XLandauScale), gRandom->Gaus(GausMean, GausRMS));
					break;
				}
				case 3:
				{
					double ExpMean;
					cout << "Dammi la media sulla Y" << endl;
					ExpMean = InputCheck<double>();
					for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Landau(XLandauLocation, XLandauScale), gRandom->Exp(ExpMean));
					break;
				}
				case 4:
				{
					double PoissonMean;
					cout << "Dammi la media sulla Y" << endl;
					PoissonMean = InputCheck<double>();
					for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Landau(XLandauLocation, XLandauScale), gRandom->Poisson(PoissonMean));
					break;
				}
				case 5:
				{
					double BinomialProbability;
					cout << "Dammi la probabilità sulla Y" << endl;
					BinomialProbability = InputCheck<double>();
					for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Landau(XLandauLocation, XLandauScale), gRandom->Binomial(hEntries, BinomialProbability));
					break;
				}
				case 6:
				{
					double YLandauLocation, YLandauScale;
					cout << "Dammi locazione e scala sulla Y" << endl;
					YLandauLocation = InputCheck<double>();
					YLandauScale = InputCheck<double>();
					for(unsigned int j=0; j<hEntries; ++j) h->Fill(gRandom->Landau(XLandauLocation, XLandauScale), gRandom->Landau(YLandauLocation, YLandauScale));
					break;
				}
			}
			break;
		}
	}
	
	
}

void Histogram2::Fitter()
{
	cout << "Vuoi fittare l'istogramma (1) oppure no(0)?" << endl;
	hFit = InputCheck<bool>();
	if(hFit)
	{
		cout << "Asse X: vuoi un fit costante(0), polinomiale(1), gaussiano(2), esponenziale(3) o personalizzato(4)?" << endl;
		hXFitType = InputCheck<unsigned int>();
		switch(hXFitType)
		{
			default:
			{
				cout << "coglionazzo, ora ti becchi la prima opzione e non discuti" << endl;
			}
			case 0:
			{
				fX = new TF1("fX", "pol0");
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
						fX = new TF1("fX", "[0]+x*[1]");
						break;
					}
					case -3:
                    {
                        fX = new TF1("f", "[0]+[1]/x+[2]/(x*x)+[3]/(x*x*x)");
                        break;
                    }
                    case -2:
                    {
                        fX = new TF1("f", "[0]+[1]/x+[2]/(x*x)");
                        break;
                    }
					case -1:
                    {
                        fX = new TF1("f", "[0]+[1]/x");
                        break;
                    }
                    case 0:
                    {
                        cout << "Ma allora non potevi scegliere il fit costante? Adesso ti becchi un fit di 19esimo grado" << endl;
                        fX = new TF1("f", "pol19");
                        break;
                    }
                    case 1:
                    {
                        fX = new TF1("f", "[0]+[1]*x");
                        break;
                    }
                    case 2:
                    {
                        fX = new TF1("f", "[0]+[1]*x+[2]*(x*x)");
                        break;
                    }
                    case 3:
                    {
                        fX = new TF1("f", "[0]+[1]*x+[2]*(x*x)+[3]*(x*x*x)");
                        break;
                    }
				}
				break;
			}
			case 2:
			{
				fX = new TF1("fX", "gaus");
				break;
			}
			case 3:
			{
				fX = new TF1("fX", "expo");
				break;
			}
			case 4:
			{
				char formula[40];
				cout << "Inserisci la formula" << endl;
				cin >> formula;
				fX = new TF1("fX", formula);
				break;
			}
		}
		
		
		cout << "Asse Y: vuoi un fit costante(0), polinomiale(1), gaussiano(2), esponenziale(3) o personalizzato(4)?" << endl;
		hYFitType = InputCheck<unsigned int>();
		switch(hYFitType)
		{
			default:
			{
				cout << "coglionazzo, ora ti becchi la prima opzione e non discuti" << endl;
				fY = new TF1("fY", "pol0");
				break;
				
			}
			case 0:
			{
				fY = new TF1("fY", "pol0");
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
						fY = new TF1("fY", "[0]+x*[1]");
						break;
					}
					case -3:
                    {
                        fY = new TF1("f", "[0]+[1]/x+[2]/(x*x)+[3]/(x*x*x)");
                        break;
                    }
                    case -2:
                    {
                        fY = new TF1("f", "[0]+[1]/x+[2]/(x*x)");
                        break;
                    }
					case -1:
                    {
                        fY = new TF1("f", "[0]+[1]/x");
                        break;
                    }
                    case 0:
                    {
                        cout << "Ma allora non potevi scegliere il fit costante? Adesso ti becchi un fit di 19esimo grado" << endl;
                        fY = new TF1("f", "pol19");
                        break;
                    }
                    case 1:
                    {
                        fY = new TF1("f", "[0]+[1]*x");
                        break;
                    }
                    case 2:
                    {
                        fY = new TF1("f", "[0]+[1]*x+[2]*(x*x)");
                        break;
                    }
                    case 3:
                    {
                        fY = new TF1("f", "[0]+[1]*x+[2]*(x*x)+[3]*(x*x*x)");
                        break;
                    }
				}
				break;
			}
			case 2:
			{
				fY = new TF1("fY", "gaus");
				break;
			}
			case 3:
			{
				fY = new TF1("fY", "expo");
				break;
			}
			case 4:
			{
				char formula[40];
				cout << "Inserisci la formula" << endl;
				cin >> formula;
				fY = new TF1("fY", formula);
				break;
			}
		}
		
		bool PersonalizedFitCosmetics;
		cout << "Vuoi parametri di cosmetica del fit standard (0) oppure personalizzati (1)?" << endl;
		PersonalizedFitCosmetics = InputCheck<bool>();
		h->FitSlicesY(fX, hXMin, hXMax, 0, "R");
		h->FitSlicesX(fY, hYMin, hYMax, 0, "R");
		if(PersonalizedFitCosmetics) FitCosmetics();
		h->FitPanel();
	}
}

void Histogram2::FitCosmetics()
{
	cout << "Asse X: dimmi i parametri di stile, colore e spessore della linea del fit. Se non sai cosa mettere, guarda qui: \nhttps://root.cern.ch/doc/master/classTAttLine.html\noppure metti 0 e ci penso io. " << endl;
	hXFitLineStyle = InputCheck<unsigned int>();
	hXFitLineColor = InputCheck<unsigned int>();
	hXFitLineWidth = InputCheck<unsigned int>();
	if(hXFitLineStyle) fX->SetLineStyle(hXFitLineStyle);
	if(hXFitLineColor) fX->SetLineColor(hXFitLineColor);
	if(hXFitLineWidth) fX->SetLineWidth(hXFitLineWidth);
	cout << "Asse Y: dimmi i parametri di stile, colore e spessore della linea del fit. Se non sai cosa mettere, guarda qui: \nhttps://root.cern.ch/doc/master/classTAttLine.html\noppure metti 0 e ci penso io. " << endl;
	hYFitLineStyle = InputCheck<unsigned int>();
	hYFitLineColor = InputCheck<unsigned int>();
	hYFitLineWidth = InputCheck<unsigned int>();
	if(hYFitLineStyle) fY->SetLineStyle(hYFitLineStyle);
	if(hYFitLineColor) fY->SetLineColor(hYFitLineColor);
	if(hYFitLineWidth) fY->SetLineWidth(hYFitLineWidth);
}

void Histogram2::Cosmetics()
{
	cout << "Dimmi i parametri di stile, dimensione e colore del Marker. Se non sai cosa mettere, guarda qui: \nhttps://root.cern.ch/doc/v608/classTAttMarker.html\noppure metti 0 e ci penso io. " << endl;
	hMarkerStyle = InputCheck<unsigned int>();
	hMarkerSize = InputCheck<double>();
	hMarkerColor = InputCheck<unsigned int>();
	
	if(hMarkerStyle) h->SetMarkerStyle(hMarkerStyle);
	if(hMarkerSize) h->SetMarkerSize(hMarkerSize);
	if(hMarkerColor) h->SetMarkerColor(hMarkerColor);
}
void Histogram2::Drawer()
{
	bool PersonalizedCosmetics;
	cout << "Vuoi parametri di cosmetica dell'istogramma standard (0) oppure personalizzati (1)?" << endl;
	PersonalizedCosmetics = InputCheck<bool>();;
	if(PersonalizedCosmetics) Cosmetics();
//	l = new TLegend (.1, .7, .3, .9, "Legenda");
	//	c = new TCanvas("c", hTitle, 10, 20, 400, 600);
//	l->SetFillColor(0);
//	l->AddEntry(h,hTitle);
	if (hFit)
	{
//		l->AddEntry(fX,"Fit X");
//		l->AddEntry(fY,"Fit Y");
		gStyle->SetOptFit();
	}
	//	c->cd();
	h->Draw("lego");
	h->DrawPanel();
//	l->Draw();
/*	if(hFit)
	{
		TH1D* h_1 = (TH1D*)gDirectory->Get("h_1");
		TH1D* h_2 = (TH1D*)gDirectory->Get("h_2");
		TH1D* h_3 = (TH1D*)gDirectory->Get("h_3");
		TH1D* h_4 = (TH1D*)gDirectory->Get("h_4");
		h_1->Draw();
		h_2->Draw();
		h_3->Draw();
		h_4->Draw();
	}
*/
	//	c->Draw();
}

//Getter
char* Histogram2:: GetTitle()
{
	return hTitle;
}
unsigned int Histogram2:: GetEntries()
{
	return hEntries;
}
unsigned int Histogram2:: GetXBinNum()
{
	return hXBinNum;
}
double Histogram2:: GetXMin()
{
	return hXMin;
}
double Histogram2:: GetXMax()
{
	return hXMax;
}
unsigned int Histogram2:: GetYBinNum()
{
	return hYBinNum;
}
double Histogram2:: GetYMin()
{
	return hYMin;
}
double Histogram2:: GetYMax()
{
	return hYMax;
}
unsigned int Histogram2:: GetXDistribution()
{
	return hXDistribution;
}
unsigned int Histogram2:: GetYDistribution()
{
	return hYDistribution;
}
bool Histogram2:: GetFit()
{
	return hFit;
}
unsigned int Histogram2:: GetXFitType()
{
	return hXFitType;
}
unsigned int Histogram2:: GetYFitType()
{
	return hYFitType;
}
unsigned int Histogram2:: GetXFitLineStyle()
{
	return hXFitLineStyle;
}
unsigned int Histogram2:: GetXFitLineColor()
{
	return hXFitLineColor;
}
unsigned int Histogram2:: GetXFitLineWidth()
{
	return hXFitLineWidth;
}
unsigned int Histogram2:: GetMarkerStyle()
{
	return hMarkerStyle;
}
double Histogram2:: GetMarkerSize()
{
	return hMarkerSize;
}
unsigned int Histogram2:: GetMarkerColor()
{
	return hMarkerColor;
}
unsigned int Histogram2:: GetYFitLineStyle()
{
	return hYFitLineStyle;
}
unsigned int Histogram2:: GetYFitLineColor()
{
	return hYFitLineColor;
}
unsigned int Histogram2:: GetYFitLineWidth()
{
	return hYFitLineWidth;
}

//Setter
void  Histogram2:: SetTitle(const char* Title)
{
	hTitle = const_cast<char*>(Title);
}
void Histogram2:: SetEntries(unsigned int Entries)
{
	hEntries = Entries;
}
void Histogram2:: SetXBinNum(unsigned int BinNum)
{
	hXBinNum = BinNum;
}
void Histogram2:: SetXMin(double Min)
{
	hXMin = Min;
}
void Histogram2:: SetXMax(double Max)
{
	hXMax = Max;
}
void Histogram2:: SetYBinNum(unsigned int BinNum)
{
	hYBinNum = BinNum;
}
void Histogram2:: SetYMin(double Min)
{
	hYMin = Min;
}
void Histogram2:: SetYMax(double Max)
{
	hYMax = Max;
}
void Histogram2:: SetXDistribution(unsigned int Distribution)
{
	hXDistribution = Distribution;
}
void Histogram2:: SetYDistribution(unsigned int Distribution)
{
	hYDistribution = Distribution;
}
void Histogram2:: SetFit(bool Fit)
{
	hFit = Fit;
}
void Histogram2:: SetXFitType(unsigned int FitType)
{
	hXFitType = FitType;
}
void Histogram2:: SetYFitType(unsigned int FitType)
{
	hYFitType = FitType;
}
void Histogram2:: SetXFitLineStyle(unsigned int FitLineStyle)
{
	hXFitLineStyle = FitLineStyle;
}
void Histogram2:: SetXFitLineColor(unsigned int FitLineColor)
{
	hXFitLineColor = FitLineColor;
}
void Histogram2:: SetXFitLineWidth(unsigned int FitLineWidth)
{
	hXFitLineWidth = FitLineWidth;
}
void Histogram2:: SetMarkerStyle(unsigned int MarkerStyle)
{
	hMarkerStyle = MarkerStyle;
}
void Histogram2:: SetMarkerSize(double MarkerSize)
{
	hMarkerSize = MarkerSize;
}
void Histogram2:: SetMarkerColor(unsigned int MarkerColor)
{
	hMarkerColor = MarkerColor;
}
void Histogram2:: SetYFitLineStyle(unsigned int FitLineStyle)
{
	hYFitLineStyle = FitLineStyle;
}
void Histogram2:: SetYFitLineColor(unsigned int FitLineColor)
{
	hYFitLineColor = FitLineColor;
}
void Histogram2:: SetYFitLineWidth(unsigned int FitLineWidth)
{
	hYFitLineWidth = FitLineWidth;
}


//private



void histogram2()
{
	Histogram2* histogram = new Histogram2();
	histogram->Filler();
	histogram->Fitter();
	histogram->Drawer();
	
}




	// BARRA DI CARICAMENTO
	/*
	 clock_t t;
	 float tt;
	 int n;
	 for(int i=2; i<=n; ++i)
	 {
	 if(differenza == 0)
	 {
	 	cout << "|";
	 	cout.flush();
	 }
	 cout.flush();
	 t = clock()*10e-07;
	 
	 }
*/


	

