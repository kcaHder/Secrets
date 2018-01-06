//
//  histograph.cpp
//  
//
//  Created by Michele Iannello on 13/11/17.
//
//

#include "histogram.cpp"
#include "graph.cpp"

using namespace std;
void histograph()
{
	bool again = 1;
	while(again)
	{
		//Histogram or Graph?
		bool choice;
        cout << "Vuoi fare un istogramma (0) o un grafico (1)?" << endl;
        cin >> choice;
		//Histogram
		if(!choice)
		{
			cin.get();
			histogram();
		}
		//Graph
		else
		{
			cin.get();
			graph();
		}
		//Again?
        cout << "Vuoi fare un altro grafico o istogramma (1) oppure no (0)?" << endl;
        cin >> again;
    
	}
}
