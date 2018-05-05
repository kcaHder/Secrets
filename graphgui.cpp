//
//  histograph.cpp
//  
//
//  Created by Michele Iannello on 13/11/17.
//
//

#include "graph.hpp"
#include "Gui.C"
using namespace std;
Graph* G = new Graph();




#if defined(__linux__)

bool OS = 1;

#endif

//static
//private

char* Graph::graphTitle = new char[50];
char* Graph:: graphFile = new char[300];
//double* Graph:: graphEntriesX = new double[10];
//double* Graph:: graphEntriesY = new double[10];
//double* Graph:: graphEntriesEX = new double[10];
//double* Graph:: graphEntriesEY = new double[10];
TGraphErrors* Graph:: g = new TGraphErrors();
//public

//non static
//public

Graph::Graph(){}
Graph::Graph(int)
{

	char maybeApostrophe;
	cout << "Trascina il file sul terminale e premi invio(oppure dammi il percorso del file seguito da uno spazio e da un invio)\n";
    cin.get(maybeApostrophe);
    if(maybeApostrophe == '\'') cin.getline(graphFile, 50, '\'');
    else
    {
    	cin.putback(maybeApostrophe);
    	cin.getline(graphFile, 50, '\ ');
	}
//	Probabilmente sarebbe più elegante così:
/*
	cout << "Trascina il file sul terminale e premi invio(oppure dammi il percorso del file seguito da uno spazio e da un invio)\n";
	char maybeApostrophe = cin.peek();
	if(maybeApostrophe == '\'')
	{
		cin.get();
		cin.getline(graphFile, 50, '\'');
	}
	else cin.getline(graphFile, 50, '\ ');
*/

// Questo invece sarebbe senza scrupoli (e valido solo su Mac):
//	cout << "Dammi il percorso del file (per inserire il percorso puoi trascinare il file sul terminale)" << endl;
//	cin >> graphFile;
	//cout << "Vuoi un grafico con gli errori su entrambe le variabili(0), con gli errori solo su y (1) o senza (2)?" << endl;
	//graphWoW = InputCheck<unsigned int>();
	switch(fComboBox1230->GetSelected())
	{
		default: cout << "coglionazzo, ora ti becchi la prima opzione e non discuti" << endl;
		case 0:
		{
			g = new TGraphErrors(graphFile, "%lg%lg%lg%lg");
			break;
		}
		case 1:
		{	g = new TGraphErrors(graphFile, "%lg%lg%lg");
			break;
		}
		case 2:
		{
			g = new TGraphErrors(graphFile, "%lg%lg");
			break;
		}
	}

}
//Graph::Graph(char)
//{
//	cout << "Dammi il numero di entrate del grafico" << endl;
//	graphEntries = InputCheck<unsigned int>();
///*	EntriesX = new double[graphEntries];
//	EntriesY = new double[graphEntries];
//	EntriesEX = new double[graphEntries];
//	EntriesEY = new double[graphEntries];
//*/	cout << "Dammi i valori in ascissa e in ordinata e i relativi errori. " << endl;
//	for (unsigned int j=0; j<graphEntries; ++j)
//	{
//		cout << j+1 << ". X = ";
//		graphEntriesX[j] = InputCheck<double>();
//		cout << " Errore sulla X = ";
//		graphEntriesEX[j] = InputCheck<double>();
//		cout << "Y = ";
//		graphEntriesY[j] = InputCheck<double>();
//		cout << " Errore sulla Y = ";
//		graphEntriesEY[j] = InputCheck<double>();
//	}
//	g = new TGraphErrors(graphEntries,graphEntriesX,graphEntriesY,graphEntriesEX,graphEntriesEY);
//	
//}
Graph::Graph(double)
{
	
	/*cout << "Sei su Mac (0) o su Linux (1)?\n";
	OS = InputCheck<bool>();*/
	if(!OS) system("touch filename.txt | open -a TextEdit filename.txt");
	else system("gedit filename.txt");
	/*cout << "Vuoi un grafico con gli errori su entrambe le variabili(0), con gli errori solo su y (1) o senza (2)?" << endl;
	graphWoW = InputCheck<unsigned int>();*/
	switch(fComboBox1230->GetSelected())
	{
		default: cout << "coglionazzo, ora ti becchi la prima opzione e non discuti" << endl;
		case 0:
		{
			g = new TGraphErrors("filename.txt", "%lg%lg%lg%lg");
			break;
		}
		case 1:
		{	g = new TGraphErrors("filename.txt", "%lg%lg%lg");
			break;
		}
		case 2:
		{
			g = new TGraphErrors("filename.txt", "%lg%lg");
			break;
		}
	}
}
void Graph::Filler()
{
//	cin.clear();
//	char c;
//  cin.get(c);
	/*cout << "Dimmi il nome del grafico" << endl;
    cin.getline(graphTitle, 50, '\n');*/
    graphTitle = const_cast<char*>(titlegraph->GetDisplayText().Data());
	//cout << "Vuoi aprire 'filename.txt' e salvare i valori (0) oppure caricare un file (1)?" << endl;
	//graphFill = InputCheck<bool>();
	if(load[0]->IsOn()) Graph(619);
	else Graph(6.9);
//	{
//		cout << "Vuoi digitare da terminale (0) o SALVARLI IN UN FILE DI TESTO (OPZIONE CONSIGLIATA) (1)?" << endl;
//		graphInputType = InputCheck<bool>();
//		//File writing
//		if(!graphInputType) Graph('z');
//		else Graph(6.9);
//	}
	
}

