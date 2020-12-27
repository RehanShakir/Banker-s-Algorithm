#include<stdio.h>
#include<conio.h>

int noOfResources=3, noOfProcesscess=5,safeSeq[5];
struct process{                       
	int maxNeed[5][3];
	int allocated[5][3];
	int remainingNeed[5][3];
	int available[5][3];
	
}p;

void available(){   //Availabe Resources for Processess
	int ri=1,j=0,d=0,m=0,n=0,flag=0;
	int proce[] = {0,1,2,3,4};
	for(int i=0; i<noOfProcesscess; i++){
		rep:
			if(p.available[d][m] >= p.remainingNeed[i][j] && p.available[d][m+1] >= p.remainingNeed[i][j+1] && p.available[d][m+2] >= p.remainingNeed[i][j+2]){
				proce[i] =-1;
				safeSeq[n] = i;
				printf("\nProcess=%d\n",i);
				for(int k=0; k<noOfResources; k++){
					p.available[ri][k]= p.allocated[i][k]+ p.available[n][k];
				}
				ri++;
				d++;
				n++;
				flag++;
			}
			if(i >= 4){
				for(int t=0; t<noOfProcesscess; t++){
					if(proce[t] != -1){
						i=0;
						goto rep;
					}
				}
				
			}
	
	}
	printf("\nFLAG=%d\n",flag);
	for(int i=0; i<noOfProcesscess; i++){
		printf("\nP%d Available \n",i+1);
		for(int j=0; j<noOfResources; j++){
			printf("%d ",p.available[i][j]);
		}
	}
	printf("\nSafe Sequence:");
	for(int i=0; i<noOfProcesscess; i++){
		printf("P%d",safeSeq[i]+1);
		if(i== noOfProcesscess - 1){
			break;
		}
		printf("->");
	}

}

void remainingNeed(){                  //Remaining Need Of Processess
	for(int i=0; i<noOfProcesscess; i++){
		for(int j=0; j<noOfResources; j++){
			printf("\n%d - %d = %d",p.maxNeed[i][j],p.allocated[i][j],p.maxNeed[i][j] - p.allocated[i][j]);
			p.remainingNeed[i][j] = (p.maxNeed[i][j] - p.allocated[i][j]);
			//printf("\nIN REMNEED = %d",p.remainingNeed[i][j]);
		}
	}
	
	for(int i=0; i<noOfProcesscess; i++){
		printf("\n%c's Remaining Need\n",i+65);
		for(int j=0; j<noOfResources; j++){
			printf("%d ",p.remainingNeed[i][j]);
		}
	}
}

void maxNeed(){  //Maximum Need Of a Process
	
	for(int i=0; i<noOfProcesscess; i++){
		printf("\nProcess P%d\n",i+1);
		for(int j=0; j<noOfResources; j++){
			printf("Enter %c's Max Need: ",j+65);
			scanf("%d",&p.maxNeed[i][j]);
		}
		printf("\n");
	}
	for(int i=0; i<noOfProcesscess; i++){
		printf("\nProcess P%d\n",i+1);
		for(int j=0; j<noOfResources; j++){
			printf("%d ",p.maxNeed[i][j]);
		}
	}
}

void allocationOfResources(){ //Allocation of Resources to Processess
	
	int a=0,b=0,c=0,sum=0;
	for(int i=0; i<noOfProcesscess; i++){
		printf("\nProcess P%d\n",i+1);
		for(int j=0; j<noOfResources; j++){
			printf("Allocate %c's Resource: ",j+65);
			scanf("%d",&p.allocated[i][j]);
		}
		printf("\n");
	}
	for(int i=0; i<noOfProcesscess; i++){
		printf("\nProcess P%d\n",i+1);
		for(int j=0; j<noOfResources; j++){
			printf("%d ",p.allocated[i][j]);
		}
	}
	for(int i=0; i<noOfResources; i++){
		for(int j=0; j<noOfProcesscess; j++){
			sum = sum + p.allocated[j][i];
		}
		if(i==0){
			a=sum;
			p.available[0][0] = 10 - a;
		}
		if(i==1){
			b=sum;
			p.available[0][1] = 5 - b;
		}
		if(i==2){
			c=sum;
			p.available[0][2] = 7 - c;
		}
		
		sum=0;
	}
	
	printf("\nTotal Allocation of Resource A = %d",a);
	printf("\nTotal Allocation of Resource B = %d",b);
	printf("\nTotal Allocation of Resource C = %d",c);
}


int main(){                          //Main
	printf("BANKER'S ALGORITHM\n");
	allocationOfResources();
	maxNeed();
	remainingNeed();
	available();
	
}
