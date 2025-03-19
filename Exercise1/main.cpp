#include <iostream>
#include <fstream>

unsigned int sum_values(unsigned int N)
{
	return N * (N + 1) *(2 * N + 1) / 6;
}

int main()
{
	std::ifstream fstr("data.txt"); //posso farlo così, oppure
	//fstr.open("data.txt"); //oppure così
	
	//il file deve esistere, e deve esistere nella cartella di debug associata al progetto (altrimenti dovrei mettere tutto il path)
	if (fstr.fail())
	{
		std::cerr <<"File not found" <<std::endl;
		return 1;
	}
		
	std::string tmp;
	std::getline(fstr, tmp); 

	std::cout << tmp << std::endl;
	
	//manda in pappa il programma
	//unsigned int i=-1; 
	//std::cout << "i= " << i << std::endl;
	
	unsigned int sum = 0;
	unsigned int val; //unsigned int perché includo più numeri
	unsigned int n = 0;
	
	while(fstr>>val)
	{
		sum += val * val; //la potenza così perché pow() è più costoso
		n++;
	}
	
	unsigned int S = sum_values(n);
	
	std::cout << " sum = " << sum << std::endl;
	std::cout << " S = " << S << std::endl;
	
    return 0;
}
