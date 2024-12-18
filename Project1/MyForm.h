#pragma once
#include <msclr/marshal_cppstd.h>
#include <fstream>

#include <tuple>

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Timers;
	using namespace System::Windows::Forms;


	
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
			taskManager = gcnew TaskManager();
			monthCalendar1->DateSelected += gcnew DateRangeEventHandler(this, &MyForm::monthCalendar1_DateSelected);
			LoadTasks();
			UpdateBoldedDates(); 

		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			SaveTasks();
		}
	private: System::Windows::Forms::MonthCalendar^ monthCalendar1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ ���������ToolStripMenuItem;
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Collections::Generic::Dictionary<System::DateTime, System::Collections::Generic::List<String^>^>^ tasks;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton3;
	private: System::Timers::Timer^ taskReminderTimer;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private:     
		ref class TaskManager {
		public:
			Dictionary<DateTime, List<Tuple<String^, DateTime, String^, bool>^>^>^ tasks;

			TaskManager() {
				tasks = gcnew Dictionary<DateTime, List<Tuple<String^, DateTime, String^, bool>^>^>();
			}
		};

		ref class Task {
		public:
			String^ Text;
			DateTime Time;
			String^ Priority;
			bool IsCompleted;
			// �����������
			Task(String^ text, DateTime time, String^ priority) {
				Text = text;
				Time = time;
				Priority = priority;
				IsCompleted = false; // ���������� ������ �� ���������
			}
		};


	private: 	
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::GroupBox^ groupBox1;



		System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
		System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
		System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::ToolStripMenuItem^ �������ToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^ Column4;


		TaskManager^ taskManager;
		


