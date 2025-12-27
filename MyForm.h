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
			this->detenerBtn = (gcnew System::Windows::Forms::Button());
			this->panel->SuspendLayout();
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
			this->inicioBtn->Location = System::Drawing::Point(51, 68);
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
			this->panel->Controls->Add(this->inicioBtn);
			this->panel->Controls->Add(this->detenerBtn);
			this->panel->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel->Location = System::Drawing::Point(0, 0);
			this->panel->MaximumSize = System::Drawing::Size(200, 750);
			this->panel->Name = L"panel";
			this->panel->Size = System::Drawing::Size(200, 703);
			this->panel->TabIndex = 2;
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
			this->detenerBtn->Location = System::Drawing::Point(51, 68);
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
		timer->Interval = 100;
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

	};
}