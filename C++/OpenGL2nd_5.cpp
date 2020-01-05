#include <stdio.h>

// �������Q�i���ɕϊ�
void Set(int * p, int n){
	for(int i = 0 ; i < 8; ++i){
		p[i] = n % 2;
		n /= 2;
	}
}

// 2�i���̉��Z
int Add(const int * a , const int * b, int *c){
	int carry = 0; //�J��オ��
	for(int i  = 0; i < 8; ++i){
		int n = a[i] + b[i] + carry;
		carry = n / 2;
		c[i] = n % 2;
	}

	return carry;

}

// 2�i������ʌ����牺�ʌ��̏��ɕ\��
void Show(const char* name, const int* p){
	printf("%s=", name);
	for(int i = 0; i < 8; ++i){
		printf("%d", p[i]);
	}
	printf("\n");

}


int Sub(const int * a, const int * b , int *c){

	int revers[8];  // �r�b�g�̔��]�p�ϐ�
	int tmp[8] = {1,0,0,0,0,0,0,0}; // 2�i���̂P
	int ans[8]; // 2�̕␔�ϊ��p�ϐ� 

	// �r�b�g��̔��]
	for(int i = 0; i < 8; ++i ){
		int n = b[i] + 1;
		revers[i] = n % 2;
	}
	// �z��b�̃r�b�g���]�p�̕ϐ���2�i����1�̉��Z
	int carry = Add(revers, tmp, ans);

	Show("ans", ans);
	// a��b�̂Q�̕␔�����Z
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
