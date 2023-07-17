enum ConsoleColor
{
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	LightBrown = 14,
	White = 15
};

#define VGA_COLOR_CRT_ADDRESS 0x3D4
#define VGA_MONO_CRT_ADDRESS 0x3B4

#define VGA_CRT_CURSOR_START 0x0A
#define VGA_CRT_CURSOR_END 0x0B
#define VGA_CRT_H_START_ADDRESS 0x0C
#define VGA_CRT_H_END_ADDRESS 0x0D
#define VGA_CRT_CURSOR_H_LOCATION 0x0E
#define VGA_CRT_CURSOR_L_LOCATION 0x0F



void OutPortByte(unsigned short port, unsigned char value)
{
	//outportb(port, value);
}

void ClearScreen()
{
	int m_ScreenHeight = 25;
	int m_ScreenWidth = 80;
	int m_Text = White;
	int m_backGroundColor = Black;
	int m_Color = ((m_backGroundColor << 4) | m_Text);
	unsigned short m_VideoCardType = VGA_COLOR_CRT_ADDRESS;	// color

	unsigned short* m_pVideoMemory = (unsigned short*)0xb8000;

	for (int i = 0; i < m_ScreenWidth * m_ScreenHeight; i++)				//Remember, 25 rows and 80 columns
	{
		m_pVideoMemory[i] = (unsigned short)(0x20 | (m_Color << 8));
	}	

	OutPortByte(m_VideoCardType, VGA_CRT_CURSOR_H_LOCATION);
	OutPortByte(m_VideoCardType + 1, 0 >> 8);
	OutPortByte(m_VideoCardType, VGA_CRT_CURSOR_L_LOCATION);
	OutPortByte(m_VideoCardType + 1, (0 << 8) >> 8);
}

void _start()
{
	//Put a breakpoint here!
	int i = 0;
	ClearScreen();
	for (;;);
}
