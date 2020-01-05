#include <stdio.h>

// 整数を２進数に変換
void Set(int * p, int n){
	for(int i = 0 ; i < 8; ++i){
		p[i] = n % 2;
		n /= 2;
	}
}

// 2進数の加算
int Add(const int * a , const int * b, int *c){
	int carry = 0; //繰り上がり
	for(int i  = 0; i < 8; ++i){
		int n = a[i] + b[i] + carry;
		carry = n / 2;
		c[i] = n % 2;
	}

	return carry;

}

// 2進数を上位桁から下位桁の順に表示
void Show(const char* name, const int* p){
	printf("%s=", name);
	for(int i = 0; i < 8; ++i){
		printf("%d", p[i]);
	}
	printf("\n");

}


int Sub(const int * a, const int * b , int *c){

	int revers[8];  // ビットの反転用変数
	int tmp[8] = {1,0,0,0,0,0,0,0}; // 2進数の１
	int ans[8]; // 2の補数変換用変数 

	// ビット列の反転
	for(int i = 0; i < 8; ++i ){
		int n = b[i] + 1;
		revers[i] = n % 2;
	}
	// 配列bのビット反転用の変数と2進数の1の加算
	int carry = Add(revers, tmp, ans);

	Show("ans", ans);
	// aとbの２の補数を加算
	carry = Add(a, ans, c);


	return carry;
}


void main(){
	int r0[8], r1[8], r2[8];
	int a, b;
	scanf("%d %d", &a, &b);

	Set(r0, a);
	Set(r1, b);
	int carry = Add(r0, r1, r2);
	Show("r0", r0);
	Show("r1", r1);
	Show("r2", r2);
	
	printf("carry = %d\n", carry);


	Set(r0, a);
	Set(r1, b);
	carry = Sub(r0, r1, r2);
	Show("r0", r0);
	Show("r1", r1);
	Show("r2", r2);


	printf("carry = %d\n", carry);

}
