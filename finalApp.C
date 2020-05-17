#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

typedef struct Drone {
	int Drone_number, Year_mfd;
	char Drone_name[15];
	float Mass,Top_speed,Max_distance,Load_capacity;
}Dr;

void init(Dr array[]) {
	int i=0;
	int nums[5] = {1,2,3,4,5};
	char name[5][15] = {"8Direction","TheLabour","BlackBoy","KiMiMi","OctoParse"};
	int years[5] = {2017,2018,2018,2019,2019};
	float mass[5] = {67,44,17.5,22.8,36.7};
	float speed[5] = {220,325,96.5,300,115.9};
	float maxdis[5] = {400,80,295,40,523.17};
	float load[5] = {110,58,17.5,22.8,80.13};
	for(i=0; i<5; i++) {
		array[i].Drone_number = nums[i];
		array[i].Year_mfd = years[i];
		array[i].Mass = mass[i];
		array[i].Top_speed = speed[i];
		array[i].Max_distance = maxdis[i];
		array[i].Load_capacity = load[i];
		strcpy(array[i].Drone_name, name[i]);
	}
	printf("\nList of Drone Information: \n");
	printf("\nDrone Number\tDrone Name\tYear Manufactured\tMass(kg)\tTop Speed(km/h)\tMax Distance(km)\tLoad Capacity(kg)\n");
	for(i=0; i<5 ;i++) {
		printf("\n%d\t%s\t%d\t%.2f\t%.2f\t%.2f\t%.2f\n",array[i].Drone_number,array[i].Drone_name,array[i].Year_mfd,array[i].Mass,array[i].Top_speed,array[i].Max_distance,array[i].Load_capacity);
	}
}

int searchDrones(Dr Drone_info[], float dist, float dl_wg, int length, Dr extra[], int secLen) {
	int cnt = 0;
	if(dist<=0 || dl_wg <=0) {
		printf("\nWrong Input!!!");
	} else {
	int i = 0;
	int j = 0;
	printf("\nDrones capable of being used to deliver %.2f(kg) products to a distance of %.2f(km) are:\n",dl_wg,dist);
	for(i=0; i<length ;i++) {
		if(Drone_info[i].Max_distance >= dist && Drone_info[i].Load_capacity >= dl_wg) {
			extra[secLen+cnt].Drone_number=Drone_info[i].Drone_number;
			strcpy(extra[secLen+cnt].Drone_name,Drone_info[i].Drone_name);
			extra[secLen+cnt].Year_mfd=Drone_info[i].Year_mfd;
			extra[secLen+cnt].Mass=Drone_info[i].Mass;
			extra[secLen+cnt].Top_speed=Drone_info[i].Top_speed;
			extra[secLen+cnt].Max_distance=Drone_info[i].Max_distance;
			extra[secLen+cnt].Load_capacity=Drone_info[i].Load_capacity;
			cnt+=1;
			j++;
			printf("%d\t%s\t%d\t%.2f\t%.2f\t%.2f\t%.2f\n",Drone_info[i].Drone_number,Drone_info[i].Drone_name,Drone_info[i].Year_mfd,Drone_info[i].Mass,Drone_info[i].Top_speed,Drone_info[i].Max_distance,Drone_info[i].Load_capacity);
		}
	}
	if(j==0)
		printf("\nNo Drone is capable of being used for the delivery scenario..\n");
	else
		printf("\nA total of %d drones are capable of being used for the delivery scenario.\n",j);
	}
	return (secLen + cnt);
}


void addDrones(Dr Drone_info[], int num, int curLen) {
	int i = 0;
	for(i=0; i<num ;i++) {
		printf("\nEnter The Drone Number: ");
		scanf("%d",&Drone_info[curLen+i].Drone_number);
		fflush(stdin);
		printf("\nEnter The Name of Drone: ");
		gets(Drone_info[curLen+i].Drone_name);
		fflush(stdin);
		printf("\nEnter The Manufacturing Year of Drone: ");
		scanf("%d",&Drone_info[curLen+i].Year_mfd);
		printf("\nEnter The Mass of Drone: ");
		scanf("%f",&Drone_info[curLen+i].Mass);
		printf("\nEnter The Top Speed of Drone: ");
		scanf("%f",&Drone_info[curLen+i].Top_speed);
		printf("\nEnter The Max Distance of Drone: ");
		scanf("%f",&Drone_info[curLen+i].Max_distance);
		printf("\nEnter The Load Capacity of Drone: ");
		scanf("%f",&Drone_info[curLen+i].Load_capacity);
	}
}

void showDrones(Dr array[], int curLen) {
	int i = 0,cnt=0;
	printf("\nList of Drone Information: \n");
	printf("\nDrone Number\tDrone Name\tYear Manufactured\tMass(kg)\tTop Speed(km/h)\tMax Distance(km)\tLoad Capacity(kg)\n");
	for(i=0; i<curLen; i++) {
		printf("\n%d\t%s\t%d\t%.2f\t%.2f\t%.2f\t%.2f\n",array[i].Drone_number,array[i].Drone_name,array[i].Year_mfd,array[i].Mass,array[i].Top_speed,array[i].Max_distance,array[i].Load_capacity);
	}
}	

