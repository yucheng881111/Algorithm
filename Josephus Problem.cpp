#include <iostream>
using namespace std;

//����: f(n,k)=(f(n-1,k)+k)%n
int josephus(int n, int k) { //�D���^����
	int s = 0; //�u���@�ӤH�ɡA�@�w�ѤU�L(�s��0) f(1,k)=0
	for (int i = 2; i <= n; i++){
        s = (s + k) % i;
	}

	return s;
}
int josephus_recursion(int n, int k) { //���^����
	return n > 1 ? (josephus_recursion(n - 1, k) + k) % n : 0;
}
int main() {
    cout<<josephus(10,5)<<endl;
    cout<<josephus_recursion(10,5)<<endl;
	return 0;
}
