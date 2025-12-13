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
	private: System::Windows::Forms::Button^ inicioBtn;
	private: System::Windows::Forms::Label^ TitleLabel;


	private: System::ComponentModel::IContainer^ components;

	public:
		MyForm(void)
		{
			fondo = gcnew Bitmap("carretera.png");
			//brujula= gcnew Bitmap("norte.png");
			brujula= gcnew Bitmap("brujula.png");
			
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
			this->TitleLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// inicioBtn
			// 
			this->inicioBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->inicioBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->inicioBtn->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->inicioBtn->Location = System::Drawing::Point(232, 471);
			this->inicioBtn->Name = L"inicioBtn";
			this->inicioBtn->Size = System::Drawing::Size(308, 40);
			this->inicioBtn->TabIndex = 0;
			this->inicioBtn->Text = L"Iniciar";
			this->inicioBtn->UseVisualStyleBackColor = true;
			this->inicioBtn->Click += gcnew System::EventHandler(this, &MyForm::inicioBtn_Click);
			// 
			// timer
			// 
			this->timer->Enabled = true;
			this->timer->Tick += gcnew System::EventHandler(this, &MyForm::timer_Tick);
			// 
			// TitleLabel
			// 
			this->TitleLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->TitleLabel->AutoSize = true;
			this->TitleLabel->BackColor = System::Drawing::Color::Transparent;
			this->TitleLabel->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TitleLabel->Location = System::Drawing::Point(198, 124);
			this->TitleLabel->Name = L"TitleLabel";
			this->TitleLabel->Size = System::Drawing::Size(357, 92);
			this->TitleLabel->TabIndex = 1;
			this->TitleLabel->Text = L"Simulador de\r\nTráfico Vehicular";
			this->TitleLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(782, 653);
			this->Controls->Add(this->TitleLabel);
			this->Controls->Add(this->inicioBtn);
			this->MaximumSize = System::Drawing::Size(800, 700);
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Tráfico Vehicular";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::Form_Paint);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void inicioBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		inicioBtn->Visible = false;
		TitleLabel->Visible = false;
		iniciar = true;
	}

	private: System::Void Form_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		graph = this->CreateGraphics();
		BufferedGraphicsContext^ context = BufferedGraphicsManager::Current;
		bgraph = context->Allocate(graph, this->ClientRectangle);

	}
	private: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e) {
		timer->Interval = 100;
		bgraph->Graphics->DrawImage(fondo, 0, 0, 600, 600);
		simulador->IniciarSimulacion(iniciar, bgraph, autos);
		bgraph->Graphics->DrawImage(brujula, 500, 10, 70, 70);
		bgraph->Render(graph);
	}

	};
}
