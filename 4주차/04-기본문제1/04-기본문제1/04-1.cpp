#include <iostream>
using namespace std;

struct Info {
    int max;
    int min;
    int sum;
    bool isInitialized; // True, False만 저장하는 자료형
};

Info getMergedInfo(Info& a, Info& b); // 함수 선언

int main() {

    int n;
    int m;

    cin >> n >> m;

    Info info[100]; // 2 <= n <= 100

    for (int i = 0; i < n; i++) { // 배열 전부 False 만들기
        info[i].isInitialized = false;
    }


    for (int i = 0; i < m; i++) {
        char command;
        cin >> command;


        if (command == 'A') {
            int idx;
            int a, b, c;

            cin >> idx >> a >> b >> c;

            Info newInfo;

            newInfo.max = a;
            newInfo.min = b;
            newInfo.sum = c;
            newInfo.isInitialized = true;


            if (info[idx - 1].isInitialized == false) {
                info[idx - 1] = newInfo;
            }

            else {
                info[idx - 1] = getMergedInfo(info[idx - 1], newInfo);
            }

        }


        else if (command == 'P') {
            int idx;
            cin >> idx;

            if (info[idx - 1].isInitialized == false) {
                cout << "error" << endl;
            }
            else {
                cout << info[idx - 1].max << " " // 한줄로 안 쓰고 여러 줄로 나눠써도 괜찮음
                    << info[idx - 1].min << " "
                    << info[idx - 1].sum << endl;
            }
        }


        else if (command == 'Q') {
            Info total;
            total.isInitialized = false; // 임시 뭉탱이 만들기

            for (int j = 0; j < n; j++) { // 0부터 n-1까지 확인
                if (info[j].isInitialized == true) {  // 뭉탱이가 비어있는 경우 무시
                    if (total.isInitialized == false) {
                        total = info[j];
                    }
                    else {
                        total = getMergedInfo(total, info[j]);
                    }
                }
            }


            if (total.isInitialized == false) {
                cout << "error" << endl;
            }
            else {
                cout << total.max << " "
                    << total.min << " "
                    << total.sum << endl;
            }

        }

    }

    return 0;
}



Info getMergedInfo(Info& a, Info& b) {

    Info result;

    if (a.max >= b.max) {
        result.max = a.max;
    }

    else {
        result.max = b.max;
    }


    if (a.min <= b.min) {
        result.min = a.min;
    }

    else {
        result.min = b.min;
    }


    result.sum = a.sum + b.sum;

    result.isInitialized = true;

    return result;
}

/* GPT 코드
Info getMergedInfo(Info& a, Info& b) {
    Info result;

    result.max = (a.max > b.max) ? a.max : b.max;
    result.min = (a.min < b.min) ? a.min : b.min;
    result.sum = a.sum + b.sum;
    result.isInitialized = true;

    return result;
}
*/

// ( ) ? : 삼항 연산자.
// (조건) ? 참일 떄 값 : 거짓일 때 값
