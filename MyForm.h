#pragma once
#include "Simulador.h"

namespace TraficoVehicular {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		bool iniciar = false;
		int nivelTrafico = 1; // 1: bajo, 2: medio, 3: alto
		Bitmap^ fondo;
		Bitmap^ brujula;
		Bitmap^ autos;
		Graphics^ graph;
		BufferedGraphics^ bgraph;
		Simulador* simulador;
	private: System::Windows::Forms::Timer^ timer;
	private: System::Windows::Forms::Panel^ panel;




	private: System::Windows::Forms::Button^ inicioBtn;
	private: System::Windows::Forms::Button^ detenerBtn;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ highTrafficBtn;

	private: System::Windows::Forms::Button^ medTrafficBtn;

	private: System::Windows::Forms::Button^ lowTrafficBtn;
	private: System::Windows::Forms::GroupBox^ gbVelocidad;

	private: System::Windows::Forms::RadioButton^ vel15x;

	private: System::Windows::Forms::RadioButton^ vel1x;
	private: System::Windows::Forms::RadioButton^ vel2x;





	private: System::ComponentModel::IContainer^ components;

	public:
		MyForm(void)
		{
			fondo = gcnew Bitmap("carretera.png");
			brujula = gcnew Bitmap("brujula.png");

			// sprite 
			autos = gcnew Bitmap("setAutos-noB.png");
			simulador = new Simulador();
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public:
	protected:

	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->inicioBtn = (gcnew System::Windows::Forms::Button());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel = (gcnew System::Windows::Forms::Panel());
			this->gbVelocidad = (gcnew System::Windows::Forms::GroupBox());
			this->vel2x = (gcnew System::Windows::Forms::RadioButton());
			this->vel15x = (gcnew System::Windows::Forms::RadioButton());
			this->vel1x = (gcnew System::Windows::Forms::RadioButton());
			this->highTrafficBtn = (gcnew System::Windows::Forms::Button());
			this->medTrafficBtn = (gcnew System::Windows::Forms::Button());
			this->lowTrafficBtn = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->detenerBtn = (gcnew System::Windows::Forms::Button());
			this->panel->SuspendLayout();
			this->gbVelocidad->SuspendLayout();
			this->SuspendLayout();
			// 
			// inicioBtn
			// 
			this->inicioBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->inicioBtn->BackColor = System::Drawing::Color::SeaGreen;
			this->inicioBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->inicioBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->inicioBtn->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->inicioBtn->ForeColor = System::Drawing::Color::PaleGreen;
			this->inicioBtn->Location = System::Drawing::Point(43, 23);
			this->inicioBtn->Name = L"inicioBtn";
			this->inicioBtn->Size = System::Drawing::Size(113, 53);
			this->inicioBtn->TabIndex = 0;
			this->inicioBtn->Text = L"Iniciar";
			this->inicioBtn->UseVisualStyleBackColor = false;
			this->inicioBtn->Click += gcnew System::EventHandler(this, &MyForm::inicioBtn_Click);
			// 
			// timer
			// 
			this->timer->Enabled = true;
			this->timer->Tick += gcnew System::EventHandler(this, &MyForm::timer_Tick);
			// 
			// panel
			// 
			this->panel->BackColor = System::Drawing::Color::Silver;
			this->panel->Controls->Add(this->gbVelocidad);
			this->panel->Controls->Add(this->highTrafficBtn);
			this->panel->Controls->Add(this->medTrafficBtn);
			this->panel->Controls->Add(this->lowTrafficBtn);
			this->panel->Controls->Add(this->label1);
			this->panel->Controls->Add(this->inicioBtn);
			this->panel->Controls->Add(this->detenerBtn);
			this->panel->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel->Location = System::Drawing::Point(0, 0);
			this->panel->MaximumSize = System::Drawing::Size(200, 750);
			this->panel->Name = L"panel";
			this->panel->Size = System::Drawing::Size(200, 703);
			this->panel->TabIndex = 2;
			// 
			// gbVelocidad
			// 
			this->gbVelocidad->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->gbVelocidad->BackColor = System::Drawing::Color::Transparent;
			this->gbVelocidad->Controls->Add(this->vel2x);
			this->gbVelocidad->Controls->Add(this->vel15x);
			this->gbVelocidad->Controls->Add(this->vel1x);
			this->gbVelocidad->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->gbVelocidad->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->gbVelocidad->Location = System::Drawing::Point(3, 403);
			this->gbVelocidad->Name = L"gbVelocidad";
			this->gbVelocidad->Padding = System::Windows::Forms::Padding(3, 3, 3, 0);
			this->gbVelocidad->Size = System::Drawing::Size(194, 122);
			this->gbVelocidad->TabIndex = 0;
			this->gbVelocidad->TabStop = false;
			this->gbVelocidad->Text = L"Velocidad de simulacion";
			// 
			// vel2x
			// 
			this->vel2x->Appearance = System::Windows::Forms::Appearance::Button;
			this->vel2x->AutoSize = true;
			this->vel2x->Location = System::Drawing::Point(134, 60);
			this->vel2x->Name = L"vel2x";
			this->vel2x->Size = System::Drawing::Size(54, 34);
			this->vel2x->TabIndex = 2;
			this->vel2x->TabStop = true;
			this->vel2x->Text = L"  2x ";
			this->vel2x->UseVisualStyleBackColor = true;
			this->vel2x->CheckedChanged += gcnew System::EventHandler(this, &MyForm::vel2x_CheckedChanged);
			// 
			// vel15x
			// 
			this->vel15x->Appearance = System::Windows::Forms::Appearance::Button;
			this->vel15x->AutoSize = true;
			this->vel15x->Location = System::Drawing::Point(70, 60);
			this->vel15x->Name = L"vel15x";
			this->vel15x->Size = System::Drawing::Size(54, 34);
			this->vel15x->TabIndex = 1;
			this->vel15x->TabStop = true;
			this->vel15x->Text = L"1.5x";
			this->vel15x->UseVisualStyleBackColor = true;
			this->vel15x->CheckedChanged += gcnew System::EventHandler(this, &MyForm::vel15x_CheckedChanged);
			// 
			// vel1x
			// 
			this->vel1x->Appearance = System::Windows::Forms::Appearance::Button;
			this->vel1x->AutoSize = true;
			this->vel1x->Location = System::Drawing::Point(7, 60);
			this->vel1x->Name = L"vel1x";
			this->vel1x->Size = System::Drawing::Size(54, 34);
			this->vel1x->TabIndex = 0;
			this->vel1x->TabStop = true;
			this->vel1x->Text = L"  1x ";
			this->vel1x->UseVisualStyleBackColor = true;
			this->vel1x->CheckedChanged += gcnew System::EventHandler(this, &MyForm::vel1x_CheckedChanged);
			// 
			// highTrafficBtn
			// 
			this->highTrafficBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->highTrafficBtn->BackColor = System::Drawing::Color::DarkSlateGray;
			this->highTrafficBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->highTrafficBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->highTrafficBtn->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->highTrafficBtn->ForeColor = System::Drawing::Color::Crimson;
			this->highTrafficBtn->Location = System::Drawing::Point(45, 300);
			this->highTrafficBtn->Name = L"highTrafficBtn";
			this->highTrafficBtn->Size = System::Drawing::Size(100, 50);
			this->highTrafficBtn->TabIndex = 5;
			this->highTrafficBtn->Text = L"Alto";
			this->highTrafficBtn->UseVisualStyleBackColor = false;
			this->highTrafficBtn->Click += gcnew System::EventHandler(this, &MyForm::highTrafficBtn_Click);
			// 
			// medTrafficBtn
			// 
			this->medTrafficBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->medTrafficBtn->BackColor = System::Drawing::Color::DarkSlateGray;
			this->medTrafficBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->medTrafficBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->medTrafficBtn->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->medTrafficBtn->ForeColor = System::Drawing::Color::Gold;
			this->medTrafficBtn->Location = System::Drawing::Point(45, 229);
			this->medTrafficBtn->Name = L"medTrafficBtn";
			this->medTrafficBtn->Size = System::Drawing::Size(100, 50);
			this->medTrafficBtn->TabIndex = 4;
			this->medTrafficBtn->Text = L"Medio";
			this->medTrafficBtn->UseVisualStyleBackColor = false;
			this->medTrafficBtn->Click += gcnew System::EventHandler(this, &MyForm::medTrafficBtn_Click);
			// 
			// lowTrafficBtn
			// 
			this->lowTrafficBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lowTrafficBtn->BackColor = System::Drawing::Color::DarkSlateGray;
			this->lowTrafficBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lowTrafficBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->lowTrafficBtn->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lowTrafficBtn->ForeColor = System::Drawing::Color::PaleGreen;
			this->lowTrafficBtn->Location = System::Drawing::Point(45, 153);
			this->lowTrafficBtn->Name = L"lowTrafficBtn";
			this->lowTrafficBtn->Size = System::Drawing::Size(100, 50);
			this->lowTrafficBtn->TabIndex = 3;
			this->lowTrafficBtn->Text = L"Bajo";
			this->lowTrafficBtn->UseVisualStyleBackColor = false;
			this->lowTrafficBtn->Click += gcnew System::EventHandler(this, &MyForm::lowTrafficBtn_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->label1->Location = System::Drawing::Point(27, 113);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(137, 24);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Nivel de tráfico";
			// 
			// detenerBtn
			// 
			this->detenerBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->detenerBtn->BackColor = System::Drawing::Color::OrangeRed;
			this->detenerBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->detenerBtn->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->detenerBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->detenerBtn->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->detenerBtn->ForeColor = System::Drawing::Color::PeachPuff;
			this->detenerBtn->Location = System::Drawing::Point(43, 23);
			this->detenerBtn->Name = L"detenerBtn";
			this->detenerBtn->Size = System::Drawing::Size(113, 53);
			this->detenerBtn->TabIndex = 1;
			this->detenerBtn->Text = L"Detener";
			this->detenerBtn->UseVisualStyleBackColor = false;
			this->detenerBtn->Visible = false;
			this->detenerBtn->Click += gcnew System::EventHandler(this, &MyForm::detenerBtn_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->detenerBtn;
			this->ClientSize = System::Drawing::Size(982, 703);
			this->Controls->Add(this->panel);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Tráfico Vehicular";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::Form_Paint);
			this->panel->ResumeLayout(false);
			this->panel->PerformLayout();
			this->gbVelocidad->ResumeLayout(false);
			this->gbVelocidad->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void inicioBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		inicioBtn->Visible = false;
		detenerBtn->Visible = true;
		iniciar = true;
	}

	private: System::Void Form_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		graph = this->CreateGraphics();
		BufferedGraphicsContext^ context = BufferedGraphicsManager::Current;
		bgraph = context->Allocate(graph, this->ClientRectangle);

	}

	private: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e) {
		bgraph->Graphics->DrawImage(fondo, 150, 0, 600, 600);
		simulador->IniciarSimulacion(iniciar, bgraph, autos);
		bgraph->Graphics->DrawImage(brujula, 650, 10, 70, 70);
		bgraph->Render(graph);
	}

