using namespace std;

namespace MatrixMath {
	
	class MatrixInverter {
		
		int matDims;
		
		MatrixInverter(int* mat, int matSize) {
			
			matDims = matSize;
			
			int* arr[matSize],
				identMat[matSize];
			
			for(int i = 0; i < matSize; i++) {
				arr[i] = (int*)(malloc(matSize * sizeof(int));
				identMat[i] = (int*)(malloc(matSize * sizeof(int));
			}
			
			for(int i = 0; i < matSize; i++) {
				for(int j = 0; j < matSize; j++) {
					arr[i][j] = mat[i][j];
					identMat[i][j] = 0;
				}
				identMat[i][i] = 1;
			}
			
		}
		
		void rowMult(int* arr, int row, float fac) {
			for(int i = 0; i < matDims; i++) {
				arr[row][i] *= fac;
			}
		}
		
		void rowAdd(int* arr, int row1, int row2, float fac) {
			for(int i = 0; i < matDims; i++) {
				arr[row2][i] += arr[row1] * fac;
			}
		}
		
		void gaussElim() {
			for(int i = 0; i < matDims; i++) {
				rowMult(arr, i, pow(arr[i][i], -1));
				rowMult(identMat, i, pow(arr[i][i], -1));
				for(int j = 0; j < matDims; j++) {
					rowAdd(arr, j, i, -arr[j][i]);
					rowAdd(identMat, j, i, -arr[j][i]);
				}
			}
		}
		
		void outputInverse(int* output) {
			for(int i = 0; i < matSize; i++) {
				for(int j = 0; j < matSize; j++) {
					output[i][j] = identMat[i][j];
				}
			}
		}
	}
}