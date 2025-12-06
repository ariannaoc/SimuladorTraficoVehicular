#include "MyForm.h"
#include <time.h>

using namespace System::Windows;
using namespace System::Windows::Forms;

int main() {
	srand(time(NULL));
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew TraficoVehicular::MyForm());
	return 0;
}