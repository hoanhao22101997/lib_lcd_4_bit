#ifndef __LCD_H__
#define __LCD_H__
#define  LCD_RS   PIN_C0
#define  LCD_RW   PIN_C1
#define  LCD_EN   PIN_C2
#define  LCD_D4   PIN_C3
#define  LCD_D5   PIN_C4
#define  LCD_D6   PIN_C5
#define  LCD_D7   PIN_C6
void lcd_enable(void);
void lcd_send_4_bit(unsigned char   data);
void lcd_send_command(unsigned char command);
void lcd_clear(void);
void lcd_init();
void lcd_gotoxy(unsigned char x,unsigned char y);
void lcd_put(unsigned char data);
void lcd_puts(char *s);
#endif
