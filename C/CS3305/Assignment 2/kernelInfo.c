#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*

display /proc/cpuinfo and /proc/version

processor type - vendor name, and model

kernel version

*/
void DisplayCPUandKernel(){

	FILE * fpCPU;
	FILE * fpKern;
	int flag;
	char left[100], right[100];
	char str1[] = "vendor_id	";
	char str2[] = "model name	";
	char buffer[4096];
		
		//opening /proc/cpuinfo
		fpCPU = fopen("/proc/cpuinfo", "r"); 
		flag = 0;
		while(flag == 0){

			fscanf(fpCPU,"%[^:]:%[^\n]\n", left, right);
			//vendor_id
			if(strcmp(left,str1) == 0){
				printf("Vendor ID:%s\n", right);
			}
			
			//model name
			else if(strcmp(left,str2) == 0){
				printf("Model Name:%s\n", right);
				flag = 1;
			}
		}
		fclose(fpCPU);
		printf("\n");
		
		//opening /proc/version
		fpKern = fopen ("/proc/version", "r"); 
		flag = 0;

		//Kernel Version
		while(flag == 0){
			fscanf(fpKern,"%[^\n]\n", buffer);			
			printf("Kernel Version:\n%s\n", buffer);
			flag = 1;
		}
		
		fclose(fpKern);
}

int main(int argc, char *argv[]){

	DisplayCPUandKernel();
	
}
