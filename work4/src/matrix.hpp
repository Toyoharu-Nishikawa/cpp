typedef struct {
  double d[3][3];
} Mat3;


Mat3 createMat3(double a00, double a01, double a02,
                double a10, double a11, double a12,
                double a20, double a21, double a22,
);
Mat3 mulScalarMat3(const double a, const Mat3 mat3);
Mat3 addMat3(const Mat3 mat3_1, const Mat3 mat3_2);
Mat3 subMat3(const Mat3 mat3_1, const Mat3 mat3_2);


