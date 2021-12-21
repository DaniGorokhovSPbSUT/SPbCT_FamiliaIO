#pragma once
#include <string>
#include <fstream>
#include <chrono>
#include <ctime>
#include <StringsDll.h>
#include <vector>
#include <algorithm>

#include "Thread.h"
#include "FixDefs.h"

#define BUF_SIZE 256

std::string INPUT_FILE = "digits.txt";
std::string OUTPUT_FILE = "output.txt";

std::ofstream ofilestream(OUTPUT_FILE);
std::ifstream ifilestream(INPUT_FILE);

char digits[800];

void MarshalString(String^ s, std::string& os) {
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}

void MarshalString(String^ s, std::wstring& os) {
	using namespace Runtime::InteropServices;
	const wchar_t* chars =
		(const wchar_t*)(Marshal::StringToHGlobalUni(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}

void NetUserAdd2(std::string fio) {
	if (fio == "") {
		/*
		USER_INFO_1 ui;
		DWORD dwLevel = 1;
		DWORD dwError = 0;
		NET_API_STATUS nStatus;

		ui.usri1_name = argv[2];
		ui.usri1_password = argv[2];
		ui.usri1_priv = USER_PRIV_USER;
		ui.usri1_home_dir = NULL;
		ui.usri1_comment = NULL;
		ui.usri1_flags = UF_SCRIPT;
		ui.usri1_script_path = NULL;

		NetUserAdd(argv[1],
            dwLevel,
            (LPBYTE)&ui,
            &dwError
		);
		*/
	}
}

std::vector<std::string> getStrs(std::string source) {
	std::vector<std::string> strs;

		int length = source.length();

		std::vector<int> ixs;

		for (int i = 1; i < 10; i += 1) {
			ixs.push_back(i * 10);
		}
		ixs.push_back(length);

		int prevIx = 0;
		auto it = ixs.begin();
		while (it != ixs.end()) {
			strs.push_back(
				source.substr(prevIx, *it - prevIx)
			);

			prevIx = *it;
			it++;
		}

		return strs;
}

class Sort
{
public:
	std::string* _strs;
	void addStrs(std::string strs[10]) {
		this->_strs = strs;
	}
	std::string* getStrs() {
		return _strs;
	}
	DWORD doIt()
	{
		std::vector<std::string> tmp;
		for (int i = 0; i < 10; i++) {
			tmp.push_back(_strs[i]);
		}
		std::sort(tmp.begin(), tmp.end());

		int i = 0;
		auto it = tmp.begin();
		while (it != tmp.end()) {
			_strs[i] = *it;
			i++;
			it++;
		}
		return 0;
	}
};

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	typedef struct
	{
		TCHAR TempFile[MAX_PATH];
	} PROCFILE;

	/// <summary>
	/// Zusammenfassung fьr Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufьgen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	protected:

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode fьr die Designerunterstьtzung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geдndert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(20, 20);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(300, 26);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Горохов Даниил, группа 500";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(20, 53);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 26);
			this->label2->TabIndex = 1;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(25, 156);
			this->textBox1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(504, 32);
			this->textBox1->TabIndex = 2;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(20, 125);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(620, 26);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Для продолжения надо зарегистрироваться. Введите ФИО";
			// 
			// button1
			// 
			this->button1->Enabled = false;
			this->button1->Location = System::Drawing::Point(25, 196);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(288, 38);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Зарегистрироваться";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(24, 251);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 26);
			this->label4->TabIndex = 5;
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(25, 419);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(163, 36);
			this->button2->TabIndex = 6;
			this->button2->Text = L"STL replace";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(25, 379);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(275, 32);
			this->textBox2->TabIndex = 7;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &Form1::textBox2_TextChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(327, 379);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(183, 26);
			this->label5->TabIndex = 8;
			this->label5->Text = L"На что заменять";
			this->label5->Click += gcnew System::EventHandler(this, &Form1::label5_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(328, 340);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(152, 26);
			this->label6->TabIndex = 10;
			this->label6->Text = L"Что заменять";
			this->label6->Click += gcnew System::EventHandler(this, &Form1::label6_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(26, 340);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(275, 32);
			this->textBox3->TabIndex = 9;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &Form1::textBox3_TextChanged);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(29, 479);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(124, 26);
			this->label7->TabIndex = 11;
			this->label7->Text = L"Результат:";
			this->label7->Click += gcnew System::EventHandler(this, &Form1::label7_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
			this->label8->Location = System::Drawing::Point(29, 523);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(0, 17);
			this->label8->TabIndex = 12;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
			this->label9->Location = System::Drawing::Point(26, 549);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(0, 17);
			this->label9->TabIndex = 13;
			// 
			// button3
			// 
			this->button3->Enabled = false;
			this->button3->Location = System::Drawing::Point(32, 632);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(156, 34);
			this->button3->TabIndex = 14;
			this->button3->Text = L"Сортировать";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
			this->label10->Location = System::Drawing::Point(34, 673);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(0, 17);
			this->label10->TabIndex = 15;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
			this->label11->Location = System::Drawing::Point(34, 708);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(0, 17);
			this->label11->TabIndex = 16;
			this->label11->Click += gcnew System::EventHandler(this, &Form1::label11_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1414, 786);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.8F));
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"Form1";
			this->Text = L"Educational Practice";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
		auto dateTime = std::chrono::system_clock::now();

		std::time_t parsedDateTime = std::chrono::system_clock::to_time_t(dateTime);

		const int bufSize = 255;
		char buffer[bufSize];
		ctime_s(buffer, bufSize, &parsedDateTime);

		ofilestream << "Горохов Даниил, группа 500\n";
		ofilestream << buffer;

		this->label2->Text = gcnew String(buffer);
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		this->button1->Enabled = this->textBox1->Text->Length > 0;
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->label4->Text = "Ваши ФИО: " + this->textBox1->Text;
	std::string a = "";
	MarshalString(this->textBox1->Text, a);
	ofilestream << a;

	NetUserAdd2(a);

	this->textBox1->Text = "";
	this->button1->Enabled = false;
	this->textBox1->Enabled = false;
	this->button2->Enabled = true;
	this->textBox2->Enabled = true;
	this->textBox3->Enabled = true;
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	ifilestream >> digits;

	std::string strDigits(digits);

	std::vector<std::string> stringVectors = getStrs(strDigits);
	std::string strs[10];

	int i = 0;
	auto it = stringVectors.begin();
	while (it != stringVectors.end()) {
		strs[i] = *it;
		i++;
		it++;
	}

	int strsC = 10;

	SECURITY_ATTRIBUTES StdOutSA = {
		sizeof (SECURITY_ATTRIBUTES),
		NULL,
		TRUE
	};
	TCHAR CommandLine[MAX_PATH + 100];
	STARTUPINFO StartUp;
	PROCESS_INFORMATION ProcessInfo;
	DWORD iProc;
	HANDLE* hProc;

	PROCFILE* ProcFile;

	GetStartupInfo(&StartUp);

	ProcFile = (PROCFILE*)malloc((strsC) * sizeof(PROCFILE));
	hProc = (HANDLE*)malloc((strsC) * sizeof(HANDLE));

	for (iProc = 0; iProc < strsC; iProc++)
	{
		CreateProcess(NULL, CommandLine, NULL, NULL, TRUE, 0, NULL, NULL, &StartUp, &ProcessInfo);

		hProc[iProc] = ProcessInfo.hProcess;
	}

	for (iProc = 0; iProc < strsC; iProc += MAXIMUM_WAIT_OBJECTS) {
		WaitForSingleObject(hProc[iProc], INFINITE);
		CloseHandle(hProc[iProc]);
	}

	CloseHandle(ProcessInfo.hThread);

	free(ProcFile);
	free(hProc);

	std::string a = "";
	MarshalString(this->textBox2->Text, a);
	std::string b = "";
	MarshalString(this->textBox3->Text, b);

	std::string init = "";
	std::string sum = "";

	for (int i = 0; i < 10; i++) {
		init += strs[i];
		std::replace(strs[i].begin(), strs[i].end(), b[0], a[0]);
		sum += strs[i];
	}

	ofilestream << init << std::endl;
	ofilestream << sum << std::endl;

	char tab2[800];
	strncpy(tab2, sum.c_str(), sizeof(tab2));
	tab2[sizeof(tab2) - 1] = 0;

	auto preparedDigits = gcnew String(tab2);

	this->label8->Text = preparedDigits;

	char tab1[800];
	strncpy(tab1, init.c_str(), sizeof(tab1));
	tab1[sizeof(tab1) - 1] = 0;

	this->label9->Text = "Начальное значение: " + gcnew String(tab1);

	this->textBox2->Enabled = false;
	this->textBox3->Enabled = false;
	this->button2->Enabled = false;
	this->button3->Enabled = true;
}
private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string strDigits(digits);

	char tab1[800];
	strncpy(tab1, strDigits.c_str(), sizeof(tab1));
	tab1[sizeof(tab1) - 1] = 0;

	ofilestream << strDigits << std::endl;

	this->label11->Text = "Начальное значение: " + gcnew String(tab1);

	std::vector<std::string> stringVectors = getStrs(strDigits);
	std::string strs[10];

	int i = 0;
	auto it = stringVectors.begin();
	while (it != stringVectors.end()) {
		strs[i] = *it;
		i++;
		it++;
	}

	Sort sort;
	sort.addStrs(strs);
	Thread<Sort> thread(&sort, &Sort::doIt);
	thread.join(); // wait for thread

	sort.doIt();
	std::string* strs2 = sort.getStrs();

	std::string sum = "";

	for (int i = 0; i < 10; i++) {
		sum += strs2[i];
		if (i != 9) sum += ",";
	}

	ofilestream << sum << std::endl;

	char tab2[800];
	strncpy(tab2, sum.c_str(), sizeof(tab2));
	tab2[sizeof(tab2) - 1] = 0;

	auto preparedDigits = gcnew String(tab2);

	this->label10->Text = preparedDigits;
}
private: System::Void label11_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
