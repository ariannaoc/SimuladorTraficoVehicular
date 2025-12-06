#include "MyForm.h"

using namespace System::Windows;
using namespace System::Windows::Forms;

int main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew TraficoVehicular::MyForm());
	return 0;
}