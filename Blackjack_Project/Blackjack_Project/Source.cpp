#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main()
{
	struct person {
		string name;
		int age;
	};
	
	
	person personNumberOne;
	personNumberOne.name = "Tommy";
	personNumberOne.age = 22;

	person personNumberTwo;
	personNumberTwo.name = "Scottie";
	personNumberTwo.age = 18;

	stack<person> stackOfPeople;
	stackOfPeople.push(personNumberOne);
	stackOfPeople.push(personNumberTwo);

	cout << stackOfPeople.top().name << " " << stackOfPeople.top().age << endl;
	stackOfPeople.pop(); 
	cout << stackOfPeople.top().name << " " << stackOfPeople.top().age << endl;

	system("pause");
	return 0;
}