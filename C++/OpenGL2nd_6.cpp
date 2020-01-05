#include <stdio.h>

int length(const char* s){
	const char* p = s;
	while(*p){
		++p;
	}
	return p - s;
}

char* copy(const char* s, char* d){
	while(*s){
		*d = *s;
		++s;
		++d;

	}
	*d = '\n';
	return d;
}
char* reverse(const char* s, char* d){
	const char* p = s + length(s);
	while(p != s){
		--p;
		*d = *p;
		++d;
	}
	*d = '\n';
	return d;
}

char* concat(const char * s0, const char* s1, char* d){
	d = copy(s0, d);
	return copy(s1, d);

}

void main(){
	char mem_a[100] = "Hello";
	char mem_b[100] = "World";

	copy(mem_b, mem_a + length(mem_a));
	printf("mem_a = %s\n", mem_a);
	
	reverse(mem_a, mem_b + 10);

	printf("mem_b + 10 = %s\n", mem_b + 10);
	printf("mem_b = %s\n", mem_b);

	concat(mem_a, mem_b, mem_b + 30);
	printf("mem_b + 30 = %s\n", mem_b + 30);
	printf("mem_b = %s\n", mem_b);
	printf("mem_a = %s\n", mem_a);
	
	copy(mem_b + 10,mem_a + 20);
	printf("mem_a = %s", mem_a + 20);
	



}