#include "_DS_FromScratch.cpp"

using namespace Utils;

int main() {

	Node<float> n(3.14);
	Node<float> *pN = &n;
	show(*pN);

	return 0;
}