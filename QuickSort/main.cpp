#include<iostream>
#include<vector>
#include <bits/stdc++.h>
#include <time.h>

using namespace std;

// Gerador de Vectores aleatórios
vector<long int> generationvector(int geracao)
{
	srand(geracao);
	std::vector<long int> v(100000);
	generate(v.begin(), v.end(), rand);
	return v;
}

// Ordenador de Vetores em ordem crescente
void ascendingsort(vector<long int> &vec)
{
	sort(vec.begin(), vec.end());
	
}

// Ordenador de Vetores em ordem decrescente
void descendingsort(vector<long int> &vec)
{
	sort(vec.begin(), vec.end(), greater<int>());
}

// Conversor de vetores para metade crescente e metade decrescentes de valores de 0 a tamanho/2
void ascendingdescendingsort(vector<long int> &vec)
{
	for(long int value = 0; value < vec.size(); value++)
	{
		if(value <= (vec.size()/2))
		{
			vec[value] = value;
		}
		else
		{
			vec[value] = vec.size() - value - 1;
		}
	}
}

// Conversor de vetores de metade decrescentes e metade crescente e de valores tamanho/2 a 0
void descendingascendingsort(vector<long int> &vec)
{
	for(long int value = vec.size(); value >= 0; value--)
	{
		if(value <= (vec.size()/2))
		{
			vec[value] = value;
		}
		else
		{
			vec[value] = vec.size() - value + 1;
		}
	}
}



long int particionar(vector<long int> &vet, long int inicio, long int fim) {
    long int esq, dir, pivo, aux;

    esq = inicio;
    dir = fim;
    pivo = vet[inicio]; // Definindo o pivô como o primeiro número do vetor

    while (esq < dir) {

        // Avançando para esquerda até encontrar um número maior que o pivô
        while (vet[esq] <= pivo)
            esq++;

        // Recuando para direita até encontrar um número menor ou igual ao pivô
        while (vet[dir] > pivo)
            dir--;

        // Trocando os elementos de posição
        if (esq < dir) {
            aux = vet[esq];
            vet[esq] = vet[dir];
            vet[dir] = aux;
        }
    }

    vet[inicio] = vet[dir]; // Trocando os elementos de posição
    vet[dir] = pivo; // Definindo a nova posição do pivô
	
    return dir;
}

// Função de Ordenação com o vetore suas partições
void Quicksort(vector<long int> &vet, long int inicio, long int fim) {
    long int pivo;
	
    if (fim > inicio) {
        pivo = particionar(vet, inicio, fim); // Definindo um pivô pela função particionar
		
        // Chamandas recursivas para ordenar as partições do vetor
        Quicksort(vet, inicio, pivo-1);
        Quicksort(vet, pivo+1, fim);
    }
}

int main() {
	
	// Valores de definição
	int start = 0;
	clock_t start_time;
	
	// Geração de números aleatórios
	std::vector<long int> randomVector = generationvector(1);
	std::vector<long int> ascendVector = generationvector(2);
	std::vector<long int> descendVector = generationvector(3);
	std::vector<long int> ascendDescendVector(100000);
	std::vector<long int> descendAscendVector(100000);
	
	// Ordenação dos Vetores aleatórios
	ascendingsort(ascendVector);
	descendingsort(descendVector);
	
	// Oredenação e preenchimento dos vetores para o modelo crescente/decrescente e decrescente/crescente
	ascendingdescendingsort(ascendDescendVector);
	descendingascendingsort(descendAscendVector);
	

	start_time = clock();  // Iniciando a contagem do tempo de processamento
	Quicksort(randomVector,start,randomVector.size()-1);
	start_time = clock() - start_time; // Finalizando a contagem do tempo de processamento
	cout<<"Tempo de executacao: "<<(start_time/CLOCKS_PER_SEC)<<endl;
	cout<<"Ordenacao do Vetor aleatorio Concluida"<<endl;
	
	start_time = clock();
	Quicksort(ascendVector,start,ascendVector.size()-1);
	start_time = clock() - start_time;
	cout<<"Tempo de executacao: "<<(start_time/CLOCKS_PER_SEC)<<endl;
	cout<<"Ordenacao do Vetor crescente Concluida"<<endl;
	
	start_time = clock();
	Quicksort(descendVector,start,descendVector.size()-1);
	start_time = clock() - start_time;
	cout<<"Tempo de executacao: "<<(start_time/CLOCKS_PER_SEC)<<endl;
	cout<<"Ordenacao do Vetor decrescente Concluida"<<endl;
	
	start_time = clock();
	Quicksort(ascendDescendVector,start,ascendDescendVector.size()-1);
	start_time = clock() - start_time;
	cout<<"Tempo de executacao: "<<(start_time/CLOCKS_PER_SEC)<<endl;
	cout<<"Ordenacao do Vetor metade crescente metade de decrescente Concluida"<<endl;
	
	start_time = clock();
	Quicksort(descendAscendVector,start,descendAscendVector.size()-1);
	start_time = clock() - start_time;
	cout<<"Tempo de executacao: "<<(start_time/CLOCKS_PER_SEC)<<endl;
	cout<<"Ordenacao do Vetor metade decrescente metade de crescente Concluida"<<endl;
}
