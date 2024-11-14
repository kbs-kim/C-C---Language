#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <malloc.h>
#include <cstring>
#include <cmath> // atan2 값을 호출할 때 이것 필요함

using namespace std;

int ex01()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

double f(double r)
{
    return 3.14 * r * r;
}

int ex0909_1()
{
    /*문자열 및 기본 타입의 데이터 출력*/
    int n = 3;
    char c = '#';
    std::cout << c << 1000 << '-' << n << "hello" << true << std::endl; // #1000-3hello1
    // #은 char / n은 int "hello"은 string / true는 bool이므로 각각 출력됨
    // std::endl은 줄바꿈을 의미함

    std::cout << "n+5=" << n + 5 << std::endl;
    ; // n+5=8

    /*함수호출도 가능하다.*/
    std::cout << ex01(); // Hello, World!

    /*출력 형식 조정*/
    std::cout << 123;
    std::cout.width(10); // 출력 폭을 10으로 설정
    std::cout << 123 << std::endl;

    // std::cout.setf(ios_base::left); //왼쪽 정렬
    // std::cout<< 123;

    /*원넓이 계산하는 함수 호출*/
    std::cout << f(10.0) << '\n';
    double y = f(10.0);
    std::cout << y << std::endl;

    return 0;
}

// namespace함수
namespace KIM
{
    float area(float r)
    {
        return 3.14 * r * r;
    }

}

namespace LEE
{
    float area(float x)
    {
        return x * 10;
    }

}

int ex0909_2()
{
    /*namespace 활용하기*/
    float A = KIM::area(5.0); // KIM의 area함수 호출
    float B = LEE::area(5.0); // LEE의 area함수 호출
    std::cout << A << " / " << B << std::endl;

    // using namespace std; 코드로 인하여 std:: 생략 가능
    cout << "ByeBye" << endl;

    /*cin 연습하기*/
    int width;  // 너비
    int height; // 높이

    cout << "space and height>>";
    cin >> width >> height;
    cout << " space is " << width << endl;
    cout << "height is " << height << endl;

    return 0;
}

/*#include <string>*/
int ex0909_3(void)
{
    int a = 100;
    string song1 = "falling in love with you";
    string song2("falling in love with you");

    cout << song1 << endl; // falling in love with you
    cout << song2 << endl; // falling in love with you

    string song3 = song2 + "!!!!";
    cout << song3 << endl; // falling in love with you!!!!

    string name = "KBS";
    song3 = song3 + name;
    cout << song3 << endl; // falling in love with you!!!!KBS

    int index = song3.find("love"); // in이 있는 위치를 찾아줌
    cout << index << endl;          // 11 (index는 0부터 시작)
    return 0;
}

/*getlilne 연습*/
int ex0909_4()
{
    string singer;

    getline(cin, singer); // 공백을 포함한 문자열을 입력받음

    cout << singer << endl; // 입력받은 문자열 출력

    if (singer == "BTS")
    {
        cout << "IDOL" << endl;
    }
    else if (singer == "BTOB")
    {
        cout << "WOW" << endl;
    }
    else
    {
        cout << "What is your favorite song?" << endl;
    }

    return 0;
}

int ex0909_5()
{
    int sum = 0;
    int n;
    cout << "please enter last number>>";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    cout << "result of sum 1 to " << n << " is " << sum << endl;

    return 0;
}

// 함수가 호출될때 값을 복사해서 가져온다. 따라서 이름이 달라도 상관없다.
double biggest(double b[], int n) // 배열의 이름과 배열의 크기를 받아야함
// 위의 코드는 이함수내에서 선언하는것과 같은 효과를 가진다.

// double biggest(double *b, int n) //변수의 주소와 변수의 크기를 받아야함
{
    double a_max = b[0];

    for (int i = 1; i < n; i++)
    {
        if (a_max < b[i])
        {
            a_max = b[i];
        }
    }
    return a_max;
}

int ex0909_6(void)
{

    /*배열에 입력받기*/
    double a[5]; // a[0] ~ a[4]

    cout << a; // 배열의 이름은 배열의 시작주소를 의미함. 0x61fed0

    cout << "type 5 floating point5 numbers>>";
    for (int n = 0; n < 5; n++)
    {
        cin >> a[n];
    }
    for (int n = 0; n < 5; n++)
    {
        cout << a[n] << " ";
    }

    /*큰수 찾기*/
    int N = 5;
    double a_max = biggest(a, N); // 호출할때는 타입이 필요없고, 배열의 이름만 적어주면 됨***

    cout << "max number is " << a_max << endl;
}

int ex0913(void)
{
    int K[3] = {7, 8, 9};

    cout << K << " " << &K[0] << " " << &K[1] << " " << &K[2] << endl;
    // 0x61ff04 0x61ff04 0x61ff08 0x61ff0c
    // 배열의 이름은 배열의 시작주소를 의미함. 따라서 K는 K[0]의 주소와 같다.
    // K[1]은 K[0]의 주소에서 4만큼 떨어진곳에 있다. K[2]는 K[0]의 주소에서 8만큼 떨어진곳에 있다.

    char C[3] = {'7', '8', '9'};
    cout << C << " " << &C[0] << " " << &C[1] << " " << &C[2] << endl;
    // 문자????

    int M[3] = {6, 5, 4};
    int *p = M; // 주소를 저장하는 변수라는 뜻***

    cout << *p << endl; // 변수의 내용이라는 뜻***
    // 6
    cout << p << " " << p + 1 << " " << p + 2 << endl; // 그다음 주소로 이동하고 싶을때는 +1을 해주면 된다.
    // 0x61fee0 0x61fee4 0x61fee8

    // 다음 둘은 같은 의미이다.
    cout << p[0] << " " << p[1] << " " << p[2] << endl;
    // 6 5 4

    cout << *p << " " << *(p + 1) << " " << *(p + 2) << endl; // 주소를 증가시킨다음 그 내용
    // 6 5 4

    p = &K[2];                                                // p에 K[2]의 주소를 저장
    cout << *p << " " << *(p - 1) << " " << *(p - 2) << endl; // 내용을 출력
    // 9 8 7
    cout << p[0] << " " << p[-1] << " " << p[-2] << endl;
    // 9 8 7

    return 0;
}

