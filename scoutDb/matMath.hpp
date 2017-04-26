using namespace std;

namespace MatrixMath {
	
	class MatrixInverter {
		
		int matDims;
		
		MatrixInverter(int matSize) {
			
			matDims = matSize;
			
			int* arr[matSize];
			
			for(int i = 0; i < matSize; i++)
				arr[i] = (int*)(malloc(matSize * sizeof(int));
		}
		
		void rowMult(int row, float fac) {
			for(int i = 0; i < matDims; i++) {
				arr[row][i] *= fac;
			}
		}
		
		void rowAdd(int row1, int row2, float fac) {
			for(int i = 0; i < matDims; i++) {
				arr[row2][i] += arr[row1] * fac;
			}
		}
		
		void gaussElim() {
			for(int i = 0; i < matDims; i++) {
				rowMult(i, pow(arr[i][i], -1));
				for(int j = 0; j < matDims; j++) {
					rowAdd(j, i, -arr[j][i]);
				}
			}
		}
		
	}
	
}