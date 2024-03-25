//
// MainPage.xaml.cpp
// Implémentation de la classe MainPage.
//

#include "pch.h"
#include "MainPage.xaml.h"
#include <sstream>
#include <string>

using namespace CharacterCreator;
using namespace std;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// Pour plus d'informations sur le modèle d'élément Page vierge, consultez la page https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

string name;
string description;

int attack[] = { 0,0,0,5 };
int defense[] = { 0,0,0,5 };
int luck[] = { 0,0,5 };
int gold[] = { 0,0,0,0,10 };


MainPage::MainPage()
{
	InitializeComponent();
}

void AttackDice(TextBlock^ textBloc) {
	attack[1] = (1 + rand() % 6);
	attack[2] = (1 + rand() % 6);

	attack[0] = attack[1] + attack[2] + attack[3];

	textBloc->Text = "Attack : " + attack[0] + " (" + attack[1] + " + " + attack[2] + " + " + attack[3] + ")";
}
void CharacterCreator::MainPage::attackButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	AttackDice(attackTxt);
}

void DefenseDice(TextBlock ^textBloc) {
	defense[1] = (1 + rand() % 6);
	defense[2] = (1 + rand() % 6);

	defense[0] = defense[1] + defense[2] + defense[3];

	textBloc->Text = "Defense : " + defense[0] + " (" + defense[1] + " + " + defense[2] + " + " + defense[3] + ")";
}
void CharacterCreator::MainPage::defenseButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	DefenseDice(defenseTxt);
}

void LuckDice(TextBlock^ textBloc) {
	luck[1] = (1 + rand() % 6);

	luck[0] = luck[1] + luck[2];

	textBloc->Text = "luck : " + luck[0] + " (" + luck[1] + " + " + luck[2] + ")";
}
void CharacterCreator::MainPage::luckButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	LuckDice(luckTxt);
}


void GoldDice(TextBlock^ textBloc) {
	gold[1] = (1 + rand() % 6);
	gold[2] = (1 + rand() % 6);
	gold[3] = (1 + rand() % 6);

	gold[0] = gold[1] + gold[2] + gold[3] + gold[4];

	textBloc->Text = "Gold : " + gold[0] + " (" + gold[1] + " + " + gold[2] + " + " + gold[3] + " + " + gold[4] + ")";
}
void CharacterCreator::MainPage::goldButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	GoldDice(goldTxt);
}

void CharacterCreator::MainPage::allDiceButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	AttackDice(attackTxt);
	DefenseDice(defenseTxt);
	LuckDice(luckTxt);
	GoldDice(goldTxt);
}

void CharacterCreator::MainPage::nameTxt_TextChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e)
{
	String^ str_input = nameTxt->Text;
	std::wstring wsstr(str_input->Data());
	std::string s(wsstr.begin(), wsstr.end());
	name = s;
}

void CharacterCreator::MainPage::descriptionTxt_TextChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e)
{
	String^ str_input = nameTxt->Text;
	std::wstring wsstr(str_input->Data());
	std::string s(wsstr.begin(), wsstr.end());
	description = s;
}