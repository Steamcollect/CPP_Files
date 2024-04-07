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
	currentQuest.questID = 0;

	npcID_txtBox->Text = currentQuest.npcID.ToString();
	quests.push_back(currentQuest);
}

wstring StringToWString(string str)
{
	wstring temp = wstring(str.begin(), str.end());
	return temp;
}

void MainPage::SetPanelVisual() {
	questID_txtBox->Text = currentQuest.questID.ToString();
	npcID_txtBox->Text = currentQuest.npcID.ToString();

	//preQuestDialog_txtBox->Text = currentQuest.preQuestDialog;
	//questInProgressDialog_txtBox->Text = currentQuest.inProgressDialog;
	//postQuestDialog_txtBox->Text = currentQuest.postQuestDialog;

	amount_txtBox->Text = currentQuest.objectivesQuantity.ToString();
	coins_txtBox->Text = currentQuest.coinsGiven.ToString();
	xp_txtBox->Text = currentQuest.xpGiven.ToString();
}

void QuestEditor::MainPage::questID_txtBox_SelectionChanged(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	// Do nothing
}

// NPC ID
void QuestEditor::MainPage::npcID_txtBox_TextChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e)
{
	String^ str_input = amount_txtBox->Text;
	std::wstring wsstr(str_input->Data());
	std::string s(wsstr.begin(), wsstr.end());
	currentQuest.npcID = stoi(s);
}
// Quest title
void QuestEditor::MainPage::questTitle_TxtBox_TextChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e)
{
	String^ str_input = amount_txtBox->Text;
	std::wstring wsstr(str_input->Data());
	std::string s(wsstr.begin(), wsstr.end());
	currentQuest.questTitle = s;
}

// Pre quest dialog
void QuestEditor::MainPage::preQuestDialog_txtBox_TextChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e)
{
	String^ str_input = amount_txtBox->Text;
	std::wstring wsstr(str_input->Data());
	std::string s(wsstr.begin(), wsstr.end());
	currentQuest.preQuestDialog = s;
}
// Quest in progress dialog
void QuestEditor::MainPage::questInProgressDialog_txtBox_TextChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e)
{
	String^ str_input = amount_txtBox->Text;
	std::wstring wsstr(str_input->Data());
	std::string s(wsstr.begin(), wsstr.end());
	currentQuest.inProgressDialog = s;
}
// Post quest dialog
void QuestEditor::MainPage::postQuestDialog_txtBox_TextChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e)
{
	String^ str_input = amount_txtBox->Text;
	std::wstring wsstr(str_input->Data());
	std::string s(wsstr.begin(), wsstr.end());
	currentQuest.postQuestDialog = s;
}

// Coins
void QuestEditor::MainPage::coins_txtBox_TextChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e)
{
	String^ str_input = amount_txtBox->Text;
	std::wstring wsstr(str_input->Data());
	std::string s(wsstr.begin(), wsstr.end());
	currentQuest.coinsGiven = stoi(s);
}
// XP
void QuestEditor::MainPage::xp_txtBox_TextChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e)
{
	String^ str_input = amount_txtBox->Text;
	std::wstring wsstr(str_input->Data());
	std::string s(wsstr.begin(), wsstr.end());
	currentQuest.xpGiven = stoi(s);
}
// Quest quantity
void QuestEditor::MainPage::amount_txtBox_TextChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e)
{
	String^ str_input = amount_txtBox->Text;
	std::wstring wsstr(str_input->Data());
	std::string s(wsstr.begin(), wsstr.end());
	currentQuest.objectivesQuantity = stoi(s);
}


// Reset quest button
void QuestEditor::MainPage::ResetQuestButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	currentQuest.ResetInfos();
	SetPanelVisual();
}
// Delete quest button
void QuestEditor::MainPage::DeleteQuestButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{

}
// Test interact button
void QuestEditor::MainPage::InteractButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	switch(currentQuest.questState)
	{
	case QuestData::QuestState::NotStarted:
		//DialogTest->Text = currentQuest.preQuestDialog;
		break;
	case QuestData::QuestState::Started:
		//DialogTest->Text = currentQuest.inProgressDialog;
		break;
	case QuestData::QuestState::Finished:
		//DialogTest->Text = currentQuest.postQuestDialog;
		break;
	default:
		break;
	}
}
// Test reset quest info
void QuestEditor::MainPage::TestResetQuestInfo(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	currentQuest.questState = QuestData::QuestState::NotStarted;
	MainPage::ResetTestPanel();
}

void MainPage::ResetTestPanel() {
	testCoinsAmountTXT->Text = "0";
	testXpAmountTXT->Text = "0";
	DialogTest->Text = "";
}

// Add quest button
void QuestEditor::MainPage::AddQuestButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Button ^ b = ref new Button();
	QuestContent->Children->Append(b);
	b->Content = "Button" + quests.size();
	b->Name = quests.size().ToString();
	b->Click += ref new Windows::UI::Xaml::RoutedEventHandler(this, &MainPage::OnButtonClick);

	quests[currentQuest.questID] = currentQuest;

	QuestData tmp;
	tmp.questID = quests.size();
	quests.push_back(tmp);
	currentQuest = tmp;

	currentQuest.ResetInfos();
	MainPage::SetPanelVisual();
}

void MainPage::OnButtonClick(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
	MainPage::ResetTestPanel();
}

void QuestEditor::MainPage::ObjectiveTypeDropdown_SelectionChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::SelectionChangedEventArgs^ e)
{
	if (objectiveTypeDropdown->SelectedItem == "Slay") currentQuest.objectiveType = QuestData::ObjectiveType::Slay;
	else if (objectiveTypeDropdown->SelectedItem == "Loot") currentQuest.objectiveType = QuestData::ObjectiveType::Loot;
	else if (objectiveTypeDropdown->SelectedItem == "Save") currentQuest.objectiveType = QuestData::ObjectiveType::Save;
}

void QuestEditor::MainPage::UpdateQuestButton(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	switch (currentQuest.questState)
	{
	case QuestData::QuestState::NotStarted:
		currentQuest.questState = QuestData::QuestState::Started;
		break;
	case QuestData::QuestState::Started:
		currentQuest.questState = QuestData::QuestState::Finished;
		break;
	case QuestData::QuestState::Finished:
		break;
	default:
		break;
	}
}