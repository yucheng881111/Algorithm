#include <iostream>
using namespace std;

//公式: f(n,k)=(f(n-1,k)+k)%n
int josephus(int n, int k) { //非遞回版本
	int s = 0; //只有一個人時，一定剩下他(編號0) f(1,k)=0
	for (int i = 2; i <= n; i++){
        s = (s + k) % i;  //上一個位置，往後數k格，再%人數
	}

	return s;
}
int josephus_recursion(int n, int k) { //遞回版本
	return n > 1 ? (josephus_recursion(n - 1, k) + k) % n : 0;
}
int main() {
    cout<<josephus(10,5)<<endl;
    cout<<josephus_recursion(10,5)<<endl;
	return 0;
}
