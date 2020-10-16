#include <iostream>

using namespace std;

int main(){
  int rows = 100, cols = 200;
  double** A;
  
  A = new double* [rows];
  for (int i=0; i<rows; i++){
    A[i]=new double[cols];
    for (int j=0;j<cols; j++){
      A[i][j]=0.2*(i+1)*(j+1);
      cout << "A[" <<i <<"," << j <<"] = " << A[i][j] << endl;
    }
  }
  for(int i=0; i<rows; i++){
    delete[] A[i];
  }
  delete[] A;

}
