// Usage example file
#include <stdio.h>
#include "matrix.h"

int main(){
	Matrix M0 = init(3,3);
	create(&M0);
	view(M0);
	float f;
	det(&f, M0);
	printf("determinant -> %f\n", f);
	Matrix M1 = init(3,3);
	//matcpy(&M1, M0);	// Copying M0 to M1
	create(&M1);
	mul(&M1, M0);	// Multiply M0 by M1 and store in M1
	view(M1);

	return 0;
}
