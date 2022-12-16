#include<iostream>
#include<vector>
#include <bits/stdc++.h>


using namespace std;

// Gerador de Vectores aletórios
vector<long int> generationvector(int geracao)
{
	srand(geracao);
	std::vector<long int> v(100);
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

// Conversor de vetores para valores crescentes de 0 a seu tamanho
void ascendinggeneration(vector<long int> &vec)
{
	for(long int value = 0; value < vec.size(); value++)
	{
		vec[value] = value;
	}
}

// Conversor de vetores para valores decrescentes seu tamanho até 0
void descendinggeneration(vector<long int> &vec)
{
	for(long int value = vec.size(); value >= 0; value--)
	{
		vec[value] = value;
	}
}

// Conversor de vetores para metade crescete e metade decrescentes de valores de 0 a tamanho/2
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

// Conversor de vetores de metade decrescentes e metade crescete e de valores tamanho/2 a 0
void descendingascendingsort(vector<long int> &vec)
{
	for(long int value = vec.size(); value >= 0; value--)
	{
		if(value >= (vec.size()/2))
		{
			vec[value] = value;
		}
		else
		{
			vec[value] = vec.size() - value + 1;
		}
	}
}



// retorna o proximo pivo
long int Partition(vector<long int> &v,long int start,long int end){
	
	long int pivot = end;
	long int j = start;
	for(long int i=start;i<end;++i){
		if(v[i]<v[pivot]){
			swap(v[i],v[j]);
			++j;
		}
	}
	swap(v[j],v[pivot]);
	return j;
	
}

// recursão do processo de partição, ordena por partes
void Quicksort(vector<long int> &v,long int start,long int end ){

	if(start<end){
		long int p = Partition(v,start,end);
		Quicksort(v,start,p-1);
		Quicksort(v,p+1,end);
	}
	
}

// Imprime o vetor
void PrintVector(vector<long int> v){
	for(long int i=0;i<v.size();++i)
		cout<<v[i]<<" ";
	cout<<"\n\n";
}

int main() {
	
	// Constantes Universais 
	long int vector_size = 100000;
	int start = 0;
	
	// Lista de vetores requisitadoss
	std::vector<long int> randomVector = generationvector(1);
	std::vector<long int> ascendVector(vector_size);
	std::vector<long int> descendVector(vector_size);
	std::vector<long int> ascendDescendVector(vector_size);
	std::vector<long int> descendAscendVector(vector_size);
	
	// Conversão dos vetores ordenados
	ascendinggeneration(ascendVector);
	descendinggeneration(descendVector);
	ascendingdescendingsort(ascendDescendVector);
	descendingascendingsort(descendAscendVector);
	
	// Saidas do Vetor Aleatório
	cout<<"Vetor aleatorio antes da ordenação: "<<endl;
	//PrintVector(randomVector);
	
	
	Quicksort(randomVector,start,randomVector.size()-1);
	
	//cout<<"Vetor aleatorio apos a ordenacao "<<endl;
	//PrintVector(randomVector);
	cout<<"Ordenacao do Vetor aleatorio Concluida"<<endl;
	
	
	// Saidas do Vetor Crescente
	cout<<"Vetor crescente antes da ordenacao: "<<endl;
	//PrintVector(ascendVector);
	
	Quicksort(ascendVector,start,ascendVector.size()-1);
	
	//cout<<"Vetor crescente apos a ordenacao "<<endl;
	//PrintVector(ascendVector);
	cout<<"Ordenacao do Vetor crescente Concluida"<<endl;
	
	// Saidas do Vetor Decrescente
	cout<<"Vetor decrescente antes da ordenacao: "<<endl;
	//PrintVector(descendVector);
	
	Quicksort(descendVector,start,descendVector.size()-1);
	
	//cout<<"Vetor decrescente apos a ordenacao "<<endl;
	//PrintVector(descendVector);
	
	// Saidas do Vetor metade crescente metade de decrescente
	cout<<"Vetor metade crescente metade de decrescente antes da ordenacao: "<<endl;
	//PrintVector(ascendDescendVector);
	
	Quicksort(ascendDescendVector,start,ascendDescendVector.size()-1);
	
	//cout<<"Vetor metade crescente metade de decrescente apos a ordenacao "<<endl;
	//PrintVector(ascendDescendVector);
	cout<<"Ordenacao do Vetor metade crescente metade de decrescente Concluida"<<endl;
	
	// Saidas do Vetor metade decrescente metade de crescente
	cout<<"Vetor metade decrescente metade de crescente antes da ordenacao: "<<endl;
	//PrintVector(descendAscendVector);
	
	Quicksort(descendAscendVector,start,descendAscendVector.size()-1);
	
	//cout<<"Vetor metade decrescente metade de crescente apos a ordenacao "<<endl;
	//PrintVector(descendAscendVector);
	cout<<"Ordenacao do Vetor metade decrescente metade de crescente Concluida"<<endl;
}