int ex0919_1(void)
{
    int K[3] = {7, 8, 9};    // K[0], K[1], K[2]
    int M[4] = {6, 5, 4, 0}; // M[0], M[1], M[2]
    int N[2] = {1, 2};       // N[0], N[1]

    int *p;
    int *q[3]; // q[0], q[1] <---- 포인터 배열

    q[0] = K; // q[0]에 K의 주소를 저장
    q[1] = M; // q[1]에 M의 주소를 저장
    q[2] = N; // q[2]에 N의 주소를 저장

    cout << q[0] << endl;

    cout << *(q[0]) << " " << *(q[0] + 1) << " " << *(q[0] + 2) << endl; // 7 8 9
    cout << q[0][0] << " " << q[0][1] << " " << q[0][2] << endl;         // 7 8 9

    cout << *(q[1]) << " " << *(q[1] + 1) << " " << *(q[1] + 2) << " " << *(q[1] + 3) << endl; // 6 5 4 0
    cout << q[1][0] << " " << q[1][1] << " " << q[1][2] << " " << q[1][3] << endl;             // 6 5 4 0

    cout << *(q[2]) << " " << *(q[2] + 1) << endl; // 1 2
    cout << q[2][0] << " " << q[2][1] << endl;     // 1 2

    cout << *(*(q + 2) + 0) << " " << *(*(q + 2) + 1) << endl; // 1 2
    // q[2] : *(q+2)와 같다.

    return 0;
}

double biggest1(double *b, int n)
{
    double a_max = *(b + 0); // b[0]

    for (int i = 1; i < n; i++)
    {
        if (a_max < *(b + i))
        {
            a_max = *(b + i);
        }
    }
    return a_max;
}

int ex0919_2(void)
{

    /*배열에 입력받기*/
    double a[5]; // a[0] ~ a[4]

    cout << a; // 배열의 이름은 배열의 시작주소를 의미함. 0x61fed0

    cout << "type 5 floating point5 numbers>>";
    for (int n = 0; n < 5; n++)
    {
        cin >> a[n];
    }
    for (int n = 0; n < 5; n++)
    {
        cout << a[n] << " ";
    }

    /*큰수 찾기*/
    int N = 5;
    double a_max = biggest1(a, N); // 호출할때는 타입이 필요없고, 배열의 이름만 적어주면 됨***

    cout << "max number is " << a_max << endl;

    return 0;
}

void pfunc_1_(int *c, int *d)
{
    cout << *c << " " << *d << endl;
    *c = 30;
    *d = 40; // c는 주소이기 때문에 c에다가 넣으면 안된다.
    //*C에 넣어야한다.
}

int ex0919_3(void)
{
    int a = 10, b = 20;

    pfunc_1_(&a, &b);

    cout << a << " " << b << endl;
    return 0;
}

void pfunc_2_(int &c, int &d)
{
    cout << c << " " << d << endl;
    c = 30;
    d = 40;
}

int ex0919_4(void)
{
    int a = 10, b = 20;
    pfunc_2_(a, b);
    cout << a << " " << b << endl;
    return 0;
}

int ex0919_5()
{
    int a = 10, b = 20;
    int &c = a;        // c는 a의 별명이다.
    c = b;             // c는 b의 별명이다.
    cout << c << endl; // b의 값인 20이 출력된다.

    int annnnnnnnnn = 10, d = 20;
    int &e = annnnnnnnnn;
    cout << e << endl; // 10

    int f[5] = {1, 2, 3, 4, 5};

    int &g = f[3];
    cout << g << endl; // 4

    return 0;
}

bool average(int *a, int size, float &avg)
{
    avg = 0.0;
    for (int i = 0; i < size; i++)
    {
        avg += a[i];
    }
    avg = avg / size;
    return true;
}

int ex0919_6(void)
{
    int x[] = {0, 1, 2, 3, 4, 5};
    float avg;
    average(x, 6, avg);
    cout << "average is " << avg << endl;
    return 0;
}

bool bigger3(int a, int b, int &big) // big는 레퍼런스 변수이다.
{                                    // 레퍼런스 변수를 사용하면 함수의 반환값을 두개 이상으로 만들 수 있다.

    /*
    삼항연사자 이용
    big = (a > b) ? a : b;
    */

    if (a == b)
    {
        return true;
    }
    else
    {
        if (a > b)
        {
            big = a;
        }
        else
        {
            big = b;
        }
        return false;
    }
}

int ex0919_7()
{
    int x, y, big;
    bool b;
    cout << "input two integers>>";
    cin >> x >> y;
    b = bigger3(x, y, big);

    if (b) // b가 true이면
        cout << "same" << endl;
    else // b가 false이면
        cout << "bigger integer is " << big << endl;
    return 0;
}

/*디폴트 인자*/
// 디폴트 인자는 오른쪽부터 채워야한다.
int sum3(int a, int b = 200, int c = 100)
{
    return a + b + c;
}

int ex0923_1(void)
{
    int x = 10, y = 20, z = 30;
    int w = sum3(x, y, z); // 60
    int u = sum3(x, y);    // 130
    int v = sum3(x);       // 310

    cout << w << " " << u << " " << v << endl;

    return 0;
}

/*실습 3-1 디폴트인자*/
void f(char c = ' ', int line = 1)
{
    for (int i = 0; i < line; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << c;
        }
        cout << endl;
    }

    return;
}

int ex0923_2(void)
{
    f();       // 빈칸을 10개 1줄 출력
    f('%');    //%를 10개 1줄 출력
    f('@', 5); //@를 10개 5줄 출력

    return 0;
}

/* 함수 중복 (오버로딩)*/
int ssum(int a, int b, int c)
{
    return a + b + c;
}

// c와 다르게 c++에서는 매개변수의 타입이 다르기 때문에 함수 중복이 가능하다.
double ssum(double a, double b, double c)
{
    return a + b + c;
}

int ex0923_3(void)
{
    cout << ssum(2, 5, 33) << endl;       // 40
    cout << ssum(2.0, 5.0, 33.0) << endl; // 40

    return 0;
}

/* 함수중복 예시 */
int big(int a, int b)
{
    int max_value = (a > b) ? a : b;

    if (max_value <= 100)
    {
        return max_value;
    }
    else
    {
        return 100;
    }
}

int big(int a, int b, int c) // c가 최대값이면 c를 반환해라.
{
    int max_value = (a > b) ? a : b;
    max_value = (max_value > c) ? c : max_value;
    return max_value;
}

int ex0923_4(void)
{
    int x = big(3, 5);       // 3과 5중 큰수를 출력. 큰수가 100보다 크면 100을 출력
    int y = big(300, 60);    // 결과는 100
    int z = big(30, 60, 50); // 결과는 50
    cout << x << " " << y << " " << z << endl;
}

