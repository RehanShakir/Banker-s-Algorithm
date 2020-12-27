#include<stdio.h>
#include<conio.h>

void allocationOfResources(int noOfProcesscess,int noOfResources){
	
	int allocated[noOfResources][noOfProcesscess];
	for(int i=0; i<noOfResources; i++){
		for(int j=0; j<noOfProcesscess; j++){
			printf("Enter %c's Resource P%d: ",i+65,j+1);
			scanf("%d",&allocated[i][j]);
		}
		printf("\n");
	}
}

int main(){
	printf("BANKER'S ALGORITHM\n");
	int noOfProcesscess,noOfResources;
	printf("\nEnter No of Processess:");
	scanf("%d",&noOfProcesscess);
	printf("\nEnter No of Resources:");
	scanf("%d",&noOfResources);
	allocationOfResources(noOfProcesscess,noOfResources);
	
	
}
