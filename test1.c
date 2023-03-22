#include <stdio.h>
#include <string.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	char name[20];
	printf("Enter name: ");
	fgets(name, sizeof(name), stdin); // read string
	printf("Your name is: ");
	puts(name);
	printf("\n");
	int len;
	len = strlen(name);
	printf("El largo es: %d\n\n", len);
	int r = 0;
	long int s = syscall(439, name, &r);
	if (s == -1){
		printf("System call .: sys_expr_arit :. returned %ld \n", s);	
		printf("ERROR\n");
		printf("\n");
	}
	else{
		printf("System call .: sys_expr_arit :. returned %ld \n", s);	
		printf("\n");
		printf("\n");
		system("dmesg");
		printf("El valor de r es:  %d \n", r);
		
	}
	return 0;
}
