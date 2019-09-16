#include <iostream>
#include <windows.h>
#include <tchar.h>
int main()
{
	setlocale(LC_ALL, "Russian");

	LPTSTR buffer = new TCHAR[150];
	LPDWORD size = new DWORD[200];

	GetComputerName(buffer, size);
	_tprintf(TEXT("Имя компьютера: %s\n"), buffer);

	
	GetUserName(buffer, size);
	_tprintf(TEXT("Имя пользователя: %s\n"), buffer);

	DWORD nsize=100;
	GetWindowsDirectory(buffer, nsize);
	_tprintf(TEXT("Путь к каталогу Windows: %s\n"), buffer);

	
	GetSystemDirectory(buffer, nsize);
	_tprintf(TEXT("Путь к системному каталогу: %s\n"), buffer);

	
	GetTempPath(nsize, buffer);
	_tprintf(TEXT("Путь к каталогу временных файлов Windows: %s\n"), buffer);

	OSVERSIONINFO version;
	version.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	GetVersionEx(&version);
	if (version.dwMajorVersion==6)
		std::cout << "Версия Windows: 10.0" << std::endl;
	else
		std::cout << "Версия Windows: " << version.dwMajorVersion << std::endl;
	std::cout << "Имеется ли колесико прокрутки: ";
		if (GetSystemMetrics(75))
		{
			std::cout << "ДА" << std::endl;
		}
		else
		{
			std::cout << "НЕТ" << std::endl;
		}
	std::cout << "Размер экрана: " << GetSystemMetrics(0) << "x" << GetSystemMetrics(1) << std::endl;

	int par;
	SystemParametersInfo(SPI_GETKEYBOARDSPEED, 0, &par, 0);
	std::cout << "Скорость повтора символов на клавиатуре при нажатой клавише = " << par <<std::endl;
	SystemParametersInfo(SPI_GETFASTTASKSWITCH, 0, &par, 0);
	if (par)	
		std::cout << "Alt + Tab включён: " << "Да" << std::endl;
	else
		std::cout << "Alt + Tab включён: " << "Нет" << std::endl;

	nsize = GetSysColor(3);
	printf("Текущие цвета: (0x%x, 0x%x, 0x%x)\n", GetRValue(nsize), GetGValue(nsize), GetBValue(nsize));
	DWORD color = RGB(0x80, 0x80, 0x80);
	const INT a = 3;
	SetSysColors(1, &a, &color);
	color = GetSysColor(3);
	printf("Новые цвета: (0x%x, 0x%x, 0x%x)\n", GetRValue(color), GetGValue(color), GetBValue(color));
	SetSysColors(1, &a, &nsize);
	color = GetSysColor(3);
	printf("Возврат к старым цветам: (0x%x, 0x%x, 0x%x)\n", GetRValue(color), GetGValue(color), GetBValue(color));

	SYSTEMTIME time;
	GetSystemTime(&time);
	std::cout << "Системное время: " << time.wHour << ":" << time.wMinute <<":"<<time.wSecond<< std::endl;
	GetLocalTime(&time);
	std::cout << "Местное время : " << time.wHour << ":" << time.wMinute << ":" << time.wSecond << std::endl;
	std::cout << "Версия сборки ос : " << version.dwBuildNumber<< std::endl;
	std::cout << "Количество кнопок мыши : " << GetSystemMetrics(43) << std::endl;
	LASTINPUTINFO input;
	GetLastInputInfo(&input);
	std::cout << "Последний ввод с клавиатуры зафиксирован сколько тиков назад : " << input.dwTime << std::endl;
	system("pause");
	return 0;
	
}

