#include <stdio.h>
#include <string.h>

void main(){

	// 1
	int a, b;
	char op;
	scanf("%d %c %d",&a, &op, &b);

	int result = 0;
	if(op == '+'){
		result = a + b;
	}else if(op == '-'){
		result = a - b;
	}else if(op == '*'){
		result = a * b;
	}else if(op == '/'){
		result = a / b ;
	}

	printf("%d\n",result);
	
	// 2
	char str[200];
	scanf("%s", &str);

	for(int i = 1; i <= strlen(str); i++ ){
		
		printf("%c", str[i - 1]);
		if(i % 8 == 0) {
			printf("\n");
		}

	}

	
}