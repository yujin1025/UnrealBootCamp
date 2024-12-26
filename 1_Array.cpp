#include <iostream>
using namespace std;

// 배열 원소들의 합을 계산하는 함수
int CalSum(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++){
        sum += arr[i];
    }
    return sum;
}

// 배열 원소들의 평균을 계산하는 함수
double CalAvg(int sum, int size)
{
    return static_cast<double>(sum) / size;
}

// 배열을 오름차순으로 정렬하는 함수
void SortAscending(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) swap(arr[i], arr[j]);
        }
    }
}

// 배열을 내림차순으로 정렬하는 함수
void SortDescending(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] < arr[j]) swap(arr[i], arr[j]);
        }
    }
}

int main()
{
    const int size = 5;
    int num[size];
    int input;
    
    cout << "숫자 입력하기 : ";
    for (int i = 0; i < size; i++)
        cin >> num[i];

    int sum = CalSum(num, size);
    double avg = CalAvg(sum, size);

    cout << "합계 : " << sum << endl;
    cout << "평균 : " << avg << endl;

    cin >> input;
    if (input == 1)
    {
        SortAscending(num, size);
        cout << "오름차순 정렬 결과: ";
    }
    else if (input == 2)
    {
        SortDescending(num, size);
        cout << "내림차순 정렬 결과: ";
    }
    else
        cout << "정렬하지 않은 배열: ";
        
    for (int i = 0; i < size; i++) {
        cout << num[i] << " ";
    }

    return 0;
}