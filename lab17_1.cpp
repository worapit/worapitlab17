#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void showData(double *,int,int);

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void findColSum(const double *,double *,int,int);

int main(){
	srand(time(0));
	const int N = 6, M = 8;
	double data[N][M] = {};
	double sum1[N] = {};
	double sum2[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,sum1,N,M);
	showData(sum1,N,1);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,sum2,N,M); 
	showData(sum2,1,M);
}

void randData(double *a,int N,int M){
    for(int i = 0; i < N*M; i++){
        *(a + i) = (rand()%101)*0.01;
    }
}

void showData(double *a,int N,int M){
    cout << fixed << setprecision(2);
    for(int i = 0; i < N*M; i++){
        cout << *(a + i);
        if((i+1)%M == 0)cout << endl;
        else cout << " ";
    }
}

void findRowSum(const double *a,double *sum1,int N,int M){
	int j = 0,i = 0;
	double num = 0.0;
	while(j < N*M){
		num = 0;
		for(int k = 0;k < M;k++){
			num += *(a + j);
			j++;
		}
		sum1[i] = num;
		i++;
	}
}

void findColSum(const double *a,double *sum2,int N,int M){
	int j = 0;
	double num = 0.0;
	while(j < M){
	    num = 0;
		for(int k = 0; k < N;k++){
			num += *(a + j + k*M);
		}
		sum2[j] = num;
		j++;
	}
	
}