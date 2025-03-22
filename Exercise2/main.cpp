#include <iostream> //input/output
#include <fstream> //lavorare con i file
#include <iomanip> //per la precisione


//trasformazione affine da (1,5) a (-1,2)
//1 --> -1
//5 --> 2
//y=mx-q
//-1=1*m+q e 2=5*m+q, da cui y=3/4*x-7/4 
double trasformazione(double x) //voglio un double in output (richiesta della traccia), e prendo x come double
{
	return (3.0/4.0)*x - (7.0/4.0); //sto operando con x double
}

	

int main()
{
	std::ifstream inputFile("data.txt"); //apro in lettura
	std::ofstream outputFile("results.txt"); //creo results.txt e lo aprirò in scrittura

	//gestisco gli errori con i file
    if(inputFile.fail())
    {
        std::cerr << "File not found" << std::endl;
        return 1;
    }
	
	if(outputFile.fail())
    {
        std::cerr << "File not opened" << std::endl;
        return 1;
    }


	//definisco i valori 
	double s=0.0;
	double valore;
	
	//nel file in output results.txt inserisco i valori calcolati delle medie
	outputFile << "N Medie\n"; //prima riga di results.txt
	
	int i=0;
	while (inputFile >> valore)
	{
		double nuovoValore = trasformazione(valore); //trasformo il valore dall'intervallo (1,5) in un nuovo valore dell'intervallo (-1,2)
		s += nuovoValore;
		i++;
		
		double media=s/i;
		
		//stampo i risultati in results.txt in precisione 16
		outputFile << i << " " << std::scientific <<std::setprecision(16) << media << "\n";
	}
	
	//chiudo i file
	inputFile.close();
	outputFile.close();
	
	std::cout << "Risultati salvati con succcesso." <<std::endl;
	
    return 0;
}