#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->monthCalendar1 = (gcnew System::Windows::Forms::MonthCalendar());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->���������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->taskReminderTimer = (gcnew System::Timers::Timer());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->taskReminderTimer))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// monthCalendar1
			// 
			this->monthCalendar1->BackColor = System::Drawing::Color::LightYellow;
			this->monthCalendar1->CalendarDimensions = System::Drawing::Size(3, 1);
			this->monthCalendar1->ForeColor = System::Drawing::Color::DarkBlue;
			this->monthCalendar1->Location = System::Drawing::Point(-11, 32);
			this->monthCalendar1->Name = L"monthCalendar1";
			this->monthCalendar1->TabIndex = 0;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->���������ToolStripMenuItem,
					this->�������ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(769, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ���������ToolStripMenuItem
			// 
			this->���������ToolStripMenuItem->Enabled = false;
			this->���������ToolStripMenuItem->Name = L"���������ToolStripMenuItem";
			this->���������ToolStripMenuItem->Size = System::Drawing::Size(78, 20);
			this->���������ToolStripMenuItem->Text = L"���������";
			this->���������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::���������ToolStripMenuItem_Click);
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(63, 20);
			this->�������ToolStripMenuItem->Text = L"�������";
			this->�������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::�������ToolStripMenuItem_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(479, 33);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(204, 344);
			this->textBox1->TabIndex = 3;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Column1,
					this->Column2, this->Column3, this->Column4
			});
			this->dataGridView1->EditMode = System::Windows::Forms::DataGridViewEditMode::EditOnEnter;
			this->dataGridView1->Location = System::Drawing::Point(1, 195);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(476, 182);
			this->dataGridView1->TabIndex = 4;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			this->dataGridView1->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellValueChanged);
			this->dataGridView1->DataError += gcnew System::Windows::Forms::DataGridViewDataErrorEventHandler(this, &MyForm::dataGridView1_DataError);
			this->dataGridView1->MouseWheel += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::dataGridView1_MouseWheel);
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"������";
			this->Column1->Name = L"Column1";
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"�����";
			this->Column2->Name = L"Column2";
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"��������";
			this->Column3->Name = L"Column3";
			// 
			// Column4
			// 
			this->Column4->FalseValue = false;
			this->Column4->HeaderText = L"���������";
			this->Column4->Name = L"Column4";
			this->Column4->TrueValue = true;
			this->Column4->ReadOnly = false;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButton1->ForeColor = System::Drawing::Color::Tomato;
			this->radioButton1->Location = System::Drawing::Point(6, 16);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(49, 41);
			this->radioButton1->TabIndex = 5;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"�";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButton2->ForeColor = System::Drawing::Color::Gold;
			this->radioButton2->Location = System::Drawing::Point(6, 47);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(49, 41);
			this->radioButton2->TabIndex = 6;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"�";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButton3->ForeColor = System::Drawing::Color::LimeGreen;
			this->radioButton3->Location = System::Drawing::Point(6, 78);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(49, 41);
			this->radioButton3->TabIndex = 7;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"�";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Time;
			this->dateTimePicker1->Location = System::Drawing::Point(689, 159);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->ShowUpDown = true;
			this->dateTimePicker1->Size = System::Drawing::Size(76, 20);
			this->dateTimePicker1->TabIndex = 8;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Controls->Add(this->radioButton3);
			this->groupBox1->Location = System::Drawing::Point(689, 27);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(76, 126);
			this->groupBox1->TabIndex = 9;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"��������";
			// 
			// taskReminderTimer
			// 
			this->taskReminderTimer->Enabled = true;
			this->taskReminderTimer->Interval = 60000;
			this->taskReminderTimer->SynchronizingObject = this;
			this->taskReminderTimer->Elapsed += gcnew System::Timers::ElapsedEventHandler(this, &MyForm::CheckForUpcomingTasks);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(686, 294);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(80, 82);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 10;
			this->pictureBox1->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(769, 379);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->monthCalendar1);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"����������";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->taskReminderTimer))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		void UpdateTaskList() {
			dataGridView1->Rows->Clear(); // ������� ���� ����� � dataGridView
			DateTime selectedDate = monthCalendar1->SelectionStart;

			// ��������, ����� �� ������� ���� tasks.csv �� ������
			try {
				FileStream^ fs = gcnew FileStream("tasks.csv", FileMode::Open, FileAccess::Read, FileShare::None);
				fs->Close();
			}
			catch (IOException^ ex) {
				MessageBox::Show("������: ���� tasks.csv ��� ������. �������� ���� � ��������� �������.", "������ ����������", MessageBoxButtons::OK, MessageBoxIcon::Error);
				BlockEditing(true);
				return;
			}

			if (taskManager->tasks->ContainsKey(selectedDate)) {
				for each (Tuple<String^, DateTime, String^, bool> ^ task in taskManager->tasks[selectedDate]) {
					int rowIndex = dataGridView1->Rows->Add(); // ���������� ����� ������ ��� ����������
					DataGridViewRow^ row = dataGridView1->Rows[rowIndex];
					row->Cells["Column4"]->Value = task->Item4; // ��������� �������� `CheckBox`
					row->Cells["Column1"]->Value = task->Item1; // ��������� �������� ��� ������� "������"
					row->Cells["Column2"]->Value = task->Item2.ToShortTimeString(); // ��������� �������� ��� ������� "�����"
					row->Cells["Column3"]->Value = task->Item3; // ��������� �������� ��� ������� "��������"

					// ��������� ����� ������ � ����������� �� ���������� ������
					if (task->Item3 == "�������") {
						row->DefaultCellStyle->BackColor = ColorTranslator::FromHtml("#ff6666");
					}
					else if (task->Item3 == "������") {
						row->DefaultCellStyle->BackColor = ColorTranslator::FromHtml("#ffff99");
					}
					else if (task->Item3 == "�������") {
						row->DefaultCellStyle->BackColor = ColorTranslator::FromHtml("#50c878");
					}
				}

				// ��������� ������ ������
				if (dataGridView1->Rows->Count > 0) {
					dataGridView1->ClearSelection();
					dataGridView1->Rows[0]->Selected = true;
					dataGridView1->CurrentCell = dataGridView1->Rows[0]->Cells[1];
				}
			}

			UpdateBoldedDates();
		}


		void monthCalendar1_DateSelected(System::Object^ sender, System::Windows::Forms::DateRangeEventArgs^ e) {
			UpdateTaskList();
		}

		void CheckFileStatus(System::Object^ sender, EventArgs^ e) {
			String^ fileName = "tasks.csv";
			try {
				FileStream^ fs = gcnew FileStream(fileName, FileMode::Open, FileAccess::ReadWrite, FileShare::None);
				fs->Close();

				// ���� ���� ��������, ������������ �������� ����������
				BlockEditing(false);
			}
			catch (IOException^) {
				// ���� ���� ��� ��� ������, ���������� ��������
				BlockEditing(true);
			}
		}



		void BlockEditing(bool block) {
			// ��������� ��� ������������ �������� ����������
			dataGridView1->Enabled = !block;
			textBox1->Enabled = !block;

			// ���� ��������� �������� ����������, ��������� ������ ��� �������� ������� �����
			System::Windows::Forms::Timer^ timer = (System::Windows::Forms::Timer^)this->Tag;
			if (block) {
				if (timer == nullptr) {
					timer = gcnew System::Windows::Forms::Timer();
					timer->Interval = 2000; // �������� ������ 5 ������
					timer->Tick += gcnew EventHandler(this, &MyForm::CheckFileStatus);
					this->Tag = timer;
				}
				timer->Start();
			}
			else {
				if (timer != nullptr) {
					timer->Stop();
				}
			}
		}

		void ���������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			DateTime selectedDate = monthCalendar1->SelectionStart;
			String^ task = textBox1->Text;
			DateTime taskTime = dateTimePicker1->Value;
			String^ priority;

			if (radioButton1->Checked) {
				priority = "�������";
			}
			else if (radioButton2->Checked) {
				priority = "������";
			}
			else if (radioButton3->Checked) {
				priority = "�������";
			}
			else {
				MessageBox::Show("����������, �������� ������� ��������.");
				return;
			}

			if (task->Length > 0) {
				if (!taskManager->tasks->ContainsKey(selectedDate)) {
					taskManager->tasks[selectedDate] = gcnew List<Tuple<String^, DateTime, String^, bool>^>();
				}
				taskManager->tasks[selectedDate]->Add(gcnew Tuple<String^, DateTime, String^, bool>(task, taskTime, priority, false));
				textBox1->Clear();

				// ��������� ������ � ���� ����� ����������� DataGridView
				SaveTasks();
				LoadTasks();
				UpdateTaskList();
			}
		}

		void SaveTasks() {
			String^ fileName = "tasks.csv";
			try {
				// ��������� ������� ���� �� ������
				FileStream^ fs = gcnew FileStream(fileName, FileMode::Open, FileAccess::ReadWrite, FileShare::None);
				fs->Close();

				StreamWriter^ writer = gcnew StreamWriter(fileName, false, System::Text::Encoding::UTF8);
				writer->WriteLine("����;������;�����;���������;���������");
				for each (KeyValuePair<DateTime, List<Tuple<String^, DateTime, String^, bool>^>^> task in taskManager->tasks) {
					for each (Tuple<String^, DateTime, String^, bool> ^ t in task.Value) {
						writer->WriteLine("{0};{1};{2};{3};{4}", task.Key.ToString("yyyy-MM-dd"), t->Item1, t->Item2.ToString("HH:mm"), t->Item3, t->Item4);
					}
				}
				writer->Close();
			}
			catch (IOException^ ex) {
				MessageBox::Show("������: ���� tasks.csv ��� ������. �������� ���� � ��������� �������.", "������ ����������", MessageBoxButtons::OK, MessageBoxIcon::Error);
				BlockEditing(true);
			}
			catch (Exception^ ex) {
				MessageBox::Show("������ ��� ������ � ����: " + ex->Message, "������ ����������", MessageBoxButtons::OK, MessageBoxIcon::Error);
				BlockEditing(true);
			}
		}




		void LoadTasks() {
			String^ fileName = "tasks.csv";
			if (!File::Exists(fileName)) return;

			try {
				// ��������� ������� ���� �� ������
				FileStream^ fs = gcnew FileStream(fileName, FileMode::Open, FileAccess::Read, FileShare::None);
				fs->Close();

				StreamReader^ reader = gcnew StreamReader(fileName, System::Text::Encoding::UTF8);
				reader->ReadLine(); // ���������� ���������
				taskManager->tasks->Clear(); // ������� ������� �����

				while (!reader->EndOfStream) {
					String^ line = reader->ReadLine();
					array<String^>^ parts = line->Split(';');
					if (parts->Length == 5) { // ��������� 5 ������ ������: ����, ������, �����, ���������, ���������
						DateTime date = DateTime::Parse(parts[0]);
						String^ taskText = parts[1];
						DateTime taskTime = DateTime::Parse(parts[2]);
						String^ priority = parts[3];
						bool isCompleted = Convert::ToBoolean(parts[4]);

						if (!taskManager->tasks->ContainsKey(date)) {
							taskManager->tasks[date] = gcnew List<Tuple<String^, DateTime, String^, bool>^>();
						}
						taskManager->tasks[date]->Add(gcnew Tuple<String^, DateTime, String^, bool>(taskText, taskTime, priority, isCompleted));
					}
				}
				reader->Close();
				UpdateTaskList();
			}
			catch (IOException^ ex) {
				MessageBox::Show("������: ���� tasks.csv ��� ������. �������� ���� � ��������� �������.", "������ ��������", MessageBoxButtons::OK, MessageBoxIcon::Error);
				BlockEditing(true);
			}
			catch (Exception^ ex) {
				MessageBox::Show("������ ��� ������ �����: " + ex->Message, "������ ��������", MessageBoxButtons::OK, MessageBoxIcon::Error);
				BlockEditing(true);
			}
		}




		void CheckForUpcomingTasks(Object^ sender, System::Timers::ElapsedEventArgs^ e) {
			DateTime now = DateTime::Now;
			DateTime reminderTime = now.AddMinutes(1); // ����������� �� 1 ����� �� ������

			for each (auto kvp in taskManager->tasks) {
				DateTime date = kvp.Key;
				auto tasksForDate = kvp.Value;

				for each (auto task in tasksForDate) {
					if (date.Date == now.Date && task->Item2.TimeOfDay >= now.TimeOfDay && task->Item2.TimeOfDay <= reminderTime.TimeOfDay) {
						ShowTaskReminder(task->Item1, task->Item2);
					}
				}
			}
		}

		void ShowTaskReminder(String^ task, DateTime taskTime) {
			String^ message = String::Format("����� ����� ��������� ������: {0} � {1}", task, taskTime.ToShortTimeString());
			MessageBox::Show(message, "����������� � ������", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}


		void UpdateBoldedDates() {
			// �������� ���� ������ ���
			monthCalendar1->RemoveAllBoldedDates();

			// ����������� �� ������� � ��������� ������ ����� � ����� �����
			for each (KeyValuePair<DateTime, List<Tuple<String^, DateTime, String^, bool>^>^> ^ task in taskManager->tasks) {
				DateTime date = task->Key;
				monthCalendar1->AddBoldedDate(date);
			}

			// ���������� ������ ��� � ���������
			monthCalendar1->UpdateBoldedDates();
		}

		private: System::Void �������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			if (dataGridView1->SelectedRows->Count > 0) {
				DateTime selectedDate = monthCalendar1->SelectionStart;
				DataGridViewRow^ selectedRow = dataGridView1->SelectedRows[0];
				String^ taskText = selectedRow->Cells["Column1"]->Value->ToString();
				DateTime taskTime;

				// ��������� ������������� �������� ������� ������
				if (!DateTime::TryParse(selectedRow->Cells["Column2"]->Value->ToString(), taskTime)) {
					taskTime = DateTime::MinValue; // ������������� ���������� ��������� �������� ����
				}

				// ������� ������ �� taskManager
				if (taskManager->tasks->ContainsKey(selectedDate)) {
					auto tasksForDate = taskManager->tasks[selectedDate];
					for (int i = 0; i < tasksForDate->Count; i++) {
						auto task = tasksForDate[i];
						if (task->Item1 == taskText && (task->Item2 == taskTime || taskTime == DateTime::MinValue)) {
							tasksForDate->RemoveAt(i);
							break;
						}
					}
					if (tasksForDate->Count == 0) {
						taskManager->tasks->Remove(selectedDate);
					}

					// ���������� ����������� ����� � ����
					SaveTasks();
				}

				// �������� ������ �� DataGridView
				dataGridView1->Rows->RemoveAt(selectedRow->Index);

				// ���������� ������ �����
				UpdateTaskList();
			}
			else {
				MessageBox::Show("����������, �������� ������ ��� ��������.");
			}
		}
			   
			   void DeleteTaskAfterThirtySeconds(System::Object^ sender, EventArgs^ e) {
				   System::Windows::Forms::Timer^ timer = (System::Windows::Forms::Timer^)sender;
				   DataGridViewRow^ row = (DataGridViewRow^)timer->Tag;

				   // ��������, ��� ������ ����������
				   if (row == nullptr) {
					   timer->Stop();
					   return; // ����������, ���� ������ �� �������
				   }

				   // �������� ����, ����� ������ � ����� ������ ��� ��������
				   DateTime selectedDate = monthCalendar1->SelectionStart; // ���������, ��� � ��� ����������� ���������� ����

				   // ������ ���������� ������� ��� ��������� ��������
				   String^ taskText = row->Cells[0]->Value->ToString(); // ��������������, ��� ����� ������ ��������� � ������ �������
				   DateTime taskTime;
				   if (!DateTime::TryParse(row->Cells[1]->Value->ToString(), taskTime)) {
					   taskTime = DateTime::MinValue; // ������ ������: ����� ������ �� �����������
				   }

				   // �������� ������ �� taskManager
				   if (taskManager->tasks->ContainsKey(selectedDate)) {
					   auto tasksForDate = taskManager->tasks[selectedDate];

					   // ���� ��� ������������, ���� �� ��������
					   bool taskRemoved = false;

					   for (int i = 0; i < tasksForDate->Count; i++) {
						   auto task = tasksForDate[i];
						   // ���������� ����� ������ � �����
						   if (task->Item1 == taskText && (task->Item2 == taskTime || taskTime == DateTime::MinValue)) {
							   tasksForDate->RemoveAt(i); // ������� ������
							   taskRemoved = true; // ������������� ���� ��������
							   break; // ��������� ���� ����� ���������� � ��������
						   }
					   }

					   // ������� ���� �� taskManager, ���� �������� ���� �������� � ��� ����� ��� ���� ����
					   if (taskRemoved && tasksForDate->Count == 0) {
						   taskManager->tasks->Remove(selectedDate);
					   }
				   }

				   // �������� ������ �� DataGridView
				   int rowIndex = row->Index;
				   if (rowIndex >= 0 && rowIndex < dataGridView1->Rows->Count) {
					   dataGridView1->Rows->RemoveAt(rowIndex);
				   }

				   // ���������� ����� tasks.csv
				   SaveTasks(); // ��������� ����������� ��������� � ����

				   // ���������� ������ �����
				   UpdateTaskList();

				   // ��������� �������
				   timer->Stop();
			   }

			   
			   void dataGridView1_CellValueChanged(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
				   if (e->RowIndex >= 0 && e->RowIndex < dataGridView1->Rows->Count && e->ColumnIndex == dataGridView1->Columns["Column4"]->Index) {
					   DataGridViewRow^ row = dataGridView1->Rows[e->RowIndex];
					   if (row->Cells["Column4"]->Value != nullptr) {
						   try {
							   bool isCompleted = Convert::ToBoolean(row->Cells["Column4"]->Value);
							   if (isCompleted) {
								   // ���������, ��� �� ������� ����� ������, ���� ������ ��� �������
								   if (row->Tag == nullptr) {
									   System::Windows::Forms::Timer^ timer = gcnew System::Windows::Forms::Timer();
									   timer->Interval = 4000; // 30 ������
									   timer->Tag = row;
									   timer->Tick += gcnew EventHandler(this, &MyForm::DeleteTaskAfterThirtySeconds);
									   timer->Start();
									   row->Tag = timer; // ��������� ������ � ���� ������
								   }
							   }
						   }
						   catch (FormatException^) {
							   // ���������� ������ �������������� �������
						   }
					   }
				   }
			   }


		   void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
			   this->���������ToolStripMenuItem->Enabled = (textBox1->Text->Length > 0);
		   }

		   void dataGridView1_MouseWheel(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			   int currentIndex = dataGridView1->CurrentRow ? dataGridView1->CurrentRow->Index : 0;
			   int newIndex = currentIndex;

			   if (e->Delta > 0) {
				   // ��������� �����
				   if (currentIndex > 0) {
					   newIndex = Math::Max(0, currentIndex - 1);
				   }
			   }
			   else if (e->Delta < 0) {
				   // ��������� ����
				   if (currentIndex < dataGridView1->Rows->Count - 1) {
					   newIndex = Math::Min(dataGridView1->Rows->Count - 1, currentIndex + 1);
				   }
			   }

			   // ������������ � �������� ����� ������
			   if (newIndex != currentIndex) {
				   dataGridView1->FirstDisplayedScrollingRowIndex = newIndex;
				   dataGridView1->ClearSelection();
				   dataGridView1->Rows[newIndex]->Selected = true;
				   dataGridView1->CurrentCell = dataGridView1->Rows[newIndex]->Cells[0];
			   }
		   }

		   		    
		   void dataGridView1_DataError(System::Object^ sender, System::Windows::Forms::DataGridViewDataErrorEventArgs^ e) {
			   // ��������� ������ �������������� ������
			   if (e->Exception != nullptr && e->Context == (System::Windows::Forms::DataGridViewDataErrorContexts::Formatting | System::Windows::Forms::DataGridViewDataErrorContexts::PreferredSize)) {
				   // ���������� ������
				   e->ThrowException = false;
			   }
		   }

		   void MyForm::dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
			   if (e->ColumnIndex == dataGridView1->Columns["Column4"]->Index && e->RowIndex >= 0) {
				   DataGridViewCheckBoxCell^ checkBoxCell = (DataGridViewCheckBoxCell^)dataGridView1->Rows[e->RowIndex]->Cells["Column4"];
				   checkBoxCell->Value = !(Convert::ToBoolean(checkBoxCell->Value)); // ����������� �������� CheckBox
			   }
		   }

};
}

