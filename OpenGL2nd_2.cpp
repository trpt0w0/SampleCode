#include <stdio.h>

void main(){
	// 1
	if(a == 0){
		if(b != 0){
			func();
		}
	}

	if(a == 0 && b != 0){
		func();
	}

	// 2
	if(x > 5){
		func();
	}else if(y > 5){
		func();
	}

	if(x > 5 || y >5){
		func();
	}

	// 3
	if(p0){
		if(p1){
			func();
		}else if(p2){
			func();
		}
	}

	if(p0 && (p1 || p2)){
		func();
	}

	// 4
	if(a < 5){
		if(c + d > 0){
			func();
		}
	}else if( a + d < b + c){
		func();
	}

	if(( a > 5 && (c + d >0) ) || (a + d < b + c) ){
		func();
	}



}