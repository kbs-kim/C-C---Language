
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