void searchDroneByNumber(Dr array[], int query, int curLen) {
	int i;
	int j = 0;
	for(i=0; i<curLen; i++)
		if(array[i].Drone_number == query) {
			printf("\nRequired Drone is: ");
			printf("\n%d\t%s\t%d\t%f\t%f\t%f\t%f\n",array[i].Drone_number,array[i].Drone_name,array[i].Year_mfd,array[i].Mass,array[i].Top_speed,array[i].Max_distance,array[i].Load_capacity);
			j++;
		}
	if(j==0)
		printf("\nNo Drones with that Drone Number..");
}

void searchDroneByName(Dr array[], char query[], int curLen) {
	int i;
	int j = 0;
	for(i=0; i<curLen; i++) {
		if(strcmpi(query, array[i].Drone_name) == 0) {
			printf("\n%d\t%s\t%d\t%f\t%f\t%f\t%f\n",array[i].Drone_number,array[i].Drone_name,array[i].Year_mfd,array[i].Mass,array[i].Top_speed,array[i].Max_distance,array[i].Load_capacity);
			j++;
		}
	}
	if(j==0)
		printf("\nNo Drones with that Drone Name..");
}

void searchDroneByPoints(Dr Drone_info[], float dist, float dl_wg, int length) {
	if(dist<=0 || dl_wg <=0) {
		printf("\nWrong Input!!!");
	} else {
	int i = 0;
	int j = 0;
	printf("\nDrones capable of being used to deliver %.2f(kg) products to a distance of %.2f(km) are:\n",dl_wg,dist);
	for(i=0; i<length ;i++) {
		if(Drone_info[i].Max_distance >= dist && Drone_info[i].Load_capacity >= dl_wg) {
			j++;
			printf("%d\t%s\t%d\t%.2f\t%.2f\t%.2f\t%.2f\n",Drone_info[i].Drone_number,Drone_info[i].Drone_name,Drone_info[i].Year_mfd,Drone_info[i].Mass,Drone_info[i].Top_speed,Drone_info[i].Max_distance,Drone_info[i].Load_capacity);
		}
	}
	if(j==0)
		printf("\nNo Drone is capable of being used for the delivery scenario..\n");
	else
		printf("\nA total of %d drones are capable of being used for the delivery scenario.\n",j);
	}
}

int main() {
	int currentLength = 5, length, numberAdd, query, secondaryLength = 0,n;
	char queryName[15];
	float reqDist, reqDlWg, x1, x2, y1, y2;
	Dr Drone_info[50], Drone_capable[50];
	
	printf("----------------------------------------");
	printf("\nWelcome to The Drone Project\n");
	printf("----------------------------------------");
	init(Drone_info);
	
	
	length = sizeof(Drone_info) / sizeof(Drone_info[0]);
	
	while(1) {
		printf("\n");
		printf("----------------------------------------");
		printf("\nMenu");
		printf("\n----------------------------------------");
		printf("\nEnter 1 to View All Drones:\n");
		printf("\nEnter 2 to Search Drone by It's capability:\n");
		printf("\nEnter 3 to Add More Drones:\n");
		printf("\nEnter 4 to Search Drone By It's Number:\n");
		printf("\nEnter 5 to Search Drone By It's Name:\n");
		printf("\nEnter 6 to Search Drone By Co-ordinates:\n");
		printf("\nEnter 7 to View All Eligible Drones:\n"); 
		printf("\nEnter 8 to Terminate The Program:\n");
		printf("----------------------------------------");
		printf("\nEnter Your Choice: ");
		scanf("%d",&n);
		
		switch(n) {
			case 1: {
				showDrones(Drone_info, currentLength);
				break;
			}
			case 2: {
				printf("\nEnter The Distance: ");
				scanf("%f", &reqDist);
				printf("\nEnter The Delivery Weight: ");
				scanf("%f", &reqDlWg);
				printf("\n");
				searchDrones(Drone_info, reqDist, reqDlWg, currentLength, Drone_capable, secondaryLength);
				secondaryLength = searchDrones(Drone_info, reqDist, reqDlWg, currentLength, Drone_capable, secondaryLength);
				printf("\n\n");
				break;
			}
			case 3: {
				printf("Enter the Number of Drones you want to add: ");
				scanf("%d",&numberAdd);
				if((numberAdd + currentLength) <= 50) {
					addDrones(Drone_info, numberAdd, currentLength);
					currentLength += numberAdd;
				} else {
					printf("\n\nSorry We can't store more than 50 Drone's info at a time.");
				}
				break;
			}
			case 4: {
				printf("\nEnter The Drone Number you want to Search: ");
				scanf("%d",&query);
				fflush(stdin);
				searchDroneByNumber(Drone_info, query, currentLength);
				break;
			}		
			case 5: {
				printf("\nEnter The Drone Name you want to Search: ");
				gets(queryName);
				searchDroneByName(Drone_info, queryName, currentLength);
				break;
			}
			case 6: {
				printf("\nEnter The Co-ordinates of Original Point: ");
				scanf("%f%f",&x1,&y1);
				printf("\nEnter The Co-ordinates of Destination Point: ");
				scanf("%f%f",&x2,&y2);
				printf("\nEnter The Delivery Weight: ");
				scanf("%f", &reqDlWg);
				reqDist = sqrt(pow((x1 - x2),2) + pow((y1 - y2), 2));
				searchDroneByPoints(Drone_info, reqDist, reqDlWg, currentLength);
				break;
			}
			case 7: {
				showDrones(Drone_capable, secondaryLength);
				break;
			}
			case 8: {
				printf("\nYou said to terminate the Program.");
				exit(0);
			}
		}
	}
}
