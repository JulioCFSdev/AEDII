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
	sort(vec.begin(), vec.end(), greater<long int>());
	
}

vector<long int> descendingsorteeee(vector<long int> &vec)
{
	int max = vec.size();
	std::vector<long int> vet(100000);
	
	for(int i = 0; i < max; i++)
        vet[i] = vec[(max - 1) - i];
        
    return vet;
	
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



// retorna o proximo pivo
long int partition(vector<long int> & a, int start, int end) {
  unsigned int pivot = a[start];
  unsigned int from_left = start+1;
  unsigned int from_right = end;
  unsigned int tmp;
  
  //cout << "Vector entering partition:";
  //print (a,start,end);
  //cout << endl;
  
  while (from_left != from_right) {
    if (a[from_left]  <= pivot) from_left++;
    else {
      while (( from_left != from_right)  && (pivot < a[from_right])) from_right--;
      //cout << "swaping " << a[from_left] << " with "<< a[from_right] << endl;
      tmp =  a[from_right];
      a[from_right] = a[from_left];
      a[from_left] = tmp;
    }
  }
  
  if (a[from_left]>pivot) from_left--;
  a[start] = a[from_left];
  a[from_left] = pivot;
  
  //cout << "Vector after partition:   ";
  //print (a,start,end);
  //cout << endl;

  return (from_left);
}


// recursão do processo de partição, ordena por partes
void Quicksort(vector <long int> & a, int p, int r) {
  if (p < r) {
    int q = partition(a, p, r);
    Quicksort(a, p, q - 1);
    Quicksort(a, q + 1, r);
  }
}

// Imprime o vetor
void PrintVector(vector<long int> v){
	for(long int i=0;i<v.size();++i)
		cout<<v[i]<<" ";
	cout<<"\n\n";
}

int main() {
	
	// Valores de definição
	int start = 0;
	
	// Geração de números aleatórios
	std::vector<long int> randomVector = generationvector(1);
	std::vector<long int> ascendVector = generationvector(2);
	std::vector<long int> descendVector(100000);
	std::vector<long int> ascendDescendVector(100000);
	std::vector<long int> descendAscendVector(100000);
	
	// Ordenação dos Vetores aleatórios
	ascendingsort(ascendVector);
	descendingsort(descendVector);
	
	// Oredenação e preenchimento dos vetores para o modelo crescente/decrescente e decrescente/crescente
	ascendingdescendingsort(ascendDescendVector);
	descendingascendingsort(descendAscendVector);
	
	clock_t start_time;
	start_time = clock();
	Quicksort(randomVector,start,randomVector.size()-1);
	start_time = clock() - start_time;
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