void Graph::Fitter()
{
	cout << "Vuoi fittare il grafico(1), oppure no(0)? SETTATO A 0" << endl;
	graphwannaFit = 0; //InputCheck<bool>()
	if(graphwannaFit)
	{
		cout << "Vuoi un fit costante(0), polinomiale(1), gaussiano(2), esponenziale(3) o personalizzato(4)?" << endl;
		graphFitType = InputCheck<unsigned int>();
		switch(graphFitType)
		{
			default:
			{
				cout << "coglionazzo, ora ti becchi la prima opzione e non discuti" << endl;
				f = new TF1("f", "pol0");
				break;
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
		if(PersonalizedFitCosmetics) FitCosmetics();
		else g->Fit("f");
		
	}
}
void Graph::FitCosmetics()
{
	cout << "Dimmi i parametri di stile, colore e spessore della linea del fit. Se non sai cosa mettere, guarda qui: \nhttps://root.cern.ch/doc/master/classTAttLine.html\noppure metti 0 e ci penso io. " << endl;
	graphFitLineStyle = InputCheck<unsigned int>();
	graphFitLineColor = InputCheck<unsigned int>();
	graphFitLineWidth = InputCheck<unsigned int>();
	if(graphFitLineStyle) f->SetLineStyle(graphFitLineStyle);
	if(graphFitLineColor) f->SetLineColor(graphFitLineColor);
	if(graphFitLineWidth) f->SetLineWidth(graphFitLineWidth);
	
	cout << "Dimmi gli estremi del fit sull'asse X" << endl;
	graphFitMin = InputCheck<double>();
	graphFitMax = InputCheck<double>();
	g->Fit("f", "", "", graphFitMin, graphFitMax);
}

void Graph::Cosmetics(bool PersonalizedCosmetics)
{
	if(!PersonalizedCosmetics)
	{
		g->SetMarkerStyle(kFullCircle);
		g->SetMarkerColor(kBlue);
	}
	else
	{
		//cout << "Dimmi i parametri di stile, dimensione e colore del Marker. Se non sai cosa mettere, guarda qui: \nhttps://root.cern.ch/doc/v608/classTAttMarker.html\n oppure metti 0 e ci penso io. " << endl;
		graphMarkerStyle = markstyle->GetIntNumber();
		graphMarkerSize = marksize->GetIntNumber();
		graphMarkerColor = markcolor->GetIntNumber();
		//cout << "Dimmi i parametri di stile, colore e spessore della linea. Se non sai cosa mettere, guarda qui: \nhttps://root.cern.ch/doc/master/classTAttLine.html\n oppure metti 0 e ci penso io. " << endl;
		graphLineStyle = linestyle->GetIntNumber();
		graphLineColor = linecolor->GetIntNumber();
		graphLineWidth = linewidth->GetIntNumber();
		g->SetMarkerStyle(graphMarkerStyle);
		g->SetMarkerSize(graphMarkerSize);
		g->SetMarkerColor(graphMarkerColor);
		g->SetLineStyle(graphLineStyle);
		g->SetLineColor(graphLineColor);
		g->SetLineWidth(graphLineWidth);
		/*cout << "Dammi gli estremi su Y del grafico (metti entrambi 0 per parametri standard)." << endl;
	graphMin = InputCheck<double>();
	graphMax = InputCheck<double>();
	if(graphMin || graphMax)
	{
		g->SetMinimum(graphMin);
		g->SetMaximum(graphMax);
	}*/
	}
}

void Graph::Drawer()
{
	bool PersonalizedCosmetics;
	//cout << "Vuoi parametri di cosmetica del grafico standard (0) oppure personalizzati (1)?" << endl;
	PersonalizedCosmetics = cosm[0]->IsOn();
	Cosmetics(PersonalizedCosmetics);
//	l = new TLegend (.1, .7, .3, .9, "Legenda");
	c = new TCanvas("c", "Canvas", 10, 20, 400, 600);
//	l->SetFillColor(0);
//	l->AddEntry(g, graphTitle);
	if (graphwannaFit)
	{
//		l->AddEntry(f,"Fit Lineare");
		gStyle->SetOptFit();
	}
	g->SetTitle(titlegraph->GetDisplayText().Data());
	
	g->Draw();
	g->DrawPanel();
//	l->Draw();
	c->Draw();
}

//Getter
char* Graph:: GetTitle()
{
	return graphTitle;
}
TGraphErrors* Graph:: GetGraph()
{
	return g;
}
TF1* Graph:: GetFunction()
{
	return f;
}
bool Graph:: GetFill()
{
	return graphFill;
}
char* Graph:: GetFile()
{
	return graphFile;
}
unsigned int Graph:: GetWoW()
{
	return graphWoW;
}
//bool Graph:: GetInputType()
//{
//	return graphInputType;
//}
//unsigned int Graph:: GetEntries()
//{
//	return graphEntries;
//}
bool Graph:: GetWannaFit()
{
	return graphwannaFit;
}
unsigned int Graph:: GetFitType()
{
	return graphFitType;
}
unsigned int Graph:: GetFitLineStyle()
{
	return graphFitLineStyle;
}
unsigned int Graph:: GetFitLineColor()
{
	return graphFitLineColor;
}
unsigned int Graph:: GetFitLineWidth()
{
	return graphFitLineWidth;
}
double Graph:: GetFitMin()
{
	return graphFitMin;
}
double Graph:: GetFitMax()
{
	return graphFitMax;
}
double Graph:: GetFitRange()
{
	cout << "Fit Range: [" << graphFitMin << ", " << graphFitMax << "]" << endl;
	return (graphFitMax - graphFitMin);
}
unsigned int Graph:: GetLineStyle()
{
	return graphLineStyle;
}
unsigned int Graph:: GetLineColor()
{
	return graphLineColor;
}
unsigned int Graph:: GetLineWidth()
{
	return graphLineWidth;
}
unsigned int Graph:: GetMarkerStyle()
{
	return graphMarkerStyle;
}
double Graph:: GetMarkerSize()
{
	return graphMarkerSize;
}
unsigned int Graph:: GetMarkerColor()
{
	return graphMarkerColor;
}
double Graph:: GetMin()
{
	return graphMin;
}
double Graph:: GetMax()
{
	return graphMax;
}

//Setter
void Graph:: SetTitle(const char* Title)
{
	graphTitle = const_cast<char*>(Title);
}
void Graph:: SetGraph(TGraphErrors* G)
{
	g = G;
}
void Graph:: SetFunction(TF1* F)
{
	f = F;
}
void Graph:: SetFill(bool Fill)
{
	graphFill = Fill;
}
void Graph:: SetFile(char* File)
{
	graphFile = File;
}
void Graph:: SetWoW(unsigned int WoW)
{
	graphWoW = WoW;
}
//void Graph:: SetInputType(bool InputType)
//{
//	graphInputType = InputType;
//}
//void Graph:: SetEntries(unsigned int Entries)
//{
//	graphEntries = Entries;
//}
void Graph:: SetWannaFit(bool wannaFit)
{
	graphwannaFit = wannaFit;
}
void Graph:: SetFitType(unsigned int FitType)
{
	graphFitType = FitType;
}
void Graph:: SetFitLineStyle(unsigned int FitLineStyle)
{
	graphFitLineStyle = FitLineStyle;
}
void Graph:: SetFitLineColor(unsigned int FitLineColor)
{
	graphFitLineColor = FitLineColor;
}
void Graph:: SetFitLineWidth(unsigned int FitLineWidth)
{
	graphFitLineWidth = FitLineWidth;
}
void Graph:: SetFitMin(double FitMin)
{
	g->Fit("f", "", "", (graphFitMin = FitMin));
}
void Graph:: SetFitMax(double FitMax)
{
	graphFitMax = FitMax;
	g->Fit("f", "", "", graphFitMin, graphFitMax);
}
void Graph:: SetFitRange(double FitMin, double FitMax)
{
	g->Fit("f", "", "", (graphFitMin = FitMin), (graphFitMax = FitMax));
}
void Graph:: SetLineStyle(unsigned int LineStyle)
{
	graphLineStyle = LineStyle;
}
void Graph:: SetLineColor(unsigned int LineColor)
{
	graphLineColor = LineColor;
}
void Graph:: SetLineWidth(unsigned int LineWidth)
{
	graphLineWidth = LineWidth;
}
void Graph:: SetMarkerStyle(unsigned int MarkerStyle)
{
	graphMarkerStyle = MarkerStyle;
}
void Graph:: SetMarkerSize(double MarkerSize)
{
	graphMarkerSize = MarkerSize;
}
void Graph:: SetMarkerColor(unsigned int MarkerColor)
{
	graphMarkerColor = MarkerColor;
}
void Graph:: SetMin(double Min)
{
	graphMin = Min;
}
void Graph:: SetMax(double Max)
{
	graphMax = Max;
}
//private





void graph()
{
	//Graph filling
	G->Filler();
	//Graphs fitting
	G->Fitter();
	//Graphs drawing
	G->Drawer();
	
}

# ifndef __CINT__
int main()
{
  graph();
  return 0;
}
#endif
