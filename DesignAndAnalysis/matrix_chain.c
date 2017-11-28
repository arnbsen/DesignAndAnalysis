#include<stdio.h>
int n = 0;
void print_opt_par(int s[n+1][n+1], int i,int j){
	if(i==j){
		printf("A%d",i);
	}else{
		printf("(");
		print_opt_par(s, i,s[i][j]);
		print_opt_par(s, s[i][j]+1,j);
		printf(")");
	}
}
int main(){
	int i,j,k,l;
	printf("Enter the number of matrices");
	scanf("%d",&n);
	int p[n+2],m[n+1][n+1],s[n+1][n+1];
	for(i=0;i<=n;i++){
		printf("Enter the p[%d]\n",i);
		scanf("%d",&p[i]);
	}
	for(i=1;i<=n;i++){
		m[i][i] = 0;	
	}
	for(l=2;l<=n;l++){
		for(i=1;i<=n-l+1;i++){
			j = i + l -1;
			m[i][j] = 99999;
			for(k=i;k<=j-1;k++){
				int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				if(q<m[i][j]){
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}

	}
	printf("The matrix operation order\n");
	print_opt_par(s,1,n);	
}
