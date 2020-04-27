#include "wifi_driver.h"
void wifisetup()
{
	delay();

	 UART_Write_String("AT+CWMODE=1\r\n");
   	 delay();
	 UART_Write_String("AT+CIPSTA=\"192.168.43.50\",\"192.168.43.1\",\"255.255.255.0\"\r\n");
	 delay();
	// UART_Write_String("AT+CWJAP=\"HATEM\",\"12345678\"\r\n");
	//_delay_ms(2000);
	 UART_Write_String("AT+CIPMUX=1\r\n");
	 delay();
	 UART_Write_String("AT+CIPSERVER=1,8080\r\n");
	 delay();
}
void get_the_command(uint8_t recieved_char)
{
}
void delay()
{
	 for(uint16_t i=0xFFFF;i!=0;i--)
	 {
	 }

}
