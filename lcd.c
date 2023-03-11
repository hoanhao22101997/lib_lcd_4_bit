#include"lcd.h"
void lcd_enable(void){
   output_high(LCD_EN);
   delay_us(3);
   output_low(LCD_EN);
   delay_us(50);
}
void lcd_send_4_bit(unsigned char   data){
   output_bit(LCD_D4,data&0x01);
   output_bit(LCD_D5,data&0x02);
   output_bit(LCD_D6,data&0x04);
   output_bit(LCD_D7,data&0x08);
}
void lcd_send_command(unsigned char command){
   lcd_send_4_bit(command>>4);
   lcd_enable();
   lcd_send_4_bit(command);
   lcd_enable();
}
void lcd_clear(void){
   lcd_send_command(0x01);
   lcd_enable();
}
void lcd_init(){
   lcd_send_4_bit(0x00);   // khoi tao lcd
   delay_us(10);
   output_low(LCD_RS);
   output_low(LCD_RW);
   lcd_send_4_bit(0x03);
   lcd_enable();
   delay_ms(5);
   lcd_enable();
   delay_us(100);
   lcd_enable();
   lcd_send_4_bit(0x02);
   lcd_enable();
   lcd_send_command(0x28);
   lcd_send_command(0x0c);
   lcd_send_command(0x06);
   lcd_send_command(0x01);
}
void lcd_gotoxy(unsigned char x,unsigned char y){
   unsigned char addr;
   if(!y){
      addr =0x80+x;
   }else addr=0xc0+y;
   lcd_send_command(addr);
}
void lcd_put(unsigned char data){
   output_high(LCD_RS);
   lcd_send_command(data);
   output_low(LCD_RS);  
}
void lcd_puts(char *s){
   while(*s){
      lcd_put(*s);
      s++;
   }
}