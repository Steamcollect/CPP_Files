//
// MainPage.xaml.cpp
// Implémentation de la classe MainPage.
//

#include "pch.h"
#include "MainPage.xaml.h"
#include "QuestData.h"

using namespace QuestEditor;

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

vector<QuestData> quests;
QuestData currentQuest;

MainPage::MainPage()
{
	InitializeComponent();
}

void ResetPanelVisual(TextBox npcID_box, TextBox questName_box, TextBox preDialog_box, TextBox inDialog_box, TextBox postDialog_box, TextBox objectivesAmount_box, TextBox coins_box, TextBox xp_box) {
	npcID_box.Text = "";
	questName_box.Text = "";

	preDialog_box.Text = "";
	inDialog_box.Text = "";
	postDialog_box.Text = "";

	objectivesAmount_box.Text = "";
	coins_box.Text = "";
	xp_box.Text = "";

	currentQuest.ResetInfos();
}

void QuestEditor::MainPage::questID_txtBox_SelectionChanged(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{

}

void QuestEditor::MainPage::npcID_txtBox_TextChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e)
{
	String^ str_input = amount_txtBox->Text;
	std::wstring wsstr(str_input->Data());
	std::string s(wsstr.begin(), wsstr.end());
	currentQuest.npcID = s;
}

void QuestEditor::MainPage::questTitle_TxtBox_TextChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e)
{
	String^ str_input = amount_txtBox->Text;
	std::wstring wsstr(str_input->Data());
	std::string s(wsstr.begin(), wsstr.end());
	currentQuest.questTitle = s;
}


void QuestEditor::MainPage::preQuestDialog_txtBox_TextChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e)
{
	String^ str_input = amount_txtBox->Text;
	std::wstring wsstr(str_input->Data());
	std::string s(wsstr.begin(), wsstr.end());
	currentQuest.preQuestDialog = s;
}


void QuestEditor::MainPage::questInProgressDialog_txtBox_TextChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e)
{
	String^ str_input = amount_txtBox->Text;
	std::wstring wsstr(str_input->Data());
	std::string s(wsstr.begin(), wsstr.end());
	currentQuest.inProgressDialog = s;
}


void QuestEditor::MainPage::postQuestDialog_txtBox_TextChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e)
{
	String^ str_input = amount_txtBox->Text;
	std::wstring wsstr(str_input->Data());
	std::string s(wsstr.begin(), wsstr.end());
	currentQuest.postQuestDialog = s;
}


void QuestEditor::MainPage::coins_txtBox_TextChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e)
{
	String^ str_input = amount_txtBox->Text;
	std::wstring wsstr(str_input->Data());
	std::string s(wsstr.begin(), wsstr.end());
	currentQuest.coinsGiven = s;
}


void QuestEditor::MainPage::xp_txtBox_TextChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e)
{
	String^ str_input = amount_txtBox->Text;
	std::wstring wsstr(str_input->Data());
	std::string s(wsstr.begin(), wsstr.end());
	currentQuest.xpGiven = s;
}


void QuestEditor::MainPage::amount_txtBox_TextChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e)
{
	String^ str_input = amount_txtBox->Text;
	std::wstring wsstr(str_input->Data());
	std::string s(wsstr.begin(), wsstr.end());
	currentQuest.objectivesQuantity = s;
}

void QuestEditor::MainPage::ResetQuestButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{

}

void QuestEditor::MainPage::AddQuestButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Button ^ b = ref new Button();
	QuestContent->Children->Append(b);
	b->Content = "Button" + quests.size();
	b->Style = Button1->Style;
}