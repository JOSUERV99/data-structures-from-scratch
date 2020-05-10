#include "_DS_FromScratch.cpp"

int main() {

	LinkedList<int> list;

	list.add(0);
	list.add(1);
	list.add(2);
	list.add(3);
	list.add(4);
	list.add(5);

	std::cout << list << std::endl;

	LinkedList<int> list2 =  list.subList(3, 5);
	std::cout << list2 << std::endl;

	return 0;
}