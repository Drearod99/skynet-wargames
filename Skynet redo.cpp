#include<iostream>
#include<cstdlib>
#include<ctime>

using std::cout;
using std::endl;
using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(0)));

	int randomNumber = rand();

	int samLocation = (randomNumber % 64) + 1;
	cout << "Enemy location is grid number " << samLocation << endl;
	cout << "------------------------------------------------------------------------------------"<<endl;
	
	int searchGridLowNumber = (randomNumber % 64) + 1;

	int searchGridHighNumber = (randomNumber % 64) + 1;

	int samLocationPrediction = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;

	do
	{
		int tries = 0;
		++tries;

		if (samLocationPrediction > samLocation)
		{
			cout << "The prediction of " << samLocation << " is larger than the actual SAM location.\n";
			++tries;
		}
		if (samLocationPrediction < samLocation)
		{
			cout << "The prediction of " << samLocation << "is lower than the actual SAM location.\n";
			cout << "The new searchGridLowNumber is " << searchGridLowNumber + 1 << "\n";
			++tries;
		}
		else if (samLocationPrediction == samLocation)
		{
			cout << "SAM was found at grid number " << samLocation << " after " << tries << " prediction(s).\n";
		}
	} while (samLocationPrediction != samLocation);

	system("pause");

	return 0;
	
}