/*함수템플릿*/
// 두함수는 매개변수만 다르고, 나머지 코드는 모두 동일하다.
void myswap(int &a, int &b)
{
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void myswap(double &a, double &b)
{
    double tmp;
    tmp = a;
    a = b;
    b = tmp;
}

template <class T>
void myswap(T &a, T &b)
{
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int ex0926_1(void)
{
    int a = 4, b = 5;
    myswap(a, b); // myswap(int &a, int &b)함수 호출
    cout << a << '\t' << b << endl;

    double c = 4.3, d = 5.6;
    myswap(c, d); // myswap(double &a, double &b)함수 호출
    cout << c << '\t' << d << endl;

    return 0;
}

template <class T1, class T2>
T1 add(T1 *x, T2 num)
{

    T1 sum = 0;

    for (int n = 0; n < num; n++)
    {
        sum += x[n];
    }
    return sum;
}

int ex0926_2()
{

    int x[] = {1, 2, 3, 4, 5};
    double d[] = {1.2, 2.3, 3.4, 4.5, 5.6, 6.7};
    float f[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    cout << "sum of x[] is " << add(x, 5) << endl;
    cout << "sum of d[] is " << add(d, 6) << endl;
    cout << "sum of f[] is " << add(f, 5) << endl;
}

class Circle
{
    // 클래스 private이 디폴트이다.

public:
    int radius;
    double getArea()
    {
        double area = 3.14 * radius * radius;
        return area;
    }
};

// double Circle::getArea() //getArea함수는 Circle클래스의 멤버함수이다.
// {
//     double area = 3.14*radius*radius;
//     return area;
// }

int ex0926_3()
{
    Circle A, B, C; // int a,b,c;
    A.radius = 10;

    cout << A.getArea() << endl;

    Circle *p = &A;
    cout << (*p).radius << endl; // 10
    cout << p->radius << endl;   // 10  이방식을 더 많이 사용한다.

    cout << (*p).getArea() << endl; // 314
    cout << p->getArea() << endl;   // 314
}

class Rectangle
{
public:
    // 멤버변수
    int width;  // 사각형의 폭
    int height; // 사각형의 높이

    int getArea(); // 멤버함수 선언
    // int getArea()
    // {
    //     //여기 함수 내에서 선언하는 변수는 멤버가 아닌 지역변수이다.
    //     int area= width*height;
    //     return area;

    // }
};
int Rectangle::getArea()
{
    int area = width * height;
    return area;
}

int ex0926_4()
{
    Rectangle rect;
    rect.width = 3;
    rect.height = 5;
    cout << "square area is " << rect.getArea() << endl;
}

class Rectangle1
{
private:
    int width;
    int height;

public:
    int Area()
    {
        int area = width * height;
        return area;
    }
    bool setWidth(int input)
    {
        if (input < 0)
            return false;
        else
        {
            width = input;
            return true;
        }
    }

    bool setHeight(int input)
    {
        if (input < 0)
            return false;
        else
        {
            height = input;
            return true;
        }
    }

    int getWidth()
    {
        return width;
    }
    int getHeight()
    {
        return height;
    }
};

int ex0926_5()
{
    Rectangle1 rect;
    if (rect.setWidth(3) == false)
    {
        cout << "width error" << endl;
    }
    if (rect.setHeight(5) == false)
    {
        cout << "height error" << endl;
    }
    rect.setWidth(3);
    rect.setHeight(5);
    cout << "width=" << rect.getWidth() << endl;
    cout << "height=" << rect.getHeight() << endl;
    cout << "area=" << rect.Area() << endl;

    return 0;
}

class Circle2
{
public:
    int radius;
    Circle2();        // 기본 생성자 선언
    Circle2(int r);   // 매개변수 있는 생성자 선언
    ~Circle2();       // 소멸자 선언
    double getArea(); // 멤버 함수 선언
};

Circle2::~Circle2()
{
    cout << "terminater  radius=" << radius << endl;
}

// 기본 생성자 정의
Circle2::Circle2()
{
    radius = 1;
    cout << "radius is " << radius << " and made circle" << endl;
}

// 매개변수 있는 생성자 정의
Circle2::Circle2(int r)
{
    radius = r;
    cout << "radius is " << radius << " and made circle" << endl;
}

// 면적 계산 멤버 함수 정의
double Circle2::getArea()
{
    return 3.14 * radius * radius;
}

int ex0930_1()
{
    Circle2 donut; // 기본 생성자 호출 (1)   (4)소멸자 실행
    double area = donut.getArea();
    cout << "donut area is " << area << endl;

    Circle2 pizza(30); // (2)      (3)소멸자 실행
    area = pizza.getArea();
    cout << "pizza area is " << area << endl;

    return 0;
}

void func0930()
{
    Circle2 donut; //(1) donut이 생성된다.
    double area = donut.getArea();
    cout << "donut area is " << area << endl;
} //(2) 이 함수를 나올면서 donut이 소멸된다.

int ex0930_2()
{
    func0930();

    Circle2 pizza(30); // (3) 피자가 생성된다.
    double area = pizza.getArea();
    cout << "pizza area is " << area << endl;

    return 0;

} // (4) 피자가 소멸된다.

/*실습 5-1*/
class Rectangle3
{
public:
    int width;
    int height;

    Rectangle3()
    {
        width = 1;
        height = 1;
    }
    Rectangle3(int width_in, int height_in)
    {
        width = width_in; // this ->width = width
        height = height_in;
    }

    Rectangle3(int length)
    {
        width = height = length;
    }
    ~Rectangle3()
    {

        cout << "Rectangle is deleted " << width << " " << height << endl;
    }
    bool isSquare();
};

bool Rectangle3::isSquare()
{
    if (width == height)
        return true; // return true
    else
        return false; // return false
}

int ex0930_3()
{
    Rectangle3 rect1;
    Rectangle3 rect2(3, 5);
    Rectangle3 rect3(3);

    if (rect1.isSquare())
        cout << "rect1 is square" << endl;
    if (rect2.isSquare())
        cout << "rect2 is square" << endl;
    if (rect3.isSquare())
        cout << "rect3 is square" << endl;
}

class Oval
{

public:
    // 변수 width, height
    int width, height;

    // 디폴트생성자: Oval()
    Oval()
    {
        width = 1;
        height = 1;
    }
    // 매개변수 2개짜리 생성자: Oval(int w, int h)
    Oval(int w, int h)
    {
        width = w;
        height = h;
    }

    // 함수 set(), show(),
    void set(int w, int h)
    {
        width = w;
        height = h;
    }

    void show()
    {
        cout << "width = " << width << ", height = " << height << endl;
    }

    // getWidth(), getHeight(), getArea()
    int getWidth()
    {
        return width;
    }
    int getHeight()
    {
        return height;
    }

    // 소멸자 : ~Oval()
    ~Oval()
    {
        cout << "terminate Oval : width = " << width << ", height = " << height << endl;
    }

    double getArea(); // getArea 함수 선언
};

double Oval::getArea()
{
    return 3.14 * width * height;
}

int ex0930_4()
{
    Oval a, b(3, 4);
    a.set(10, 20);
    a.show();
    cout << b.getWidth() << ", " << b.getHeight() << endl;
}

inline bool isEven(int B)
{
    if (B % 2 == 0)
        return true;
    else
        return false;
}

int ex0930_5()
{
    int A = 10;
    if (isEven(A)) // if(isEven(A)==true)
        cout << "짝수입니다." << endl;
    else
        cout << "홀수입니다." << endl;
}

// /* */
// #include "cal.h" // Calculator 클래스 선언 포함

// int ex1007_1()
// {
//     Calculator calc; // Calculator 객체 생성
//     // calc.run(); // run() 함수 호출
//     return 0;
// }

/*메모리 읽기 쓰기*/
class Ram
{
    char mem[100 * 1024]; // 100KB 메모리
    int size;

public:
    Ram();                               // mem을 0으로 초기화하고 size를 100 * 1024로 초기화
    ~Ram();                              // 메모리 해제 시 문자열 출력
    char read(int address);              // address에 해당하는 메모리의 값을 반환
    void write(int address, char value); // address에 해당하는 메모리에 value를 씀
};

Ram::Ram()
{
    for (int i = 0; i < 100 * 1024; i++)
    {
        mem[i] = 0;
    }
    size = 100 * 1024; // 클래스의 멤버 변수 size를 초기화
}

Ram::~Ram()
{
    cout << "Memory released!!" << endl;
}

char Ram::read(int address)
{
    if (address < 0 || address >= size)
    {
        cout << "Error: Address out of bounds" << endl;
        return 0; // 잘못된 주소에 접근하면 0을 반환
    }
    return mem[address];
}

void Ram::write(int address, char value)
{
    if (address < 0 || address >= size)
    {
        cout << "Error: Address out of bounds" << endl;
        return; // 잘못된 주소에 접근하려고 할 경우 처리
    }
    mem[address] = value;
}

int ex1007_2()
{
    Ram ram;

    // 메모리 쓰기 예시
    ram.write(1024, 'A');       // 1024번지에 'A' 저장
    ram.write(100 * 1024, 'B'); // 잘못된 주소, 오류 메시지 출력

    // 메모리 읽기 예시
    cout << "Value at 1024: " << ram.read(1024) << endl;
    cout << "Value at 100*1024: " << ram.read(100 * 1024) << endl; // 잘못된 주소, 오류 메시지 출력

    return 0;
}

int ex1007_3()
{
    const int A = 100;
    // A = 200; //컴파일 에러. const 변수는 값을 변경할 수 없다.
}

class PERSON33
{
public:
    double money; // 개인 소유의 돈
    void addMoney(int money_in)
    {
        money += money_in;
    }
    PERSON33()
    {
        money = 0;
    }
    static int sharedMoney; // 공유돈
    static void addShared(int n)
    {
        sharedMoney += n;
    }
};

// static 변수 생성. 전역 공간에 생성
int PERSON33::sharedMoney = 10; // 10으로 초기화

int ex1007_4()
{

    PERSON33 han;
    han.money = 100;       // han의 개인 돈 =100
    han.sharedMoney = 200; // static멤버 접근, 공급 =200
    PERSON33 lee;
    lee.money;         // lee의 개인동 =350
    lee.addMoney(200); // static멤버 접근, 공금 =400
    lee.addShared(300);
    cout << han.money << " " << han.sharedMoney << endl;
    cout << lee.money << " " << lee.sharedMoney << endl;
}

class MyMath
{
public:
    static int abs(int a) { return a > 0 ? a : -a; }
    static int max(int a, int b) { return a > b ? a : b; }
    static int min(int a, int b) { return a < b ? a : b; }
};

int ex1010_1()
{
    // 객체를 안 만들고 static 함수를 호출
    cout << MyMath::abs(-5) << endl;
    cout << MyMath::max(10, 8) << endl;
    cout << MyMath::min(-3, -8) << endl;

    return 0;
}

class PERSON332
{
public:
    int money;
    string name;

    PERSON332() { money = 0; }
    PERSON332(string name_in)
    {
        money = 0;
        name = name_in;
    }
    ~PERSON332()
    {
        cout << name << "의 money는" << money << endl;
    }

    void addMoney(int money_in)
    {
        money += money_in;
    }

    static int sharedMoney;
    static int addShared(int money_in)
    {
        sharedMoney += money_in;
    }
};

int PERSON332::sharedMoney = 0;

int ex1010_2()
{
    PERSON332 A("KANG"), B("KIM");
    // 3월
    A.addMoney(100);
    A.addShared(5);
    B.addMoney(200);
    B.addShared(5);

    // 4월
    A.addMoney(100);
    A.addShared(5);
    B.addMoney(200);
    B.addShared(5);
    cout << "공금" << PERSON332::sharedMoney << endl;
    cout << "공금" << PERSON332::sharedMoney << endl;
}

/*객체 포인터*/
int ex1010_3()
{
    PERSON332 A("KANG"); // 객체 생성
    A.addMoney(100);     // 100원 추가
    A.addShared(5);      // 공금 5원 추가

    // p:주소
    // &A : A의 주소
    // A: 객체
    // *p : 객체 (p가 가리키도 있는 객체)

    PERSON332 *p = &A; // 포인터 p에 A의 주소를 저장

    cout << A.money << ' ' << (*p).money << ' ' << p->money << endl; // 100 100 100
}

// int ex1010_4()
// {
//     Circle3 circleArray[3]; // Circle3 객체 배열 생성
//     // Circle3 circleArray[0], circleArray[1], circleArray[2]; //각자 하나의 객체이다.
//     circleArray[1].radius = 50;
//     circleArray[2].radius = 70;

//     Circle3 *p = &circleArray[1];
//     cout << (*p).radius << ' ' << p->radius << endl; // 50 50

//     // 객체 배열 초기화 방법
//     Circle2 carray[3] = {Circle2(10), Circle2(20), Circle2(30)};
//     Circle2 *q;
//     q = carray;
//     cout << carray[0].radius << ' ' << q[0].radius << endl;

//     q = &carray[1];
//     cout << (*(q + 1)).radius << endl;
//     cout << q[-1].radius << " " << q[0].radius << " " << q[1].radius << endl;

//     // color colors[3];
//     // Color* p =colors;
//     // colors[1], colors[2], colors[3]
// }

class Color
{
    int red, green, blue;

public:
    Color() { red = green = blue = 0; }
    Color(int r, int g, int b)
    {
        red = r;
        green = g;
        blue = b;
    }
    void setColor(int r, int g, int b)
    {
        red = r;
        green = g;
        blue = b;
    }
    void show() { cout << red << ' ' << green << ' ' << blue << endl; }
};

int ex1014_1()
{
    Color screenColor(255, 0, 0); // 빨간색 객체 생성
    Color *p;                     // Color 포인터 p 선언
    p = &screenColor;             // (1) p가 screenColor주소를 가지도록 코드 작성.

    (*p).show(); // (2) p와 show()를 이용하려 screenClor 색을 출력한다.
    // p->show();  이렇게 표현할 수 있다.

    Color colors[3]; // (3) Color의 일차원 배열 colors선언. 원소는 3개
    p = colors;      // (4) p가 colors배열을 가리키도록 코드 작성

    colors[0].setColor(255, 0, 0); // (5) colors[0]의 색을 빨간색으로 설정.
    // 빨강: p[2] => *(p+2)

    colors[1].setColor(0, 255, 0); // (6) colors[1]의 색을 초록색으로 설정
    colors[2].setColor(0, 0, 255); // (7) colors[2]의 색을 파란색으로 설정

    //(6) p와 show()를 이용하여 colors배열의 모든 객체의 색을 출력한다.
    for (int i = 0; i < 3; i++)
    {
        p[i].show();
    }
    /*
        colors[0].show();
        colors[1].show();
        colors[2].show();
    */
    return 0;
}

// int ex1014_2(int number)
int ex1014_2()
{

    int A[5]; // <---컴파일러가 자동으로 메모리 할당
    // int A[number]; //배열안에 변수를 넣을 수 없다.
    A[0] = 100;
    A[1] = 200;
    A[2] = 300;
    A[3] = 400;
    A[4] = 500;

    // A=100; //변경 불가! 배열은 주소를 가지고 있기 때문에 주소에 값을 넣을 수 없다.

    for (int n = 0; n < 5; n++)
    {
        printf("%d \n", A[n], *(A + n));
    }
    // delete[] A; // <---- 메모리 해제
}

int ex1014_3(int number)
{

    int *A = (int *)malloc(number * sizeof(int)); // <----- 개발자가 동적할당
    A[0] = 100;
    A[1] = 200;
    A[2] = 300;
    A[3] = 400;
    A[4] = 500;

    for (int n = 0; n < 5; n++)
    {
        printf("%d \n", A[n], *(A + n));
    }

    free(A); // <---- 메모리 해제
}

int ex1014_4(int number)
{

    int *A = new int[number]; // <----- 개발자가 동적할당
    A[0] = 100;
    A[1] = 200;
    A[2] = 300;
    A[3] = 400;
    A[4] = 500;

    for (int n = 0; n < 5; n++)
    {
        printf("%d \n", A[n], *(A + n));
    }

    delete[] A; // <---- 메모리 해제
}

int ex1014_5(void)
{

    ex1014_2();
    ex1014_3(5);
    ex1014_4(5);

    // p[i]==*(p+i) 이다. 이표현은 외워두자!!

    return 0;
}

class Circle3
{
    int radius;

public:
    Circle3();
    Circle3(int r);
    ~Circle3();
    void setRadius(int r) { radius = r; }
    double getArea() { return 3.14 * radius * radius; }
};

Circle3::Circle3()
{
    radius = 1;
    cout << "생성자 실행 radius = " << radius << endl;
}

Circle3::Circle3(int r)
{
    radius = r;
    cout << "생성자 실행 radius = " << radius << endl;
}

Circle3::~Circle3()
{
    cout << "소멸자 실행 radius = " << radius << endl;
}

int ex1014_6()
{
    Circle3 *p;
    Circle3 *q;
    p = new Circle3;
    q = new Circle3(10);

    cout << (*p).getArea() << endl;
    // cout<<p->getArea()<<endl; (*p).getArea()와 동일
    cout << (*q).getArea() << endl;
    // cout<<q->getArea()<<endl; (*q).getArea()와 동일

    delete p;
    delete q;

    return 0;
}

int ex1014_7()
{
    Circle3 *p = new Circle3[3];

    cout << p[0].getArea() << endl;
    cout << p[1].getArea() << endl;
    cout << p[2].getArea() << endl;

    Circle3 *q = p;
    cout << q[0].getArea() << endl;
    cout << q[1].getArea() << endl;
    cout << q[2].getArea() << endl;

    cout << "----------------------\n";
    cout << (*(q + 0)).getArea() << endl; //(q+0)->
    cout << (*(q + 1)).getArea() << endl; //(q+1)->
    cout << (*(q + 2)).getArea() << endl; //(q+2)->

    delete[] p;

    return 0;
}

/* 실습 7-3 */
class PERSON3
{
    std::string name; // string을 std::string으로 변경

public:
    PERSON3() { name = ""; }
    PERSON3(std::string name) { this->name = name; }
    std::string getName() { return name; }                // return 타입도 std::string으로 변경
    void setName(std::string name) { this->name = name; } // 인자 타입도 std::string으로 변경
};

class Family
{
    std::string name; // string을 std::string으로 변경
    PERSON3 *p;       // PERSON3 배열 포인터
    int size;         // PERSON3 배열의 크기. 가족 구성원 수

public:
    Family(std::string name_in, int size_in);  // 생성자 인자의 string도 std::string으로 변경
    void setName(int index, std::string name); // 인자 타입도 std::string으로 변경
    void show();                               // 모든 가족 구성원 출력
    ~Family();
};

Family::Family(std::string name_in, int size_in)
{
    name = name_in;
    size = size_in;
    p = new PERSON3[size]; // size 개수만큼 PERSON3 배열 동적 생성
}

void Family::setName(int index, std::string name)
{
    p[index].setName(name); // PERSON3 객체의 setName 호출
}

void Family::show()
{
    cout << name << " family is consist of " << size << " members" << endl;
    for (int n = 0; n < size; n++)
        cout << p[n].getName() << endl; // getName 호출 후 출력
}

Family::~Family()
{
    cout << name << " family is deleted" << endl;
    delete[] p; // 동적 할당한 PERSON3 배열 메모리 해제
}

int ex1017_1()
{
    Family simpson("Simpson", 3); // 3명으로 구성된 Simpson 가족
    simpson.setName(0, "Mr. Simpson");
    simpson.setName(1, "Mrs. Simpson");
    simpson.setName(2, "Bart Simpson");
    simpson.show();

    return 0;
}

class A
{
public:
    int value; // A 클래스의 value 변수
};

class B
{
public:
    A sub;       // A 클래스 객체를 포함하는 sub 변수
    int counter; // B 클래스의 counter 변수
};

int ex1028_1()
{
    B abc;

    abc.sub.value = 100; // A 클래스의 value 변수에 값 할당
    abc.counter = 200;   // B 클래스의 counter 변수에 값 할당

    cout << "abc.sub.value = " << abc.sub.value << endl; // 출력: 100
    cout << "abc.counter = " << abc.counter << endl;     // 출력: 200

    // 동적 메모리 할당
    int *p = new int; // int 타입 메모리 공간 동적 할당
    *p = 50;          // 할당된 메모리에 값 할당

    cout << "*p = " << *p << endl; // 출력: 50

    // 동적 할당된 메모리 해제
    delete p; // 할당된 메모리 반환

    return 0; // 프로그램 정상 종료
}

class Circle5
{
private:
    int radius;

public:
    Circle5();
    Circle5(int r);
    ~Circle5();
    double getArea() { return 3.14 * radius * radius; }
    int getRadius() { return radius; }
    void setRadius(int radius) { this->radius = radius; }
};

Circle5::Circle5()
{
    radius = 1;
    cout << "Constructor radius = " << radius << endl;
}

Circle5::Circle5(int radius)
{
    this->radius = radius;
    cout << "Constructor radius = " << radius << endl;
}

Circle5::~Circle5()
{
    cout << "Destructor radius = " << radius << endl;
}

void increase(Circle5 c)
{
    int r = c.getRadius();
    c.setRadius(r + 1);
}

/*이름이 같지만 매개변수의 타입 다르다.*/
void increase(Circle5 *c)
{
    int r = (*c).getRadius();
    (*c).setRadius(r + 1);
}

int ex1028_2()
{
    Circle5 waffle(30);
    increase(&waffle);
    return 0;
}

/*실습 8-1*/
// C는 A의 또 다른 이름이다.
// 객체를 새로 만드는것이 아니다.
void Swap(Circle5 &C, Circle5 &D)
{
    Circle5 tmp = C;
    C = D;
    D = tmp;
}

void ex1028_3()
{
    Circle5 A(30), B(10);
    Swap(A, B);
    cout << "A: " << A.getRadius() << endl;
    cout << "B: " << B.getRadius() << endl;
}

// 실습 8-2
void readRadius(Circle5 &cir)
{
    cout << "정수 값으로 반지름을 입력하세요 >> ";
    int tmp;
    cin >> tmp;
    cir.setRadius(tmp);
}

void ex1028_5()
{
    Circle5 donut;
    readRadius(donut);
    cout << "donut의 면적 = " << donut.getArea() << endl;
}

void ex1031_1()
{ // 얕은 복사
    int *A = new int[10];
    int *B;

    for (int i = 0; i < 10; i++)
    {
        A[i] = i * 10;
    }

    B = A; // 얕은 복사, 메모리 주소를 공유

    delete[] A;
}

void ex1031_2()
{ // 깊은 복사
    int *A = new int[10];
    int *B;

    for (int i = 0; i < 10; i++)
    {
        A[i] = i * 10;
    }

    B = new int[10]; // 깊은 복사
    for (int i = 0; i < 10; i++)
    {
        B[i] = A[i]; // 주소 값에 있는 내용물을 직접 복사해줌
    }

    delete[] A;
}

// 실습 8-3
class Accumulator
{
    int value;

public:
    Accumulator(int value);  // 매개변수 value로 멤버 value를 초기화한다.
    Accumulator &add(int n); // value에 n을 더해 값을 누적한다.
    int get();               // 누적된 값 value를 리턴한다.
};

Accumulator::Accumulator(int value)
{
    this->value = value;
}

Accumulator &Accumulator::add(int n)
{
    this->value += n;
    return *this;
}

int Accumulator::get()
{
    return this->value;
}

void ex1031_3()
{
    Accumulator acc(10);
    acc.add(5).add(6).add(7);  // acc의 value 멤버가 28이 된다.
    cout << acc.get() << endl; // 28 출력
}

// 실습 8-4 포인터를 이용한 복사 생성자
class Book
{
    char *title; // 제목 문자열
    int price;   // 가격
public:
    Book(char *title, int price); // 그냥 자
    Book(Book &obj);              // 복사 생성자
    ~Book();
    void operator+=(int value)
    {
        this->price = price + value;
    }
    void operator-=(int value)
    {
        this->price = price + value;
    }

    bool operator==(int price)
    {
        return this->price == price;
    }

    void set(char *title, int price);
    void show() { cout << title << ' ' << price << "원" << endl; }
};

Book::Book(char *title, int price)
{
    // 클래스 멤버 명이랑 함수 내 지역변수명이랑 같을때 this 포인터 사용
    // this->title = title;
    // this->price = price;
    // 클래스 멤버   지역변수
    // 근데 이리하는게 바람직하지 않다고...

    int length = strlen(title);
    this->title = new char[length + 1];
    this->price = price;
    strcpy(this->title, title);
}
Book::Book(Book &obj)
{
    this->price = obj.price;
    int length = strlen(obj.title);
    this->title = new char[length + 1];
    strcpy(this->title, obj.title);
}
Book::~Book()
{
    delete[] this->title;
    cout << "소멸자" << endl;
}
void Book::set(char *title, int price)
{
    delete[] this->title;
    int length = strlen(title);
    this->title = new char[length + 1];
    strcpy(this->title, title);
    this->price = price;
}
void ex1031_4()
{
    // Book cpp("명품C++", 10000); // 글자는 고정된 값이기에(상수라 생각하면 됨), 함수쪽이랑
    Book cpp((char *)"명품C++", 10000);
    Book java = cpp;
    java.set((char *)"명품자바", 12000);
    cpp.show();
    java.show();
}

/*실습 8-5*/
class Book2
{
    char title[100]; // 제목 문자열
    int price;       // 가격
public:
    Book2(char *title, int price); // 그냥 자
    ~Book2();
    void set(char *title, int price);
    void show() { cout << title << ' ' << price << "원" << endl; }
};

Book2::Book2(char *title, int price)
{
    strcpy(this->title, title);
    this->price = price;
}

Book2::~Book2()
{
    cout << "소멸자" << endl;
}
void Book2::set(char *title, int price)
{
    strcpy(this->title, title);
    this->price = price;
}
int ex1104_1()
{
    // Book cpp("명품C++", 10000); // 글자는 고정된 값이기에(상수라 생각하면 됨), 함수쪽이랑
    Book cpp((char *)"명품C++", 10000);
    Book java = cpp;
    java.set((char *)"명품자바", 12000);
    cpp.show();
    java.show();
    return 0;
}

// 9장: 복소수 , friend
class Rect
{
    int width, height;

public:
    Rect(int width, int height)
    {
        this->width = width;
        this->height = height;
    }
    bool equals(Rect r);
};
bool Rect::equals(Rect r)
{
    if (this->width == r.width && this->height == r.height)
        return true;
    else
        return false;
}

int ex1104_2(void)
{
    Rect a(3, 4), b(4, 5);
    if (a.equals(b)) // equals(a,b)
        cout << "height는equal" << endl;
    else
        cout << "not equal" << endl;

    return 0;
}

class Rect2
{
    int width, height;

public:
    Rect2(int width, int height)
    {
        this->width = width;
        this->height = height;
    }
    friend bool equals(Rect2 a, Rect2 b); // friend 선언함으로서 접근 가능
};

bool equals(Rect2 a, Rect2 b)
{
    // width,  private이기 때문에 접근 불가
    if (a.width == b.width && a.height == b.height)
        return true;
    else
        return false;
}

int ex1104_3()
{
    Rect2 a(2, 3), b(3, 4);
    if (equals(a, b))
        cout << "equal" << endl;
    else
        cout << "not equal" << endl;

    return 0;
}

/*연산자 중복*/
class Power
{
    int kick;
    int punch;

public:
    // 생성자 정의
    Power(int kick = 0, int punch = 0)
    {
        this->kick = kick;
        this->punch = punch;
    }

    // + 연산자 오버로딩
    Power operator+(Power input)
    {
        Power tmp;
        tmp.kick = this->kick + input.kick;
        tmp.punch = this->punch + input.punch;
        return tmp;
    }

    // - 연산자 오버로딩
    Power operator-(Power input)
    {
        Power tmp;
        tmp.kick = this->kick - input.kick;
        tmp.punch = this->punch - input.punch;
        return tmp;
    }

    // == 연산자 오버로딩
    bool operator==(Power input)
    {
        return (this->kick == input.kick && this->punch == input.punch);
    }

    // 객체의 속성 출력 함수
    void show()
    {
        cout << "kick = " << kick << ", punch = " << punch << endl;
    }
};

#define PI (4.0 * atan(1.0)) // 3.1415926535

#include <iostream>
#include <cmath>

using namespace std;

class complex
{
    float re;
    float im;

public:
    // 생성자
    complex(float re = 0, float im = 0) : re(re), im(im) {}

    // operator+
    complex operator+(complex input)
    {
        return complex(this->re + input.re, this->im + input.im);
    }

    // operator-
    complex operator-(complex input)
    {
        return complex(this->re - input.re, this->im - input.im);
    }

    // operator*
    complex operator*(complex input)
    {
        double mag = getMag() * input.getMag();
        double angle = getAngle() + input.getAngle();
        return convert2Cart(mag, angle);
    }

    // operator/
    complex operator/(complex input)
    {
        double mag = getMag() / input.getMag();
        double angle = getAngle() - input.getAngle();
        return convert2Cart(mag, angle);
    }

    // 출력 함수
    void show()
    {
        cout.precision(5);
        if (im >= 0)
            cout << re << "+j" << im << endl;
        else
            cout << re << "-j" << -im << endl;
    }

    // 크기 계산
    double getMag() const
    {
        return sqrt(re * re + im * im);
    }

    // 각도 계산
    double getAngle() const
    {
        if (re == 0 && im == 0)
            return 0.0;
        else if (re == 0 && im > 0)
            return PI / 2.0;
        else if (re == 0 && im < 0)
            return -PI / 2.0;
        else
            return atan(im / re);
    }

    // 극좌표를 직교좌표로 변환
    complex convert2Cart(double mag, double ang) const
    {
        return complex(mag * cos(ang), mag * sin(ang));
    }
};

int ex1107_1()
{
    complex a(2, 3), b(4, 5), c, d, e, f;
    c = a + b;
    d = a - b;
    e = a * b;
    f = a / b;
    c.show();
    d.show();
    e.show();
    f.show();

    return 0;
}

/*실습 9-1
class Book {
    char* title; // 제목 문자열
    int price; // 가격
public:
    Book(char* title, int price); // 그냥 자
    Book(Book& obj); // 복사 생성자
    ~Book();
    void operator+=(int value){
        this->price = price +value;

    }
    void operator-=(int value){
        this->price = price +value;
    }

    void set(char* title, int price);
    void show() { cout << title << ' ' << price << "원" << endl; }
};

Book::Book(char* title, int price) {
    // 클래스 멤버 명이랑 함수 내 지역변수명이랑 같을때 this 포인터 사용
    //this->title = title;
    //this->price = price;
    // 클래스 멤버   지역변수
    // 근데 이리하는게 바람직하지 않다고...

    int length = strlen(title);
    this->title = new char[length+1];
    this->price = price;
    strcpy(this->title, title);

}
Book::Book(Book& obj) {
    this->price = obj.price;
    int length = strlen(obj.title);
    this->title = new char[length + 1];
    strcpy(this->title, obj.title);
}
Book::~Book() {
    delete[] this->title;
    cout << "소멸자" << endl;
}
void Book::set(char* title, int price) {
    delete[] this->title;
    int length = strlen(title);
    this->title = new char[length+1];
    strcpy(this->title, title);
    this->price = price;
}
*/

int ex1107_2()
{
    Book a((char *)"About APPle", 20000), b((char *)"What is justice?", 30000);

    a += 5000; // a.operator+=(int value)
    b -= 5000; //
    a.show();
    b.show();

    return 0;
}

#include <iostream>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

/*11월7일자 코드.*/

class Power2
{
    int kick;
    int punch;

public:
    // 생성자 정의
    Power2(int kick = 0, int punch = 0)
    {
        this->kick = kick;
        this->punch = punch;
    }

    void show()
    {
        cout << "kick=" << kick << ", punch=" << punch << endl;
    }

    // operator+와 operator-를 friend로 선언하여 접근 가능하게 함
    friend Power2 operator+(Power2 A, Power2 B);
    friend Power2 operator-(Power2 A, Power2 B);
};

// 외부 함수
Power2 operator+(Power2 A, Power2 B)
{
    Power2 tmp;
    tmp.kick = A.kick + B.kick;
    tmp.punch = A.punch + B.punch;
    return tmp;
}

Power2 operator-(Power2 A, Power2 B)
{
    Power2 tmp;
    tmp.kick = A.kick - B.kick;
    tmp.punch = A.punch - B.punch;
    return tmp;
}

int ex1107_3()
{
    Power2 a(3, 5), b(4, 6), c, d;
    c = a + b; // 파워 객체 + 연산
    d = a - b; // 파워 객체 - 연산
    a.show();
    b.show();
    c.show();
    d.show();
    return 0;
}

/*11월11일자 코드. (공결)*/

// 실습 9-3 -> operator와 friend의 사용
class Book5
{
    char *title; // 제목 문자열
    int price;   // 가격
public:
    Book5(char *title, int price); // 일반 생성자
    Book5(Book5 &obj);             // 복사 생성자
    ~Book5();
    void operator+=(int value) { this->price += value; }
    void operator-=(int value) { this->price -= value; }
    bool operator!()
    {
        if (this->price == 0)
            return false;
        else
            return true;
    }
    void set(char *title, int price);
    void show() { cout << title << ' ' << price << "원" << endl; }

    // == 연산자를 friend 함수로 선언
    friend bool operator==(const Book5 &book, int price);
};

// 외부에서 정의된 == 연산자
bool operator==(const Book5 &book, int price)
{
    return book.price == price;
}

Book5::Book5(char *title, int price)
{
    // 클래스 멤버 변수와 함수 내 지역변수라서 구분을 this 포인터 사용
    int length = strlen(title);
    this->title = new char[length + 1];
    this->price = price;
    strcpy(this->title, title);
}

Book5::Book5(Book5 &obj)
{
    this->price = obj.price;
    int length = strlen(obj.title);
    this->title = new char[length + 1];
    strcpy(this->title, obj.title);
}

Book5::~Book5()
{
    delete[] this->title;
    cout << "소멸자" << endl;
}

void Book5::set(char *title, int price)
{
    delete[] this->title;
    int length = strlen(title);
    this->title = new char[length + 1];
    strcpy(this->title, title);
    this->price = price;
}

int ex1107_4()
{
    Book5 a((char *)"About Apple", 20000), b((char *)"What is justice?", 30000);

    if (a == 30000) // friend operator== 호출
        cout << "정가 30000원" << endl;
    else
        cout << "30000원 아니다" << endl;

    return 0;
}

/*
상속 문법은

class 파생클래스이름 : 접근지정자 기본클래스이름
{
};
*/

// 2차원 평면에서 한 점을 표현하는 클래스 Point 선언
class Point
{
    int x, y; // 한 점 (x,y) 좌표값
public:
    void set(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    void showPoint()
    {
        cout << "(" << x << "," << y << ")" << endl;
    }
};

// 2차원 평면에서 컬러점을 표현하는 클래스 ColorPoint. Point를 상속받음
class ColorPoint : public Point
{                 // 컬러 하나 추가하기
    string color; // 점의 색 표현
public:
    void setColor(string color)
    {
        this->color = color;
    }
    void showColorPoint()
    {
        cout << color << ":";
        showPoint(); // Point의 showPoint() 호출
    }
};

// 교재 자료 10-1 p.7
void ex1111_3()
{                        // 업 캐스팅
    Point p;             // 기본 클래스의 객체 생성
    ColorPoint cp;       // 파생 클래스의 객체 생성
    cp.set(3, 4);        // 기본 클래스의 멤버 호출
    cp.setColor("Red");  // 파생 클래스의 멤버 호출
    cp.showColorPoint(); // 파생 클래스의 멤버 호출

    ColorPoint *pDer = &cp;
    pDer->set(30, 40);
    // (*pDer).set(30, 40)이나 cp.set(30, 40) 이랑 동일결과
    pDer->setColor("Blue");
    pDer->showColorPoint();

    Point *pBase = (Point *)pDer;
    pBase->set(300, 400);
    pDer->showColorPoint();
}

void ex1111_4()
{ // 다운 캐스팅 : 부모의 주소 -> 자식의 주소
    ColorPoint cp;
    ColorPoint *pDer;
    Point *pBase = &cp; // 업캐스팅

    pBase->set(3, 4);
    pBase->showPoint();

    pDer = (ColorPoint *)pBase; // 다운캐스팅
    pDer->set(30, 40);
    pDer->setColor("Blue");
    pDer->showColorPoint();
    pDer->showPoint();
}

// 실습 10-1
class Circle6
{
private:
    int radius;

public:
    Circle6() { radius = 1; }
    Circle6(int radius) { this->radius = radius; }
    double getArea() { return 3.14 * radius * radius; }
    int getRadius() { return radius; }
    // private이라 접근이 안되기에 함수로 값을 가져오기
    void setRadius(int radius) { this->radius = radius; }
};

class NamedCircle6 : public Circle6
{
    string name;

public:
    NamedCircle6()
    {
        setRadius(0);
        name = "default";
    }
    NamedCircle6(int radius, string name)
    {
        setRadius(radius);
        this->name = name;
    }
    void show()
    {
        cout << "반지름이 " << getRadius() << "인 " << name << endl;
        // radius는 부모 클래스의 private
    }

    string getName() { return name; }

    friend void FindLargestNamedCircle6(NamedCircle6 *namedcircle, int size);
};

void ex1111_5()
{
    NamedCircle6 waffle(3, "waffle"); // 반지름이 3이고 이름이 waffle인 원
    waffle.show();
}

// 실습 10-2
void FindLargestNamedCircle6(NamedCircle6 *namedcircle, int size)
{
    int r_max = namedcircle[0].getRadius(); // namecircle -> namedcircle로 수정
    int index_max = 0;

    for (int i = 1; i < size; i++)
    { // size-1 -> size로 수정
        if (namedcircle[i].getRadius() > r_max)
        { // < 를 >로 수정 (가장 큰 것을 찾아야 함)
            r_max = namedcircle[i].getRadius();
            index_max = i; // n -> i로 수정
        }
    }
    //
    cout << "가장 큰 피자는 반지름이 " << r_max << "인 " << namedcircle[index_max].getName() << " 입니다." << endl;

    /*friend를 선언한다면! */
    // friend 함수이므로 private 멤버 name에 직접 접근 가능
    cout << "가장 큰 피자는 반지름이 " << r_max << "인 " << namedcircle[index_max].name << " 입니다." << endl;
}

int ex1114_1()
{
    NamedCircle6 pizza[5];
    cout << "5개의 정수 반지름과 원의 이름을 입력하세요." << endl;
    for (int i = 0; i < 5; i++)
    {
        int radius;
        string name;
        cin >> radius >> name;
        pizza[i] = NamedCircle6(radius, name);
    }
    FindLargestNamedCircle6(pizza, 5);

    return 0;
}

class BaseArray
{
private:
    int capacity; // 동적 할당된 메모리 용량
    int *mem;     // 정수 배열을 만들기 위한 메모리 //int meme[100]

protected: // 부모가 자식을 위해 만들어놓음. 외부는 접근 불가, 자식은 접근 가능
    void put(int index, int val) { mem[index] = val; }
    int get(int index) { return mem[index]; }
    int getCapacity() { return capacity; }
    void MakeQueue(int capacity)
    {
        this->capacity = capacity;
        mem = new int[capacity];
    }

public:
    BaseArray(int capacity = 100)
    {
        this->capacity = capacity;
        mem = new int[capacity];
    }
    ~BaseArray() { delete[] mem; }
};

class MyQueue : public BaseArray
{
    int index;

public:
    MyQueue(int cap)
    {
        MakeQueue(cap);
        index = 0; // 초기화해줘야함
    }
    void enqueue(int n)
    {
        put(index, n);
        index++; // 인덱스를 하나 증가시킨다.
    }
    int capacity() { return getCapacity(); } // 용량 리턴!!

    int length()
    {
        return index;
    }

    int dequeue()
    {
        int value = get(0); //(1)
        index--;            //(2)
        for (int i = 0; i < index; i++)
        { //(3)
            // mem[i] = mem[i+1];
            put(i, get(i + 1));
        }
        return value;
    }
};

int main(void)
{
    MyQueue mQ(100);
    int n;

    cout << "enter 5 integer to put into queue>> ";
    for (int i = 0; i < 5; i++)
    {
        cin >> n;
        mQ.enqueue(n); // 수정된 부분: 입력받은 n을 큐에 삽입
        // mQ.enqueue(i*10); // 큐에 삽입
    }

    cout << "queue's capacity:  " << mQ.capacity() << "  queue's size : " << mQ.length() << endl;

    cout << "delete queue's content, and print it" << endl; // 큐의 내용을 삭제하고 출력
    while (mQ.length() != 0)
    {                                // 큐가 빌 때까지
        cout << mQ.dequeue() << ' '; // dequeue하여 출력
    }
    cout << endl;

    return 0;
}