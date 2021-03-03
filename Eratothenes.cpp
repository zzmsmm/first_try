#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

const int N = 200;
bool is_prime[N + 1];
int num;

void Eratothenes(){
	for(int i = 2;i <= N;i++) 
		is_prime[i] = true;
	for(int i = 2;i <= sqrt(N);i++){
		if(is_prime[i]){
			for(int j = 2;j <= N / i;j++)
				if(is_prime[i * j]) 
					is_prime[i * j] = false;
		}
	}
	return;
}

int main()
{
	freopen("prime_number.txt", "w", stdout);
	Eratothenes();
	for(int i = 1;i <= N;i++)
		if(is_prime[i]){
			num++;
			cout << i << "\t";
			if(num % 5 == 0) cout << endl;
		}
	cout << endl << num << " in total";	
	return 0;
} 
