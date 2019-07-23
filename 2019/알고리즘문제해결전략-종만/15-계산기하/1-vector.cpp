#include <stdio.h>
#include <math.h>

struct vector2 {
  double x, y;

  // 생성자
  vector2(double x_ = 0, double y_ = 0) {
    x = x_;
    y = y_;
  }

  // 벡터 비교 연산자
  bool operator == (vector2& rhs) {
    return x == rhs.x && y == rhs.y;
  }
  bool operator < (vector2& rhs) {
    return x != rhs.x ? x < rhs.x : y < rhs.y;
  }

  // 벡터 덧셈, 뺄셈
  vector2 operator + (vector2& rhs) {
    return vector2(x + rhs.x, y + rhs.y);
  }
  vector2 operator - (vector2& rhs) {
    return vector2(x - rhs.x, y - rhs.y);
  }

  // 벡터 스칼라곱 (길이 rhs 배 만큼 늘린 벡터)
  vector2 operator * (double rhs) {
    return vector2(x * rhs, y * rhs);
  }

  // 벡터 크기(norm) (x^2 + y^2)^0.5
  double norm() {
    return sqrt(x * x + y * y); // return hypot(x, y);
  }

  // 방향같은 길이 1짜리 단위 벡터
  vector2 normalize() {
    return vector2(x / norm(), y / norm());
  }

  // 내적, 외적
  double dot(vector2& rhs) {
    return x * rhs.x + y * rhs.y;
  }
  double cross(vector2& rhs) {
    return x * rhs.y - rhs.x * y;
  }

  // 사영 : 벡터를 rhs위로 projection
  vector2 project(vector2& rhs) {
    vector2 direction = rhs.normailize();
    return direction * rhs.dot(*this);
  }
};

int main() {
  vector2 v1(3, 4);
  vector2 v2(3, 6);
  vector2 v3(10, 10);
  
  printf("v1 : (%f, %f)\n", v1.x, v1.y);
  printf("v2 : (%f, %f)\n", v2.x, v2.y);
  printf("v3 : (%f, %f)\n", v3.x, v3.y);

  printf("v1 == v2 : %s\n", v1 == v2 ? "true" :"false");
  printf("v1 < v2 : %s\n", v1 < v2 ? "true" :"false");
  printf("v1 < v3 : %s\n", v1 < v3 ? "true" :"false");

  vector2 v4 = v1 + v2;
  vector2 v5 = v1 - v3;
  printf("v1 + v2 : (%f, %f) \n", v4.x, v4.y);
  printf("v1 - v3 : (%f, %f) \n", v5.x, v5.y);
  
  vector2 v6 = v1 * 0.5;
  printf("v1 * 0.5 : (%f, %f) \n", v6.x, v6.y);

  printf("|v1| : %f \n", v1.norm());

  vector2 v7 = v1.normalize();
  printf("v1 방향의 단위 벡터 : (%f, %f) \n", v7.x, v7.y);

  double dot_product_v1_v2 = v1.dot(v2);
  double cross_product_v1_v2 = v1.cross(v2);
  printf("v1 내적 v2 : %f \n", dot_product_v1_v2);
  printf("v1 외적 v2 : %f \n", cross_product_v1_v2);


  return 0;
}