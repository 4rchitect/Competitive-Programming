#include <bits/stdc++.h>

using namespace std;

// Verifica se os vidros cabem em con conteiners de capacidade cap;
bool verificar(vector<int> vec, int cap, int con);

int main()
{
	// n numero de vidros;
	// m numero de conteiners;
	int n,m;
	while(scanf("%d %d", &n, &m) != EOF)
	{
		vector<int> vec;
		
		for(int i = 0; i < n; i++)
		{
			int valor;
			scanf("%d", &valor);
			
			vec.push_back(valor);
		}
		
		int menor = 1, maior = 1000000000, cap = 0;
		
		while(menor <= maior)
		{
			int meio = (menor+maior)/2;
			
			if(verificar(vec,meio,m))
			{
				cap = meio;
				maior = meio - 1;
			}
			else
			{
				menor = meio + 1;
			}
		}
		printf("%d\n", cap);
	}
	return 0;
}

bool verificar(vector<int> vec, int cap, int con)
{
	// conteiners usados e peso que resta no conteiner;
	int conteiner = 1;
	int peso = cap;
	
	for(int i = 0; i < vec.size(); i++)
	{
		// Se o vidro não cabe em um conteiner
		if(vec[i] > cap)
			return false;
			
		if(vec[i] > peso)
		{
			if(conteiner == con)
				return false;
			conteiner++;
			peso = cap;
		}
		
		peso -= vec[i];
	}
	return true;
}
