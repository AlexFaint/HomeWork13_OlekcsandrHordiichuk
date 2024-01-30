#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	
	cout << "Enter your name: ";
	string HeroName = "Awsome name";
	cin >> HeroName;

	cout << "Enter MAX Health : ";
	float HeroHealth = 100;
	cin >> HeroHealth;

	
	cout << "Write to chose your class 1-Mage or 2-Warior: ";
	int HeroClassInt;
	string MyHeroClass;
	cin >> HeroClassInt;
	switch (HeroClassInt)
	{
	case 1:
	{
		MyHeroClass = "Mage";
		break;
	}
	case 2:
	{
		MyHeroClass = "Warior";
		break;
	}
	default:
		cout << "Sorry, at the moment such a cool class is not available" << endl;
		return 0;
		break;
		
	}
	
	cout << "Hello young HERO " << HeroName << ". Your Max Health :" << HeroHealth << " and class: " << MyHeroClass << endl;
		
	cout << "Let`s begin the fight!!! " << endl;
		
	bool IsDead = false;
	float Power = 0;
	float StartHealthHero = HeroHealth;
	
	cout << "Enter Power level: ";
	cin >> Power;

	while (!IsDead)
	{
		int Damage = 0;
		
		
		cout << "Enter Damage: " << endl;
		cin >> Damage;
		

		switch (HeroClassInt)
		{
		case 1: //Mage Class
		{			
			if (Damage > (Power * 2))
			{
				srand(time(NULL));
				int randomizer = rand() % 2;
				if (randomizer == 0)
				{
					if (Damage % 2)
					{
						HeroHealth = HeroHealth - Damage;
					}
					else
					{
						HeroHealth = HeroHealth - Damage * 2;
					}
				}

			}			
			else
			{
				if (Damage % 2)
				{
					HeroHealth = HeroHealth - Damage;
				}
				else
				{
					HeroHealth = HeroHealth - Damage * 2;
				}
			}
			
			if (HeroHealth <= 0)
			{
				cout << "You was to weak and you DIED: " << endl;
				IsDead = true;
			}
			else
			{
				cout << "Nice job, your still live and have: " << HeroHealth << " healt left" << endl;
			}
			
			break;
		}
		case 2: // Warior Class
		{
			if (HeroHealth <= 0)
			{
				cout << "You was to weak and you DIED: " << endl;
				IsDead = true;
			}
			else if (HeroHealth < (StartHealthHero * 0.3f))
			{
				if (Damage > Power)
				{
					HeroHealth = HeroHealth - (Damage - Power);
				}				
			}
			else
			{
				if (Damage % 2)
				{
					HeroHealth = HeroHealth - Damage * 3;
				}					
			}

			cout << "Nice job, your still live and have: " << HeroHealth << " healt left" << endl;

			break;
		}
		default:
			break;
		}
	}
	return 0;

}