	private: System::Void detenerBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		iniciar = false;
		detenerBtn->Visible = false;
		inicioBtn->Visible = true;
	}

	private: System::Void resetBotones() {
		lowTrafficBtn->BackColor = System::Drawing::Color::DarkSlateGray;
		medTrafficBtn->BackColor = System::Drawing::Color::DarkSlateGray;
		highTrafficBtn->BackColor = System::Drawing::Color::DarkSlateGray;

	}
	private: System::Void lowTrafficBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		resetBotones();
		lowTrafficBtn->BackColor = System::Drawing::Color::SeaGreen;
		nivelTrafico = 1;
		simulador->setNivelTrafico(nivelTrafico);
	}
	private: System::Void medTrafficBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		resetBotones();
		medTrafficBtn->BackColor = System::Drawing::Color::LemonChiffon;
		nivelTrafico = 2;
		simulador->setNivelTrafico(nivelTrafico);

	}
	private: System::Void highTrafficBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		resetBotones();
		highTrafficBtn->BackColor = System::Drawing::Color::PeachPuff;
		nivelTrafico = 3;
		simulador->setNivelTrafico(nivelTrafico);

	}
	private: System::Void resetRadio() {
		vel1x->BackColor = System::Drawing::Color::LightGray;
		vel1x->ForeColor = System::Drawing::Color::DarkSlateGray;
		vel15x->BackColor = System::Drawing::Color::LightGray;
		vel15x->ForeColor = System::Drawing::Color::DarkSlateGray;
		vel2x->BackColor = System::Drawing::Color::LightGray;
		vel2x->ForeColor = System::Drawing::Color::DarkSlateGray;

	}

	private: System::Void vel1x_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (vel1x->Checked) {
			timer->Interval = 100;
			resetRadio();
			vel1x->BackColor = System::Drawing::Color::DarkSlateGray;
			vel1x->ForeColor = System::Drawing::Color::LightGray;
		}
	}
	private: System::Void vel15x_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (vel15x->Checked) {
			timer->Interval = 66; 
			resetRadio();
			vel15x->BackColor = System::Drawing::Color::DarkSlateGray;
			vel15x->ForeColor = System::Drawing::Color::LightGray;
		}
	}
	private: System::Void vel2x_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (vel2x->Checked) {
			timer->Interval = 50; 
			resetRadio();
			vel2x->BackColor = System::Drawing::Color::DarkSlateGray;
			vel2x->ForeColor = System::Drawing::Color::LightGray;
		}
	}
	};
}